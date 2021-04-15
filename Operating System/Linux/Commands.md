# Linux

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
- [cat](#cat)
- [grep](#grep)
- [nano Editor](#nano-editor)
- [vi Editor](#vi-editor)
- [IO Redirection](#io-redirection)

<br>

---

<br>

## 리눅스 기본 폴더 정리

- `/` : 최상위 디렉토리(루트 디렉토리)

- `/bin` : binary의 약자로 실행파일 모음. 일반적으로 사용하는 mv, cat등 명령어 프로그램들이 있음

- `/boot` : 부팅과 관련된 파일들이 모여있음

- `/dev` : device의 약자로 물리적인 장치들이 파일화 되어 있다.

- `/etc` : 각종 환경 설정 파일들이 모여 있음

- `/home` : 개인사용자들 디렉토리

- `/lib` : 각종 라이브러리 저장 디렉토리

- `/mnt` : CD-ROM, 네트워크 파일 시스템 등을 마운트 할때 사용되는 디렉토리

- `/proc` : 현재 실행되고 있는 프로세스들이 파일화 되어서 저장되는 디렉토리

- `/root` : root계정의 홈 디렉토리

- `/sbin` : System-binary의 약자로, 주로 시스템 관리자가 쓰는 시스템 관련 명령어 프로그램들이 모여있다.

- `/tmp` : 임시 저장 디렉토리. 일반적으로 모든 사용자들에게 열려 있음

- `/usr` : 주로 새로 설치되는 프로그램들이 저장된다. '명령어' 보다는 '프로그램'이라고 부르는게 더 익숙한 놈들이 저장된다. 윈도우의 Program Files같은 폴더

- `/var` : 시스템 로그, 스풀링 파일 들이 저장된다. 메일 서버로 운영될 경우 메일이 여기 저장된다,.

## 리눅스와 파일

- 리눅스는 모든 것은 파일이라는 철학을 따른다. 즉, 모든 인터렉션은 파일을 읽고, 쓰는 것처럼 이루어져 있다.
- 마우스, 키보드와 같은 모든 디바이스 관련된 기술도 파일과 같이 다루어진다.
- 파일 네임스페이스
  - A 드라이브(A:/), C 드라이브 (C:/windows)처럼 사용하지 않고 전역 네임스페이스를 사용한다. 즉, 최상단(root)이 있고 `/media/floofy/me.jpg`로 접근한다.
- 파일은 inode 고유값과 자료구조에 의해 주요 정보를 관리한다.

## 리눅스와 프로세스

- 리눅스 실행 파일 포멧은 `ELF(Executable and Linkable Format)`이다.
  - 콜스택, 코드, 데이터 및 BSS 섹션 등
- 다양한 시스템 리소스와 관련
  - 시스템콜 호출을 통해 리소스 처리 가능하도록 구성
  - 타이머, 시그널, 파일, 네트워크, 디바이스, IPC 기법
- 가상 메모리 지원
- 각 프로세스는 pid(프로세스 ID) 고유값으로 구분한다.
- init 프로세스(첫 번째 프로세스)를 기반으로 fork() 시스템콜을 사용해서, 신규 프로세스가 생성

## 리눅스와 권한

- 운영체제는 사용자/리소스 권한을 관리한다.
- 리눅스는 사용자/그룹으로 권한을 관리한다.
- root는 슈퍼 관리자이다.
- 파일마다 소유자, 소유자 그룹, 모든 사용자에 대해 읽고, 쓰고, 실행하는 권한을 관리한다.

<br>

---

<br>

## Kernel

Management the Memory, File System, CPU, Device, etc

### Lunux Shell typed

- **bash** (Bourne-agin shell) : Super shell in linux
  - GNU 프로젝트의 일환으로 개발됨, 리눅스에서 거의 디폴트
- **sh** (Bourne shell) : By Unix Shell, Super shell
- **csh** (C shell) : C like syntax
- **tcsh** (Enhanced-C shell)
- **ksh** (Korn shell) : By David Korn, Powerful Script Language
- **zch** (Z shell) : Unix/GNU shell script, Powerful Script Language

### Linux File System Directories

- `/bin` : 기본 명령어
- `/boot` : for booting
- `/dev` : device file, cd-rom
- `/etc` : config, passwd, rc.d
- `/home` : user home dir
- `/lib` : shared library
- `/media` : ssd
- `/opt` : application software package
- `/proc` : process info
- `/root` : root home dir
- `/sbin` : 관리자용, ifconfig
- `/srv` : system data
- `/tmp` : temporary dir
- `/usr` : source or programs
- `/usr/local`
- `/var` : logs, ftp, spool, mail
- `/lost+found`

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

### cat

리눅스(Linux)에서 cat 명령은 다양하게 활용된다. 파일의 내용을 간단하게 출력할 때도 사용하지만, 두 개 이상의 파일을 연결(concatenate)해서 출력할 때 사용하는 것이 기본이다. 보통 리다이렉션 기호와 함께 사용하여 파일을 생성(standard input)하거나 병합을 할 때도 사용됩니다.

### grep

grep은 입력으로 전달된 파일의 내용에서 특정 문자열을 찾고자할 때 사용하는 명령어이다.

- `$ grep Django test.txt`

- `$ ls --help | grep sort`

<br>

---

<br>

## nano Editor

- `control + shift + 6` : 텍스트 긁기

## vi Editor

<br>

---

<br>

## IO Redirection

UNIX Process는 하나의 standard input과 standard output, standard error가 있다. (IO Stream)

### output

특정 폴더 안으로 들어가서 `$ ls -l > result.txt` 명령어를 수행하면 `result.txt`에 `ls -l`에 대한 결과들을 저장한다. 즉, `ls -l`로 콘솔에 출력하는 것이 아니라 `result.txt`에 redirection한다. 다시 말해, `>`는 `1>`와 같고 standard output을 redirection한다.

`$ cat result.txt`로 `result.txt` 내용을 확인해보자.

만약에 standard output을 redirection하는 것이 목적이 아닌 **standard error를 redirection하고자 한다면** 어떻게 해야 할까ㄴ?

`2>`를 사용하면 된다. 현재 폴더에 `nothing.txt` 파일이 없다고 하자. 즉, `$ rm nothing.txt`는 에러가 출력이 될 것이다. 이 에러 메세지를 redirection하고자 한다면 `$ rm nothing.txt 2> error.txt` 명령어로 `error.txt` 파일에 redirection(방향을 바꾸어 저장)하면 된다.

`$ cat error.txt`로 `error.txt` 내용을 확인해보자.

`$ rm hello.txt 1> result.txt 2> error.log` 명령어를 해석해 보자면 `hello.txt` 파일을 삭제하는데에 있어서 standard output이 있다면 `result.txt`에 redirection하고 standard error가 있다면 `error.log`에 redirection한다.

## input

`$ cat` 명령어를 수행하고 문자열을 입력하면 해당 문자열이 출력된다.

hello world라는 텍스트가 적혀있는 `hello.txt` 파일의 내용을 보고 싶다고 하자. `$ cat < hello.txt` 명령을 사용하면 되는데, `$ cat < hello.txt`명령어의 의미는 `hello.txt` 내용을 `cat`에 입력한뒤에 출력을 하는 명령이다.
