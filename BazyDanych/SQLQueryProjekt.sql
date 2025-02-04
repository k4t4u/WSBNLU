CREATE TABLE dbo.Pracownicy
(
    ID_Pracownika INT IDENTITY(1,1) NOT NULL,
    Imie          NVARCHAR(50)      NOT NULL,
    Nazwisko      NVARCHAR(50)      NOT NULL,
    Stanowisko    NVARCHAR(50)      NOT NULL
        CONSTRAINT CK_Pracownicy_Stanowisko
        CHECK (Stanowisko IN ('Kierownik', 'Robotnik', 'Inzynier', 'Administrator')),
    DataZatrudnienia DATE           NOT NULL,
    Placa         DECIMAL(10,2)     NOT NULL,
    CONSTRAINT PK_Pracownicy PRIMARY KEY (ID_Pracownika)
);

CREATE TABLE dbo.Projekty
(
    ID_Projektu     INT IDENTITY(1,1) NOT NULL,
    NazwaProjektu   NVARCHAR(100)     NOT NULL,
    DataRozpoczecia DATE              NOT NULL,
    DataZakonczenia DATE              NULL,
    Budzet          DECIMAL(12,2)     NOT NULL
        CONSTRAINT CK_Projekty_Budzet
        CHECK (Budzet >= 0),
    ID_Kierownika   INT               NOT NULL,
    CONSTRAINT PK_Projekty PRIMARY KEY (ID_Projektu),
    CONSTRAINT FK_Projekty_Pracownicy
        FOREIGN KEY (ID_Kierownika) 
        REFERENCES dbo.Pracownicy(ID_Pracownika)
);

CREATE TABLE dbo.Klienci
(
    ID_Klienta   INT IDENTITY(1,1) NOT NULL,
    Imie         NVARCHAR(50)      NOT NULL,
    Nazwisko     NVARCHAR(50)      NOT NULL,
    NazwaFirmy   NVARCHAR(100)     NULL,
    Adres        NVARCHAR(200)     NOT NULL,
    Miasto       NVARCHAR(50)      NOT NULL,
    Telefon      NVARCHAR(20)      NOT NULL,
    Email        NVARCHAR(100)     NULL,
    CONSTRAINT PK_Klienci PRIMARY KEY (ID_Klienta)
);

CREATE TABLE dbo.Materialy
(
    ID_Materialu     INT IDENTITY(1,1) NOT NULL,
    NazwaMaterialu   NVARCHAR(100)     NOT NULL,
    JednostkaMiary   NVARCHAR(20)      NOT NULL,
    CenaZaJednostke  DECIMAL(10,2)     NOT NULL,
    IloscDostepna    DECIMAL(10,2)     NOT NULL,
    CONSTRAINT PK_Materialy PRIMARY KEY (ID_Materialu)
);

CREATE TABLE dbo.Zlecenia
(
    ID_Zlecenia     INT IDENTITY(1,1) NOT NULL,
    ID_Projektu     INT               NOT NULL,
    ID_Klienta      INT               NOT NULL,
    DataZlecenia    DATE              NOT NULL,
    TerminRealizacji DATE             NOT NULL,
    KosztZlecenia   DECIMAL(12,2)     NOT NULL,
    CONSTRAINT PK_Zlecenia PRIMARY KEY (ID_Zlecenia),
    CONSTRAINT FK_Zlecenia_Projekty
        FOREIGN KEY (ID_Projektu) 
        REFERENCES dbo.Projekty(ID_Projektu),
    CONSTRAINT FK_Zlecenia_Klienci
        FOREIGN KEY (ID_Klienta) 
        REFERENCES dbo.Klienci(ID_Klienta)
);

CREATE TABLE dbo.SzczegolyZlecenia
(
    ID_Szczegolu    INT IDENTITY(1,1) NOT NULL,
    ID_Zlecenia     INT               NOT NULL,
    ID_Materialu    INT               NOT NULL,
    Ilosc           DECIMAL(10,2)     NOT NULL,
    CONSTRAINT PK_SzczegolyZlecenia PRIMARY KEY (ID_Szczegolu),
    CONSTRAINT FK_Szczegoly_Zlecenia
        FOREIGN KEY (ID_Zlecenia) 
        REFERENCES dbo.Zlecenia(ID_Zlecenia),
    CONSTRAINT FK_Szczegoly_Materialy
        FOREIGN KEY (ID_Materialu) 
        REFERENCES dbo.Materialy(ID_Materialu)
);


IF OBJECT_ID('dbo.vw_PodsumowanieProjektow', 'V') IS NOT NULL
    DROP VIEW dbo.vw_PodsumowanieProjektow;
GO

