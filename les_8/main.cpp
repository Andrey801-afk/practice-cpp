#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

bool IsPalindrome(const std::string& word) {
    if (word.empty()) {
        return false;
    }
    
    std::string cleanWord;
    
    for (char c : word) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            cleanWord += std::tolower(static_cast<unsigned char>(c));
        }
    }
    
    if (cleanWord.empty()) {
        return false;
    }
    
    std::string reversedWord = cleanWord;
    std::reverse(reversedWord.begin(), reversedWord.end());
    
    return cleanWord == reversedWord;
}

std::string InsertCommaBeforeAnd(const std::string& input) {
    std::cout << ">>> Вставка запятой перед 'and'" << std::endl;
    
    std::string result;
    std::istringstream iss(input);
    std::string word;
    bool isFirstWord = true;
    
    while (iss >> word) {
        std::string lowerWord = word;
        for (char& c : lowerWord) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        
        if (!isFirstWord) {
            if (lowerWord == "and") {
                result += ", " + word;
            } else {
                result += " " + word;
            }
        } else {
            result += word;
            isFirstWord = false;
        }
    }
    
    return result;
}

int CountPalindromes(const std::string& input) {
    std::cout << ">>> Подсчёт симметричных слов" << std::endl;
    
    std::istringstream iss(input);
    std::string word;
    int count = 0;
    std::vector<std::string> palindromes;
    
    while (iss >> word) {
        if (IsPalindrome(word)) {
            count++;
            palindromes.push_back(word);
        }
    }
    
    if (!palindromes.empty()) {
        std::cout << "  Найдены симметричные слова: ";
        for (size_t i = 0; i < palindromes.size(); i++) {
            std::cout << palindromes[i];
            if (i < palindromes.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "  Симметричные слова не найдены" << std::endl;
    }
    
    return count;
}

void PrintMenu() {
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Меню обработки строк:                      " << std::endl;
    std::cout << "  1. Вставить запятую перед 'and'           " << std::endl;
    std::cout << "  2. Подсчитать симметричные слова          " << std::endl;
    std::cout << "  3. Выполнить оба задания                  " << std::endl;
    std::cout << "  4. Выход                                  " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::string input;
    
    std::cout << std::endl;
    std::cout << ">>> Введите строку:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, input);
    
    if (input.empty()) {
        std::cout << "Вы вввели пустую строку" << std::endl;
        return 1;
    }
    
    std::cout << std::endl;
    std::cout << "Исходная строка:" << std::endl;
    std::cout << "\"" << input << "\"" << std::endl;
    std::cout << "Длина строки: " << input.length() << " символов" << std::endl;
    
    int choice;
    
    while (true) {
        PrintMenu();
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        
        std::cin.ignore(10000, '\n');
        
        std::cout << std::endl;
        
        switch (choice) {
            case 1: {
                std::cout << "ЗАДАНИЕ 1: Вставка запятой перед 'and'"<< std::endl;
                std::string result = InsertCommaBeforeAnd(input);
                std::cout << "Результирующая строка:" << std::endl;
                std::cout << "\"" << result << "\"" << std::endl;
                break;
            }
            
            case 2: {
                std::cout << "\nЗАДАНИЕ 2: Симметричные слова" << std::endl;
                int count = CountPalindromes(input);
                std::cout << "Количество симметричных слов: " << count << std::endl;
                break;
            }
            
            case 3: {
                std::cout << "\nЗАДАНИЕ 1 и 2" << std::endl;
                
                std::cout << std::endl;
                std::string result = InsertCommaBeforeAnd(input);
                std::cout << "Результирующая строка:" << std::endl;
                std::cout << "\"" << result << "\"" << std::endl;
                
                std::cout << std::endl;
                int count = CountPalindromes(input);
                std::cout << "Количество симметричных слов: " << count << std::endl;
                
                break;
            }
            
            case 4: {
                std::cout << ">>> Завершение программы..." << std::endl;
                return 0;
            }
            
            default: {
                std::cout << "Такого варианта выбора нету. Попробуйте снова." << std::endl;
                break;
            }
        }
        
        std::cout << std::endl;
        std::cout << "Нажмите Enter для продолжения...";
        std::cin.ignore(10000, '\n');
    }
    
    return 0;
}