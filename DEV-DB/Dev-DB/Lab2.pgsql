-- ������������ ������ 2
---- ������� 1. ��������� �������� � �����������
-- 1.	�������� ���������� � ����� (id) 30

SELECT * FROM "Sales"."Customers"
    where custid=30;

-- 2.	�������� ��� ������, ��������� (�����������) ����� 10 ������ 2008 ����

select orderid, custid, orderdate from "Sales"."Orders"
    where orderdate > '2008-04-10';

-- 3.	�������� �������� � ��������� ���������, ��� �������, ��� ��������� ��������� � ��������� �� 100 �� 250.

SELECT productname, unitprice  FROM "Production"."Products"
    where unitprice between 100::money and 250::money;

-- 4.	�������� ���� ����������, ����������� � ������, ������� ��� �������.

SELECT companyname, city  FROM "Sales"."Customers"
    where city in ('Berlin', 'Madrid', 'Paris');

-- 5.	�������� ���� �����������, ��� ������� �� ��������� ������ ����������

SELECT firstname, lastname, region  FROM "HR"."Employees"
    where region is null;

-- 6.	�������� ���������� � ������� ����� �Linda�, �Robert�, �Ann�

SELECT contactname FROM "Sales"."Customers"
    where contactname NOT LIKE '% Linda' 
        OR contactname NOT LIKE '% Robert' 
        OR contactname NOT LIKE '% Ann';

-- 7.	�������� ����������, ��� ������� ���������� ���� �� ����� �B� ���� �R� ���� �N�. 
---- ���������� ������ ������������ �� �������� ������ ������� (�� �� ����������� ���������)

SELECT custid, contactname, contacttitle FROM "Sales"."Customers" c
    WHERE contactname LIKE 'B%'
        OR contactname LIKE 'R%'
        OR contactname LIKE 'N%';

-- 8.	�������� ���������� � ����������, ����������� ��� ����������� �������: ������� ��������� � ��� ���������. 
----- � �������������� ������� ������ ������� ������ �� ���������, ��� ��� ���������� ���� �� ����� "P" ���� �� ����� "M", 
----- � ������� ��� ���� ���������� ���� ��  �S�  ���� ��  �K�.
----- ���������� ������ ������������ �� �������� ������ ������� (�� �� ����������� ���������)
 
SELECT 
    split_part(contactname, ',', 1) as SURNAME,
    trim(split_part(contactname, ',', 2)) as NAME
FROM "Sales"."Customers"
WHERE 
     substring(split_part(contactname, ',', 1), 1, 1) in ('S', 'K')
    AND
     substring(trim(split_part(contactname, ',', 2)), 1, 1) in ('P', 'M');


---- ������� 2. ��������� �������� � ���������� ��������
-- 1.	����������� ������� ���������� ����:    ��� ����������, ����� ������, ���� ������.
-- ������������ ������� �� ���� (�� ����� ������ � ����� ������� �������)

select lastname, firstname, orderid, orderdate 
    from  "HR"."Employees" as Emp
        join "Sales"."Orders" as Ord on Emp.empid = Ord.empid
order by orderdate desc;

-- 2.	�������� ������, ������� �������� ���������� � ������� � �� �������:[orderid], [custid],[empid],[orderdate] ,[productid],[unitprice],[qty],[discount].
-- ����������� � ���� ������� ����������� ������� (LineTotal), ������� ������������ ��������� ������ ������� � ������ � ������ ������

select o.orderid, custid , empid , orderdate, productid, unitprice, qty, discount, (unitprice*qty)-(discount*(unitprice*qty))::money as "Linetotal"
    from "Sales"."Orders" as o 
    join "Sales"."OrderDetails" as c on o.orderid = c.orderid;


-- 3.	�������� ������, ������������ ������� ���������� ����:   ����� ������, �������� ���������, ������� ���������� (�������� ���������), ���� ������, �������� ������������ ��������.
-- � ������ ������ ����� ������ �� ������, ������� ������������� �������:  ��������� � ���������� (Emploees) ��������� � ����� ������
 
select orderid, contactname, contacttitle, orderdate, concat(lastname, ' ', firstname, ', ', title) as employeer
    from "Sales"."Orders" AS E
        JOIN "Sales"."Customers"  AS O ON E.custid = O.custid
        JOIN "HR"."Employees" AS D ON E.empid = D.empid
    order by orderid;


---- ������� 3. ������������� ���������� ������� ������� (UNION, EXCEPT, INTERSECT)
-- 1.	�������� ������, ������������ ����� ���������� ������� �� ������ Employees � Customers. �������������� ������� ������ ��������� 3 �������: country, region, city. 

select country, region, city from "HR"."Employees"
INTERSECT
select country, region, city from "Sales"."Customers";

-- 2.	�������� ������, ������������ ����� ���������� ������� �� ������ Employees (������ ����������� - country, region, city), 
------ �������� �� ����� ������ ������ �� ������� Customers (������ �������� - country, region, city). \
------ �������������� ������� ������ ��������� 3 �������: country, region, city. 

select country, region, city from "HR"."Employees"
EXCEPT
select country, region, city from "Sales"."Customers";

---- ������� 4. ������� � ������������
-- 1.	�������� ������� �� ���� ��������: ������������, ����������� � ������� ��������� ���������. 

select min(unitprice), max(unitprice), avg(unitprice::numeric)::money from "Production"."Products";

-- 2.	�������� ������� �� 2-� ��������: ����� ��������� � ���������� ��������� � ������ ���������.

select Cat.categoryid, count(Prod.productname) from "Production"."Categories" as Cat
join "Production"."Products" as Prod on Cat.categoryid = Prod.categoryid
group by 1;

-- 3.	�������� ������ � ���������� �������, ����������� ������ �����������

select concat(lastname, ' ', firstname) as Employer, count(orderid)  from  "HR"."Employees" as Emp
join "Sales"."Orders" as Ord on Emp.empid = Ord.empid
group by 1;

-- 4.	�������� 5 ����� �������� ����������, � ����� ������ ��������� ��������� �� �������

select companyname, sum(freight) from "Sales"."Customers" as Cust
join "Sales"."Orders" as Ord on Cust.custid = Ord.custid
group by companyname
order by 2 desc
limit 5;

-- 5.	�������� ���, ���������� ��������� ������� � ���� ���� � ���������� ���������� ����������, ������� ������ ��� ������.

select extract(year from shippeddate) as year, count(orderid) as Count, count (distinct custid) as Unique from "Sales"."Orders"
group by year;

-- 6.	�������� ������ ������ ��� �������, ����� ��������� ������� ��������� 1000
-- ��������: ����������� ������� ������ ����� ��������������� ������������.

select * from "Sales"."Orders" where freight::numeric > 1000