-- Active: 1731173242441@@127.0.0.1@3306@brocode

CREATE DATABASE brocode;

-- to use a database 
USE brocode;

-- to drop a database
DROP DATABASE brocode;

-- to set database to read-only (in read-only mode we can't modify the db but we can access the data)
-- now if you try to dop db it will show 'schema brocode is in read only mode'
-- to disable read-only mode set it's value to 0 (now dropping db is possible)
ALTER DATABASE brocode READ ONLY = 0; 