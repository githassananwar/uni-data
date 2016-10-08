/*
SQLyog Enterprise v4.06 RC1
Host - 5.0.51b-community-nt : Database - person
*********************************************************************
Server version : 5.0.51b-community-nt
*/


create database if not exists `person`;

USE `person`;

/*Table structure for table `person` */

drop table if exists `person`;

CREATE TABLE `person` (
  `name` varchar(25) default NULL,
  `address` varchar(50) default NULL,
  `phoneNumber` int(9) default NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `person` */

insert into `person` values ('Ahmed','Lahore',93687),('Kashif','Lahore',9876543),('M. Ali','Lahore',852147963),('Kamran Ahmed','Multan',987654321),('Ali Murtaza','Karachi',852147);
