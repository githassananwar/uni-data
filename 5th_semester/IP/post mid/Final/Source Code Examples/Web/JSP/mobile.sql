/*
SQLyog Enterprise v4.06 RC1
Host - 5.0.51b-community-nt : Database - mobile
*********************************************************************
Server version : 5.0.51b-community-nt
*/


create database if not exists `mobile`;

USE `mobile`;

/*Table structure for table `company` */

drop table if exists `company`;

CREATE TABLE `company` (
  `id` int(5) NOT NULL,
  `companyName` varchar(25) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `company` */

insert into `company` values (1,'Nokia'),(2,'Samsung');

/*Table structure for table `detail` */

drop table if exists `detail`;

CREATE TABLE `detail` (
  `id` int(5) default NULL,
  `model` varchar(15) default NULL,
  `price` int(10) default NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `detail` */

insert into `detail` values (1,'Lumia 625',50000),(1,'Lumia 710',26000),(1,'C2 01',7100),(1,'112',4750),(2,'E2202',3900),(2,'S5610',10000),(2,'S6102',14500),(2,'C5212',5000),(1,'C6',20000);
