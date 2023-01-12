CREATE DATABASE inception;

CREATE USER 'gson'@'%' IDENTIFIED BY 'thsrl6598dnd';
GRANT ALL privileges ON inception.* TO 'gson'@'%';

ALTER USER 'root'@'localhost' IDENTIFIED BY 'thsrl6598dnd';
FLUSH PRIVILEGES;
