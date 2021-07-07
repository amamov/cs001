#include "scv.h"

// 비즈니스 로직

inline int SCV::scvCount = 0;
inline void SCV::printSCVCount() {
    cout << "SCV 객체 수 : " << scvCount << endl;
}
inline SCV::~SCV() {
    scvCount--;
    cout << "객체가 소멸합니다." << endl;
}
inline SCV::SCV() : hp(60), attackRate(5) {
    scvCount++;
    cout << "SCV good to go sir!" << endl;
}
inline SCV::SCV(string voiceKor) : hp(60), attackRate(5) {
    scvCount++;
    cout << voiceKor << endl;
}
inline SCV::SCV(const SCV &s) : hp(s.hp), attackRate(s.attackRate) {
    scvCount++;
    cout << "SCV good to go sir!" << endl;
    cout << "복사 생성자 할당됨!" << endl;
}
inline int SCV::getHp() {
    return hp;
}
inline void SCV::setHp(int value) {
    hp = value;
}
inline int SCV::getAttackRate() {
    return attackRate;
}
inline void SCV::setAttackRate(int value) {
    attackRate = value;
}
