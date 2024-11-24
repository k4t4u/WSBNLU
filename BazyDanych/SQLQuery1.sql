--TRANSACT SQL  T-SQL  TSQL

CREATE DATABASE Z1 

CREATE TABLE Studenci 
(
    Id_studenta INT PRIMARY KEY,
    Imie NVARCHAR(50) NOT NULL,
    Nazwisko NVARCHAR(50) NOT NULL,
    Data_urodzenia DATE NULL,
    Nr_albumu INT UNIQUE NOT NULL
);

INSERT INTO Studenci VALUES (1,N'Jan',N'Kowalski',NULL, 1001)

SELECT * FROM dbo.Studenci;

INSERT INTO Studenci (Id_studenta, Imie, Nazwisko, Nr_albumu) VALUES (2,'Anna','Nowak', 1002)

INSERT INTO Studenci VALUES (1,'Piotr','Wrona','1989-05-01', 1003)

INSERT INTO Studenci VALUES (3,'Piotr','Wrona','1989-05-01', 1003)

SELECT * FROM Studenci

SELECT Nazwisko, Imie FROM Studenci

SELECT * FROM Studenci
WHERE Id_studenta = 3

SELECT * FROM Studenci WHERE Nr_albumu > 1002

SELECT * FROM Studenci WHERE Id_studenta = 2

DELETE FROM Studenci WHERE Id_studenta = 2
SELECT * FROM Studenci
