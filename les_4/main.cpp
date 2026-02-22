#include <iostream>
#include "Rectangle.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "\nТЕСТ 1: Конструктор по умолчанию" << std::endl;
    Rectangle r1;
    r1.Print();
    std::cout << "" << std::endl;
    
    std::cout << "\nТЕСТ 2: Конструктор с параметрами" << std::endl;
    Rectangle r2(0, 0, 10, 5);
    r2.Print();
    
    std::cout << "\nТЕСТ 3: Конструктор копирования"<< std::endl;
    Rectangle r3(r2);
    r3.Print();
    
    std::cout << "\nТЕСТ 4: Оператор присваивания" << std::endl;
    Rectangle r4;
    r4 = r2;
    r4.Print();
    
    std::cout << "\nТЕСТ 5: Оператор + (сложение)"<< std::endl;
    Rectangle r5(0, 0, 5, 3);
    Rectangle r6(0, 0, 4, 2);
    std::cout << "Прямоугольник 1:" << std::endl;
    r5.Print();
    std::cout << "Прямоугольник 2:" << std::endl;
    r6.Print();
    Rectangle r7 = r5 + r6;
    std::cout << "Результат (r5 + r6):" << std::endl;
    r7.Print();
    
    std::cout << "\nТЕСТ 6: Оператор +" << std::endl;
    Rectangle r10(0, 0, 6, 4);
    Rectangle r11;
    std::cout << "Прямоугольник 1:" << std::endl;
    r10.Print();
    std::cout << "Прямоугольник 2:" << std::endl;
    r11.Print();
    Rectangle r12 = r10 + r11;
    std::cout << "Результат (r10 + r11):" << std::endl;
    r12.Print();
    
    std::cout << "\nТЕСТ 7: Бинарный - (без пересечения)" << std::endl;
    Rectangle r13(0, 0, 5, 5);
    Rectangle r14(10, 10, 5, 5);
    std::cout << "Прямоугольник 1:" << std::endl;
    r13.Print();
    std::cout << "Прямоугольник 2:" << std::endl;
    r14.Print();
    Rectangle r15 = r13 - r14;
    std::cout << "Результат (r13 - r14):" << std::endl;
    r15.Print();
    
    std::cout << "\nТЕСТ 8: Бинарный - (с пересечением)" << std::endl;
    Rectangle r16(0, 0, 10, 10);
    Rectangle r17(5, 5, 10, 10);
    std::cout << "Прямоугольник 1:" << std::endl;
    r16.Print();
    std::cout << "Прямоугольник 2:" << std::endl;
    r17.Print();
    Rectangle r18 = r16 - r17;
    std::cout << "Результат (r16 - r17):" << std::endl;
    r18.Print();
    
    std::cout << "\nТЕСТ 9: Унарный - (отражение)" << std::endl;
    Rectangle r19(2, 3, 4, 5);
    std::cout << "Исходный прямоугольник:" << std::endl;
    r19.Print();
    Rectangle r20 = -r19;
    std::cout << "После отражения (-r19):" << std::endl;
    r20.Print();
    
    std::cout << "\nТЕСТ 10: Комбинированная операций 1" << std::endl;
    Rectangle r21(1, 1, 3, 2);
    Rectangle r22(0, 0, 2, 2);
    Rectangle r23 = -(r21 + r22);
    std::cout << "Результат -(r21 + r22):" << std::endl;
    r23.Print();
    
    std::cout << "\nТЕСТ 11: Комбинированная операция 2" << std::endl;
    Rectangle r24(0, 0, 5, 5);
    Rectangle r25(0, 0, 3, 3);
    Rectangle r26(0, 0, 2, 2);
    Rectangle r27 = (r24 + r25) - r26;
    std::cout << "Результат ((r24 + r25) - r26):" << std::endl;
    r27.Print();
    
    return 0;
}