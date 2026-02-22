#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

const int MAX_VECTOR_SIZE = 1000;  

class Vector {
    private:
        int* _data;     
        int _lenght;     
        int _capacity;   

    public:
        Vector();
        Vector(int size);
        Vector(const Vector& other);
        ~Vector();

        Vector& operator=(const Vector& other);

        int& operator[](int index);                    
        const int& operator[](int index) const;        
        int operator()() const;                        
        Vector operator+(int value) const;             
        Vector operator-(int n);                       

        void Print() const;
        void PushBack(int value);
        int GetSize() const;
        int GetCapacity() const;
        bool IsEmpty() const;

        void Clear();
};

class VectorSizeException : public std::exception {
    private:
        std::string _message;
    public:
        VectorSizeException(const std::string& msg) : _message(msg) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
};

class VectorIndexException : public std::exception {
    private:
        std::string _message;
    public:
        VectorIndexException(const std::string& msg) : _message(msg) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
};

class VectorOperationException : public std::exception {
    private:
        std::string _message;
    public:
        VectorOperationException(const std::string& msg) : _message(msg) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
};