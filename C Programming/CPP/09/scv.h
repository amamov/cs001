// #include "scv.h" 를 두 번 쓰는 걸 방지하기 위해 아래와 같이 ifndef, define 등 키워드를 사용하면 된다.
#ifndef SCV_H
#define SCV_H

#include <iostream>

using namespace std;

// 설계도

class SCV {
   private:
    int hp;
    int attackRate;

   public:
    //* constructor
    SCV();
    SCV(string voiceKor);
    SCV(const SCV &s);

    //* destructor
    ~SCV();

    //* getter & setter
    int getHp();
    void setHp(int value);
    int getAttackRate();
    void setAttackRate(int value);

    //* static fields & static method
    static int scvCount;
    static void printSCVCount();
};

#endif
