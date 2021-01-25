# Docker

- [good post](https://cultivo-hy.github.io/docker/image/usage/2019/03/14/Docker정리/)

- [docker 명령어 정리 블로그](https://captcha.tistory.com/49)

## Docker 명령어 정리

### version

- `$ docker version` : 클라이언트와 서버의 버전을 알 수 있다.

<br>

### search : image 검색

Docker Hub로쿠터 사용 가능한 image를 찾는 명령어

- `$ docker search linux`

<br>

### run : 컨테이너 생성과 동시에 컨테이너로 접속

- `$ docker run 이미지이름` : 이미지를 받아서 해당 이미지 기반의 Container를 실행한다.
- `$ docker run --name 컨테이너이름 이미지이름`
- `$ docker run --rm 이미지이름` : 컨테이너를 생성하고 실행이 끝나면 바로 지운다.
- `$ docker run --rm --detach --publish 8000:80 nginx`
  - `--name` : 옵션으로 컨테이너 이름을 지정할 수 있다.

#### 자주 사용하는 옵션

- `-d` : detached mode (백그라운드 모드)
- `-p` : 호스트와 컨테이너의 포트를 연결 (포워딩)
- `-v` : 호스트와 컨테이너의 디렉터리를 연결 (마운트)
- `-e` : 컨테이너 내에서 사용할 환경변수 설정
- `-name` : 컨테이너 이름 설정
- `-rm` : 프로세스 종료시 컨테이너 자동 제거
- `-it` : `-i`와 `-t`를 동시에 사용한 것으로 터미널 입력을 위한 옵션
- `-itd` : `-it` + `-d`
- `-link` : 컨테이너 연결

<br>

### exec : 실행중인 container에 명령어 전달

- `$ docker exec -it ubuntush cat /etc/hosts`

### attach : 컨테이너에 접속하기

- `$ docker attach 'container ID`

### stop : 컨테이너 중지하기

- `$ docker stop [options] <container>`

<br>

### rm : 컨테이너 삭제하기

- `$ docker container rm 컨테이너_ID` : 컨테이너를 제거한다.

<br>

### images

- `$ docker images` : 현재 Image 목록을 확인할 수 있다.
  - `$ docker image ls`와 같다.
- `$ docker image rm <이미지ID>` : 특정 이미지를 제거한다.
  - `$ docker rmi <이미지ID>`와 같다.
  - `$ docker rmi <이미지ID> -f` : 특정 이미지를 무조건 제거한다.

<br>

### ps (컨테이너 확인)

- `$ docker ps` : 현재 실행중인 컨테이너 목록들을 확인할 수 있다.
  - `$ docker container ls`와 같다.
- `$ docker ps -a` : 모든 컨테이너 목록들을 확인할 수 있다. (종료되었던 컨테이너 포함)
  - `$ docker container ls -a`와 같다.

<br>

### pull

- `$ docker pull nginx` : nginx Image를 받아온다.

<br>

### logs

- `$ docker logs [options] <container>` : 컨테이너가 정상적으로 동작하는 지 확인할 수 있다.

<br>

---

<br>

## Docker Playground - cent OS

1. `$ docker pull centos`

2. `$ docker run -it --name 'test' centos /bin/cal`

3. `$ docker run -it --name 'centossh' centos /bin/bash`
   - centos 세계로 들어간다.
   - `exit`로 나갈 수 있다.

<br>

## Docker Playground

- `$ docker run --rm -it python:3.9` : python 3.9 버전 사용하기

  - `-it` : 표준 입출력이 가능하게 된다.

<br>

- `$ docker run --detach --publish 8080:80 --name mynginx nginx` : nginx 웹 서버 띄우기

  - nginx 이미지를 통해 mynginx Container 적재 및 실행
  - nginx 이미지는 80포트로 listen으로 세팅되어 있다.
  - host의 8080포트와 container의 80포트를 연결
  - `http://localhost:8080` 주소로 접속 가능
  - `$ docker stop mynginx` : mynginx container 정지
  - `$ docker rm mynginx` : mynginx container 삭제

<br>

- `$ docker run -d -p 8080:80 --volume 'pwd'/html:/usr/share/nginx/html --name mynaginx nginx` : (MAC/Linux) 현재 디렉터리내 html/index.html을 서버에 올린다.

<br>

---

<br>

## Docker Oracle 설치하기

- `$ docker search oracle`

- `$ docker pull oracleinanutshell/oracle-xe-11g`

  - oracle은 유료이므로 xe 버전(학습용)으로 사용하자.

- `$ docker run -d --name testoracle -p 8080:8080 -p 1521:1521 oracleinanutshell/oracle-xe-11g`

  - 8080 포트 : 웹으로 관리할 수 있는 admin 포트
  - 1521 포트 : 데이터베이스 자체의 포트

- `$ docker exec -it testoracle /bin/bash`

- `$ cat /etc/issue`

  - testoracle 컨테이너 안에 ubuntu가 설치되어 있음을 알 수 있다. (이미지마다 다르다.)

- `$ lsnrctl`

  - 오라클 리스너를 관리할 수 있다.
  - 오라클 리스너는 네트워크를 이용하여 클라이언트에서 오라클 서버로 연결하기 위한 오라클 네트워크 관리자이다.
  - ubuntu 안에 오라클이 설치되어 있다.

## Docker MySQL 설치하기

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
