# Nginx http 구성

HTTP 핵심 모듈은 HTTP 구성에 쓰이는 필수 구성품으로, 가상 호스트라고도 하는 웹 사이트를 설정해서 제공하는 데 사용된다.

## HTTP 핵심 모듈

HTTP 핵심 모듈은 HTTP 서버의 모든 기반 블록, 지시어, 변수를 포함하는 구성 요소이다. 이 모듈은 Nginx를 컴파일하고자 구성할 때 기본으로 활성화된다.

(이 모듈은 빌드에 포함되지 않게 할 수 있기 때문에 사실 옵션이다. 이 모듈은 컴파일 과정에서 빼면 HTTP 기능이 전혀 동작하지 않을 뿐 아니라 다른 HTTP 모듈도 컴파일되지 않게 된다.)

이 모듈은 모든 Nginx 모듈 중에서 가장 규모가 커서 매우 많은 지시어와 변수를 제공한다.

## 구조 블록

- http
  - 이 블록은 구성 파일의 최상위에 삽입된다. Nginx의 HTTP 관련된 모듈 전부의 지시어와 블록은 http 블록에만 정의할 수 있다.
  - 그럴만한 이유는 없지만, 이 블록은 여러 번 추가될 수 있는데, 이런 경우 뒤에 오는 블록의 지시어 값이 선행되는 블록의 지시어 값을 재지정하게 된다.
- server
  - 이 블록으로는 웹사이트 하나를 선언할 수 있다. 다시 말해 Nginx가 특정 웹 사이트를 인식하고 그 구성을 얻는 블록이다.
  - 이 블록은 http 블록 안에서만 사용할 수 있다.
- location
  - 웹 사이트의 특정 위치에만 적용되는 설정을 정의하는 데 쓰는 블록이다.
  - 이 블록은 server 블록 안이나 다른 location 블록 안에 중첩해서 사용할 수 있다.

http 블록으로 정의된 HTTP 영역은 웹 관련 구성 전체를 망라한다. 이 블록은 호스팅하는 도메인이나 하위 도메인을 정의하는 하나 이상의 server 블록을 포함한다. 각 웹 사이트마다 특정 요청 URI나 요청 URI 패턴에 부가 설정을 적용할 수 있는 location 블록을 여러 번 정의할 수 있다.

## 소켓과 호스트 구성

아래의 나열된 지시어로는 가상 호스트를 구성할 수 있다. 가상 호스트는 호스트 이름이나 IP 주소와 포트의 조합으로 식별되는 server 블록을 만들어 실현된다.

