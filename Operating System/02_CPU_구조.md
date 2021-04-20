# CPU 구조

![img](https://upload.wikimedia.org/wikipedia/commons/d/d8/ABasicComputer.gif)

- **ALU (산술연산 장치)**

  - 각종 산술 연산들과 논리 연산들을 수행하는 회로들로 이루어진 하드웨어 모듈
  - 산술 연산 : +, -, x, /
  - 논리 연산 : AND, OR, NOT, XOR 등

- **Control Unit (제어 유닛)**

  - 프로그램 코드(명령어)를 해석하고, 그것을 실행하기 위한 제어 신호들을 순차적으로 발생하는 하드웨어 모듈
  - RS간 정보 전송 감시
  - ALU에게 수행할 동작을 지시

- **Register Set**

  - 필요한 데이터를 임시로 보관하는 곳
  - 엑세스 속도가 가장 빠른 기억 장치

---

## Register

> CPU는 필요한 데이터를 메모리에서 가져와 RS에 저장하고 ALU를 이용하여 연산을 한 후, 그 결과를 다시 RS에 저장했다가 메모리로 옮긴다.

### User-Visible Register

사용자 프로그램에 의해 변경되는 RS

#### DR (Data Register)

메모리에서 가져온 데이터를 임시로 보관할 때 사용한다.

CPU에 있는 대부분의 RS가 DR이기 때문에 일반 레지스터 또는 범용 레지스터라고 부른다.

#### AR (Address Register)

데이터 또는 명령어가 저장된 메모리의 주소

### User-Invisible Register

사용자가 임의로 변경할 수 없는 RS

#### PC (Program Counter)

다음에 실행할 명령어의 주소를 기억하고 있다가 Control Unit에게 알려준다.

#### IR (Instruction Register)

**현재 실행중인 명령어를 저장한다.** Control Unit은 IR에 있는 명령을 해석한 후 외부 장치에 적절한 제어 신호를 보낸다.

#### MAR (Memory Address Register)

PC에 저장된 명령어 주소가 시스템 주소 버스로 출력되기 전에 일시적으로 저장되는 주소 레지스터

#### MBR (Memory Buffer Register)

기억장치에 쓰여질 데이터 혹은 기억장치로부터 읽혀진 데이터를 일시적으로 저장한다.

#### AC (Accumulator)

연산 결과 데이터를 일시적으로 자장하는 레지스터

---

## Control Unit 구현 방식

### Hard Wired 방식 (H/W 방식, 고정배선방식)

RISC와 같이 프로그램 방식이 아닌 H/W적으로 고정된 구현방식으로 빠른 성능과 설계가 간단하다는 장점이 있는 반면 상태수 증가 시 복잡해 지고 수정이 어려우며 가격 측면에서 S/W 방식보다 비싸다는 단점이 있다.

### Micro Program 방식 (S/W 방식)

Hard Wired 방식에 비해 유연(수정, 변경이 쉬움)하게 제어할 수 있으며 H/W 구조가 Hard Wired 방식에 비해 간단하다. 하지만 H/W 방식에 비해 성능이슈가 발생한다.

---

## ALU

![img](https://upload.wikimedia.org/wikipedia/commons/0/0f/ALU_block.gif)

---

## 명령어 Set

> CPU에 의해 실행 가능하도록 연산 종류, 데이터 형태, 명령어 형식, 주소 지정 방식을 정의하여 실행가능하게 하는 명령어들의 집합

### 연산의 종류

- 데이터 전송

  - RS와 RS 간, RS와 기억장치 간, 혹은 기억장치와 기억장치 간에 데이터를 이동하는 동작

- 산술 연산

  - 덧셈, 뺄셈, 곱셈 및 나눗셈과 같은 기본적인 산술 연산들

- 논리 연산

  - 데이터의 각 비트들 간의 데이터 이동을 위한 동작들

- 입출력 (I/O)

  - CPU와 외부 장치들 간의 데이터 이동을 위한 동작들

- 프로그램 제어

  - 명령어 실행 순서를 변경하는 연산들
  - 분기 (branch), 서브루틴 호출(Subroutine call)

### Addressing Mode (주소지정방식)

> 명령어 실행에 필요한 오퍼랜드의 주소를 결정하는 방식

**_EA (유효주소) : 데이터가 저장된 기억장치의 실제 주소_**

#### Memory Direct Addressing (직접 주소지정방식)

오퍼랜드 필드의 내용이 EA가 되는 방식

- 데이터 인출(fetch)을 위하여 한 번의 기억장치 엑세스만 필요
- 직접 지정할 수 있는 기억장소의 수가 제한된다.

#### Memory Indirect Addressing (간접 주소지정방식)

오퍼랜드 필드에 EA의 주소를 저장하는 방식 (EA의 주소는 기억장치에 있다.)

- 엑세스 되어지는 메모리의 범위가 명령어 형식의 오퍼랜드 필드의 길이에 제한을 받지 않고 확장이 가능하다.

- 실행 사이클동안에 두 번의 기억장치 엑세스가 필요하다. (느리다.)

#### Register Addressing (레지스터 주소지정방식)

연산에 사용될 데이터가 내부 레지스터에 저장되어 있는 경우, 오퍼랜드가 해당 레지스터를 가리키는 방식

- 데이터가 저장될 수 있는 공간이 CPU 내부 레지스터들로 제한

#### Register Indirect Addressing (레지스터 간접 주소 지정 방식)

오퍼랜드 필드가 가리키는 레지스터의 내용을 유효 주소로 사용하여 실제 데이터를 인출하는 방식

- 주소지정을 할 수 있는 기억장치 영역이 확장
- 구현이 상대적으로 어렵고 비용이 상승한다.

#### Displacement Addressing

- Indexed Addressing

#### Immediate Addressing

데이터가 명령어에 포함되어 있는 방식

- 데이터를 인출하게 위하여 기억장치를 액세스할 필요가 없다.

- 상수값의 크기가 오퍼랜드 필드의 비트 수에 의해 제한된다.

---

## 명령어 처리 과정

> [CPU 명령어 수행 BLOG](https://velog.io/@ckstn0777/%EC%BB%B4%ED%93%A8%ED%84%B0%EA%B5%AC%EC%A1%B0-9htxi9jo)

## 명령어 파이프라이닝
