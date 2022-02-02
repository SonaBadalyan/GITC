CREATE DATABASE `tproger`;

USE `tproger`;

CREATE TABLE `company`(
    `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `poster` VARCHAR(100) NOT NULL,
    `logo` VARCHAR(100) NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `description` TEXT NULL,
    `headline` VARCHAR(80) NULL,
    PRIMARY KEY(`id`)
);

INSERT INTO     `company`(    `id`,   `poster`, `logo`,    `name`, `description`, `headline`) 
                VALUES(     1,      "synopsys.jpg", "snpslogo.jpg", "Synopysy", "snps blah blah blah", "snps we are very ....." );

INSERT INTO     `company`(    `id`,   `poster`, `logo`,    `name`, `description`, `headline`) 
                VALUES(     2,      "emap.jpg", "epamlogo.jpg", "EPAM", "epam blah blah blah", "epam we are very ....." );

INSERT INTO     `company`(    `id`,   `poster`, `logo`,    `name`, `description`, `headline`) 
                VALUES(     3,      "egs.jpg", "egslogo.jpg", "EGS", "egs blah blah blah", "egs we are very ....." );

INSERT INTO     `company`(    `id`,   `poster`, `logo`,    `name`, `description`, `headline`) 
                VALUES(     4,      "grandcandy.jpg", "grandcandylogo.jpg", "GRAND CANDY", "grand candy blah blah blah", "grand candy we are very ....." );
               

CREATE TABLE `users`(
    `id`  INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `image` VARCHAR(100) NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `surname` VARCHAR(80) NULL,
    `info` VARCHAR(150) NULL,
    `rating` INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);

INSERT INTO     `users`(    `id`,   `image`,    `name`, `surname`, `info`,              `rating`) 
                VALUES(     1,      "jhon.jpg", "John", "Johnyan", "jhon blah blah blah", 4 );

INSERT INTO     `users`(    `id`, `image`,      `name`,  `surname`,     `info`,                 `rating`) 
                VALUES(     2,     "ani.jpg",   "Ani",   "Aramyan",     "ani blah blah blah",  10);

INSERT INTO     `users`(    `id`,   `image`,    `name`,  `info`,              `rating`) 
                VALUES(     3,      "zhar.jpg", "Zhar",  "zhar blah blah blah", 0 );

INSERT INTO     `users`(    `id`, `image`,      `name`,      `info`,                 `rating`) 
                VALUES(     4,     "Vardush.jpg",   "Vardush",        "Vardush blah blah blah",  100);


CREATE TABLE `posts`(
    `id`  INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `poster` VARCHAR(100) NOT NULL,
    `name` VARCHAR(150) NOT NULL,
    `text` TEXT NOT NULL,
    `user_id` INT UNSIGNED NOT NULL,
    `views` INT UNSIGNED NULL DEFAULT 0,
    `create_at` DATETIME NOT NULL,
    `rating` TYNYINT NOT NULL,
    `company_id` INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);

INSERT INTO     `posts`(    `id`, `poster`,                 `name`,                  `text`,                 `user_id`, `views`, `create_at`,               `rating`, `company_id` ) 
                VALUES(     1,     "vardushposter.jpg",   "Vardushs first poster",   "Red fox jump"           4,            40,   "1998-01-01 23:59:59.997",  100,      2);

INSERT INTO     `posts`(    `id`, `poster`,                 `name`,                  `text`,                 `user_id`, `views`, `create_at`,               `rating`, `company_id` ) 
                VALUES(     2,     "zharposter.jpg",   "zhars first poster",   "zhar Red fox jump"           3,            0,   "1998-01-01 23:59:59.997",  0,      2);

INSERT INTO     `posts`(    `id`, `poster`,                 `name`,                  `text`,                 `user_id`,  `create_at`,               `rating`, `company_id` ) 
                VALUES(     3,     "zhar1poster.jpg",   "zhars 1 first poster",   "zhars 1 Red fox jump"           3,     "1998-01-01 23:59:59.997",  100,      2);

INSERT INTO     `posts`(    `id`, `poster`,                 `name`,                  `text`,                 `user_id`, `views`, `create_at`,               `rating`, `company_id` ) 
                VALUES(     4,     "aniposter.jpg",   "anis first poster",   "ani Red fox jump"           2,            70,   "1998-01-01 23:59:59.997",  40,      4);


CREATE TABLE `comments`(
    `id`  INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `text` TEXT NOT NULL,
    `user_id` INT UNSIGNED NOT NULL,
    `create_at` DATETIME NOT NULL,
    `rating` TYNYINT NOT NULL,
    `post_id` INT UNSIGNED UNO NULL,
    `comment_id` INT UNSIGNED NULL DEFAULT 0,
    PRIMARY KEY(`id`)
);

INSERT INTO     `comments`(    `id`, `text`,  `user_id`, `create_at`, `rating`, `post_id`, `company_id` ) 
                VALUES(     1,     "Շատ վատ փոստ",   3,  "1998-01-01 23:59:59.997", 30,  3,  4);

INSERT INTO     `comments`(    `id`, `text`,  `user_id`, `create_at`, `rating`, `post_id`, `company_id` ) 
                VALUES(     2,     "Շատ վատ փոստ 2",   2,  "1998-01-01 23:59:59.997", 10,  2,  1);

INSERT INTO     `comments`(    `id`, `text`,  `user_id`, `create_at`, `rating`, `post_id`, `company_id` ) 
                VALUES(     3,     "Շատ վատ փոստ3",   3,  "1998-01-01 23:59:59.997", 2,  1,  4);

INSERT INTO     `comments`(    `id`, `text`,  `user_id`, `create_at`, `rating`, `post_id`, `company_id` ) 
                VALUES(     4,     "Շատ վատ փոստ 4",   1,  "1998-01-01 23:59:59.997", 40,  4,  2);
                