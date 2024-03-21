-- ������ � ���������
-- 1.	���������� ��� �������� ������� [192, 168,10,10] � ������, �������� �� � ������� ������� ����� (.)

SELECT array_to_string(ARRAY[192, 168, 10, 10], '.') AS result;

-- 2.	���������� ��� �������� ������� ['������', NULL, '�����������', '�� ��'], �������� �� � ������� ������� ������. �������� NULL ������ ���� �������� �� ������ ������� (,)

SELECT string_agg(COALESCE(column_value, ','), ' ') AS result
    FROM unnest(ARRAY['������', null, '�����������', '�� ��']) AS t(column_value);

-- 3.	����  2 �������  {"sql", "sqlserver"}  � {"database", "plsql"}.
-- a.	���������� ��� ������� � ���� ������

SELECT array_cat
    (
    ARRAY['sql', 'sqlserver'], 
    ARRAY['database', 'plsql']
    );

-- b.	������� �� ������������� ������� 3 ������� 

SELECT (array_cat
        (ARRAY['sql', 'sqlserver'], 
         ARRAY['database', 'plsql']
        )
       )[3];

-- c.	�������� � ������� ������� sqlserver ��  postgres

SELECT ARRAY_REPLACE(ARRAY['sql', 'sqlserver'], 'sqlserver', 'postgres');

-- d.	������� �� ����������� ������� ��������� �������

SELECT (array['sql', 'sqlserver'])[cardinality(array['sql', 'sqlserver'])];

-- 4.	���� ������ �����_�������, ����_���� � ������� ������� �������������� ������ � ������ ��������� ���������� ������ �� �������� ������� � ������� �������� ������� � ���
-- ������: '����������, ��������'
 
select 
    (column_value)[1] as "�������",
    (column_value)[2] as "���"
FROM string_to_array('��������, ������', ',') AS t(column_value);

-- ������ � json
-- ��� json, ������� ��������� ���������:
-- { "company_name": "Poupkine and Sons", "offices": [ { "name": "�������", "city": "�����", "area": 1000 }, { "name": "��������", "city": "������", "area" : 200 } ] }

-- 1.	�������� ������ ������

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::jsonb->'offices';

-- 2.	�������� �������� ��������

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::jsonb->'company_name';

-- 3.	�������� ������ �� ������� � ������ �����

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::jsonb->'offices'->0;

-- 4.	�������� �������� (name) ������� ����� � ������ ������

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::jsonb->'offices'->1->>'name';

-- 5.	��������� ��������, ������� ����� � �����-����������

SELECT EXISTS (SELECT 1 FROM jsonb_array_elements('{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::jsonb->'offices') office WHERE office->>'city' = '�����-���������');

SELECT  '{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::jsonb->'city' ? '�����-���������';

-- 6.	��������� ������ ������, � ������� ��������� ������� ���� �� ����� �����-���������

SELECT  '{"company_name": "poupkine and sons", "offices": [{"name": "�������", "city": "�����", "area": 1000}, {"name": "��������", "city": "������", "area" : 200}]}'::json->'offices'-> '{"city":"�����-���������"}'