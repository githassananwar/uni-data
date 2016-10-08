-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Apr 13, 2016 at 01:38 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `sharkimp`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE IF NOT EXISTS `admin` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `email` varchar(100) NOT NULL,
  `last_login_time` datetime NOT NULL,
  `last_logout_time` datetime NOT NULL,
  `login_status` tinyint(1) NOT NULL,
  `changecode` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `username`, `password`, `email`, `last_login_time`, `last_logout_time`, `login_status`, `changecode`) VALUES
(2, 'muzamil', '202cb962ac59075b964b07152d234b70', 'muzamil', '2016-04-07 00:26:44', '2016-04-07 00:27:10', 0, 62397),
(3, 'hassan', '202cb962ac59075b964b07152d234b70', 'hassan', '2016-04-09 22:14:17', '2016-04-09 22:26:16', 0, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `other_reason`
--

CREATE TABLE IF NOT EXISTS `other_reason` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `reason` varchar(200) DEFAULT NULL,
  `admin_id` int(11) DEFAULT NULL,
  `super_admin_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `admin_id` (`admin_id`),
  KEY `super_admin_id` (`super_admin_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=24 ;

--
-- Dumping data for table `other_reason`
--

INSERT INTO `other_reason` (`id`, `reason`, `admin_id`, `super_admin_id`) VALUES
(19, 'Probation', NULL, 1),
(20, 'Final failure', NULL, 1),
(21, 'Fail', NULL, 1),
(22, 'Fail', 2, NULL),
(23, 'DC', NULL, 1);

-- --------------------------------------------------------

--
-- Table structure for table `query`
--

CREATE TABLE IF NOT EXISTS `query` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `nsuid` varchar(100) DEFAULT NULL,
  `message` varchar(1000) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `submitdate` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `reply` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=23 ;

--
-- Dumping data for table `query`
--

INSERT INTO `query` (`id`, `name`, `nsuid`, `message`, `email`, `submitdate`, `reply`) VALUES
(19, 'asad', '123', 'dfd', 'asad', '2016-04-07 21:11:25', 'yes'),
(20, 'asad', '123', 'hi', 'hgs456@gmail.com', '2016-04-07 21:16:44', 'no'),
(21, 'Hassan', '123', 'Hi', 'hassan@gmail.com', '2016-04-10 09:44:42', 'no'),
(22, 'Ahsan', '123', 'Hi', 'bsef12m014@pucit.edu.pk', '2016-04-10 09:44:56', 'no');

-- --------------------------------------------------------

--
-- Table structure for table `requests`
--

CREATE TABLE IF NOT EXISTS `requests` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `status` varchar(100) DEFAULT NULL,
  `reason` varchar(200) DEFAULT NULL,
  `studentid` int(100) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `studentid` (`studentid`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=28 ;

--
-- Dumping data for table `requests`
--

INSERT INTO `requests` (`id`, `status`, `reason`, `studentid`) VALUES
(1, 'Pending', '', 1),
(2, 'Pending', '', 2),
(3, 'Pending', NULL, 7),
(4, 'Pending', NULL, 8),
(5, 'Pending', NULL, 9),
(6, 'Pending', NULL, 10),
(7, 'Pending', NULL, 11),
(8, 'Pending', NULL, 12),
(9, 'Pending', NULL, 13),
(10, 'Pending', NULL, 14),
(11, 'Pending', NULL, 15),
(12, 'Pending', NULL, 15),
(13, 'Pending', NULL, 15),
(14, 'Pending', NULL, 15),
(15, 'Pending', NULL, 15),
(16, 'Pending', NULL, 15),
(17, 'Pending', NULL, 15),
(18, 'Pending', NULL, 15),
(19, 'Pending', NULL, 15),
(20, 'Pending', NULL, 15),
(21, 'Pending', NULL, 15),
(22, 'Pending', NULL, 15),
(23, 'Pending', NULL, 15),
(24, 'Pending', NULL, 15),
(25, 'Pending', NULL, 15),
(26, 'Pending', NULL, 30),
(27, 'Pending', NULL, 31);

-- --------------------------------------------------------

--
-- Table structure for table `student_info`
--

CREATE TABLE IF NOT EXISTS `student_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `nsuid` varchar(100) NOT NULL,
  `phoneno` varchar(100) NOT NULL,
  `term` varchar(100) NOT NULL,
  `major` varchar(100) NOT NULL,
  `agency` varchar(100) NOT NULL,
  `agency_address` varchar(100) NOT NULL,
  `agency_website` varchar(100) NOT NULL,
  `supervisor_name` varchar(100) NOT NULL,
  `supervisor_phoneno` varchar(100) NOT NULL,
  `supervisor_email` varchar(100) NOT NULL,
  `studentid` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `studentid` (`studentid`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=28 ;

--
-- Dumping data for table `student_info`
--

INSERT INTO `student_info` (`id`, `name`, `nsuid`, `phoneno`, `term`, `major`, `agency`, `agency_address`, `agency_website`, `supervisor_name`, `supervisor_phoneno`, `supervisor_email`, `studentid`) VALUES
(1, 'Hassan Anwar', 'BSEF12M014', '03244563233', 'Summer', 'Software Engoneering', 'Esipick', 'Johar Town', 'www.esipick.com', 'Fareed', '03334444444', 'fd@gmail.com', 1),
(2, 'Asad', 'BSEF12M035', '0333444444', 'Fall', 'SE', 'NB', 'Jail Road', 'nb.com', 'Fareed', '04444444444', 'fd.com', 2),
(3, 'sfkjbjk', 'bkjb', 'kjb', 'Fall', 'kjb', 'kj', 'kb', 'kbk', 'bk', 'bk', 'bk', 7),
(4, 'hassan', 'kjgk', 'kjb', 'Fall', 'kjb', 'kjb', 'kjb', 'kjb', 'kjbkj', 'bkj', 'bkj', 8),
(5, 'd,smfbjkb', 'nkjnkj', 'nkj', 'Fall', 'nkj', 'nkj', 'nkj', 'nkj', 'nk', 'nk', 'nk', 9),
(6, 'dfkjhkj', 'jg', 'gjhb', 'Fall', 'b', 'b', 'b', 'bjk', 'b', 'jkb', 'jkbjk', 10),
(7, 'kjg', 'kjb', 'b', 'Fall', 'bhj', 'b', 'bjh', 'bhj', 'b', 'hjb', 'jhg', 11),
(8, 'fkjn', 'kjnjk', 'kjb', 'Fall', 'kjb', 'kjb', 'kjb', 'jkbjk', 'bjk', 'bjk', 'bb', 12),
(9, 'Hassan', 'ksjfbjkb', 'v', 'Fall', 'v', 'v', 'kv', 'kv', 'kv', 'vkjv', 'jv', 13),
(10, 'sfgbhj', 'hjg', 'v', 'Fall', 'v', 'vkjv', 'kjv', 'jkvk', 'jvkj', 'v', 'lkb', 14),
(11, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(12, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(13, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(14, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(15, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(16, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(17, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(18, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(19, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(20, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(21, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(22, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(23, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(24, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(25, 'kghjgvjhgv', 'jhvjh', 'vjhv', 'Fall', 'hjv', 'hjv', 'kvh', 'jvv', 'k', 'hvh', 'jb', 15),
(26, 'slkf', 'kjbkj', 'bhjb', 'Fall', 'l', 'bjb', 'ljk', 'bklj', 'bljk', 'bl', 'kjb', 30),
(27, 'djfbnkjnjk', 'bjkjkb', 'kjb', 'Fall', 'kjb', 'kjb', 'kjb', 'kjb', 'kjb', 'kj', 'bkj', 31);

-- --------------------------------------------------------

--
-- Table structure for table `super_admin_$$`
--

CREATE TABLE IF NOT EXISTS `super_admin_$$` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `last_login_time` datetime NOT NULL,
  `last_logout_time` datetime NOT NULL,
  `login_status` tinyint(1) NOT NULL,
  `email` varchar(100) DEFAULT NULL,
  `changecode` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`,`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `super_admin_$$`
--

INSERT INTO `super_admin_$$` (`id`, `username`, `password`, `last_login_time`, `last_logout_time`, `login_status`, `email`, `changecode`) VALUES
(1, 'justin', '202cb962ac59075b964b07152d234b70', '2016-04-13 07:36:20', '2016-04-13 07:36:24', 0, 'hgs456@gmail.com', 53108);

-- --------------------------------------------------------

--
-- Table structure for table `userlogin`
--

CREATE TABLE IF NOT EXISTS `userlogin` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `last_login_time` datetime NOT NULL,
  `last_logout_time` datetime NOT NULL,
  `login_status` tinyint(1) NOT NULL,
  `email` varchar(100) DEFAULT NULL,
  `changecode` int(11) DEFAULT NULL,
  `registerdate` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `job_extension` varchar(11) DEFAULT NULL,
  `offer_extension` varchar(11) DEFAULT NULL,
  PRIMARY KEY (`id`,`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=32 ;

--
-- Dumping data for table `userlogin`
--

INSERT INTO `userlogin` (`id`, `username`, `password`, `last_login_time`, `last_logout_time`, `login_status`, `email`, `changecode`, `registerdate`, `job_extension`, `offer_extension`) VALUES
(1, 'hassan123', '202cb962ac59075b964b07152d234b70', '2016-04-09 21:45:15', '2016-04-09 21:46:11', 0, 'bsef12m014@pucit.edu.pk', NULL, '2016-04-10 01:44:53', NULL, NULL),
(2, 'asad', '202cb962ac59075b964b07152d234b70', '2016-04-09 23:15:12', '2016-04-09 23:15:28', 0, 'asadurrehman123@gmail.com', NULL, '2016-04-10 02:28:32', NULL, NULL),
(4, 'knk', '7220d65820839700b6c9ae74f87b48e0', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'nkn', NULL, '2016-04-10 18:13:23', NULL, NULL),
(6, 'bj', 'ba34ea40525a4379add785228e37fe86', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'bjk', NULL, '2016-04-10 18:17:24', NULL, NULL),
(7, 'kjbkj', 'd1127742bedf4c5b88bcf0f1736bcea4', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'kj', NULL, '2016-04-12 11:44:05', '7.pdf', '7.pdf'),
(8, 'jbjk', 'c9ea187ec0f61fa1c874e9465a6d5497', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'kjb', NULL, '2016-04-12 15:02:22', 'jobDescript', 'offerLetter'),
(9, 'njk', '841ee18a2275ed55e33f75e73c0b6acc', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'nkj', NULL, '2016-04-12 15:04:20', 'jobDescript', 'offerLetter'),
(10, 'jg', '3f10ae3dda3cb1618dc30e768434efcc', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'jhbjh', NULL, '2016-04-12 15:05:46', 'jobDescript', 'offerLetter'),
(11, 'hjbjh', 'e8ace885caf6d569036c37a12dbe74c4', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'bhj', NULL, '2016-04-12 15:06:25', 'jobDescript', 'offerLetter'),
(12, 'njkkjb', '4d7c1e1b16a4d890e4c3c344d9278e76', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'jkb', NULL, '2016-04-12 15:07:30', 'jobDescript', 'offerLetter'),
(13, 'jb', 'f90b8184488fa0772c5b6fb32d0aae95', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:25:48', 'jobDescript', 'offerLetter'),
(14, 'v', '22bd705d62805ab9c1b41e4293e9911c', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:26:22', 'jobDescript', 'offerLetter'),
(15, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:18', 'jobDescript', 'offerLetter'),
(16, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:20', NULL, NULL),
(17, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:21', NULL, NULL),
(18, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:22', NULL, NULL),
(19, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:23', NULL, NULL),
(20, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:25', NULL, NULL),
(21, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:27', NULL, NULL),
(22, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:28', NULL, NULL),
(23, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:29', NULL, NULL),
(24, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:31', NULL, NULL),
(25, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:32', NULL, NULL),
(26, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:34', NULL, NULL),
(27, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:37', NULL, NULL),
(28, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:49', NULL, NULL),
(29, 'vjh', '8af70c5f31d956a7f0ae021529a11728', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'v', NULL, '2016-04-12 15:27:51', NULL, NULL),
(30, 'bljk', '39b9df3a0fb3356d11a63e22260e96ab', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'b', NULL, '2016-04-12 15:28:08', 'jobDescript', 'offerLetter'),
(31, 'kjb', '4d7c1e1b16a4d890e4c3c344d9278e76', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 'kjbk', NULL, '2016-04-12 15:31:19', 'jobDescript', 'offerLetter');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `other_reason`
--
ALTER TABLE `other_reason`
  ADD CONSTRAINT `other_reason_ibfk_1` FOREIGN KEY (`admin_id`) REFERENCES `admin` (`id`),
  ADD CONSTRAINT `other_reason_ibfk_2` FOREIGN KEY (`super_admin_id`) REFERENCES `super_admin_$$` (`id`);

--
-- Constraints for table `requests`
--
ALTER TABLE `requests`
  ADD CONSTRAINT `requests_ibfk_1` FOREIGN KEY (`studentid`) REFERENCES `userlogin` (`id`);

--
-- Constraints for table `student_info`
--
ALTER TABLE `student_info`
  ADD CONSTRAINT `student_info_ibfk_1` FOREIGN KEY (`studentid`) REFERENCES `userlogin` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
