--Zadanie 1
CREATE PROCEDURE P_Z1
AS
BEGIN
    SELECT ProductName, UnitPrice
    FROM Products;
END
GO

EXEC P_Z1;
GO

--Zadanie 2
CREATE FUNCTION F_Z2()
RETURNS TABLE
AS
RETURN (
    SELECT ProductName, UnitPrice
    FROM Products
);
GO

SELECT * FROM F_Z2();
GO

--Zadanie 3
CREATE PROCEDURE P_Z3
(@Price MONEY)
AS
BEGIN
    SELECT ProductName, UnitPrice
    FROM Products
    WHERE UnitPrice > @Price;
END
GO

EXEC P_Z3 50.0;
EXEC P_Z3 90.0;
GO

--Zadanie 4
CREATE FUNCTION F_Z4(@Price MONEY)
RETURNS TABLE
AS
RETURN (
    SELECT ProductName, UnitPrice
    FROM Products
    WHERE UnitPrice > @Price
);
GO

SELECT * FROM F_Z4(50);
SELECT * FROM F_Z4(90);
GO

--Zadanie 5
CREATE PROCEDURE P_Z5
    @CategoryName NVARCHAR(15)
AS
BEGIN
    SELECT P.ProductName, P.UnitPrice, P.CategoryID
    FROM Products P
    JOIN Categories C ON P.CategoryID = C.CategoryID
    WHERE C.CategoryName = @CategoryName;
END
GO

EXEC P_Z5 'Beverages';
GO

--Zadanie 6
CREATE FUNCTION F_Z6(@CategoryName NVARCHAR(15))
RETURNS TABLE
AS
RETURN (
    SELECT P.ProductName, P.UnitPrice, P.CategoryID
    FROM Products P
    JOIN Categories C ON P.CategoryID = C.CategoryID
    WHERE C.CategoryName = @CategoryName
);
GO

SELECT * FROM F_Z6('Beverages');
GO

--Zadanie 7
CREATE FUNCTION F_Z7(@MinPrice MONEY, @MaxPrice MONEY)
RETURNS TABLE
AS
RETURN (
    SELECT ProductID, ProductName, CategoryID, UnitPrice
    FROM Products
    WHERE UnitPrice BETWEEN @MinPrice AND @MaxPrice
);
GO

SELECT * FROM F_Z7(10, 50);
GO

--Zadanie 8
CREATE FUNCTION F_Z8(@MinPrice MONEY, @MaxPrice MONEY, @CategoryName NVARCHAR(15))
RETURNS TABLE
AS
RETURN (
    SELECT P.ProductID, P.ProductName, P.CategoryID, P.UnitPrice
    FROM Products P
    JOIN Categories C ON P.CategoryID = C.CategoryID
    WHERE P.UnitPrice BETWEEN @MinPrice AND @MaxPrice
      AND C.CategoryName = @CategoryName
);
GO

SELECT * FROM F_Z8(10, 50, 'Beverages');
GO

--Zadanie 9
CREATE FUNCTION F_Z9(@MinPrice MONEY, @MaxPrice MONEY, @CategoryName NVARCHAR(15))
RETURNS @T TABLE (ProductID INT, ProductName NVARCHAR(40), CategoryID INT, UnitPrice MONEY)
AS
BEGIN
    IF @CategoryName IS NULL
    BEGIN
        INSERT INTO @T
        SELECT ProductID, ProductName, CategoryID, UnitPrice
        FROM Products
        WHERE UnitPrice BETWEEN @MinPrice AND @MaxPrice;
    END
    ELSE
    BEGIN
        INSERT INTO @T
        SELECT P.ProductID, P.ProductName, P.CategoryID, P.UnitPrice
        FROM Products P
        JOIN Categories C ON P.CategoryID = C.CategoryID
        WHERE P.UnitPrice BETWEEN @MinPrice AND @MaxPrice
          AND C.CategoryName = @CategoryName;
    END
    RETURN;
END
GO

SELECT * FROM F_Z9(10, 50, 'Beverages');
SELECT * FROM F_Z9(10, 50, NULL);
GO

--Zadanie 10
CREATE OR ALTER FUNCTION F_Z10 ()
RETURNS @T TABLE(CustomerID NCHAR(5), CompanyName NVARCHAR(40), OrderID INT, OrderDate DATE)
AS
BEGIN
    DECLARE @Tmp TABLE (CustomerID NCHAR(5), Amount MONEY);
    INSERT INTO @Tmp
    SELECT TOP 3 WITH TIES O.CustomerID, SUM(ROUND(Quantity * UnitPrice * CAST((1 - Discount) AS MONEY), 2)) Amount
    FROM [Order Details] AS OD
    JOIN Orders AS O ON OD.OrderID = O.OrderID
    GROUP BY O.CustomerID
    ORDER BY Amount DESC;
    INSERT INTO @T
    SELECT C.CustomerID, C.CompanyName, O.OrderID, O.OrderDate
    FROM @Tmp AS T
    JOIN Customers AS C ON T.CustomerID = C.CustomerID
    JOIN Orders AS O ON T.CustomerID = O.CustomerID
    ORDER BY C.CustomerID, O.OrderDate;
    RETURN;
END
GO

SELECT * FROM F_Z10();
GO

--Zadanie 11
CREATE OR ALTER FUNCTION F_Z11 ()
RETURNS @T TABLE(CustomerID NCHAR(5), OrderID INT, OrderDate DATE)
AS
BEGIN
    DECLARE @AllCustomers TABLE (CustomerID NCHAR(5), Amount MONEY);
    
    INSERT INTO @AllCustomers
    SELECT TOP 3 WITH TIES O.CustomerID, SUM(ROUND(Quantity * UnitPrice * CAST((1 - Discount) AS MONEY), 2)) Amount
    FROM [Order Details] AS OD
    JOIN Orders AS O ON OD.OrderID = O.OrderID
    JOIN Customers AS C ON O.CustomerID = C.CustomerID
    GROUP BY O.CustomerID
    ORDER BY Amount DESC;

    INSERT INTO @T
    SELECT C.CustomerID, Sub.OrderID, Sub.OrderDate
    FROM @AllCustomers AS C
    CROSS APPLY (
        SELECT TOP 3 WITH TIES OrderID, OrderDate 
        FROM Orders AS O 
        WHERE O.CustomerID = C.CustomerID
        ORDER BY OrderDate DESC
    ) AS Sub;

    RETURN;
END
GO

SELECT * FROM F_Z11();
GO