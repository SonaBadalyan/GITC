CREATE DATABASE `blog`;

USE `blog`;

CREATE TABLE `account`(
    `id`  INT UNSIGNED NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    PRIMARY KEY(`id`)
);

CREATE TABLE `users`(
    `id`  INT UNSIGNED NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `surname` VARCHAR(80) NULL,
    `age` TINYINT(100) UNSIGNED NOT NULL,
    `email` VARCHAR(120) NOT NULL UNIQUE,
    `accountID` INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);

CREATE TABLE `notifications`(
    `id`  INT UNSIGNED NOT NULL,
    `accountID` INT UNSIGNED NOT NULL,
    `count` INT UNSIGNED NULL,
    `status` BOOLEAN NOT NULL, 
    PRIMARY KEY(`id`)
);

CREATE TABLE `companies`(
    `id`  INT UNSIGNED NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `rating` INT UNSIGNED NOT NULL,
    `status` BOOLEAN NOT NULL, 
    PRIMARY KEY(`id`)
);

CREATE TABLE `eventsAndcourses`(
    `id`  INT UNSIGNED NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `descriptions` VARCHAR(250) NOT NULL,
    `paid` BOOLEAN NOT NULL,
    `online` BOOLEAN NOT NULL,
    PRIMARY KEY(`id`)
);

CREATE TABLE `jobs`(
    `id`  INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);

CREATE TABLE `games`(
    `id`  INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);


CREATE TABLE `categories`(
    `id`  INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);


CREATE TABLE `themes`(
    `id`  INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);


CREATE TABLE `languages`(
    `id`  INT UNSIGNED NOT NULL,
    PRIMARY KEY(`id`)
);

CREATE TABLE `posts`(
    `id`  INT UNSIGNED NOT NULL,
    `name` VARCHAR(50) NOT NULL,
    `tag` VARCHAR(250) NOT NULL,
    `comment` BOOLEAN NOT NULL,
    `views` BOOLEAN NOT NULL,
    PRIMARY KEY(`id`)
);

