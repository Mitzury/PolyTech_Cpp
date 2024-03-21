Задание 2. Написание простых запросов (работаем с БД dbTSQL)
Создание элементарных запросов без проекции (все столбцы) и фильтрации 
1.	Выведите список всех продуктов
select * from "Production"."Products" p 
2.	Выведите список всех заказчиков
select * from "Sales"."Customers"
3.	Выведите список всех сотрудников
select * from "HR"."Employees"

Создание запросов с проекцией и обработкой столбцов
1.	Выведите названия страны, региона и города, в которых проживают заказчики
select country, region, city from "Sales"."Customers"
2.	Выведите название и стоимость продуктов, упорядочив результирующую выборку в порядке убывания стоимости
select productname, unitprice from "Production"."Products" order by 2 desc
Задание 3. Написание запросов с вычисляемыми столбцами
1.	На основе таблицы Employees напишите запрос, возвращающий таблицу из 3 столбцов: Фамилия сотрудника, Имя сотрудника, e-mail адрес.
Столбец e-mail адрес должен быть сформирован в соответствие со следующим шаблоном: <имя>.<фамилия>@<названиеорганизации>.ru. Название организации придумайте сами! Полученные e-mail должны быть в нижнем регистре. Символы, недопустимые в адресе эл.почты, должны быть заменены нижним подчеркиванием.
 
select lastname as "Фамилия"
      , firstname as "Имя"
      , lower(replace(firstname || '.' || lastname || '@' || 'petrovich.tech', ' ', '_')) as "e-mail"
from "HR"."Employees";

2.	На основании данных ТОЛЬКО таблицы Products (запрос только к одной таблице!) сформируйте таблицу из трех столбцов: Номер категории, Название продукта и Название категории. 
Название категории должно выводиться в соответствии с ее номером:
1 -  'Beverages'; 2 - 'Condiments'; 3 - 'Confections'; 4 - 'Dairy Products'; 5 - 'Grains/Cereals'; 6 - 'Meat/Poultry';  7 - 'Produce'; 8 - 'Seafood'. Для категорий, не попавших в данный список, необходимо вернуть значение  'Other'
 
SELECT categoryid, productname,
case categoryid
when 1 then 'Beverages'
when 2 then 'Condiments'
when 3 then  'Confections'
when 4 then  'Dairy Products'
when 5 then 'Grains/Cereals'
when 6 then 'Meat/Poultry'
when 7 then 'Produce'
when 8 then  'Seafood'
else 'Other'
end "Название категории"
FROM "Production"."Products"
ORDER BY unitprice desc

3.	Напишите запрос к таблице Customers, возвращающий таблицу из 3 столбцов: contactname, LName и FName. Значение в столбцах LName и FName должны вычисляться на основе данных столбца contactname. (Можно использовать регулярные выражения!)
 
select contactname
      , left(contactname, position(',' in contactname)-1) as "LName"
      , right(contactname, -position(',' in contactname)-1)  as "FName"
from "Sales"."Customers";


4.	Напишите запрос к таблице OrderDetails, возвращающий таблицу из 3 столбцов: unitprice, qty и LineTotal. Значение в столбце LineTotal – является расчетной величиной с учетом количества товара, цены и скидки.
 
select unitprice, qty, (qty * unitprice)*(1-discount) as "LineTotal"
from "Sales"."OrderDetails";

Задание 4. Написание запросов с сортировкой
1.	Выведите 10 самых дорогих товаров.
2.	Выведите из таблицы Orders строки с 51 по 100, упорядоченные по дате заказа
SELECT productname, unitprice
FROM "Production"."Products"
ORDER BY unitprice desc
limit 10;


select orderid, custid, orderdate
FROM "Sales"."Orders"
order by orderdate desc
offset 50 rows fetch first 50 rows only;


