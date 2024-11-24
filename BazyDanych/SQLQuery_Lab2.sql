SELECT 
	Orders.OrderID, Orders.OrderDate, Customers.CustomerID, Customers.CompanyName, Customers.Country
FROM 
	Orders, Customers
WHERE 
	Orders.CustomerID = Customers.CustomerID;

SELECT 
    Orders.OrderID, 
    Orders.OrderDate, 
    Customers.CustomerID, 
    Customers.CompanyName, 
    Customers.Country
FROM 
    Orders
JOIN 
    Customers 
ON 
    Orders.CustomerID = Customers.CustomerID;


SELECT 
    [Order Details].*, 
    Products.ProductID, 
    Products.ProductName, 
    Products.UnitPrice AS CurrentUnitPrice
FROM 
    [Order Details]
JOIN 
    Products 
ON 
    [Order Details].ProductID = Products.ProductID;


SELECT 
    [Order Details].*, 
    Orders.OrderDate, 
    Customers.CustomerID, 
    Customers.CompanyName, 
    Products.ProductID, 
    Products.ProductName, 
    Products.UnitPrice AS CurrentUnitPrice
FROM 
    [Order Details]
JOIN 
    Products 
ON 
    [Order Details].ProductID = Products.ProductID
JOIN 
    Orders 
ON 
    [Order Details].OrderID = Orders.OrderID
JOIN 
    Customers 
ON 
    Orders.CustomerID = Customers.CustomerID;


SELECT 
    Customers.CustomerID, 
    Customers.CompanyName
FROM 
    Customers
LEFT JOIN 
    Orders 
ON 
    Customers.CustomerID = Orders.CustomerID
WHERE 
    Orders.OrderID IS NULL;

SELECT 
    COUNT(*) AS TotalCustomers
FROM 
    Customers;

SELECT 
    COUNT(*) AS CustomersInGermany
FROM 
    Customers
WHERE 
    Country = N'Germany';

SELECT 
    COUNT(*) AS CustomersInGermanyAndAustria
FROM 
    Customers
WHERE 
    Country IN (N'Germany', N'Austria');

SELECT 
    Country, 
    COUNT(*) AS CustomerCount
FROM 
    Customers
GROUP BY 
    Country
ORDER BY 
    Country ASC;

SELECT 
    Country, 
    COUNT(*) AS CustomerCount
FROM 
    Customers
GROUP BY 
    Country
ORDER BY 
    CustomerCount DESC, 
    Country ASC;

SELECT 
    Country, 
    COUNT(*) AS CustomerCount
FROM 
    Customers
GROUP BY 
    Country
HAVING 
    COUNT(*) > 5
ORDER BY 
    CustomerCount DESC, 
    Country ASC;

SELECT 
    Country, 
    City, 
    COUNT(*) AS CustomerCount
FROM 
    Customers
GROUP BY 
    Country, 
    City;

SELECT 
    Country, 
    City, 
    COUNT(*) AS CustomerCount
FROM 
    Customers
WHERE 
    CompanyName LIKE 'C%' 
    OR CompanyName LIKE 'A%'
GROUP BY 
    Country, 
    City;

SELECT 
    CategoryID, 
    COUNT(*) AS ProductCount, 
    MIN(UnitPrice) AS MinPrice, 
    MAX(UnitPrice) AS MaxPrice, 
    AVG(UnitPrice) AS AvgPrice, 
    SUM(UnitsInStock) AS TotalStock
FROM 
    Products
GROUP BY 
    CategoryID;

SELECT 
    COUNT(*) AS ProductsBetween
FROM 
    Products
WHERE 
    UnitPrice BETWEEN 20 AND 30;

SELECT 
    CategoryID, 
    COUNT(*) AS ProductsBetween
FROM 
    Products
WHERE 
    UnitPrice BETWEEN 20 AND 30
GROUP BY 
    CategoryID;

SELECT 
    LEFT(ProductName, 1) AS FirstLetter, 
    COUNT(*) AS ProductCount
FROM 
    Products
GROUP BY 
    LEFT(ProductName, 1);

SELECT 
    CategoryID, 
    AVG(UnitPrice) AS AvgPrice
FROM 
    Products
GROUP BY 
    CategoryID
HAVING 
    AVG(UnitPrice) > 30 
    AND AVG(UnitPrice) < 50;

SELECT 
    OrderID, 
    SUM(UnitPrice * Quantity) AS TotalAmount
FROM 
    [Order Details]
GROUP BY 
    OrderID;

SELECT 
	OrderID, 
	ROUND(CAST(SUM(UnitPrice*Quantity*(1-Discount)) AS money),2) AS OrderValue
FROM [Order Details]
GROUP BY OrderID

SELECT 
    YEAR(Orders.OrderDate) AS OrderYear, 
    SUM([Order Details].UnitPrice * [Order Details].Quantity) AS TotalAmount
FROM 
    [Order Details]
JOIN 
    Orders 
ON 
    [Order Details].OrderID = Orders.OrderID
GROUP BY 
    YEAR(Orders.OrderDate);

SELECT 
	YEAR(O.OrderDate), 
	ROUND(SUM(OD.UnitPrice*OD.Quantity* CAST((1-OD.Discount) AS money)),2) AS TotalOrdersValue
FROM 
	[Order Details] AS OD
JOIN 
	Orders AS O ON O.OrderID=OD.OrderID
GROUP BY 
	YEAR(O.OrderDate)

SELECT 
    O.CustomerID, 
    ROUND(SUM(OD.UnitPrice * OD.Quantity * CAST((1 - OD.Discount) AS money)), 2) AS TotalOrdersValue
FROM 
    [Order Details] AS OD
JOIN 
    Orders AS O ON O.OrderID = OD.OrderID
GROUP BY 
    O.CustomerID;

SELECT 
    C.CustomerID, 
    C.CompanyName, 
    ROUND(SUM(OD.UnitPrice * OD.Quantity * CAST((1 - OD.Discount) AS money)), 2) AS TotalOrdersValue
FROM 
    [Order Details] AS OD
JOIN 
    Orders AS O ON O.OrderID = OD.OrderID
JOIN 
    Customers AS C ON O.CustomerID = C.CustomerID
GROUP BY 
    C.CustomerID, 
    C.CompanyName;

SELECT 
    C.CustomerID, 
    C.CompanyName, 
    ROUND(SUM(OD.UnitPrice * OD.Quantity * CAST((1 - OD.Discount) AS money)), 2) AS TotalOrdersValue
FROM 
    [Order Details] AS OD
JOIN 
    Orders AS O ON O.OrderID = OD.OrderID
JOIN 
    Customers AS C ON O.CustomerID = C.CustomerID
GROUP BY 
    C.CustomerID, 
    C.CompanyName
ORDER BY 
    TotalOrdersValue DESC;

SELECT TOP 3
    C.CustomerID, 
    C.CompanyName, 
    ROUND(SUM(OD.UnitPrice * OD.Quantity * CAST((1 - OD.Discount) AS money)), 2) AS TotalOrdersValue
FROM 
    [Order Details] AS OD
JOIN 
    Orders AS O ON O.OrderID = OD.OrderID
JOIN 
    Customers AS C ON O.CustomerID = C.CustomerID
GROUP BY 
    C.CustomerID, 
    C.CompanyName
ORDER BY 
    TotalOrdersValue DESC;
