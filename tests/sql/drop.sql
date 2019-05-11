DELIMITER $$

DROP PROCEDURE IF EXISTS mysql.truncate_tables_with_foreign_key $$

CREATE PROCEDURE mysql.truncate_tables_with_foreign_key()
BEGIN 
    IF EXISTS (SELECT 1 FROM information_schema.schemata WHERE schema_name = 'testing') THEN
        IF EXISTS (SELECT 1 FROM testing.employee) THEN 
            DELETE FROM testing.employee; 
            ALTER TABLE testing.employee auto_increment = 1;
        END IF;
        
        DROP DATABASE IF EXISTS testing;
    END IF;
END $$

CALL mysql.truncate_tables_with_foreign_key() $$

DROP PROCEDURE IF EXISTS mysql.truncate_tables_with_foreign_key $$

DELIMITER ;
