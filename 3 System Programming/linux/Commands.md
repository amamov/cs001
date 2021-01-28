# 리눅스 명령어 정리

- [apt-get](#apt-get)
- [ls](#ls)
- [pwd](#pwd)
- [mkdir](#mkdir)
- [touch](#touch)
- [cd](#cd)
- [rm](#rm)
- [--help](#--help)
- [man](#man)
- [sudo](#sudo)
- [wget](#wget)
- [nano Editor](#nano-editor)
- [vi Editor](#vi-editor)

<br>

---

<br>

## 기본 명령어 정리 (쉘 : bash)

### apt-get

apt-get(Advanced Packaging Tool)은 우분투(Ubuntu)를 포함안 데비안(Debian)계열의 리눅스에서 쓰이는 패키지 관리 명령어 도구이다. (yum 또한 패키지 관리 명령어 도구이다.)

- `$ sudo apt-get update`

  - 패키지 인덱스 인덱스 정보를 업데이트
  - apt-get은 인덱스를 가지고 있는데 이 인덱스는 /etc/apt/sources.list에 있다. 이곳에 저장된 저장소에서 사용할 패키지의 정보를 얻는다.

- `$ sudo apt-get upgrade`

  - 설치된 패키지 업그레이드

- `$ sudo apt-get install 패키지이름`

  - 패키지 설치

- `$ apt-get --reinstall install 패키지이름`

  - 패키지 재설치

- `$ sudo apt-get remove 패키지이름`

  - 패키지 삭제 (설정 파일을 지우지 않는다.)

- `$ sudo apt-get --purge remove 패키지이름`

  - 패키지 삭제 (설정 파일까지 모두 지운다.)

- `$ sudo apt-cache search 패키지이름`

  - 패키지 검색

- `$ sudo apt-cache show 패키지이름`

  - 패키지 정보 보기

- `$ apt list`
  - 패키지 목록 조회

### top

리눅스의 작업관리자

`apt-get install htop`으로 조금 더 좋은 작업관리자를 다운 받아서 사용할 수 있다.

### ls

현재 디렉토리의 파일 목록을 출력한다.

- `-a` : 숨긴 파일까지 모두 출력한다.
- `-l` : 자세히 출력한다.
- `-al` : `-l` + `-a`

### pwd

현재 위치하고 있는 디렉토리를 알려주는 명령어

### mkdir

폴더를 생성한다.

- `mkdir -p dir1/dir2/dir3` : dir1/dir2/dir3 폴더를 만든다. 즉 `-p` 옵션은 필요할 경우 부모 디렉토리를 생성하고 최종 자식 디렉토리를 생성한다.

### touch

파일을 생성한다.

### cd

해당 디렉토리로 이동한다.

- `cd ..` : 부모 디렉토리로 이동한다.
- `cd ./testdir` : 현재 경로에서 testdir 폴더로 이동한다.
- `cd /home/testdir` : 최상위 디렉토리에서 이동한다. (절대 경로)

### rm

대상체를 삭제한다.

- `-rf` : 묻지도 따지지도 말고 삭제한다.

### cp

파일, 폴더를 복사하고 붙여넣기 한다.

- `cp hello.py /home/hello.py` : hello.py 파일을 /home/hello.py로 복사한다.

### mv

파일, 폴더를 잘라내고 붙여넣기 한다. (파일의 이름을 바꿀 때도 사용한다.)

### --help

명령어 뒤에 `--help`를 붙이면 명령의 사용 설명서가 출력된다.

### man

명령어에 대한 자세한 사용 설명서를 제공한다.

- `man ls`

### sudo

sudo 명령어는 유닉스 및 유닉스 계열 운영 체제에서, 다른 사용자의 보안 권한, 보통 슈퍼유저로서 프로그램을 구동할 수 있도록 하는 프로그램이다

- `apt-get install sudo` : sudo 다운

### wget

`apt-get install wget`

wget 명령어는 URL을 매개하여 파일을 다운받는다.

`$ wget img_20200403c3.webp`

<br>

---

<br>

## nano Editor

- `control + shift + 6` : 텍스트 긁기

## vi Editor

pass
