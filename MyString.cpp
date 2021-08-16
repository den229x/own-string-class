#include "MyString.h"

MyString::MyString()
{
    data = new char[1];
    data[0] = '\0';
    length = 0;
}

MyString::MyString(char* str)
{
    length = strlen(str);
    data = new char[length+1];
    strcpy(data, str);

    data[length] = '\0';
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);

    data[length] = '\0';
}

MyString::~MyString()
{
    delete[] data;
    data = nullptr;
    length = 0;
}

MyString& MyString::operator=(const MyString& other)
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }

    if (this == &other)
    {
        return *this;
    }

    length = strlen(other.data);
    data = new char[length + 1];
    strcpy(data, other.data);

    data[length] = '\0';

    return *this;
}

MyString& MyString::operator=(MyString&& other)
{
    if (this == &other) return *this;

    delete[] data;

    data = other.data;
    length = other.length;
    other.data = nullptr;

    return *this;
}

MyString::MyString(MyString&& other)
{
    data = other.data;
    length = other.length;
    other.data = nullptr;
}

char& MyString::operator[](unsigned short i)
{
    return data[i];
}

int MyString::Lenght()
{
    return length;
}

MyString MyString::operator+(const MyString& other)
{   
    MyString new_str = new char[length + other.length + 1];
    new_str.length = length + other.length;

    int i = 0;
    for (; i < length; i++)
    {
        new_str.data[i] = data[i];
    }

    for (int j = 0; j < other.length; j++, i++)
    {
        new_str.data[i] = other.data[j];
    }

    new_str.data[new_str.length] = '\0';

    return new_str;
}

istream& operator>>(istream& in, MyString& other)
{
    char str[500] = {0};

    in.getline(str, 500);

    other.length = strlen(str);
    other.data = new char[other.length + 1];

    strcpy(other.data, str);

    other.data[other.length] = '\0';

    return in;
}

ostream& operator<<(ostream& out, const MyString& other)
{
    out << other.data;
    return out;
}