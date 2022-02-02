SELECT user();
select user();
CREATE DATABASE blog;


CREATE DATABASE  IF NOT EXISTS `blog`;
USE `blog`;
CREATE TABLE `users`(
    `id`  INT UNSIGNED NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `surname` VARCHAR(80) NULL,
    `age` TINYINT(100) UNSIGNED NOT NULL,
    `email` VARCHAR(120) NOT NULL UNIQUE,
    PRIMARY KEY(`id`)
);

SHOW TABLES;
DESC `users`;

CRUD - create  read update delete 

INSERT INTO `users`(`id`, `name`, `surname`, `age`, `email`) 
VALUES(1, "John", "Johnyan", 34, "john@gmail.com");

INSERT INTO `users`(`id`, `name`,  `age`, `email`) 
VALUES(2, "Mike", 3, "mike@gmail.com");

INSERT INTO `users`(`id`, `name`,  `age`, `email`) 
VALUES(3, "Vladimir", 40, "vladimir@gmail.com");

SELECT `id`, `name`, `surname`, `age`, `email` FROM `users`;
SELECT * FROM `users`;
SELECT `id`, `name`, `email` FROM `users`;

SELECT * FROM `users` WHERE `age` = 34;
SELECT * FROM `users` WHERE `age` <= 34;
SELECT * FROM `users` WHERE `age` > 34;
SELECT * FROM `users` WHERE `age` > 34 AND `age` < 38;
SELECT * FROM `users` WHERE `age` = 34 OR `age` = 18;
SELECT * FROM `users` LIMIT 2;
SELECT * FROM `users` ORDER BY `age` ASC;
SELECT * FROM `users` ORDER BY `age` DESC;
SELECT * FROM `users` LIMIT 1, 2;
SELECT count(`id`) FROM `users`;
SELECT count(`surname`) FROM `users`;