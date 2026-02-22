#include <iostream>
#include "Vector.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "\n=== ТЕСТ 1: Конструктор по умолчанию === " << std::endl;
    try {
        Vector v1;
        v1.Print();
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 2: Конструктор с параметром ===" << std::endl;
    try {
        Vector v2(5);
        v2[0] = 10;
        v2[1] = 20;
        v2[2] = 30;
        v2[3] = 40;
        v2[4] = 50;
        v2.Print();
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 3: Исключение 1 (размер > MAX) ===" << std::endl;
    try {
        Vector v3(MAX_VECTOR_SIZE + 100);
        v3.Print();
    } catch (const VectorSizeException& e) {
        std::cout << "!!! ПОЙМАНО VectorSizeException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 4: Исключение 2 (индекс < 0) ===" << std::endl;
    try {
        Vector v4(5);
        std::cout << "Попытка доступа к элементу с индексом -1:" << std::endl;
        int value = v4[-1];
        std::cout << "Значение: " << value << std::endl;
    } catch (const VectorIndexException& e) {
        std::cout << "!!! ПОЙМАНО VectorIndexException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 5: Исключение 3 (индекс >= size) ===" << std::endl;
    try {
        Vector v5(3);
        std::cout << "Попытка доступа к элементу с индексом 10:" << std::endl;
        int value = v5[10];
        std::cout << "Значение: " << value << std::endl;
    } catch (const VectorIndexException& e) {
        std::cout << "!!! ПОЙМАНО VectorIndexException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 6: Оператор + (добавление константы) ===" << std::endl;
    try {
        Vector v6(5);
        v6[0] = 1; v6[1] = 2; v6[2] = 3; v6[3] = 4; v6[4] = 5;
        std::cout << "Исходный вектор:" << std::endl;
        v6.Print();
        
        Vector v7 = v6 + 10;
        std::cout << "После добавления 10:" << std::endl;
        v7.Print();
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 7: Оператор - (удаление элементов) ===" << std::endl;
    try {
        Vector v8(5);
        v8[0] = 1; v8[1] = 2; v8[2] = 3; v8[3] = 4; v8[4] = 5;
        std::cout << "Исходный вектор:" << std::endl;
        v8.Print();
        
        Vector v9 = v8 - 2;
        std::cout << "После удаления 2 элементов:" << std::endl;
        v9.Print();
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 8: Исключение 5 (удаление из пустого) ===" << std::endl;
    try {
        Vector v10;
        std::cout << "Попытка удалить элементы из пустого вектора:" << std::endl;
        Vector v11 = v10 - 1;
        v11.Print();
    } catch (const VectorOperationException& e) {
        std::cout << "!!! ПОЙМАНО VectorOperationException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 9: Оператор () (размер) ===" << std::endl;
    try {
        Vector v12(7);
        std::cout << "Размер вектора через operator(): " << v12() << std::endl;
        std::cout << "Размер вектора через GetSize(): " << v12.GetSize() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 10: Копирование и присваивание ===" << std::endl;
    try {
        Vector v13(4);
        v13[0] = 100; v13[1] = 200; v13[2] = 300; v13[3] = 400;
        
        std::cout << "Исходный вектор:" << std::endl;
        v13.Print();
        
        Vector v14(v13);
        std::cout << "Копия вектора:" << std::endl;
        v14.Print();
        
        Vector v15;
        v15 = v13;
        std::cout << "Присваивание вектора:" << std::endl;
        v15.Print();
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ТЕСТ 11: Цепочка операций ===" << std::endl;
    try {
        Vector v16(5);
        v16[0] = 1; v16[1] = 2; v16[2] = 3; v16[3] = 4; v16[4] = 5;
        
        std::cout << "Исходный вектор:" << std::endl;
        v16.Print();
        
        Vector v17 = (v16 + 5) - 1;
        std::cout << "Результат (v16 + 5) - 1:" << std::endl;
        v17.Print();
    } catch (const std::exception& e) {
        std::cout << "!!! ПОЙМАНО ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
    }
    
    return 0;
}