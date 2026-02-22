#include <iostream>
#include "Square.h"
#include "Prism.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "\nЧАСТЬ 1: Демонстрация классов" << std::endl;
    
    std::cout << "\n>>> Создание квадрата:" << std::endl;
    Square sq1(5);
    sq1.Print();
    
    std::cout << "\n>>> Создание призмы:" << std::endl;
    Prism pr1(5, 10);
    pr1.Print();
    
    std::cout << "\n>>> Копирование квадрата:" << std::endl;
    Square sq2(sq1);
    sq2.Print();
    
    std::cout << "\n>>> Копирование призмы:" << std::endl;
    Prism pr2(pr1);
    pr2.Print();
    
    std::cout << "\nЧАСТЬ 2: Поиск максимумов" << std::endl;
    
    const int N = 5;  
    const int M = 5;  
    
    Square squares[N] = {
        Square(3),
        Square(7),
        Square(5),
        Square(10),
        Square(4)
    };
    
    Prism prisms[M] = {
        Prism(3, 5),
        Prism(7, 8),
        Prism(5, 10),
        Prism(10, 6),
        Prism(4, 12)
    };
    
    std::cout << "\n>>> Дано " << N << " квадратов и " << M << " призм" << std::endl;
    
    std::cout << "\n>>> Поиск квадрата с максимальной площадью..." << std::endl;
    int maxSquareIndex = 0;
    double maxSquareArea = squares[0].GetArea();
    
    for (int i = 1; i < N; i++) {
        double currentArea = squares[i].GetArea();
        std::cout << "  Квадрат [" << i << "]: площадь = " << currentArea << std::endl;
        
        if (currentArea > maxSquareArea) {
            maxSquareArea = currentArea;
            maxSquareIndex = i;
        }
    }
    
    std::cout << "\n>>> Квадрат с максимальной площадью:" << std::endl;
    std::cout << "  Индекс: " << maxSquareIndex << std::endl;
    squares[maxSquareIndex].Print();
    
    std::cout << "\n>>> Поиск призмы с максимальной диагональю..." << std::endl;
    int maxPrismIndex = 0;
    double maxPrismDiagonal = prisms[0].GetDiagonal();
    
    for (int i = 1; i < M; i++) {
        double currentDiagonal = prisms[i].GetDiagonal();
        std::cout << "  Призма [" << i << "]: диагональ = " << currentDiagonal << std::endl;
        
        if (currentDiagonal > maxPrismDiagonal) {
            maxPrismDiagonal = currentDiagonal;
            maxPrismIndex = i;
        }
    }
    
    std::cout << "\n>>> Призма с максимальной диагональю:" << std::endl;
    std::cout << "  Индекс: " << maxPrismIndex << std::endl;
    prisms[maxPrismIndex].Print();
    
    std::cout << "\nЧАСТЬ 3: Полиморфизм" << std::endl;
    
    Square* ptr = &pr1;  
    std::cout << "\n>>> Вызов Print() через указатель базового класса:" << std::endl;
    ptr->Print();  

    return 0;
}