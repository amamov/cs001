# SQL

## Docker MySQL 설치하기

[도움되는 블로그](https://kdinner.tistory.com/27)

- `$ docker pull mysql:5.7`

- `$ docker run -d -p 3306:3306 -e MYSQL_ROOT_PASSWORD=root1! --name mysql5 mysql:5.7`

- `$ docker exec -it mysql5 /bin/bash`

- `$ cat /etc/issue`

- `$ which mysql`

- `$ mysql -u root -p`

  - password에 아까 설정한 password인 root1!을 입력한다.
  - mysql 세계로 들어왔다.

- `$ show databases;`

  - database 목록들이 나타난다.

- `$ use mysql`

  - mysql row를 선택한다.

- `$ show tables;`
