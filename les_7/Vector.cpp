#include "Vector.h"

Vector::Vector() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _lenght = 0;
    _capacity = 10;
    _data = new int[_capacity];
}

Vector::Vector(int size) {
    std::cout << ">>> Вызван конструктор с параметром (size=" << size << ")" << std::endl;
    
    if (size > MAX_VECTOR_SIZE) {
        std::string msg = "Исключение 1: Попытка создать вектор размером " + 
                         std::to_string(size) + ", что превышает максимальный размер " + 
                         std::to_string(MAX_VECTOR_SIZE);
        std::cout << "!!! " << msg << std::endl;
        throw VectorSizeException(msg);
    }
    
    if (size < 0) {
        std::string msg = "Исключение 1: Размер вектора не может быть отрицательным";
        std::cout << "!!! " << msg << std::endl;
        throw VectorSizeException(msg);
    }
    
    _lenght = size;
    _capacity = size > 0 ? size : 10;
    _data = new int[_capacity];
    
    for (int i = 0; i < _lenght; i++) {
        _data[i] = 0;
    }
}

Vector::Vector(const Vector& other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _lenght = other._lenght;
    _capacity = other._capacity;
    _data = new int[_capacity];
    
    for (int i = 0; i < _lenght; i++) {
        _data[i] = other._data[i];
    }
}

Vector::~Vector() {
    std::cout << ">>> Удаление вектора (размер=" << _lenght << ")" << std::endl;
    delete[] _data;
    _data = nullptr;
    _lenght = 0;
    _capacity = 0;
}

Vector& Vector::operator=(const Vector& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    delete[] _data;
    
    _lenght = other._lenght;
    _capacity = other._capacity;
    _data = new int[_capacity];
    
    for (int i = 0; i < _lenght; i++) {
        _data[i] = other._data[i];
    }
    
    return *this;
}

int& Vector::operator[](int index) {
    std::cout << ">>> Доступ по индексу: " << index << std::endl;
    
    if (index < 0) {
        std::string msg = "Исключение 2: Индекс " + std::to_string(index) + 
                         " меньше 0 (допустимый диапазон: 0-" + std::to_string(_lenght - 1) + ")";
        std::cout << "!!! " << msg << std::endl;
        throw VectorIndexException(msg);
    }
    
    if (index >= _lenght) {
        std::string msg = "Исключение 3: Индекс " + std::to_string(index) + 
                         " больше или равен размеру вектора " + std::to_string(_lenght);
        std::cout << "!!! " << msg << std::endl;
        throw VectorIndexException(msg);
    }
    
    return _data[index];
}

const int& Vector::operator[](int index) const {
    std::cout << ">>> Доступ по индексу (const): " << index << std::endl;
    
    if (index < 0) {
        std::string msg = "Исключение 2: Индекс " + std::to_string(index) + " меньше 0";
        std::cout << "!!! " << msg << std::endl;
        throw VectorIndexException(msg);
    }
    
    if (index >= _lenght) {
        std::string msg = "Исключение 3: Индекс " + std::to_string(index) + 
                         " больше или равен размеру вектора " + std::to_string(_lenght);
        std::cout << "!!! " << msg << std::endl;
        throw VectorIndexException(msg);
    }
    
    return _data[index];
}

int Vector::operator()() const {
    std::cout << ">>> Запрошен размер вектора" << std::endl;
    return _lenght;
}

Vector Vector::operator+(int value) const {
    std::cout << ">>> Добавление константы " << value << " ко всем элементам" << std::endl;
    
    if (_lenght >= MAX_VECTOR_SIZE) {
        std::string msg = "Исключение 4: Попытка добавить элемент, размер вектора (" + 
                         std::to_string(_lenght) + ") достиг максимального (" + 
                         std::to_string(MAX_VECTOR_SIZE) + ")";
        std::cout << "!!! " << msg << std::endl;
        throw VectorOperationException(msg);
    }
    
    Vector result(*this);
    
    for (int i = 0; i < result._lenght; i++) {
        result._data[i] += value;
    }
    
    return result;
}

Vector Vector::operator-(int n) {
    std::cout << ">>> Удаление " << n << " элементов из конца вектора" << std::endl;
    
    if (_lenght == 0) {
        std::string msg = "Исключение 5: Попытка удалить элементы из пустого вектора";
        std::cout << "!!! " << msg << std::endl;
        throw VectorOperationException(msg);
    }
    
    if (n < 0) {
        std::string msg = "Исключение 5: Количество удаляемых элементов не может быть отрицательным";
        std::cout << "!!! " << msg << std::endl;
        throw VectorOperationException(msg);
    }
    
    if (n > _lenght) {
        std::string msg = "Исключение 5: Попытка удалить " + std::to_string(n) + 
                         " элементов, но в векторе только " + std::to_string(_lenght);
        std::cout << "!!! " << msg << std::endl;
        throw VectorOperationException(msg);
    }
    
    Vector result(*this);
    result._lenght -= n;
    
    return result;
}

void Vector::Print() const {
    std::cout << ">>> Вывод вектора" << std::endl;
    std::cout << "  Размер: " << _lenght << std::endl;
    std::cout << "  Ёмкость: " << _capacity << std::endl;
    std::cout << "  Элементы: [";
    
    for (int i = 0; i < _lenght; i++) {
        std::cout << _data[i];
        if (i < _lenght - 1) {
            std::cout << ", ";
        }
    }
    
    std::cout << "]" << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

void Vector::PushBack(int value) {
    std::cout << ">>> Добавление элемента: " << value << std::endl;
    
    if (_lenght >= _capacity) {
        // Увеличиваем ёмкость
        int newCapacity = _capacity * 2;
        
        if (newCapacity > MAX_VECTOR_SIZE) {
            std::string msg = "Исключение 4: Превышен максимальный размер вектора";
            std::cout << "!!! " << msg << std::endl;
            throw VectorOperationException(msg);
        }
        
        int* newData = new int[newCapacity];
        
        for (int i = 0; i < _lenght; i++) {
            newData[i] = _data[i];
        }
        
        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }
    
    _data[_lenght] = value;
    _lenght++;
}

int Vector::GetSize() const {
    return _lenght;
}

int Vector::GetCapacity() const {
    return _capacity;
}

bool Vector::IsEmpty() const {
    return _lenght == 0;
}

void Vector::Clear() {
    std::cout << ">>> Очистка вектора" << std::endl;
    _lenght = 0;
}