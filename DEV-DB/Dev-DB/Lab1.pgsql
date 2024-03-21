������� 2. ��������� ������� �������� (�������� � �� dbTSQL)
�������� ������������ �������� ��� �������� (��� �������) � ���������� 
1.	�������� ������ ���� ���������
select * from "Production"."Products" p 
2.	�������� ������ ���� ����������
select * from "Sales"."Customers"
3.	�������� ������ ���� �����������
select * from "HR"."Employees"

�������� �������� � ��������� � ���������� ��������
1.	�������� �������� ������, ������� � ������, � ������� ��������� ���������
select country, region, city from "Sales"."Customers"
2.	�������� �������� � ��������� ���������, ���������� �������������� ������� � ������� �������� ���������
select productname, unitprice from "Production"."Products" order by 2 desc
������� 3. ��������� �������� � ������������ ���������
1.	�� ������ ������� Employees �������� ������, ������������ ������� �� 3 ��������: ������� ����������, ��� ����������, e-mail �����.
������� e-mail ����� ������ ���� ����������� � ������������ �� ��������� ��������: <���>.<�������>@<�������������������>.ru. �������� ����������� ���������� ����! ���������� e-mail ������ ���� � ������ ��������. �������, ������������ � ������ ��.�����, ������ ���� �������� ������ ��������������.
 
select lastname as "�������"
      , firstname as "���"
      , lower(replace(firstname || '.' || lastname || '@' || 'petrovich.tech', ' ', '_')) as "e-mail"
from "HR"."Employees";

2.	�� ��������� ������ ������ ������� Products (������ ������ � ����� �������!) ����������� ������� �� ���� ��������: ����� ���������, �������� �������� � �������� ���������. 
�������� ��������� ������ ���������� � ������������ � �� �������:
1 -  'Beverages'; 2 - 'Condiments'; 3 - 'Confections'; 4 - 'Dairy Products'; 5 - 'Grains/Cereals'; 6 - 'Meat/Poultry';  7 - 'Produce'; 8 - 'Seafood'. ��� ���������, �� �������� � ������ ������, ���������� ������� ��������  'Other'
 
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
end "�������� ���������"
FROM "Production"."Products"
ORDER BY unitprice desc

3.	�������� ������ � ������� Customers, ������������ ������� �� 3 ��������: contactname, LName � FName. �������� � �������� LName � FName ������ ����������� �� ������ ������ ������� contactname. (����� ������������ ���������� ���������!)
 
select contactname
      , left(contactname, position(',' in contactname)-1) as "LName"
      , right(contactname, -position(',' in contactname)-1)  as "FName"
from "Sales"."Customers";


4.	�������� ������ � ������� OrderDetails, ������������ ������� �� 3 ��������: unitprice, qty � LineTotal. �������� � ������� LineTotal � �������� ��������� ��������� � ������ ���������� ������, ���� � ������.
 
select unitprice, qty, (qty * unitprice)*(1-discount) as "LineTotal"
from "Sales"."OrderDetails";

������� 4. ��������� �������� � �����������
1.	�������� 10 ����� ������� �������.
2.	�������� �� ������� Orders ������ � 51 �� 100, ������������� �� ���� ������
SELECT productname, unitprice
FROM "Production"."Products"
ORDER BY unitprice desc
limit 10;


select orderid, custid, orderdate
FROM "Sales"."Orders"
order by orderdate desc
offset 50 rows fetch first 50 rows only;


