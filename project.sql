-- MySQL dump 10.13  Distrib 8.0.41, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: project1
-- ------------------------------------------------------
-- Server version	8.0.41

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `name` varchar(10) DEFAULT NULL COMMENT '姓名',
  `id` varchar(7) DEFAULT NULL COMMENT '工号',
  `age` int DEFAULT NULL COMMENT '年龄',
  `entryDate` date DEFAULT NULL COMMENT '入学时间',
  `pwd` varchar(30) DEFAULT NULL COMMENT '密码',
  `major` varchar(20) DEFAULT NULL COMMENT '专业',
  `grade` varchar(4) DEFAULT NULL COMMENT '年级'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` (`name`, `id`, `age`, `entryDate`, `pwd`, `major`, `grade`) VALUES (' 王五 ','0275006',20,'2025-09-01','123456','法学','大三'),(' 李三 ','0333001',20,'2023-09-01','159357qazwsx','法学','大三'),(' 吴九 ','0343001',20,'2023-09-01','wujiu1415','法学','大三'),(' 王十一 ','0335001',19,'2022-09-01','wangshiyi1819','法学','大二'),(' 李华 ','0341001',19,'2022-09-01','lihua456','计算机科学与技术','大二'),(' 郑十 ','0273001',18,'2024-09-01','zhengshi1617','软件工程','大一'),(' 孙七 ','0351001',19,'2022-09-01','sunqi1011','软件工程','大二'),(' 小明 ','0281098',18,'2024-02-20','xiaoming123','软件工程','大一'),(' 赵明 ','0281004',18,'2024-09-01','zhaoliu789','软件工程','大一'),(' 周八 ','0281007',20,'2025-09-01','zhouba1213','软件工程','大三'),('Lisa','0341088',20,'2023-09-08','lisa888','计算机科学与技术','大三');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `teacher`
--

DROP TABLE IF EXISTS `teacher`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `teacher` (
  `name` varchar(10) DEFAULT NULL COMMENT '姓名',
  `id` varchar(7) DEFAULT NULL COMMENT '工号',
  `age` int DEFAULT NULL COMMENT '年龄',
  `title` varchar(10) DEFAULT NULL COMMENT '职称',
  `pwd` varchar(30) DEFAULT NULL COMMENT '密码',
  `majorField` varchar(20) DEFAULT NULL COMMENT '专业领域'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teacher`
--

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` (`name`, `id`, `age`, `title`, `pwd`, `majorField`) VALUES ('张三','2003020',40,'讲师','zhangsan123','软件工程'),('赵六','1999021',38,'教授','123456','法学'),('钱七','2010012',39,'副教授','123456qqq','机械工程'),('Root','0000000',0,'root','rootroot','');
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-06-13 22:17:09
