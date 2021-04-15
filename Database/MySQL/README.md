# SQL

- [SQL Tutorial 1](https://www.w3schools.com/sql/sql_intro.asp)
- [SQL Tutorial 2](https://www.mysqltutorial.org/basic-mysql-tutorial.aspx)
- [SQL IDE](https://app.popsql.com/)
- [SQL db 기본 문법](#기본-db-문법)
- [SQL 기본 문법](#기본-문법)

## Docker MySQL 구동

- `$ docker pull mysql:5.7`

- `$ docker run -d -p 3306:3306 -e MYSQL_ROOT_PASSWORD=root1! --name mysql5 mysql:5.7`

  - `$ docker start mysql5`
    - mysql5 컨테이너 start
  - `$ docker inspect mysql5 | grep IP`
    - mysql5 container의 IP를 알 수 있다.

- `$ docker exec -it mysql5 /bin/bash`

  - `$ cat /etc/issue`
  - `$ which mysql`

- `$ mysql -u root -p`

  - mysql 서버 접속
  - password에 아까 설정한 password인 root1!을 입력한다.
  - mysql에서 `SET PASSWORD = PASSWORD('11111');`으로 비밀번호 변경이 가능하다.

- `$ show databases;`

  - database 목록들이 나타난다.

- `$ use mysql`

  - mysql row를 선택한다.

- `$ show tables;`

<br>

---

<br>

## DB 생성

- `$ CREATE DATABASE testDB DEFAULT CHARACTER SET utf8;`
  - testDB라는 DB를 만들고 문자 인코딩은 utf8로 한다.

## DB 삭제

- `$ DROP DATABASE "삭제 할 데이터베이스 명"`

<br>

## DB 사용자 추가

- `$ CREATE user '사용자'@'호스트' IDENTIFIED BY '사용할 비밀번호';`
  - `$ CREATE user 'amamov'@'localhost' IDENTIFIED BY '1205';`;
  - `$ CREATE user 'amamov'@'%' IDENTIFIED BY '1205';`;
  - 사용자 계정에 외부 권한을 부여하려면, 호스트를 '%'로 하여 계정을 추가하면 된다.

## DB 사용자 삭제

- `$ DROP user '사용자'@'호스트';`

## DB 사용자 조회

1. `$ USE mysql`

2. `$ SELECT user, host FROM user;`

<br>

## DB 사용자 권한 부여

- `$ GRENT ALL PRIVILEGES ON <DB이름>.* TO <사용자>@'호스트' IDENTIFIED BY '비밀번호';`

## DB 사용자 권한 삭제

- `$ REVOKE ALL ON <DB이름>.* FROM '사용자'@'호스트';`

## DB 사용자 권한 확인하기

- `$ SHOW GRANTS FOR '사용자'@'호스트';`

<br>

---

<br>

## MySQL WorkBranch에 연결하기

[MySQL WorkBranch](https://www.mysql.com/products/workbench/)

<br>

---

<br>

# 기본 DB 문법

- [docs](https://www.tutorialspoint.com/mysql/mysql-data-types.htm)
- [tutorial](https://www.w3schools.com/sql/sql_create_db.asp)

- [x] DB 조회
- [x] DB 생성
- [x] DB 사용하기(선택하기)
- [x] 현재 사용하고 있는 DB 조회하기
- [x] DB 삭제하기
- [x] Table 조회
- [x] Table 생성
- [x] 특정 Table 구조 확인하기
- [x] Table 삭제하기

## SHOW

- DB 목록 조회

```sql
SHOW DATABASES;
```

- Table 목록 조회

```sql
SHOW TABLES;
```

<br>

## CREATE

- DB 생성

```sql
CREATE DATABASE <db_name>;

CREATE DATABASE test_dbdb;
```

- Table 생성

```sql
CREATE TABLE <name> (
  <column_name> <data_type>,
  <column_name> <data_type>);

CREATE TABLE user (
  id INT(11) NOT NULL AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  age INT NOT NULL,
  bio TEXT NULL,
  PRIMARY KEY(id));
```

<br>

## USE

- DB로 들어간다.

```sql
USE <db_name>
```

<br>

## SELECT

- 현재 사용중인 DB 확인

```sql
SELECT DATABASE();
```

<br>

## DESCRIBE

- 특정 테이블 구조 보기

```sql
DESCRIBE <table_name>
```

<br>

## DROP

- DB 삭제 하기, Table 삭제하기

```sql
DROP DATABASE <name>
DROP TABLE <name>

DROP TABLE user
```

<br>

---

<br>

# 기본 문법

## INSERT

[SQL INSERT Tutorial](https://www.w3schools.com/sql/sql_insert.asp)

<br>

## SELECT

[SQL SELECT Tutorial](https://www.w3schools.com/sql/sql_select.asp)

<br>

## UPDATE

[SQL UPDATE Tutorial](https://www.w3schools.com/sql/sql_update.asp)

<br>

## DELETE

[SQL DELETE Tutorial](https://www.w3schools.com/sql/sql_delete.asp)

<br>
