# Nginx

- [Nginx Docs](https://nginx.org/en/docs/)

## Nginx 셋업

```shell
# nginx 설치
sudo apt-get install nginx
```

```shell
# nginx 위치 확인
which nginx
```

```shell
# nginx의 환경 설정들
cd /etc/nginx && ll
```

<br>

## Nginx 서비스 제어

### Nginx start, stop, and restart

> [How to start, stop, and restart nginx](https://phoenixnap.com/kb/nginx-start-stop-restart)

> [system(system daemon)을 관리하는 systemctl 명령어 사용법](https://www.lesstif.com/system-admin/systemd-system-daemon-systemctl-24445064.html)

> 멀티태스킹 운영체제에서, 데몬(daemon)은 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램을 말한다.

```shell
# nginx server start
sudo systemctl start nginx
```

```shell
# nginx service의 status를 확인할 수 있다.
sudo systemctl status nginx
```

```shell
# nginx server stop
sudo systemctl stop nginx
```

```shell
# If you’re refreshing Nginx after changing the configuration,
# it’s best to gracefully reload the service.
# That shuts down old processes and restarts new ones with the new configuration.
sudo systemctl reload nginx
```

```shell
nginx -s stop  # 데몬을 강제로 종료한다.
nginx -s stop  # 안전하게 데몬을 종료한다.
nginx -s reopen  # 로그 파일을 다시 연다.
nginx -s reload  # 구성 파일을 다시 읽는다.
```

### 구성 테스트

서버 설정을 지속적으로 조정하려면 반드시 구성 파일의 유효성을 테스트해야 한다. 구성 파일의 사소한 실수도 서비스의 제어권을 잃어버리는 결과로 이어진다. 그러면 일반 제어 명령으로 nginx를 중지할 수 없고 당연히 재실행 명령도 거정 당할 것이다. 다음 명령은 여러 상황에 유용하다.

```shell
# Nginx 구성의 구문, 유효성, 무결성을 확인한다. 즉, 한 번 더 구성 파일을 해석해서 유효한지 여부를 알려준다.
sudo nginx -t
```

> 구성 파일이 유효하다고 해서 Nginx를 실행할 수 있다는 뜻은 아니다. 소켓 문제나 잘못된 경로나 정확하지 않은 접근 권한 같은 부가적인 문제가 있을 수 있다.

서버를 운영 중일 때 구성 파일을 조작하는 건 위험한 일이니 가능하면 피해야 한다. 이 경우 가장 좋은 방법은 새 구성을 별도 임시 파일에 저장하고 이 파일을 테스트하는 것이다.

Nginxs는 이를 위해 `-c` 스위치를 제공한다.

```shell
# /home/amamov/test.conf를 해석해서 유효한 Nginx 구성 파일인지 확인한다.
sudo nginx -t -c /home/amamov/test.conf
```

```shell
# 새 파일이 유효한지 확인한 후에는 구성 파일을 교체하고 Nginx가 서버 구성을 다시 로드하게 한다.
sudo cp -i /home/amamov/test.conf /etc/nginx/nginx.conf
sudo nginx -s reload
```

### 기타 스위치

아래의 명령어를 통해 Nginx의 빌드 버전을 알려줄 뿐만 아니라 더 중요한 구성 단계에서 사용한 인자를 재확인할 수도 있다.

```shell
sudo nginx -V
```

<br>

---

<br>

## Nginx 수동 셋업

> 중요한 컴파일 옵션을 다양하게 활용해서 Nginx를 구성하기 위해 수작업으로 셋팅한다.

> 구성 없이 Nginx를 컴파일하면 수많은 중요한 모듈을 사용할 수 없게 된다.

```shell
sudo apt-get -y install build-essential libpcre3 libpcre3-dev zlib1g zlib1g-dev openssl libssl-dev
```

### 1. gcc 설치

nginx는 C로 작성된 프로그램이기 때문에 GCC 같은 컴파일러 도구를 먼저 OS에 설치해야 한다.

GCC는 C, C++, Java 등 다양한 언어를 지원하는 오픈소스 컴파일러 모음이다.

```shell
# gcc, make 한번에 설치
sudo apt-get install build-essential
```

### 2. PCRE(Perl Compatible Regular Expression) 설치

Nginx의 URL 재작성 모듈과 HTTP 핵심 모듈은 PCRE를 정규식 구문에 사용한다.

- `PCRE` : Perl 호환 정규 표현식
- `libpcre3` : 라이브러리의 컴파일된 버전을 제공한다.
- `libpcre3-dev` : 프로젝트를 컴파일하는 데 필요한 헤더 파일과 소스를 제공한다.

```shell
sudo apt-get -y install libpcre3 libpcre3-dev
```

### 3. zlib 설치

zlib 라이브러리는 압축 알고리즘을 개발자에게 제공한다. 이 라이브러리는 nginx의 다양한 모듈에서 gzip 압축을 하는데 필요하다.

`PCRE`와 비슷하게 라이브러리와 라이브러리의 소스인 `zlib`와 `zlib-dev`을 설치한다.

```shell
sudo apt-get install zlib1g zlib1g-dev
```

### 4. OpenSSL(Open Secure Sockets Layer) 설치

> OpenSSL 프로젝트는 협력적 노력을 통해 개발된 견고하고 상용 수준으로 풍부한 기능을 가진 오픈소스 툴킷이다. 강력한 범용 암호 라이브러리와 함께 보안 소켓 계층(SSL v2/v3)과 전송 계층 보안(TLS v1) 프로토콜을 구현한다. http://www.openssl.org을 방문하면 추가 정보를 얻을 수 있다.

OpenSSL 라이브러리는 Nginx가 안전한 연결을 통해 웹 페이지를 제공하는 데 사용된다. 따라서 이 라이브러리와 라이브러리 개발 패키지를 설치해야 한다.

```shell
sudo apt-get install openssl libssl-dev
```

### 5. Nginx 다운로드 및 압축 해제

### 6. 경로 지정

### 7. 모듈 활성화
