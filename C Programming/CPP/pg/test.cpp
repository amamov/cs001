#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// 학번 : 12181878
// 성명 : 윤상석
void dice()
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand();
    int result = number % 6 + 1;
    cout << setw(6) << result << " ";
}

int main()
{

    dice();

    return 0;
}