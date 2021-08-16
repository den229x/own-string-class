#ifndef _MYSTRING_
#define _MYSTRING_

#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
private:
    char* data;
    int length;

public:
    MyString();
    MyString(char*);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();

    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);
    MyString  operator+(const MyString&);
    char& operator[](unsigned short);

    friend istream& operator>>(istream&, MyString&);
    friend ostream& operator<<(ostream&, const MyString&);

    int Lenght();
};

#endif