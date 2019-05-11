USE testing;

INSERT INTO employee (first_name, last_name, age, city, post, salary) 
VALUES 
('Victor', 'Petrov', 25, 'Moscow', 'admin', 77790.40), 
('Ivan', 'Golubev', 35, 'Moscow', 'programmer', 97500.00), 
('Elizaveta', 'Akimova', 31, 'Sochi', 'designer', 56700.00), 
('Mikhail', 'Teterev', 41, 'Sochi', 'programmer', 126000.00), 
('Elizaveta', 'Mikhailova', 27, 'Moscow', 'designer', 97800.50), 
('Petr', 'Ivanov', 22, 'Tver', 'programmer', 45000.00);

INSERT INTO has_privileges (has, id_emp) 
VALUES 
(true, (SELECT id FROM employee WHERE first_name = 'Victor' AND last_name = 'Petrov')), 
(false, (SELECT id FROM employee WHERE first_name = 'Ivan' AND last_name = 'Golubev')), 
(false, (SELECT id FROM employee WHERE first_name = 'Elizaveta' AND last_name = 'Akimova')), 
(true, (SELECT id FROM employee WHERE first_name = 'Mikhail' AND last_name = 'Teterev')), 
(false, (SELECT id FROM employee WHERE first_name = 'Elizaveta' AND last_name = 'Mikhailova')), 
(false, (SELECT id FROM employee WHERE first_name = 'Petr' AND last_name = 'Ivanov'));
