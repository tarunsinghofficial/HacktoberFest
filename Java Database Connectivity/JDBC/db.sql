DROP TABLE IF EXISTS subject;
DROP TABLE IF EXISTS student;
CREATE TABLE subject(id int PRIMARY KEY AUTO_INCREMENT, name varchar(25));
CREATE TABLE student(id int PRIMARY KEY AUTO_INCREMENT, student_name varchar(20), score float, subject_id int references subject(id));