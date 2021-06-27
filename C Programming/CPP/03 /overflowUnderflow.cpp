#include <iostream>
#include <limits>
using namespace std;

int main()
{
    //* [limits]
    unsigned short y = numeric_limits<unsigned short>::max();
    cout << y << endl;

    unsigned short unsignedShort = 100;
    cout << "unsignedShort size : " << sizeof(unsignedShort) << endl;                  // 2 byte
    cout << "unsignedShort limit : " << numeric_limits<unsigned short>::max() << endl; // 65535

    unsignedShort = 65535;                                     //* BIN  1111 1111 1111 1111
    cout << "unsignedShort 65535 : " << unsignedShort << endl; // 65535

    //* [overflow]
    unsignedShort = 65536;                                     //* BIN 0001 0000 0000 0000 0000
    cout << "unsignedShort 65536 : " << unsignedShort << endl; // 0

    //* [underflow]
    unsignedShort = -1;                                     //* BIN  1111 1111 1111 1111
    cout << "unsignedShort -1 : " << unsignedShort << endl; // 65535
    unsignedShort = -2;                                     //* BIN  1111 1111 1111 1110
    cout << "unsignedShort -2 : " << unsignedShort << endl; // 65534
    unsignedShort = -4;                                     //* BIN  1111 1111 1111 1100
    cout << "unsignedShort -4 : " << unsignedShort << endl; // 65532

    cout << "****************" << endl;

    short signedShort = 100;
    cout << "signedShort size : " << sizeof(signedShort) << "byte" << endl; // 2 byte
    cout << "signedShort limit : " << numeric_limits<short>::max() << endl; // 32767

    //* [overflow]
    signedShort = 65536;                                   //* BIN 0001 0000 0000 0000 0000
    cout << "signedShort 65536 : " << signedShort << endl; // 0

    signedShort = 32767;                                   //* BIN  0111 1111 1111 1111
    cout << "signedShort 32767 : " << signedShort << endl; // 32767

    signedShort = 32768;
    cout << "signedShort 32768 : " << signedShort << endl; // -32768

    signedShort = 32769;
    cout << "signedShort 32769 : " << signedShort << endl; // -32767

    //* [underflow]
    signedShort = -1;
    cout << "signedShort -1 : " << signedShort << endl; // -1
    signedShort = -2;
    cout << "signedShort -2 : " << signedShort << endl; // -2
    signedShort = -4;
    cout << "signedShort -4 : " << signedShort << endl; // -4
    signedShort = -32767;
    cout << "signedShort -32767 : " << signedShort << endl; // -32767
    signedShort = -32768;
    cout << "signedShort -32768 : " << signedShort << endl; // -32768
    signedShort = -32769;
    cout << "signedShort -32769 : " << signedShort << endl; // 32767

    return 0;
}