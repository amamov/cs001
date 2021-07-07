#include <iostream>

using namespace std;

//* class에서는 구조체와는 다르게 디폴트로 private 캡슐화가 적용이 된다.

class SCV {
   private:
    int hp;  // 캡슐화

   public:
    // int getHp() //* inline member function **
    // {
    //     return hp;
    // }
    int getHp();
    void setHp(int value);
};

//* inline 함수이면 스택을 사용하지 않고 컴파일 단계에서 끼워 넣는다.
inline int SCV::getHp()  //* definition of behaviour (inline o) -> **와 같이 안에 쓴 것과 동일한 상태이다.
{
    // explicit inline function이라고 한다
    return hp;
}

inline void SCV::setHp(int value)  //* definition of behaviour (inline o)
{
    // explicit inline function이라고 한다
    hp = value;
}

int main() {
    SCV s1;
    s1.setHp(60);

    cout << s1.getHp() << endl;  // 60

    return 0;
}

/*
inline void func() 
{
    cout << "hello world";
}

int main()
{
    func();
    return 0;
}

위의 코드는 아래의 컴파일 단계에서 아래의 코드로 변환된다. (스택 메모리를 사용하지 않는다. (호출하지 않는다.))
코드가 짧고 자주 참조하는 함수의 경우 굳이 스택 메모리를 사용하지 않고 오버헤드를 감소하기 위해 인라인 기법을 사용한다.
하지만 코드가 길고 복잡한 경우에는 컴파일 단계에서 변환하므로 오히려 오버헤드가 발생하므로 좋은 선택은 아니다.
최신 컴파일러 중에 인라인 함수의 코드가 매우 길고 복잡하다고 판단되면 자동으로 스택을 사용하도록 구현해준다. 또 코드가 짧고 인라인으로 처리할 필요가 있다고 생각한다면 인라인으로 처리를 자동으로 처리해준다.

int main()
{
    cout << "hello world";
    return 0;
}

*/