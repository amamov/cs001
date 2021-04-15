# Linux

## 리눅스 설치 방법

### Docker 사용

1. `$ docker search linux`

2. `$ docker run -it --name 'linuxsh' linux /bin/bash`

   1. `$ cat /etc/issue`

   2. `$ docker start linuxsh`

   3. `$ docker exec -it linuxsh /bin/bash`

   4. `$ apt-get update`
