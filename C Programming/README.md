# c++ and oop 

- [c++ docs](https://en.cppreference.com/w/)
- [c++ reference](https://www.cplusplus.com/reference/)
- [c++ ms docs](https://docs.microsoft.com/ko-kr/cpp/cpp/?view=msvc-160)
- [c++ 최신 동향](https://www.jetbrains.com/ko-kr/lp/devecosystem-2020/cpp/)

## Mac 에서 C / C++ 개발 환경 구축 (Xcode)

### 1. 앱 스토어에서 Xcode를 설치한다.

### 2. Xcode를 실행한 후, "⌘ ⇧ n"으로 새 프로젝트를 만든다.

`macOS` -> `Command Line Tool` -> `language C++ 선택`

### Xcode 단축키 정리

- `⌘ + 또는 ⌘ -` : 창 화면을 키우거나 줄일 수 있다.

- `⌘ 0` : 왼쪽 사이드바 열고 닫기

- `⌘ ⌥ 0` : 오른쪽 사이드바 열고 닫기

- `⌘ ⇧ y` : 아래 사이드바 열고 닫기

- `⌘ r` : 실행

- `⌘ b` : 디버그(빌드)

- `⌃ i` : 들여쓰기 포메팅

<br>

---

## Mac 에서 C / C++ 개발 환경 구축 (VS Code)

### 1. VS-Code 설치

    - brew를 사용하여 VS-Code를 설치한다.
    - $ brew cask install visual-studio-code

### 2. g++, lldb 설치

    - Xcode를 설치한다. (앱스토어) -> Xcode를 설치하면 자동으로 설치된다.
    - `$ g++ -v` (`$ gcc -v`) 으로 설치된 g++의 버전정보를 알 수 있다.
    - lldb란 Xcode에 기본으로 내장되어 있는 소프트웨어 디버거이다.
    - `$ lldb` 으로 디버거를 실행할 수 있다.
    - `$ vi hello.cpp` -> `$ g++ hello.cpp -o hello` -> `$ ./hello`

### 3. VS-Code Extension 설치

    - VS-Code를 열고 `command + shift + x`를 눌러서 c/c++(microsoft)와 CodeLLDB를 각각 검색하고 설치한다.
    - CodeLLDB는 VS-Code에서 lldb를 사용해 디버깅 할 수 있는 확장 툴이다.

### 4. tasks.json 파일 수정

    - test 폴더 안에 hello.cpp 파일을 만들고 다음을 작성한다.

```cpp
#include  <iostream>
using  namespace std;

int  main()
{
cout <<  "hello world!"  << endl;
return  0;
}
```

    - VS Code에서 "fn + F5"를 눌러서 "C++(GDB/LLDB)"환경에서 "g++ 활성 파일 빌드 및 디버그"를 실행하면 ".vscode"폴더 안에 "tasks.json"파일이 생성된걸 확인할 수 있다. (만약 없다면 .vscode 폴더 안에 tasks.json 파일을 생성한다.)
    - "tasks.json"를 아래와 같이 수정한다.

```js
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "C/C++: g++ build active file",
      "command": "/usr/bin/g++",
      "args": [
        "-g", // 디버깅을 위한 옵션
        "-std=c++17",
        "-stdlib=libc++",
        "${file}", // 현재 파일을 의미
        "-o", // 출력 파일의 이름을 정의해줄때 사용
        "${fileDirname}/${fileBasenameNoExtension}.out",

        // 1. execute .out file
        "&&", //to join building and running of the file
        "${fileDirname}/${fileBasenameNoExtension}.out"

        // 파일 입출력을 하고 싶을 때 주석 비활성화
        //2. file input
        //"<",
        //"${fileDirname}/input.txt",

        //3. file output
        //">",
        //"${fileDirname}/output.txt"
      ],
      "options": {
        "cwd": "${workspaceFolder}" // cwd : 현재 작업 공간
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    },

    //실행 파일 추가
    {
      "label": "exec",
      "type": "shell",
      "command": "${fileDirname}/${fileBasenameNoExtension}.out",
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

### 5. launch.json 파일 수정

    - ".vscode"폴더 안의 "launch.json"파일을 아래와 같이 수정한다.

```js
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Launch",
      "type": "lldb",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}.out",
      "args": [],
      "preLaunchTask": "C/C++: g++ build active file",
      "stdio": [null, null, null],
      "terminal": "integrated"
    },
    {
      "name": "g++ - Build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}.out",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": true,
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: g++ build active file"
    }
  ]
}
```
