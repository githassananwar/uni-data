-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jun 03, 2016 at 02:51 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `etaqreeb`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE IF NOT EXISTS `admin` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `username` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `name`, `username`, `email`, `password`) VALUES
(1, 'Muhammad Muzamil Ejaz', 'hassan', 'bsef12m054@pucit.edu.pk', '1122');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE IF NOT EXISTS `customer` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) NOT NULL,
  `email` varchar(100) NOT NULL,
  `username` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL,
  `contact` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`id`, `name`, `email`, `username`, `password`, `contact`) VALUES
(9, 'hassan', 'bsef12m014@pucit.edu.pk', 'hassan', '123', '03244563233'),
(10, 'Raza', 'raza@gmail.com', 'raza', '123', '+87578');

-- --------------------------------------------------------

--
-- Table structure for table `event`
--

CREATE TABLE IF NOT EXISTS `event` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) NOT NULL,
  `type` varchar(200) NOT NULL,
  `date` varchar(100) NOT NULL,
  `shift` varchar(50) NOT NULL,
  `customer_id` int(9) NOT NULL,
  `budget` int(20) NOT NULL,
  `numOfGuests` int(10) NOT NULL,
  `current_budget` int(20) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `customer_id` (`customer_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `event`
--

INSERT INTO `event` (`id`, `name`, `type`, `date`, `shift`, `customer_id`, `budget`, `numOfGuests`, `current_budget`) VALUES
(1, 'Farewell F12', 'Function', '07/14/2016', 'Afternoon', 9, 120000, 100, 80000),
(2, 'Mehndi', 'Wedding', '06/24/2016', 'Night', 9, 10000, 100, 23000);

-- --------------------------------------------------------

--
-- Table structure for table `event_services`
--

CREATE TABLE IF NOT EXISTS `event_services` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `vendor_service_id` int(9) NOT NULL,
  `event_id` int(9) NOT NULL,
  `status` varchar(50) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `vendor_service_id` (`vendor_service_id`),
  KEY `event_id` (`event_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `event_services`
--

INSERT INTO `event_services` (`id`, `vendor_service_id`, `event_id`, `status`) VALUES
(2, 3, 1, 'Confirm'),
(3, 3, 2, 'Confirm'),
(5, 5, 2, 'Not confirm');

-- --------------------------------------------------------

--
-- Table structure for table `message`
--

CREATE TABLE IF NOT EXISTS `message` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `customer_id` int(9) NOT NULL,
  `vendor_id` int(9) NOT NULL,
  `sent_by` int(9) NOT NULL,
  `body` varchar(1000) NOT NULL,
  `dateTimeMeta` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `rating`
--

CREATE TABLE IF NOT EXISTS `rating` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `vendor_id` int(9) NOT NULL,
  `noOfRatings` int(9) NOT NULL,
  `rating` int(9) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `vendor_id` (`vendor_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `rating`
--

INSERT INTO `rating` (`id`, `vendor_id`, `noOfRatings`, `rating`) VALUES
(3, 3, 7, 28),
(4, 4, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vendor`
--

CREATE TABLE IF NOT EXISTS `vendor` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) NOT NULL,
  `companyname` varchar(200) NOT NULL,
  `description` text,
  `address` varchar(500) NOT NULL,
  `contact1` varchar(100) NOT NULL,
  `contact2` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `username` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL,
  `availability` varchar(10) NOT NULL,
  `image` varchar(100) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `vendor`
--

INSERT INTO `vendor` (`id`, `name`, `companyname`, `description`, `address`, `contact1`, `contact2`, `email`, `username`, `password`, `availability`, `image`) VALUES
(3, 'Hassan', 'Samarqand Events', NULL, 'Nishat colony, Lahore Cantt', '03214842531', '03334567891', 'hsn@gmail.com', 'samar', '123', 'Yes', 'abtslide1.jpg'),
(4, 'Hisham', 'Event Bazar', NULL, 'Shalamar, Lahore', '03334563233', '03334842531', 'hisham@event.com', 'hisham', '123', 'Yes', 'pic3.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `vendor_services`
--

CREATE TABLE IF NOT EXISTS `vendor_services` (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) NOT NULL,
  `price` float NOT NULL,
  `type` varchar(200) NOT NULL,
  `vendor_id` int(9) NOT NULL,
  `pricemode` varchar(100) NOT NULL,
  `simage` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `vendor_id` (`vendor_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `vendor_services`
--

INSERT INTO `vendor_services` (`id`, `name`, `price`, `type`, `vendor_id`, `pricemode`, `simage`) VALUES
(3, 'Daigi Catering', 800, 'Caterers', 3, 'Per Head', 'pic2.jpg'),
(4, 'Party Decoration', 10000, 'Decorators', 3, 'Package Price', 'abtslide1.jpg'),
(5, 'Photographer', 15000, 'Photography', 3, 'Package Price', 'pic2.jpg');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `event`
--
ALTER TABLE `event`
  ADD CONSTRAINT `event_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`id`);

--
-- Constraints for table `event_services`
--
ALTER TABLE `event_services`
  ADD CONSTRAINT `event_services_ibfk_1` FOREIGN KEY (`vendor_service_id`) REFERENCES `vendor_services` (`id`),
  ADD CONSTRAINT `event_services_ibfk_2` FOREIGN KEY (`event_id`) REFERENCES `event` (`id`);

--
-- Constraints for table `rating`
--
ALTER TABLE `rating`
  ADD CONSTRAINT `rating_ibfk_1` FOREIGN KEY (`vendor_id`) REFERENCES `vendor` (`id`);

--
-- Constraints for table `vendor_services`
--
ALTER TABLE `vendor_services`
  ADD CONSTRAINT `vendor_services_ibfk_1` FOREIGN KEY (`vendor_id`) REFERENCES `vendor` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
