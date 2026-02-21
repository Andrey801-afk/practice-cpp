#include "MyString.h"
#include <cstring>
#include <fstream>

using namespace std;

MyString::MyString() {
    _length = 0;
    _str = new char[1];
    _str[0] = '\0';
}

MyString::MyString(const char* s) {
    if (s == nullptr) {
        _length = 0;
        _str = new char[1];
        _str[0] = '\0';
    } else {
        _length = strlen(s);
        _str = new char[_length + 1];
        strcpy(_str, s);
    }
}

MyString::MyString(const MyString& other) {
    _length = other._length;
    _str = new char[_length + 1];
    strcpy(_str, other._str);
}


MyString::~MyString() {
    delete[] _str;
    _str = nullptr;
    _length = 0;
}


void MyString::Set() {
    cout << "Введите строку: ";
    
    char* buffer = new char[1024];
    cin.getline(buffer, 1024);
    
    delete[] _str;
    
    _length = strlen(buffer);
    _str = new char[_length + 1];
    strcpy(_str, buffer);
    
    delete[] buffer;
    
    cout << "Строка установлена: \"" << _str << "\"" << endl;
    cout << "Длина строки: " << _length << endl;
}


void MyString::Update() {
    cout << "------Изменение строки----------" << endl;
    cout << "Исходная строка: \"" << _str << "\"" << endl;
    cout << "Длина строки: " << _length << endl;
    
    ofstream file("strings.txt", ios::app);
    if (file.is_open()) {
        file << "=== Запись от " << __DATE__ << " " << __TIME__ << " ===" << endl;
        file << "Исходная строка: \"" << _str << "\"" << endl;
        file << "Длина: " << _length << endl;
    } else {
        cout << "Ошибка: не удалось открыть файл для записи!" << endl;
    }
    
    // Проверяем, нечетная ли длина
    if (_length % 2 != 0 && _length > 0) {
        cout << "Длина нечетная, удаляем средний символ" << endl;
        
        int midIndex = _length / 2;  
        cout << "Индекс удаляемого символа: " << midIndex << endl;
        cout << "Удаляемый символ: '" << _str[midIndex] << "'" << endl;
        
        char* newStr = new char[_length];  
        
        for (int i = 0; i < midIndex; i++) {
            newStr[i] = _str[i];
        }
        
        for (int i = midIndex + 1; i < _length; i++) {
            newStr[i - 1] = _str[i];
        }
        
        newStr[_length - 1] = '\0';
        
        delete[] _str;
        
        _str = newStr;
        _length--;
        
        cout << "Изменённая строка: \"" << _str << "\"" << endl;
        cout << "Новая длина: " << _length << endl;
        
        if (file.is_open()) {
            file << "Изменённая строка: \"" << _str << "\"" << endl;
            file << "Новая длина: " << _length << endl;
            file << "----------------------------------------" << endl;
            file.close();
        }
    } else {
        cout << "Длина четная или строка пустая, изменения не требуются" << endl;
        
        if (file.is_open()) {
            file << "Изменённая строка: \"" << _str << "\" (без изменений)" << endl;
            file << "----------------------------------------" << endl;
            file.close();
        }
    }
    
    cout << "Завершение изменения строки" << endl;
}

void MyString::Print() const {
    cout << "Вывод строки на экран" << endl;
    cout << "  Строка: \"" << (_str ? _str : "nullptr") << "\"" << endl;
    cout << "  Длина: " << _length << endl;
}

int MyString::GetLength() const {
    return _length;
}

const char* MyString::GetString() const {
    return _str;
}