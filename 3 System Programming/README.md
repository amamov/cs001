# 시스템 프로그래밍

운영체제를 개발하기 위해서는 OS kernel, System Call, Compiler, API, Shell, Editor 등이 필요하다.

## 리눅스 (LINUX)

- 리눅스는 프로그래밍이 가능하다.
- 리눅스는 서버에 많이 사용되는 운영체제이다.

## 리눅스 설치 방법

### 클라우드 컴퓨팅 서비스 활용

1. AWS 클라우드 컴퓨팅 설정
   1. EC2 또는 인스턴스(서버) 생성 (공인인증서 `amamomv.pem` 잘 보관하기)
   2. Elastic IP 생성
   3. 인스턴스와 IP 연결
2. 로컬에서 실행
   1. `$ chmod 400 amamov.pem`
   2. `$ ssh -i amamov.pem ubuntu@<IP주소>`

### Docker 사용

1. `$ docker search linux`

2. `$ docker run -it --name 'linuxsh' linux /bin/bash`

   1. `$ cat /etc/issue`

   2. `$ docker start linuxsh`

   3. `$ docker exec -it linuxsh /bin/bash`
