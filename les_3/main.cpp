#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "========================================" << endl;
    cout << "  Демонстрация работы класса MyString  " << endl;
    cout << "  Вариант 1: Удаление среднего символа " << endl;
    cout << "  при нечетной длине строки            " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << ">>> ТЕСТ 1: Конструктор по умолчанию" << endl;
    cout << "----------------------------------------" << endl;
    MyString s1;
    s1.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 2: Конструктор с параметром" << endl;
    cout << "----------------------------------------" << endl;
    MyString s2("Hello");
    s2.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 3: Конструктор копирования" << endl;
    cout << "----------------------------------------" << endl;
    MyString s3(s2);
    s3.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 4: Метод Set() - ввод с клавиатуры" << endl;
    cout << "----------------------------------------" << endl;
    MyString s4;
    s4.Set();
    s4.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 5: Метод Update() - нечетная длина" << endl;
    cout << "----------------------------------------" << endl;
    MyString s5("abcdefg");  
    cout << "До Update():" << endl;
    s5.Print();
    cout << endl;
    s5.Update();
    cout << "После Update():" << endl;
    s5.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 6: Метод Update() - четная длина" << endl;
    cout << "----------------------------------------" << endl;
    MyString s6("abcd");  
    cout << "До Update():" << endl;
    s6.Print();
    cout << endl;
    s6.Update();
    cout << "После Update():" << endl;
    s6.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 7: Метод Update() - пустая строка" << endl;
    cout << "----------------------------------------" << endl;
    MyString s7("");
    cout << "До Update():" << endl;
    s7.Print();
    cout << endl;
    s7.Update();
    cout << "После Update():" << endl;
    s7.Print();
    cout << endl;
    
    cout << ">>> ТЕСТ 8: Один символ (нечетная длина)" << endl;
    cout << "----------------------------------------" << endl;
    MyString s8("X");
    cout << "До Update():" << endl;
    s8.Print();
    cout << endl;
    s8.Update();
    cout << "После Update():" << endl;
    s8.Print();
    cout << endl;
    
    return 0;
}