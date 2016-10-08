/*
SQLyog Enterprise v4.06 RC1
Host - 5.0.51b-community-nt : Database - class_test
*********************************************************************
Server version : 5.0.51b-community-nt
*/


create database if not exists `class_test`;

USE `class_test`;

/*Table structure for table `info` */

drop table if exists `info`;

CREATE TABLE `info` (
  `username` varchar(25) default NULL,
  `useraddress` varchar(50) default NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `info` */

insert into `info` values ('Musa Bhai','Lahore'),('Ajmal Khan','Lahore'),('Ahmed','Multan'),('Muhammad Ahmed','Lahore'),('null','null'),('a','a');
