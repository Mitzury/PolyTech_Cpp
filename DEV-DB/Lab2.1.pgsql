-- Работа с массивами
-- 1.	Объедините все элементы массива [192, 168,10,10] в строку, разделяя их с помощью символа точка (.)

SELECT array_to_string(ARRAY[192, 168, 10, 10], '.') AS result;

-- 2.	Объедините все элементы массива ['Привет', NULL, 'специалисты', 'по БД'], разделяя их с помощью символа пробел. Значения NULL должны быть заменены на символ запятая (,)

SELECT string_agg(COALESCE(column_value, ','), ' ') AS result
    FROM unnest(ARRAY['привет', null, 'специалисты', 'по бд']) AS t(column_value);

-- 3.	Даны  2 массива  {"sql", "sqlserver"}  и {"database", "plsql"}.
-- a.	Объедините эти массивы в один массив

SELECT array_cat
    (
    ARRAY['sql', 'sqlserver'], 
    ARRAY['database', 'plsql']
    );

-- b.	Верните из объединенного массива 3 элемент 

SELECT (array_cat
        (ARRAY['sql', 'sqlserver'], 
         ARRAY['database', 'plsql']
        )
       )[3];

-- c.	Замените в массиве элемент sqlserver на  postgres

SELECT ARRAY_REPLACE(ARRAY['sql', 'sqlserver'], 'sqlserver', 'postgres');

-- d.	Верните из полученного массива последний элемент

SELECT (array['sql', 'sqlserver'])[cardinality(array['sql', 'sqlserver'])];

-- 4.	Дана строка «Ваша_Фамилия, Ваше_Имя» с помощью функций преобразования строки в массив выполните разделение строки на элементы массива и верните отдельно Фамилию и Имя
-- Пример: 'Городецкая, Светлана'
 
select 
    (column_value)[1] as "Фамилия",
    (column_value)[2] as "Имя"
FROM string_to_array('Богданов, Сергей', ',') AS t(column_value);

-- Работа с json
-- Дан json, имеющий следующую структуру:
-- { "company_name": "Poupkine and Sons", "offices": [ { "name": "Главный", "city": "Париж", "area": 1000 }, { "name": "Запасной", "city": "Москва", "area" : 200 } ] }

-- 1.	Выведите список офисов

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::jsonb->'offices';

-- 2.	Выведите название компании

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::jsonb->'company_name';

-- 3.	Выведите данные по первому в списке офису

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::jsonb->'offices'->0;

-- 4.	Выведите название (name) второго офиса в списке офисов

SELECT '{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::jsonb->'offices'->1->>'name';

-- 5.	Выполните проверку, наличия офиса в Санкт-Петербурге

SELECT EXISTS (SELECT 1 FROM jsonb_array_elements('{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::jsonb->'offices') office WHERE office->>'city' = 'санкт-петербург');

SELECT  '{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::jsonb->'city' ? 'санкт-петербург';

-- 6.	Выполните замену города, в котором находится главный офис на город Сантк-Петербург

SELECT  '{"company_name": "poupkine and sons", "offices": [{"name": "главный", "city": "париж", "area": 1000}, {"name": "запасной", "city": "москва", "area" : 200}]}'::json->'offices'-> '{"city":"санкт-петербург"}'
