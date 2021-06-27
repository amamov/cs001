#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int value;
    int unsignedInt = 0xffffffff;
    cout << "Endter thr third number in hex : ";

    cin >> hex >> value; // ffffffff -> 1111 1111 1111 1111 1111 1111 1111 1111(2)

    cout << "oct signed value : " << oct << value << endl;         // 17777777777 -> 11|11 1|111 |111|1 11|11 1|111 |111|1 11|11 1|111(2) (부호비트는 빼서 계산하기 때문에)
    cout << "dec signed value : " << dec << value << endl;         // 2147483647 (-1이 나오는 것이 맞지만 자리가 꽉 차서 cout이 그냥 딱 max 값까지만 표현한 것이다.)
    cout << "oct unsigned value : " << oct << unsignedInt << endl; // 37777777777 -> 11|11 1|111 |111|1 11|11 1|111 |111|1 11|11 1|111(2)
    cout << "dec unsigned value : " << dec << unsignedInt << endl; // -1

    cout << numeric_limits<int>::max() << endl;          // 2147483647
    cout << numeric_limits<int>::min() << endl;          // -2147483648
    cout << numeric_limits<unsigned int>::max() << endl; // 4294967295
    cout << numeric_limits<unsigned int>::min() << endl; // 0

    return 0;
}