-- Лабораторная работа 2
---- Задание 1. Написание запросов с фильтрацией
-- 1.	Выведите заказчиков с кодом (id) 30

SELECT * FROM "Sales"."Customers"
    where custid=30;

-- 2.	Выведите все заказы, сделанные (оформленные) после 10 апреля 2008 года

select orderid, custid, orderdate from "Sales"."Orders"
    where orderdate > '2008-04-10';

-- 3.	Выведите название и стоимость продуктов, при условии, что стоимость находится в диапазоне от 100 до 250.

SELECT productname, unitprice  FROM "Production"."Products"
    where unitprice between 100::money and 250::money;

-- 4.	Выведите всех заказчиков, проживающих в Париже, Берлине или Мадриде.

SELECT companyname, city  FROM "Sales"."Customers"
    where city in ('Berlin', 'Madrid', 'Paris');

-- 5.	Выведите всех сотрудников, для которых не определен регион проживания

SELECT firstname, lastname, region  FROM "HR"."Employees"
    where region is null;

-- 6.	Выведите заказчиков с именами кроме “Linda”, “Robert”, “Ann”

SELECT contactname FROM "Sales"."Customers"
    where contactname NOT LIKE '% Linda' 
        OR contactname NOT LIKE '% Robert' 
        OR contactname NOT LIKE '% Ann';

-- 7.	Выведите заказчиков, чья фамилия начинается либо на букву “B” либо “R” либо “N”. 
---- Фильтрация должна производится на исходных данных столбца (не на вычисляемом выражении)

SELECT custid, contactname, contacttitle FROM "Sales"."Customers" c
    WHERE contactname LIKE 'B%'
        OR contactname LIKE 'R%'
        OR contactname LIKE 'N%';

-- 8.	Выведите информацию о заказчиках, сформировав два вычисляемых столбца: Фамилия заказчика и Имя заказчика. 
----- В результирующую выборку должны попасть только те заказчики, чье имя начинается либо на букву "P" либо на букву "M", 
----- а фамилия при этом начинается либо на  “S”  либо на  “K”.
----- Фильтрация должна производится на исходных данных столбца (не на вычисляемом выражении)
 
SELECT 
    split_part(contactname, ',', 1) as SURNAME,
    trim(split_part(contactname, ',', 2)) as NAME
FROM "Sales"."Customers"
WHERE 
     substring(split_part(contactname, ',', 1), 1, 1) in ('S', 'K')
    AND
     substring(trim(split_part(contactname, ',', 2)), 1, 1) in ('P', 'M');


---- Задание 2. Написание запросов к нескольким таблицам
-- 1.	Сформируйте выборку следующего вида:    ФИО сотрудника, Номер Заказа, Дата Заказа.
-- Отсортируйте выборку по дате (от самых ранних к самым поздним заказам)

select lastname, firstname, orderid, orderdate 
    from  "HR"."Employees" as Emp
        join "Sales"."Orders" as Ord on Emp.empid = Ord.empid
order by orderdate desc;

-- 2.	Напишите запрос, который выбирает информацию о заказах и их деталях:[orderid], [custid],[empid],[orderdate] ,[productid],[unitprice],[qty],[discount].
-- Сформируйте в этом запросе вычисляемый столбец (LineTotal), который рассчитывает стоимость каждой позиции в заказе с учетом скидки

select o.orderid, custid , empid , orderdate, productid, unitprice, qty, discount, (unitprice*qty)-(discount*(unitprice*qty))::money as "Linetotal"
    from "Sales"."Orders" as o 
    join "Sales"."OrderDetails" as c on o.orderid = c.orderid;


-- 3.	Напишите запрос, возвращающий выборку следующего вида:   Номер заказа, Название заказчика, Фамилия сотрудника (компании заказчика), Дата заказа, Название транспортной компании.
-- В запрос должны войти только те записи, которые соответствуют условию:  Заказчики и Сотрудники (Emploees) проживают в одном городе
 
select orderid, contactname, contacttitle, orderdate, concat(lastname, ' ', firstname, ', ', title) as employeer
    from "Sales"."Orders" AS E
        JOIN "Sales"."Customers"  AS O ON E.custid = O.custid
        JOIN "HR"."Employees" AS D ON E.empid = D.empid
    order by orderid;


---- Задание 3. Использование операторов наборов записей (UNION, EXCEPT, INTERSECT)
-- 1.	Напишите запрос, возвращающий набор уникальных записей из таблиц Employees и Customers. Результирующая таблица должна содержать 3 столбца: country, region, city. 

select country, region, city from "HR"."Employees"
INTERSECT
select country, region, city from "Sales"."Customers";

-- 2.	Напишите запрос, возвращающий набор уникальных записей из таблиц Employees (адреса сотрудников - country, region, city), 
------ исключив из этого списка записи из таблицы Customers (адреса Клиентов - country, region, city). \
------ Результирующая таблица должна содержать 3 столбца: country, region, city. 

select country, region, city from "HR"."Employees"
EXCEPT
select country, region, city from "Sales"."Customers";

---- Задание 4. Запросы с группировкой
-- 1.	Выведите таблицу из трех столбцов: максимальная, минимальная и средняя стоимость продуктов. 

select min(unitprice), max(unitprice), avg(unitprice::numeric)::money from "Production"."Products";

-- 2.	Выведите таблицу из 2-х столбцов: номер категории и количество продуктов в каждой категории.

select Cat.categoryid, count(Prod.productname) from "Production"."Categories" as Cat
join "Production"."Products" as Prod on Cat.categoryid = Prod.categoryid
group by 1;

-- 3.	Выведите данные о количестве заказов, оформленных каждым сотрудником

select concat(lastname, ' ', firstname) as Employer, count(orderid)  from  "HR"."Employees" as Emp
join "Sales"."Orders" as Ord on Emp.empid = Ord.empid
group by 1;

-- 4.	Выберите 5 самых выгодных заказчиков, с точки зрения суммарной стоимости их заказов

select companyname, sum(freight) from "Sales"."Customers" as Cust
join "Sales"."Orders" as Ord on Cust.custid = Ord.custid
group by companyname
order by 2 desc
limit 5;

-- 5.	Выведите год, количество сделанных заказов в этом году и количество уникальных заказчиков, которые делали эти заказы.

select extract(year from shippeddate) as year, count(orderid) as Count, count (distinct custid) as Unique from "Sales"."Orders"
group by year;

-- 6.	Выведите список только тех заказов, общая стоимость которых превышает 1000
-- ВНИМАНИЕ: Вычисляемые столбцы должны иметь соответствующие наименования.

select * from "Sales"."Orders" where freight::numeric > 1000