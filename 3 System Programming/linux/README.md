# Linux

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

## Kernel

Management the Memory, File System, CPU, Device, etc

## Linux Shell

Manipulate Linux Kernel

### Lunux Shell typed

- **bash** (Bourne-agin shell) : Super shell in linux
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
