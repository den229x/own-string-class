#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");

    MyString str;

    cout << "WHAT IS YOUR NAME?\n";
    cin >> str;

    for (int i = 0; i < str.Lenght(); i++)
    {
        cout << str[i] << " ";
    }

    cout << endl;
}