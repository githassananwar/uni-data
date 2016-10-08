/*
SQLyog Enterprise v4.06 RC1
Host - 5.0.51b-community-nt : Database - college
*********************************************************************
Server version : 5.0.51b-community-nt
*/


create database if not exists `college`;

USE `college`;

/*Table structure for table `post` */

drop table if exists `post`;

CREATE TABLE `post` (
  `postId` int(5) NOT NULL auto_increment,
  `postTitle` varchar(50) default NULL,
  `postDescription` varchar(100) default NULL,
  `uploadedImage` varchar(50) default NULL,
  `uploadedVideo` varchar(50) default NULL,
  `capturedImage` varchar(50) default NULL,
  `enteredBy` varchar(50) default NULL,
  `enteredDateTime` datetime default NULL,
  PRIMARY KEY  (`postId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `post` */
