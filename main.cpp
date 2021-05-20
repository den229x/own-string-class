#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    MyString str;

    cout << "WHAT IS YOUR NAME?\n";
    cin >> str;

    cout << "YOUR NAME IS: " << str << endl;
}