CREATE VIEW dbo.vw_PodsumowanieProjektow
AS
    SELECT 
        p.ID_Projektu,
        p.NazwaProjektu,
        SUM(ISNULL(z.KosztZlecenia, 0)) AS SumaKosztowZlecen
    FROM dbo.Projekty p
    LEFT JOIN dbo.Zlecenia z
        ON p.ID_Projektu = z.ID_Projektu
    GROUP BY 
        p.ID_Projektu,
        p.NazwaProjektu;
GO


IF OBJECT_ID('dbo.vw_ZleceniaKlienci', 'V') IS NOT NULL
    DROP VIEW dbo.vw_ZleceniaKlienci;
GO

CREATE VIEW dbo.vw_ZleceniaKlienci
AS
    SELECT 
        z.ID_Zlecenia,
        p.NazwaProjektu,
        k.Imie + ' ' + k.Nazwisko AS Klient,
        z.DataZlecenia,
        z.TerminRealizacji,
        z.KosztZlecenia
    FROM dbo.Zlecenia z
    INNER JOIN dbo.Projekty p 
        ON z.ID_Projektu = p.ID_Projektu
    INNER JOIN dbo.Klienci k
        ON z.ID_Klienta = k.ID_Klienta;
GO


IF OBJECT_ID('dbo.fn_ZleceniaKlienta', 'IF') IS NOT NULL
    DROP FUNCTION dbo.fn_ZleceniaKlienta;
GO

CREATE FUNCTION dbo.fn_ZleceniaKlienta
(
    @ID_Klienta INT
)
RETURNS TABLE
AS
RETURN
    SELECT 
        z.ID_Zlecenia,
        z.ID_Projektu,
        z.DataZlecenia,
        z.TerminRealizacji,
        z.KosztZlecenia
    FROM dbo.Zlecenia z
    WHERE z.ID_Klienta = @ID_Klienta;
GO

SELECT * 
FROM dbo.fn_ZleceniaKlienta(1); 


---------------------------------------------------------
-- PROCEDURA: SpDodajSzczegolyZlecenia
-- Dodaje nowy wiersz do tabeli SzczegolyZlecenia,
-- a jeśli materiału jest za mało, rzuca błąd.
---------------------------------------------------------
IF OBJECT_ID('dbo.SpDodajSzczegolyZlecenia', 'P') IS NOT NULL
    DROP PROCEDURE dbo.SpDodajSzczegolyZlecenia;
GO

CREATE PROCEDURE dbo.SpDodajSzczegolyZlecenia
(
    @ID_Zlecenia  INT,
    @ID_Materialu INT,
    @Ilosc        DECIMAL(10,2)
)
AS
BEGIN
    SET NOCOUNT ON;
    
    DECLARE @IloscDostepna DECIMAL(10,2);

    -- 1) Sprawdź, ile materiału mamy w magazynie
    SELECT @IloscDostepna = IloscDostepna
    FROM dbo.Materialy
    WHERE ID_Materialu = @ID_Materialu;

    -- 2) Jeśli nie ma wystarczającej ilości, rzuć błąd i wycofaj transakcję
    IF @IloscDostepna < @Ilosc
    BEGIN
        RAISERROR('Brak wystarczajacej ilosci materialu w magazynie.', 16, 1);
        RETURN;  -- kończy procedurę bez INSERT i UPDATE
    END
    
    -- 3) Wstawiamy nowy rekord do SzczegolyZlecenia
    INSERT INTO dbo.SzczegolyZlecenia (ID_Zlecenia, ID_Materialu, Ilosc)
    VALUES (@ID_Zlecenia, @ID_Materialu, @Ilosc);

    -- 4) Aktualizujemy stan magazynowy (odjęcie zużytej ilości)
    UPDATE dbo.Materialy
    SET IloscDostepna = IloscDostepna - @Ilosc
    WHERE ID_Materialu = @ID_Materialu;
END;
GO


EXEC dbo.SpDodajSzczegolyZlecenia 
     @ID_Zlecenia  = 1,
     @ID_Materialu = 2,
     @Ilosc        = 50.00;



---------------------------------------------------------
-- WYZWALACZ: trg_Materialy_NieujemnaIlosc
-- AFTER UPDATE na tabeli Materialy
-- Nie pozwala na ustawienie ujemnej ilosci dostepnej.
---------------------------------------------------------
IF OBJECT_ID('dbo.trg_Materialy_NieujemnaIlosc', 'TR') IS NOT NULL
    DROP TRIGGER dbo.trg_Materialy_NieujemnaIlosc;
GO

CREATE TRIGGER dbo.trg_Materialy_NieujemnaIlosc
ON dbo.Materialy
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    -- Jeśli wstawiona (INSERTED) wartość IloscDostepna jest < 0, rzuć błąd
    IF EXISTS (
        SELECT 1
        FROM inserted
        WHERE IloscDostepna < 0
    )
    BEGIN
        RAISERROR('IloscDostepna nie moze byc ujemna.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;
GO
