# Django + DRF + React + Docker = Full Stack

- [👻 Django Note 👻](https://github.com/amamov/DRF-React-Fullstack/tree/main/1%20django%20note)
- [👻 React Note 👻](https://github.com/amamov/DRF-React-Fullstack/tree/main/2%20react%20note)
- Fullstack Toy Project : backend + frontend

<br>

---

<br>

# 프로젝트 배포 (Docker + Azure)

[인프라 관련 문서](https://docs.microsoft.com/ko-kr/learn/paths/administer-containers-in-azure/)

- [Docker와 클라우드 서비스를 사용하여 배포하기](#docker와-클라우드-서비스를-사용하여-배포하기)

<br>

## Docker

- Docker는 앱과 그 실행환경/OS를 모두 포함한 소프트웨어 패키지(**Docker Image**)를 만들어주는 프로그램입니다.

- Docker는 플랫폼에 상관없이 실행될 수 있는 애플리케이션 컨테이너를 만들어줍니다.

  - 윈도우에서 exe 파일을 바로 실행하듯이, Docker를 지원하는 플랫폼에서 Docker Image를 받아서 즉시 실행할 수 있습니다.

- Docker Image는 Container의 형태로 Docker Engine이 있는 어디에서나 실행이 가능합니다.

  - 대상 : 로컬 머신 (윈도우/맥/리눅스), Azure, AWS 등
  - 하나의 Docker Image를 통해 다수의 Container를 생성할 수 있습니다.
  - `nginx`, `nginx:1.17.9`, `python:3.9.0a4-buster` 등 다양한 도커 Image들이 있습니다.
  - docker image name은 `repository:tag` 형식입니다. 여기서 repository는 hostname/accountname/name 구조입니다.
    - `name`으로 쓸 경우 : Docker Hub에 공개된 공식 Image (ex. `nginx`)
    - `accountname/name`으로 쓸 경우 : Docker Hub에 공개된 일반 유저의 Image (ex. `amamov/nginx`)
    - `hostname/accountname/name`으로 쓸 경우 : Docker Hub가 아닌 다른 Docker Registory에 공개된 Image
    - **tag는 Docker Image의 버전을 지정하는 용도로 사용합니다.**

- 어떤 추가적인 소프트웨어 없이 Docker Image만 pull해서 바로 run할 수 있습니다.

- Docker 컨테이너는 **하나의 Forefround 프로세스**를 구동하는 것이 원칙입니다.
- Docker는 리눅스의 chroot 기반의 기술입니다.

<br>

---

<br>

## Docker Registry

- Docker Registry는 Docker Image 저장소를 의미합니다.
- 공식 저장소로서 Docker Hub (Docker계의 Github)가 있습니다. 이 외에도 각 클라우드 벤더에서 저장소를 지원해줍니다.
  - Azure Container Registry
  - AWS Elastic Container Registry
  - Google Container Registry

<br>

---

<br>

## Docker 설치

- 각 OS에 맞게 Docker를 설치하고, 버전을 확인한다.
  - "Error response from daemon: Bad response from docker engine"와 같은 메세지가 출력될 경우, docker daemon이 실행 중이 아니거나, root 권한이 필요할 수 있다. linux / mac에서는 `$ sudo docker --version` 명령어를 사용한다.
- MAC : 그냥 다운받으면 된다.

<br>

---

<br>

## Docker 명령어 정리

- `$ docker version` : 클라이언트와 서버의 버전을 알 수 있다.

<br>

- `$ docker run 이미지이름` : Image를 받아서 해당 이미지 기반의 Container를 실행한다.

  - `$ docker run --name 컨테이너이름 이미지이름`
  - `$ docker run --rm 이미지이름` : 컨테이너를 생성하고 실행이 끝나면 바로 지운다.

<br>

- `$ docker container ls` : 컨테이너 목록들을 확인할 수 있다.

  - `$ docker container ls -a` : 모든 컨테이너 목록들을 확인할 수 있다.

<br>

- `$ docker ps` : 현재 실행중인 컨테이너 목록들을 확인할 수 있다.

  - `$ docker ps -a` : 모든 컨테이너 목록들을 확인할 수 있다.

<br>

- `$ docker images` : 현재 Image 목록을 확인할 수 있다.

<br>

- `$ docker container rm 컨테이너_ID` : 컨테이너를 제거한다.

<br>

- `$ docker pull nginx` : nginx Image를 받아온다.

<br>

- `$ docker run --rm --detach --publish 8000:80 nginx`
  - `--name` : 옵션으로 컨테이너 이름을 지정할 수 있다.

<br>

---

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

## Docker로 프로젝트 폴더를 docker hub에 올리기

[Docker Hub 링크](https://hub.docker.com)

**Dockerfile은 Docker 이미지를 만들 때, 수행할 명령과 설정들을 시간 순으로 기술한 파일이다.**

아래와 같은 디렉터리 구조가 있다고 하자.

- `my_test_project`
  - `backend`
  - `requirements.txt`
  - `Dockerfile`

backend는 Django기반의 앱이고 Dockerfile은 아래와 같이 쓰였다.

```Dockerfile
### docker biuld
# ubunto의 18년도 4월 버전 OS를 사용한다.
FROM ubunto:18.04

# 빌드시에 수행할 명령
RUN apt-get update && \
    apt-get install -y python3-pip python3-dev && \
    apt-get clean

# code 이름의 work directory를 지정한다. 만약 폴더가 없다면 자동 생성한다.
WORKDIR /code/

# ./backend/requirements.txt 파일을 code에 복사한다.
ADD ./backend/requirements.txt /code/

# 프로젝트 패키지를 설치한다.
RUN pip3 install -r requirements.txt

# ./backend 폴더를 code에 복사한다.
ADD ./backend /code/

### docker run
# 컨테이너에서 구동할 때 8000번 포트에서 구동할 것이다.
EXPOSE 8000

# 서버를 띄운다. (실서비스에서는 gunicorn이나 uwsgi를 사용한다.)
CMD ["python3", "/code/manage.py", "runserver", "0.0.0.0:8000"]
```

<br>

1. `$ docker build -t test_dj .`

   - 현재 디렉터리를 test_dj라는 이미지로 빌드한다.
   - `-t` : `--tag`와 같다. 이미지 이름을 설정한다.
   - `.` : 현재 디렉터리를 의미한다.

   - 빌드한 후 `$ docker run --rm -p 9000:8000 test_dj` 으로 로컬서버를 열 수 있다.
     - `-p` : `--publish`를 의미한다.

<br>

2. `$ docker tag test_dj amamov/test_dj_2020`
   - docker hub에 올리기 위해 이미지를 태그한다. 애초에 빌드할 때 `$ docker build -t amamov/test_dj .`해도 된다.
   - `$ docker tag <옵션> <이미지 이름>:<태그> <저장소 주소, 사용자명>/<이미지 이름>:<태그>`
   - `$ docker tag test_dj amamov/test_dj_2020:0.1`으로 0.1 태그를 붙일 수 있다. 여기서 0.1태그는 버전정보를 의미한다.

<br>

3. `$ docker login`

<br>

4. `$ docker push amamov/test_dj_2020`
   - docker hub에 올린다.

<br>

---

<br>

## Docker Hub에 업로드한 Image를 실제 웹 서버(클라우드)에서 사용하기

[AWS - lightsell](https://lightsail.aws.amazon.com/ls/webapp/create/instance?region=ap-northeast-2)에서 VM(Virtual Machine)을 사용할 수 있다. (EC2에 비해 확장성이 떨어지지만 저렴하게 사용할 수 있다.)

"AWS - lightsell"에서 Ubunto 가상환경을 선택하고 인스턴스를 생성한 후, 콘솔을 실행한다.

1. `$ sudo apt-get update`

   - 기본적으로 우분투가 내부적으로 설치할 패키지 목록을 OS가 가지고 있는데 이 목록을 업데이트한다.

<br>

2. `$ sudo apt-get install docker.io`

   - Docker를 설치한다.

<br>

3. `$ docker version`

   - docker 버전을 알 수 있다.

<br>

4. `$ sudo docker run --rm hello-world`

   - "hello-world" 이미지를 받아서 실행한다.(테스트)

<br>

5. `$ sudo docker run --rm --publish 80:8000 amamov/test_dj_2020:0.1`
   - docker-hub에 있는 test_dj_2020 이미지를 받아서 실행한다.
   - 이는 콘솔을 닫으면 서버도 꺼진다. 이러한 단점을 보완하기 위해 "docker swarm"을 사용한다.
   - "docker swarm"이란 도커가 공식적으로 만든 오케스트레이션 툴이다. 오케스트레이션 툴이란 여러 호스트 서버의 컨테이너들을 배포 및 관리를 위한 툴이다. ["docker swarm 링크"](https://docs.docker.com/engine/swarm/)

<br>

6. `$ sudo docker swarm init`

   - docker swarm을 초기화한다.
   - VM이 3대가 있다고 했을 때 그중에 한 대가 매인이 되어야한다. 매인 VM에서 init을 수행한다. 나머지 두 대의 VM에서는 매인 VM에 속하게 하기 위해 `$ docker swarm join`명령을 사용한다.

<br>

7. `$ sudo docker node ls`

   - 클러스터가 여러 개이면 묶여 있는 다른 여러 머신들이 보인다.

<br>

8. `$ sudo docker service create --replicas 1 --name test_dj --publish 80:8000 amamov/test_dj_2020:0.1`

   - 컨테이너를 docker swarm이 관리하게 된다.
   - `--replicas` : 컨테이너를 몇개 만들어서 분산할 것인가
   - `test_dj` : 서비스 이름

<br>

9. `$ sudo docker service ls`

   - 서버가 열린 것을 확인할 수 있다.

<br>

10. `$ sudo docker service update --image amamov/test_dj_2020:0.2 test_dj(서비스이름)`

    - "docker service update"로 업데이트한 소프트웨어를 재배포할 수 있다. 입력한 명령어는 0.1에서 0.2로 업데이트를 한 것이다. 반대로 0.2에서 0.1로 롤백도 할 수 있다.

<br>

---

<br>

# Docker와 클라우드 서비스를 사용하여 배포하기

- [Azure portal](https://portal.azure.com/#home)
- [AWS Console](https://aws.amazon.com/ko/console)

<br>

## Static & Media 파일 올리기

static 파일과 media 파일을 배포할 때 [django-storages](https://django-storages.readthedocs.io/en/latest/) 라이브러리를 사용하면 AWS-S3, Azure-strage, Google-cloud-storage 등을 쉽게 구축할 수 있다.

### Azure Storage 사용하기

1. `$ pip install "django-storages[azure]"` : `django-storages` 라이브러리 설치

2. `backend/config/storages.py` 파일을 만들고 설정을 위해 객체를 정의한다.

```python
# backend/config/storages.py

from storages.backends.azure_storage import AzureStorage


class StaticAzureStorage(AzureStorage):
    azure_container = "static"


class MediaAzureStorage(AzureStorage):
    azure_container = "media"
```

3. `backend/config/prod.py` 파일을 다음과 같이 설정한다.

```python
# backend/config/prod.py

import os
from .common import *

DEBUG = False

ALLOWED_HOSTS = os.environ.get("ALLOWED_HOSTS", "").split(",")

STATICFILES_STORAGE = "config.storages.StaticAzureStorage"
DEFAULT_FILE_STORAGE = "config.storages.MediaAzureStorage"

## 소스 코드에 공개하면 절대 안된다. (환경 변수로 지정)
AZURE_ACCOUNT_NAME = os.environ["AZURE_ACCOUNT_NAME"] # collectstatic 명령시에는 직접 작성
AZURE_ACCOUNT_KEY = os.environ["AZURE_ACCOUNT_KEY"] # collectstatic 명령시에는 직접 작성

LOGGING = {
    "version": 1,
    "disable_exiting_loggers": False,
    "handlers": {
        "console": {
            "level": "ERROR",
            "class": "logging.StreamHandler",
        },
    },
    "loggers": {
        "django": {
            "handlers": ["console"],
            "level": "ERROR",
        },
    },
}
```

4. [Azure](https://portal.azure.com/?l=en.en-us#home)에 접속하여 `Storage accounts` 서비스의 `Containers`를 사용한다.
   1. `Storage accounts`를 생성한다.
   2. 생성한 `Storage accounts`에서 "static" 이름의 `Container`를 생성한다. (`Public access level`(공용 엑세스 수준) : Bolb(누구나 파일을 읽을 수 있도록))
   3. 생성한 `Storage accounts`에서 "media" 이름의 `Container`를 생성한다. (`Public access level`(공용 엑세스 수준) : Bolb(누구나 파일을 읽을 수 있도록))

`$ python manage.py collectstatic --settings=config.settings.prod` 명령으로 `Storage accounts`에 빌드할 수 있다.

### AWS S3 사용하기

1. `$ pip install django-storages`

2. Azure Storage와 비슷한 방법으로 올리면 된다. 필자의 프로젝트중 hotel-api repository에 관련 파일이 있다.

<br>

---

<br>

## Django 프로젝트를 Dockerizing하기

### 빠르게 보기 + DB

```python
# backend/prod.txt

-r common.txt

django-storages
gunicorn
psycopg2-binary
# mysqlclient
```

```Dockerfile
# backend/Dockerfile

FROM ubuntu:18.04

# default set up
RUN apt-get update && apt-get install -y python3-pip && apt-get clean

# use mysql set up
#RUN apt-get update && \
#    apt install -y gcc python3-dev python3-pip mysql-client-core-5.7 libmysqlclient-dev && \
#    apt-get clean

WORKDIR /djangoproject
ADD . /djangoproject
RUN pip3 install -r requirements.txt

ENV PYTHONUNBUFFERED=1

EXPOSE 80
CMD ["gunicorn", "config.wsgi:application", "--bind", "0.0.0.0:80"]
```

```.dockerignore
/media
/static
db.sqlite3
```

```python
# backend/config/settings/prod.py

import os
from .common import *

# Django
SECRET_KEY = os.environ["SECRET_KEY"]

DEBUG = False

ALLOWED_HOSTS = os.environ.get("ALLOWED_HOSTS", "").split(",")

# CORS
CORS_ALLOWED_ORIGINS = os.environ.get("CORS_ALLOWED_ORIGINS", "").split(",")


# DRF
REST_FRAMEWORK["DEFAULT_RENDERER_CLASSES"] = [
    "rest_framework.renderers.JSONRenderer",
]

# Static & Media : AWS S3
STATICFILES_STORAGE = "config.storages.S3StaticStorage"
DEFAULT_FILE_STORAGE = "config.storages.S3MediaStorage"
AWS_ACCESS_KEY_ID = os.environ["AWS_ACCESS_KEY_ID"]
AWS_SECRET_ACCESS_KEY = os.environ["AWS_SECRET_ACCESS_KEY"]
AWS_S3_REGION_NAME = os.environ["AWS_S3_REGION_NAME"]  # ap-northeast-2 버킷 리전
AWS_STORAGE_BUCKET_NAME = os.environ["AWS_STORAGE_BUCKET_NAME"]  # 버킷이름
AWS_S3_CUSTOM_DOMAIN = (
    f"{AWS_STORAGE_BUCKET_NAME}.s3.{AWS_S3_REGION_NAME}.amazonaws.com"  # 버킷에 대한 URL 도메인
)
AWS_DEFAULT_ACL = os.environ["AWS_DEFAULT_ACL"]  # "public-read" 버켓에 대한 엑세스 권한

# Database : default : postgredb
DATABASES = {
    "default": {
        "ENGINE": os.environ.get("DB_ENGINE", "django.db.backends.postgresql"),
        "HOST": os.environ["DB_HOST"],
        "PORT": os.environ["DB_PORT"],
        "NAME": os.environ["DB_NAME"],
        "USER": os.environ["DB_USER"],
        "PASSWORD": os.environ["DB_PASSWORD"],
    }
}


# Logging
LOGGING = {
    "version": 1,
    "disable_exiting_loggers": False,
    "handlers": {"console": {"level": "ERROR", "class": "logging.StreamHandler",},},
    "loggers": {"django": {"handlers": ["console"], "level": "ERROR",},},
}
```

[DB 셋업하기↓](#postgresql-db와-연동하고-docker를-통해-마이그레이션-수행하기)

**Azure에서 기본적으로 PostgreSQL DB 만들 때 DB_NAME의 기본값은 postgres이고 이는 수정이 가능하다.**

1. `$ docker build -t amamov/myapp:1.0.0 .`

2. Container 실행

```shell
$ docker run --rm --publish 9000:80 \
    -e SECRET_KEY="" \
    -e ALLOWED_HOSTS="" \
     -e CORS_ALLOWED_ORIGINS="" \
    -e AWS_ACCESS_KEY_ID="" \
    -e AWS_SECRET_ACCESS_KEY="" \
    -e AWS_S3_REGION_NAME="" \
    -e AWS_STORAGE_BUCKET_NAME="" \
    -e AWS_DEFAULT_ACL="" \
    -e DB_NAME= \
    -e DB_USER= \
    -e DB_PASSWORD= \
    -e DB_HOST= \
    -e DB_PORT= \
    -it amamov/myapp:1.0.0 sh
```

3. 수행할 명령어

```shell
$ python3 manage.py collectstatic --settings=config.settings.prod
$ python3 manage.py migrate --settings=config.settings.prod
$ python3 manage.py createsuperuser --settings=config.settings.prod
```

### 천천히 음미하기

현재 프로젝트구조가 다음과 같다고 하자.

- `my-project`

  - `backend`
    - `config`
    - `manage.py`
    - `app1`
    - `app2`
    - `requirements.txt`
    - `Dockerfile`
    - `.dockerignore`
  - `frontend`

```Dockerfile
# backend/Dockerfile

FROM ubuntu:18.04

RUN apt-get update && apt-get install -y python3-pip && apt-get clean

WORKDIR /djangoproject
ADD . /djangoproject
RUN pip3 install -r requirements.txt

# ENV PYTHONUNBUFFERED=1 환경변수 설정을 하면 파이썬 표준 출력 과정에서 버퍼링을 하지 않고 바로 출력할 수 있다.
ENV PYTHONUNBUFFERED=1

## docker run 할 때 -e으로 환경 변수 설정을 해준다.
# ENV AZURE_ACCOUNT_NAME=
# ENV AZURE_ACCOUNT_KEY=

EXPOSE 80
CMD ["python3", "manage.py", "runserver", "0.0.0.0:8000"]
```

```Dockerfile
# backend/.dockerignore

/media
/static
db.sqlite3
```

이 상태에서 `$ docker build -t amamov_dj .` 명령으로 빌드해준다. (`amamov/app:1.0.0`처럼 바로 tag해도 된다.)

빌드 후에 다음 명령으로 환경 변수를 설정하여 로컬에서 서버를 열 수 있다.

```shell
docker run --rm --publish 9000:8000 \
    -e DJANGO_SETTINGS_MODULE=config.settings.prod  \
    -e AZURE_ACCOUNT_NAME=amamov \
    -e AZURE_ACCOUNT_KEY="1f9pfWaKKin7cnC4OeUye5SxaqwUn911j2SjG+qdYubOyg==" \
    -it amamov_dj
```

<br>

이제 python3이 아닌 gunicorn을 사용하여 서버를 열어보자.

`requirements.txt`에 gunicorn을 추가한다.

```Dockerfile
# backend/Dockerfile

FROM ubuntu:18.04

RUN apt-get update && apt-get install -y python3-pip && apt-get clean

WORKDIR /djangoproject
ADD . /djangoproject
RUN pip3 install -r requirements.txt

ENV PYTHONUNBUFFERED=1

EXPOSE 80
CMD ["gunicorn", "config.wsgi:application", "--bind", "0.0.0.0:80"]
```

Dockerfile을 수정하고 다시 빌드한 후 run하면 서버가 열린다.

<br>

---

<br>

## PostgreSQL DB와 연동하고 Docker를 통해 마이그레이션 수행하기

1. [Azure Database for PostgreSQL servers](https://portal.azure.com/)의 DB에서 `Single Server`를 선택하고 리소스 그룹을 선택하고(static, media와 같은 그룹을 선택하면 좋다.) DB 서버를 만든다.

   - `Connection security`에서 `Add current client IP address`를 체크해준다.

2. `psycopg2-binary` 라이브러리를 추가한다.

```python
# backend/prod.txt

-r common.txt

django-storages[azure]
gunicorn
psycopg2-binary
```

3. 설정 파일에 DB 설정을 추가한다.

```python
# backend/config/prod.py

import os
from .common import *

DEBUG = False

ALLOWED_HOSTS = os.environ.get("ALLOWED_HOSTS", "").split(",")

STATICFILES_STORAGE = "config.storages.StaticAzureStorage"
DEFAULT_FILE_STORAGE = "config.storages.MediaAzureStorage"

AZURE_ACCOUNT_NAME = os.environ["AZURE_ACCOUNT_NAME"]
AZURE_ACCOUNT_KEY = os.environ["AZURE_ACCOUNT_KEY"]

DATABASES = { # DB 설정 추가
    "default": {
        "ENGINE": os.environ.get("DB_ENGINE", "django.db.backends.postgresql"),
        "NAME": os.environ.get("DB_NAME", "postgres"),
        "USER": os.environ["DB_USER"], # Admin username
        "HOST": os.environ["DB_HOST"], # Server name
        "PASSWORD": os.environ["DB_PASSWORD"],
    }
}

CORS_ALLOWED_ORIGINS = os.environ.get("CORS_ALLOWED_ORIGINS", "").split(",") # CORS 설정 추가

LOGGING = {
    "version": 1,
    "disable_exiting_loggers": False,
    "handlers": {
        "console": {
            "level": "ERROR",
            "class": "logging.StreamHandler",
        },
    },
    "loggers": {
        "django": {
            "handlers": ["console"],
            "level": "ERROR",
        },
    },
}
```

4. docker로 빌드하고 서버 실행해보기
   `$ docker build -t amamov_dj .` 명령어로 빌드한 후 다음 명령어로 환경변수 설정을 하고 shell을 실행한다.

**Azure에서 기본적으로 PostgreSQL DB 만들 때 DB_NAME의 기본값은 postgres이고 이는 수정이 가능하다.**

```shell
docker run --rm --publish 9000:80 \
    -e DJANGO_SETTINGS_MODULE=config.settings.prod \
    -e AZURE_ACCOUNT_NAME=amamov \
    -e AZURE_ACCOUNT_KEY="1f9pfTYFh78+S1XlYnD1am11j2SjG+qdYubOyg==" \
    -e ALLOWED_HOSTS=localhost \
    -e DB_HOST=amamov.postgres.database.azure.com \
    -e DB_USER=amamov@amamov-todolist-db \
    -e DB_PASSWORD=ss981205@! \
    -e DB_NAME=postgres \
    -e CORS_ALLOWED_ORIGINS="http://localhost:9000" \
    -it amamov/todolist_dj:0.3 sh
```

shell을 실행하고 다음 명령으로 마이그레이션을 한다.

```shell
$ python3 manage.py migrate
$ python3 manage.py createsuperuser
```

이제 다음 명령으로 서버를 구동해보자.

```shell
docker run --rm --publish 9000:80 \
    -e DJANGO_SETTINGS_MODULE=config.settings.prod \
    -e AZURE_ACCOUNT_NAME=amamov \
    -e AZURE_ACCOUNT_KEY="1f9pfTYFh78+S1XlYnD1am11j2SjG+qdYubOyg==" \
    -e ALLOWED_HOSTS=localhost \
    -e DB_HOST=amamov.postgres.database.azure.com \
    -e DB_USER=amamov@amamov-todolist-db \
    -e DB_PASSWORD=ss981205@! \
    -e DB_NAME=postgres \
    -e CORS_ALLOWED_ORIGINS="http://localhost:9000" \
    amamov/todolist_dj:0.3
```

<br>

---

<br>

## Azure PaaS 서비스에 Dockerizing Django 서비스 배포하기

1. **`$ docker push amamov/instagram_dj:0.1`으로 Docker Hub에 push한다.**

   - `$ docker tag amamov_dj amamov/instagram_dj:0.1`으로 `amamov/instagram_dj:0.1` 이미지를 만들고 push한다.

2. Azure에서 `App Services`서비스를 이용하여 App을 생성한다.

   - `Publish` : `Docker Container` 선택
   - `OS` : `Linux` 선택
   - `Docker` 탭 : `Image source`는 `Docker Hub` 선택, `Image and tag`는 `amamov/instagram_dj` 선택
   - 생성 후 App 설정의 `컨데이너 설정` 탭에서 Docker Container 이미지를 업데이트할 수 있다.

3. 생성한 App에 환경 변수를 설정해준다.

   1. 만들어진 App에 들어가서 설정-`Configuration`(구성) 탭에 들어간다.
   2. `New application setting`을 클릭해서 환경변수를 입력한다.
      - `ALLOWED_HOSTS`에는 App 호스트을 입력하면 된다.(ex. amamov.azurewebsites.net) (`*` : 모든 호스트를 허용)

4. DB에서 App service의 ip를 허용해준다.

   1. `App service`의 `Properties`(속성)의 `Additional Outbound IP Address`를 복사한다.
      - `Virtual IP Adress`보다 안전하다.
   2. 복사한 IP 주소를 `DB Service`(Azure Database for PostgreSQL server) - `Settings` - `Connection security` - `Fire rule name`(방화벽 규칙)에 추가한다. (하나하나 세심하게 지정해야 한다.)
      - 이름은 `AppService01, 02, ..`이런식으로 지장해주고 IP를 하나하나 넣어준다. 시작 IP와 종료 IP는 동일하게 지정해주면 된다.

<br>

---

<br>

## React 프로젝트를 Azure Storage에 배포하기

React를 배포하는 방법엔 여러가지 방법(githubio, netlify 등)이 있다. 이중에 Azure Storage를 사용하여 배포하는 방법을 진행해보자.

1. VS-Code에서 `Azure Storage` Extension을 다운받고 storage account를 생성한다.

   1. `command + shift + a` 단축키로 들어갈 수 있다.
   2. azure 익스텐션에 들어가서 로그인해준다.
   3. **`+`버튼을 누르고 storage account를 만들어준다.**

2. frontend 폴더를 열고 `.env.production`파일을 만들고 실제 빌드할 호스트 환경변수를 설정한다.

   - `REACT_APP_API_HOST="https://amamov-instagram.azurewebsites.net`

3. `$ yarn build`로 프런트엔드 프로젝트를 빌드한다.

   - `$ yarn global add serve`로 로컬에서 서버를 열 수 있는 serve 패키지를 다운받는다.
   - frontend 폴더에서 `$ serve -s build`로 build 폴더를 서빙할 수 있다.

4. VS-Code의 azure 익스텐션에 들어가서 `+`버튼 옆의 배포 버튼(`↑`)을 누르고 build 폴더를 배포한다.
   - Azure에서 `Storage Account`에서 배포된 것을 확인할 수 있다.
