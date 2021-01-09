# 👻 git study 👻

- [Git 설치하기](#git-설치하기)
- [Github에 코드 저장하기](#github에-코드-저장하기)
- [Git으로 수정사항 reset하기](#git으로-수정사항-reset하기)

<br>

---

<br>

# Git 설치하기

## Git install (Window)

1. [Window Git 설치](https://git-scm.com)

2. "**git bash**"를 데스크탑 검색한 후 실행한다.

## Git install (mac)

1. 현재 git version을 확인한다.
   - `$ git --version`
2. Homebrew (Mac OS 패키지 관리자)를 설치한다. [링크](https://brew.sh/index_ko)
3. Homebrew를 이용하여 git을 설치한다.

   - `$ brew install git`

4. 설치된 git 정보 확인

   - `$ brew info git`
     여기서 Dependencies에서 Optiona의 pcre가 (x)로 되어 있다면 pcre도 설치해준다.
     (`$ brew install pcre`)

5. 설치 후 전과 동일한 버전 정보가 나온 경우 다음을 명령한다.

   - `echo "export PATH=/usr/local/bin:\$PATH" >> ~/.bash_profile`

## 기본적인 터미널 명령어 정리

```python
$ cd ./myFolder   # 현재 폴더 안의 myFolder로 들어간다. ("./"는 생략할 수 있다.)

$ cd ../   # 현재 폴더의 부모 폴더로 이동한다.

$ pwd  # 현재 어디 디렉토리에 있는지 경로를 표시한다.

$ ls   # 현재 디렉토리 안에 있는 파일 목록들을 보여준다.

$ tree   # 현재 디렉토리 안에 있는 tree구조를 보여준다.
# brew install tree로 설치해줘야 한다.

$ mkdir myFolder   # myFolder 폴더를 현재 경로에 생성한다.

$ touch myFile.html   # myFile.html을 현재 경로에 생성한다.

$ rm -rf myFolder   # myFolder를 묻지도 따지지도 않고 다 지우기.

$ rm -i myFolder   # 파일 하나하나 물어보고 다 지우기.

$ alias 단축명령어="명령어"
```

<br>

## git 설정 (git config)

1. `$ git config --global --list`

- git에 대한 설정을 볼 수 있다.(전역으로)
- `$ git config --list` 으로 저장소별로 설정을 조회할 수 있다.

2. `$ git config --global user.name github-username`

- git user name 설정 (--global의 의미는 해당 디렉터리뿐만 아니라 전체 모든 디렉터리에 적용된다는 의미이다.)
- ex) `$ git config --global user.name amamov`

3. `$ git config --global user.email github-email`

- git email 설정
- ex) `$ git config --global user.email ysangsuk78@gmail.com`

---

<br>

# github에 코드 저장하기

## git 서버 저장소(원격 저장소) 만들기

1. github에 접속하여 Repositories에 들어가서 New 버튼을 누른다.

2. Repository를 만들어준다.

---

<br>

## git 로컬 저장소 만들기

1. `git bash (Window OS)` 또는 터미널(Mac OS)를 실행하고 작업 디렉터리로 들어간다.

```
$ cd work-dir
```

2. git을 초기화한다.

```
$ git init
```

3. git local 작업 디렉터리의 모든 변경 사항들을 staging area로 이동시킨다.

```
$ git add .
```

4. git local 작업 디렉터리의 특정 파일 또는 폴더의 변경 사항들을 staging area로 이동시킨다.

```
$ git add filename(or dirname)
```

5. git staging area에 있는 변경 사항들을 repository로 이동시킨다.
   - 짧은 commit message로 commit 하는 경우 : `$ git commit -m "commit message"`
   - 길고 자세한 commit message로 commit 하는 경우 : `$ git commit`으로 작성 창으로 넘어간 후 자세히 작성
   - `$ git commit -am "commit message"` : add와 commit을 동시에 한다. (한번이라도 commit을 했던 파일에 대해서만 사용할 수 있다.)

```
$ git commit -m "first commit"
```

6. main branch를 생성한다.

```
$ git branch -M main
```

---

## git 서버 저장소(원격 저장소)와 로컬 저장소 연결 & Push & Pull

1. 서버 저장소와 로컬 저장소의 통로를 만든다.

```
$ git remote add origin https://github.com/amamov/git-study.git
```

2. 로컬 저장소의 repository를 서버의 origin main의 repository에 올린다.
   - `$ git push -fu origin main` 명령어는 로컬 저장소의 repository를 서버의 origin main의 repository에 강제로 올린다. (서버 저장소 파일들은 사라진다.)

```
$ git push -u origin main
```

4. 서버 저장소의 repository를 로컬 저장소에 가져온다.

```
$ git pull
```

<br>

## git 서버 저장소에 있는 Repository를 로컬 저장소에 저장하기

```
$ git clone https://github.com/amamov/git-study.git
```

<br>

---

<br>

# Git으로 수정사항 reset하기

repository에 올린 상태에서 `$ git reset`으로 되돌릴 수 있다.

|           어디까지 되돌릴까?            |     옵션      |
| :-------------------------------------: | :-----------: |
| 작업 디렉터리가 수정하기 전으로 바뀐다. | --hard HEAD^  |
|     add하기 전 상황으로 되돌아간다.     | --mixed HEAD^ |
|      commit한 것 까지만 취소한다.       | --sort HEAD^  |

- HEAD : 가장 최근 버전에서
- ^ : 하나 되돌리기

만약 가장 최근 커밋으로부터 세 개 전으로 되돌리려면 `$ git reset --hard HEAD^^^`를 사용하면 된다.

<br>

---

<br>