> [소켓이란?](https://helloworld-88.tistory.com/215)

> [네트워크 통신(socket)을 하는 방법](https://nowonbun.tistory.com/315)

### listen

- 맥락 : server

웹 사이트를 제공하는 소켓을 여는 데 사용되는 IP 주소나 포트, 또는 두 가지 모두를 지정한다.

웹 사이트는 보통 HTTP 기본값인 80 포트나 HTTPS 기본값인 443 포트에서 제공된다.

- 구문 : `listen [주소][:포트] [추가옵션];`

- 추가 옵션

  - `default_server` : 해당 server 블록을 지정된 IP 주소와 포트로 들어온 모든 요청의 기본 웹 사이트로 지정
  - `ssl` : 웹 사이트가 SSL을 통해 제공되도록 지정
  - `proxy_protocol` : 포트로 접속된 모든 네트워크 연결에 프록시 프로토콜을 활성화

### server_name

- 맥락 : server

server 블록에 하나 이상의 호스트 이름을 할당하는 지시어다. Nginx는 HTTP 요청을 받을 때 요철의 Host 헤더를 server 블록 모두와 비교한다. 이 호스트 이름과 맞는 첫 번째 server 블록이 선택된다.

- 대안

  - 아무런 server블록도 요청의 호스트와 맞지 않다면 Nginx는 listen 지시어의 매개변수와 맞는 server 블록을 선택한다.

- 구문 : `server_name 호스트이름1 [호스트이름2...];`

  - `server_name www.website.com;`
  - `server_name www.website.com www.website.com;`
  - `server_name *.website.com;`
  - `server_name website.com "";`
    - 빈 문자열을 사용해 Host 헤더 없이 들어오는 모든 요청을 받게 할 수도 있다.

```conf
server {
    listen 80;
    server_name 3.35.142.136 api.iflag.de www.api.iflag.de;

    location = /favicon.ico {
        access_log off;
        log_not_found off;
    }

    location /static/ {
        root /home/ubuntu/iflag-api/config;
    }

    location / {
        include proxy_params;
        proxy_pass http://unix:/run/gunicorn.sock;
    }
}
```

### tcp_nodelay

- 맥락 : http, server, location

연결 유지(Keep-alive) 상황에서 TCP_NODELAY 소켓 옵션을 활성화하거나 비활성화한다. 소켓 프로그래밍에 대한 리눅스 문서를 인용하면 다음과 같다.

> TCP_NODELAY는 내글 버퍼링 알고리즘을 비활성화하는 특수 목적에 쓰인다. 즉각적인 반응 없이 낮은 빈도의 정보를 주기적으로 보내는 데이터 전송이 적기에 이뤄져야 하는 애플리케이션에서만 사용해야 한다. 마우스 이동이 전형적인 예이다.

- 구문 : on, off

- 기본값 : on

### tcp_nopush

- 맥락 : http, server, location

TCP_NOPUSH나 TCP_CORK(리눅스) 소켓 옵션을 활성화 또는 비활성화한다.

이 옵션은 sendfile 지시어가 활성화돼야 적용된다. tcp_nopush가 on이면 Nginx는 모든 HTTP 응답 헤더를 TCP 패킷에 전송하려고 시도한다.

- 구문 : on. off

- 기본값 : off

### sendfile

- 맥락 : http, server, location

이 지시어가 활성화되면 Nginx는 sendfile 커널 호출을 사용해서 파일을 전송한다. 비활성화되면 Nginx는 스스로 파일을 전송한다.

전송될 파일의 물리적인 위치에 따라 이 옵션은 서버 성능에 영향을 미친다.

- 구문 : on, off

- 기본값 : off

### sendfile_max_chunk

- 맥락 : http, server

이 지시어는 sendfile 호출마다 사용될 데이터 최대 크기를 정의한다.

- 구문 : 숫자 값

- 기본값 : 0

## 경로와 문서

아래의 지시어들은 각 웹 사이트가 제공할 문서를 구성하는 지시어를 설명한다. 최상위 문서 위치, 사이트 색인, 오류 페이지 같은 것이다.

### root

- 맥락 : http, server, location, if, 변수 사용 가능

이 지시어는 방문자에게 제공하고자 하는 파일을 담고 있는 최상위 문서 위치를 정의한다.

- 구문 : 디렉터리 경로

- 기본값 : html

`root /home/website.com/public_html;`

### alias

- 맥락 : location, 변수 사용 가능

alias는 location 블록 안에서만 쓸 수 있다. Nginx가 특정 요청에서 별도 경로의 문서를 읽도록 할당한다.

```conf
http {
    server {
        server_name localhost;
        root /var/www/website.com/html;
        location /admin/ {
            alias /var/www/locked/;
        }
    }
}
```

`http://locahost/` 요청이 들어오면 `/var/www/website.com/html/` 폴더의 파일이 제공된다.

하지만 nginx가 `http://localhost/admin/` 요청을 받아 파일을 읽을 때 사용되는 경로는 `/var/www/locked/`이다.

- 구문 : 디렉터리나 파일 경로

### error_page

- 맥락 : http, server, location, if. 변수 사용 가능

HTTP 응답 코드에 맞춰 URI를 조작하거나 이 코드를 다른 코드로 대체한다.

- 구문 : `error_page code1 [code2...] [=대체 코드] [@block | URI]`

  - `error_page 404 /not_found.html;`
  - `error_page 403 http://website.com/;`
  - `error_page 404 @notfound;` # 지정한 location 블록으로 이동
  - `error_page 404 =200 /index.html;` # 404 오류일 경우, 응답 코드를 200 ok로 바꾸고 index.html로 경로를 돌림

### recursive*error*
