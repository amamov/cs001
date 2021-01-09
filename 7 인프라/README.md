## 인프라 관리

[관련 문서](https://docs.microsoft.com/ko-kr/learn/paths/administer-containers-in-azure/)

## Docker

- Docker는 앱과 그 실행환경/OS를 모두 포함한 소프트웨어 패키지(Docker Image)를 만들어주는 프로그램입니다.

- Docker는 플랫폼에 상관없이 실행될 수 있는 애플리케이션 컨테이너를 만들어줍니다.

  - 윈도우에서 exe 파일을 바로 실행하듯이, Docker를 지원하는 플랫폼에서 Docker Image를 받아서 즉시 실행할 수 있습니다.

- Docker Image는 Container의 형태로 Docker Engine이 있는 어디에서나 실행이 가능합니다.

  - 대상 : 로컬 머신 (윈도우/맥/리눅스), Azure, AWS 등
  - 하나의 Docker Image를 통해 다수의 Container를 생성할 수 있습니다.
  - `nginx`, `nginx:1.17.9`, `python:3.9.0a4-buster` 등 다양한 도커 Image들이 있습니다.
  - docker image name은 `repository:tag` 형식입니다. 여기서 repository는 hostname/accountname/name 구조입니다.
    - `name`으로 쓸 경우 : Docker Hub에 공개된 공식 Image (ex. `nginx`)
    - `accountname/name`으로 쓸 경우 : Docker Hub에 공개된 일반 유저의 Image (ex. `amamov/nginx`)
    - `hostname/accountname/name`으로 쓸 경우 : 다른 Docker Registory에 공개된 Image
    - tag는 Docker Image의 버전을 지정하는 용도로 사용합니다.

- 어떤 추가적인 소프트웨어 없이 Docker Image만 pull해서 바로 run할 수 있습니다.

- Docker 컨테이너는 **하나의 Forefround 프로세스**를 구동하는 것이 원칙입니다.
- Docker는 리눅스의 chroot 기반의 기술입니다.

## Docker Registry

- Docker Registry는 Docker Image 저장소를 의미합니다.
- 공식 저장소로서 Docker Hub (Docker계의 Github)가 있습니다. 이 외에도 각 클라우드 벤더에서 저장소를 지원해줍니다.
  - Azure Container Registry
  - AWS Elastic Container Registry
  - Google Container Registry
