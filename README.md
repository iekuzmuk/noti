# noti (user admin - pass: admin)

**permisos de usuario:

GRANT USAGE ON *.* TO 'admin'@'localhost' IDENTIFIED BY PASSWORD '*2FF39B0E6DF56F054C955EF266A4AE09515EF550';

GRANT SELECT, INSERT, UPDATE, DELETE ON `noti`.* TO 'admin'@'localhost';

###########################

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";

CREATE TABLE `escritores` (
  `id` int(11) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `apellido` varchar(50) NOT NULL,
  `edad` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `escritores` (`id`, `nombre`, `apellido`, `edad`) VALUES
(18, 'Ivan', 'Kuzmuk', 43),
(19, 'Florencia', 'Kuzmuk', 6);

ALTER TABLE `escritores`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `escritores`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

CREATE TABLE `noticias` (
  `id` int(11) NOT NULL,
  `titulo` varchar(150) NOT NULL,
  `subtitulo` varchar(150) NOT NULL,
  `fecha` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `texto` blob NOT NULL,
  `tema` varchar(50) NOT NULL,
  `escritor` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `noticias` (`id`, `titulo`, `subtitulo`, `fecha`, `texto`, `tema`, `escritor`) VALUES
(8, 'tit 222222', 'sub 2', '2019-10-10 03:00:00', 0x746578742032, 'tema 2', 19),
(10, 'noticia 1', 'sub 1', '2019-10-14 10:00:00', 0x746578746f2031, 'tema 1', 18),
(11, 'noticia 3', 'sub 3', '2019-10-14 03:00:00', 0x7465787433, 'tema3', 18),
(12, 'noticia4', 'not 4', '2019-10-14 03:00:00', 0x6e6f7420342074657874, 'tema4', 18),
(13, 'noti flor', 'sub noti f', '2019-10-13 03:00:00', 0x6171756920666c6f7263, 'Flor', 19),
(14, 'nota x', 'nota x', '2019-10-14 03:00:00', 0x746578746f2078, 'tema x', 18),
(15, 'test15', 'sub15', '2019-10-15 03:00:00', 0x787878, 'xxx', 18);

ALTER TABLE `noticias`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `noticias`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;
COMMIT;

CREATE TABLE `users` (
  `cust_id` int(5) NOT NULL DEFAULT '0',
  `user_name` varchar(50) NOT NULL DEFAULT '',
  `password` varchar(32) NOT NULL DEFAULT ''
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

INSERT INTO `users` (`cust_id`, `user_name`, `password`) VALUES
(1, 'admin', '21232f297a57a5a743894a0e4a801fc3');

ALTER TABLE `users`
  ADD PRIMARY KEY (`user_name`),
  ADD KEY `password` (`password`),
  ADD KEY `cust_id` (`cust_id`);
COMMIT;
