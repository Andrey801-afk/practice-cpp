#pragma once

#include <iostream>

class MyString {
    private:
        char* _str;      
        int _length;     

    public:
        MyString();
        MyString(const char* s);
        MyString(const MyString& other);

        ~MyString();

        void Set();

        void Update();

        void Print() const;

        int GetLength() const;
        const char* GetString() const;
};
