# EC2

## ubuntu위의 nginx 셋업

### 1. 우분투 ec2 인스턴스를 생성한다.

- 언바운드 규칙에서 ssh도 추가해준다.

- key 파일 (ex. test.pem)은 로컬 컴퓨터에 잘 보관한다.

### 2. 로컬에서 ssh를 사용하여 ec2 인스턴스와 연결한다.

```shell
$ cd documents/keys
```

```shell
$ chmod 400 test.pem
```

```shell
$ ssh -i test.pem ubuntu@2-23-3097.ap-northeast-2.compute.amazonaws.com
```

[과정중 bug fix 레퍼런스](https://youtu.be/Z-eTvYwWhuc)

### 3. ec2 셋업

```shell
$ sudo apt-get update
```

### 4. nginx 설치

```shell
$ sudo apt-get install nginx
```

```shell
$ sudo service nginx start
```

```shell
$ curl -i localhost
```

이제 인스턴스의 퍼블릭 IPv4를 브라우저에 띄우면 nginx가 실행된 것을 확인할 수 있다.

### 5. nginx 기본 설정

```shell
# nginx 로그가 쌓이는 곳을 다른 곳에서 접근할 수 있도록 설정
$ sudo chmod 644 /var/log/nginx
```

```shell
# nginx가 사용하는 홈 디렉터리가 /usr/share/nginx/html인데, 이 디렉터리를 ec2-user(ubuntu)가 사용할 수 있도록 만들어준다.
$ sudo chown -R ubuntu:ubuntu /usr/share/nginx/html
```

```shell
$ cd /usr/share/nginx/html
$ vi hello.html
# 안되지..?

```
