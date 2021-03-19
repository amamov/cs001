# Nginx 구성

- [기본 Nginx 구성](#기본-nginx-구성)
- [Nginx 프로세스 아키텍쳐](#nginx-프로세스-아키텍쳐)
- [핵심 모듈](#핵심-모듈)
- [이벤트 모듈](#이벤트-모듈)

# 기본 Nginx 구성

> [Nginx Config](https://www.digitalocean.com/community/tools/nginx)

```
├── conf.d
├── fastcgi.conf
├── fastcgi_params
├── koi-utf
├── koi-win
├── mime.types
├── nginx.conf
├── proxy_params
├── scgi_params
├── sites-available
│   └── default
├── sites-enabled
│   └── default -> /etc/nginx/sites-available/default
├── snippets
│   ├── fastcgi-php.conf
│   └── snakeoil.conf
├── uwsgi_params
└── win-utf
```

- `nginx.conf` : 웹 서버의 기본 구성
- `mime.types` : 파일 확장자와 연관된 MIME 타입의 목록
- `fastcgi_params` : Fast CGI 관련 구성
- `proxy.conf` : 프록시 관련 구성
- `sites.conf` : Nginx로 제공되는 웹 사이트(가상 호스트) 구성. 도메인 단위로 분리하기를 권장

패키지 관리자로 nginx를 설치했다면 `/etc/nginx` 폴더에 `nginx.conf` 구성 파일이 있다.

```conf
# /etc/nginx/nginx.conf

user www-data;
worker_processes auto;
pid /run/nginx.pid;
include /etc/nginx/modules-enabled/*.conf;

events {
    worker_connections 768;
    # multi_accept on;
}

http {

    ##
    # Basic Settings
    ##

    sendfile on;
    tcp_nopush on;
    tcp_nodelay on;
    keepalive_timeout 65;
    types_hash_max_size 2048;

    # server_tokens off;
    # server_names_hash_bucket_size 64;
    # server_name_in_redirect off;
    include /etc/nginx/mime.types;
    default_type application/octet-stream;

    ##
    # SSL Settings
    ##
    ssl_protocols TLSv1 TLSv1.1 TLSv1.2 TLSv1.3; # Dropping SSLv3, ref: POODLE
    ssl_prefer_server_ciphers on;

    ##
    # Logging Settings
    ##
    access_log /var/log/nginx/access.log;
    error_log /var/log/nginx/error.log;

    ##
    # Gzip Settings
    ##

    gzip on;

    # gzip_vary on;
    # gzip_proxied any;
    # gzip_comp_level 6;
    # gzip_buffers 16 8k;
    # gzip_http_version 1.1;
    # gzip_types text/plain text/css application/json application/javascript text/xml application/xml application/xml+rss text/javascript;

    ##
    # Virtual Host Configs
    ##

    include /etc/nginx/conf.d/*.conf;
    include /etc/nginx/sites-enabled/*;
}
```

## 구조와 포함

`include` 지시어는 이름 그대로 지정된 파일을 include시킨다.

```conf
# nginx.conf

user nginx nginx;
worwer_processes 4;
include other_settings.conf;
```

```conf
# other_settings.conf

error_log logs/error.log
pid logs/nginx.pid
```

위의 내용은 결과적으로 아래처럼 해석된다.

```conf
user nginx nginx;
worwer_processes 4;
error_log logs/error.log
pid logs/nginx.pid
```

`include` 지시어는 와일드카드로 특정 패턴에 맞는 파일명을 지정하는 방식도 지원한다. 여기서 \* 문자는 없거나 하나 이상 연속되는 문자에 대응된다. 아래의 구문은 sites 폴더에 있는 `.conf`로 끝나는 모든 파일을 include 시킨다. 이러한 원리로 각각의 웹 사이트마다 파일을 분리하고 한 번에 모두 include 시킬 수 있다.

```conf
include sites/*.conf;
```

**include 지시어에 지정한 파일이 없을 때는 구성 확인(nginx -t)에 실패하고 nginx가 시작하지 않기 때문에 파일을 include할 때 주의해야 한다.**

와일드카드로 파일을 포함시킬 때는 다른 결과를 보게 된다.

## 지시어 블록

기본 구성 파일에서는 이벤트 모듈이 제공하는 events 블록을 볼 수 있다. 모듈이 활성화한 지시어는 해당 모듈의 블록에서만 사용할 수 있다. 아래의 예에서 볼 수 있듯이 worker_connections 지시어는 events 블록 안에서만 의미를 가진다. 반면 서버 전반에 영향을 미치는 지시어는 반드시 어떤 블록에도 속하지 않은 구성의 최상위에 위치해야 한다. 이러한 파일의 최상위 수준을 main 블록이라고 한다.

```conf
events {
    worker_connections 1024;
}
```

## 변수

모듈은 지시어 값을 정의할 때 사용할 수 있는 변수를 제공한다. 예를 들어 nginx HTTP 핵심 모듈은 `$nginx_version` 변수를 정의한다. Nginx의 변수는 항상 `$` 표시로 시작한다.

## 문자열과 값

지시어 값으로 사용할 수 있는 문자열은 세 가지 형식이 있다. 먼저 따옴표 없이 입력할 수 있다.

```conf
root /home/amamov.com/www
```

하지만 공백이나 세미콜론(;) 또는 중괄호({}) 같은 특수문자를 쓰고 싶을 때는 역슬래시(\)를 붙이거나, 전체 문자열을 작은따옴표나 큰다옴표로 묶어야 한다.

<br>

---

<br>

# Nginx 프로세스 아키텍쳐

> Nginx 데몬이 뒷단에서 동작하는 방식에 관련된 전반적인 프로세스 아키텍쳐

Nginx 프로그램이 단순한 하나의 이진 파일로 제공되긴 하지만, 실행될때는 상대적으로 복잡하게 작동될 수 있다.

**Nginx를 시작하면 유일한 프로세스인 주 프로세스(master process)가 생기는데, 현재 사용자와 그룹의 권한으로 실행된다.**

시스템이 부팅될 때 init 스크립트로 Nginx 서비스가 실행되면 보통 root 사용자와 root 그룹 권한을 가진다.

주 프로세스는 클라이언트의 요청을 스스로 처리하지는 않고 대신 그 일을 처리해줄 작업자 프로세스(worker process)를 만든다.

작업자 프로세스는 별도로 정의한 사용자와 그룹으로 실행할 수 있다.

작업자 프로세스의 수, 작업자 프로세스당 최대 연결 수, 작업자 프로세스를 실행하는 사용자와 그룹 등을 구성 파일로 정의할 수 있다.

## 기반 모듈 소개

기반 모듈(base module)은 Nginx의 기본적인 기능을 가진 매개변수를 정의할 수 있는 지시어를 제공한다. 지시어와 블록은 항상 사용할 수 있다.

- 핵심 모듈(core module) : 프로세스 관리나 보안 같은 필수 기능 및 지시어로 이뤄진다.

- 이벤트 모듈(event module) : 네트워킹 기능의 내부 동작 방식을 구성한다.

- 구성 모듈(cofiguration module) : 구성을 외부 파일에서 가져와 포함시킨다.

## 핵심 모듈

아래의 지시어는 nginx를 서버에 처음으로 설치 할 때 조심스럽게 조정해야 한다.

- `worker_processes 1;`

  - 이 설정은 작업자 프로세스 하나만 시작하게 하는데, 모든 요청이 하나의 실행 경로로 처리되며, CPU 코어 하나로 실행됨을 의미한다. 이 값은 늘리는 것이 좋은데, CPU 코어당 최소 하나의 프로세스를 갖도록 설정한다. 또는 auto로 설정해서 Nginx가 최적의 값을 결정하게 하는 것도 좋다. 권장 값 : `worker_processes auto;`

- `worker_connections 1024;`
  - 이 설정은 작업자 프로세스의 수와 함께 서버가 동시에 수용할 수 있는 연결 수를 결정한다. 예를 들어 각각 1024개의 연결을 수용하는 작업자 프로세스가 4개라면 서버는 동시 연결을 최대 4096개까지 처리하게 된다. 이 설정은 보유한 하드웨어에 맞게 조정해야 한다. 더 많은 RAM과 고성능의 CPU를 가진 서버일수록 더 많은 동시 연결을 수용할 수 있다. 대용량 트래픽을 서비스하는 괴물 같은 서버라면 이 설정 값을 올리고 싶을 것이다.

### daemon

데몬 모드를 켜거나 끈다. 끄면 프로그램이 백그라운드에서 시작하지 않는다. 쉘에서 실행하면 전면(foreground)에서 실행된다.
언제 어디서 Nginx가 충돌이 나는지 알고 싶을 댸 디버깅에 유용하다.

- 가능한 값
  - on, off
- 구문
  - `daemon on;`
- 기본값
  - on

### env

환경 변수를 정의하거나 덮어씌운다.

- 구문
  - `env SECRET_KEY=wqendinqwijqewir9123he;`

### error_log

level은 가장 상세한 로그를 남기는 debug부터 info, notice, warn, error, crit, alert, 그리고 가장 치명적인 오류만 보고하는 emerg 중 하나로 지정할 수 있다. 오류 로그를 끄고 싶으면 로그 출력을 `/dev/null`로 지정하면 된다. `error_log /dev/null crit;`

- 구문
  - `error_log /file/path level;`
- 기본값
  - `logs/error.log error`
- 맥락
  - main
  - http
  - mail
  - stream
  - server
  - location

### pid

Nginx 데몬의 pid 파일 경로다. 기본값은 컴파일할 때 결정된다. pid 파일은 운영체제에 종속적인 Nginx init 스크립트에서 사용될 수 있기 때문에 이 지시어는 반드시 올바르게 설정돼야 한다.

- 구문
  - `pid logs/nginx.pid;`
- 기본값
  - 컴파일할 때 결정된 값

### ssl_engine

구문의 enginename은 시스템에서 사용 가능한 하드웨어 SSL 가속 명령어의 이름이다. 사용 가능한 하드웨어 SSL 가속 명령어를 확인하고 싶으면 `openssl engine -t` 명령어를 쉘에서 실행해볼 수 있다.

- 구문
  - `ssl_engine enginename`
- 기본값
  - 없음

### thread_pool

대용량 파일을 비동기로 처리하기 위한 aio 지시어와 함께 사용될 수 있는 스레드 풀 참조를 정의한다.

- 구문
  - `thread_pool name threads=number [max_queue=number]`
- 기본값
  - `thread_pool default threads=32 max_queue=65536`

### user

구성 지시어로도 정의되지 않으면 Nginx 주 프로세스의 사용자와 그룹이 사용된다. Nginx 작업자 프로세스를 시작시키는 사용자 계정과 그룹을 지정할 수 있다.그룹이 필수는 아니다. 보안상의 이유로 제한된 권한의 사용자와 그룹을 지정해야 하는데, 예를 들면 nginx 전용의 상용자와 그룹을 만들고 서비스되는 파일에 적절한 권한을 적용하는 것이다.

- 구문
  - `user username groupname`
  - `user username`
- 기본값
  - 컴파일할 때 결정됨

### worker_process

작업자 프로세스의 수를 지정한다. Nginx는 요청 처리를 다수의 프로세스로 나눠준다. 기본값은 1이지만 CPU가 듀얼 코어 이상이라면 더 큰 값으로 지정하는 것이 좋다. 게다가 느린 I/O 수행으로 프로세스가 차단(block)되더라도 들어오는 요청을 다른 프로세스에 위임할 수 있다. 대신 Nginx가 이 지시어의 값을 적절히 선택하도록 auto를 사용할 수 있도 있다. 기본적으로 auto는 시스템에서 감지된 CPU 코어의 수가 된다.

- 구문
  - `worker_processes 4;`
  - `worker_processes auto;`
- 기본값
  - 1

### worker_aio_requests

aio에 epoll 연결 처리 방식을 사용 중이라면 이 지시어는 작업자 프로세스 하나의 최대 비동기 I/O 작업수를 설정한다.

- 구문
  - `worker_aio_requests 10000;`

## 이벤트 모듈

```conf
user www-data;
worker_processes 4;

event {
    worker_connections 1024;
    use epoll;
}
[...]
```

이벤트 모듈은 네트워크 메커니즘을 구성할 수 있는 지시어를 제공한다. 그중 일부는 프로그램 성능에 중대한 영향을 미치기도 한다.

**다음 지시어들은 반드시 구성 파일의 최상위 수준에 있는 events 블록 안에 있어야 한다.**

### accept_mutex

소켓 연결을 열고자 mutex(상호 배제)를 사용할지 여부를 결정한다.

- 가능한 값
  - on, off
- 구문
  - `accept_mutex on;`
- 기본값
  - off

### accept_mutex_delay

지원을 다시 얻으려고 시도하기 전에 작업자 프로세스가 기다리는 시간을 지정한다. accept_mutex가 off이면 사용되지 않는다.

- 구문
  - 숫자(시각)
  - `accept_mutex_delay 500ms;`
- 기본값
  - 500ms

### multi_accept

Nginx가 수신 큐에서 들어와 있는 연결을 한 번에 다 받게 할지 여부를 결정한다.

- 구문
  - on, off
  - `multi_accept off;`
- 기본값
  - off

### use

어떤 이벤트 모델을 사용할지 선택한다. 컴파일할 때 활성화한 모델 중에서 선택할 수 있다. nginx가 자동으로 가장 적합한 모델을 선택하기 때문에 사용자가 이 값을 바꿀 필요가 없다. 사용할 수 있는 모델은 여러가지가 있는데, 리눅스 2.6 이상에서 효율적인 모델은 epoll이다.

- 가능한 값
  - /dev/poll, epoll, eventport, kqueue, select, rtsig
- 구문
  - `use kqueue`
- 기본값
  - 컴파일할 때 지정
