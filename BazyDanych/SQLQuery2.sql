USE Northwind

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE Country = N'Poland';

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE Country IN (N'Poland', N'Germany');

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE CompanyName LIKE N'C%';

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE CompanyName LIKE N'%i%a';

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE CompanyName LIKE 'A%' 
  OR CompanyName LIKE 'C%' 
  OR CompanyName LIKE 'N%' 
  OR CompanyName LIKE 'P%';

  SELECT * FROM Customers
WHERE CompanyName LIKE N'[ACNP]%'

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE CompanyName LIKE '[A-H]%';

SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE CompanyName NOT LIKE 'C%'
  AND CompanyName NOT LIKE 'P%';

  select distinct Country 
from Customers

SELECT *
FROM Customers
WHERE Region IS NOT NULL

SELECT *
FROM Customers
WHERE Region IS NULL;

SELECT ProductID, ProductName
FROM Products;

SELECT ProductID, ProductName, UnitPrice
FROM Products
WHERE UnitPrice > 40;

SELECT ProductID, ProductName, UnitPrice
FROM Products
WHERE UnitPrice > 10 AND UnitPrice < 20;

SELECT ProductID, ProductName, UnitPrice
FROM Products
WHERE UnitPrice < 10 OR UnitPrice > 100;

SELECT *
FROM Products
WHERE (CategoryID = 2 OR CategoryID = 5)
  AND UnitPrice BETWEEN 10 AND 50;

  SELECT *
FROM Products
WHERE (CategoryID = 2 
       OR (CategoryID = 5 AND UnitPrice BETWEEN 10 AND 50 AND ProductName LIKE '[A-M]%'));

SELECT *
FROM Products
WHERE (CategoryID = 2
       OR (CategoryID = 5 AND UnitPrice BETWEEN 10 AND 50)
	   OR (ProductName LIKE 'C%' OR ProductName LIKE 'P%'));

CREATE VIEW View_France AS
SELECT CustomerID, CompanyName, City, Country
FROM Customers
WHERE Country = N'France';

SELECT * FROM View_France

CREATE VIEW View_Poland1 AS
SELECT CustomerID AS IdKlienta, 
       CompanyName AS NazwaKlienta, 
       City AS Miejscowosc
FROM Customers
WHERE Country = N'Poland';

SELECT * FROM View_Poland1


SELECT * INTO CustomersCopy
FROM Customers;

EXEC sp_help 'CustomersCopy';

ALTER TABLE CustomersCopy
ADD CustomerNumber INT NOT NULL IDENTITY(1,1)

EXEC sp_help 'CustomersCopy';

ALTER TABLE CustomersCopy
ADD PRIMARY KEY (CustomerNumber);

DELETE FROM CustomersCopy
WHERE CustomerNumber IN (5, 7, 15, 21, 44);

DROP TABLE IF EXISTS CustomersCopy;

SELECT * INTO CustomersCopy
FROM Customers;

CREATE SEQUENCE CustomersSequence 
  AS SMALLINT 
  START WITH 1 
  INCREMENT BY 1;

ALTER TABLE CustomersCopy
ADD CustomerNumber SMALLINT;

UPDATE CustomersCopy
SET CustomerNumber = NEXT VALUE FOR CustomersSequence;

SELECT * FROM CustomersCopy;
