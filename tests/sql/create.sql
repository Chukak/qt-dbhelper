CREATE DATABASE IF NOT EXISTS testing;

USE testing;

CREATE TABLE IF NOT EXISTS employee (
    id int unsigned NOT NULL auto_increment PRIMARY KEY,
    first_name varchar(50),
    last_name varchar(60),
    age smallint,
    city varchar(100),
    post enum('admin', 'programmer', 'designer', 'engineer'),
    salary double,
    date_created timestamp DEFAULT NOW()
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS has_privileges (
    id int unsigned NOT NULL auto_increment PRIMARY KEY,
    has bool,
    id_emp int unsigned NOT NULL,
    INDEX ind_emp(id_emp), 
    FOREIGN KEY (id_emp) REFERENCES employee(id) ON DELETE CASCADE
) ENGINE=InnoDB;  
