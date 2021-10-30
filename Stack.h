#pragma once
#include <exception>

class Exce : public std::exception {
    const char * msg;
    Exce();    
public:
    explicit Exce(const char * s) throw() : msg(s) { }
    const char * what() const throw() { return msg; }
};

template <typename T>
class Stack {
    static const int defaultSize = 10;
    static const int maxSize = 1000;
    int S_size;
    int S_top;
    T * stackPtr;

    public:
    
    Stack ( int s ) {
        if(s > maxSize || s < 1) throw Exce("invalid stack size");
        else S_size = s;
        stackPtr = new T[S_size];
        S_top = -1;
    }

     ~Stack() { if(stackPtr) delete[] stackPtr; }

    T & push ( const T & i ) {
        if(isFull()) throw Exce("stack full");
        return stackPtr[++S_top] = i;
    }

    T & pop () {
        if(isEmpty()) throw Exce("stack empty");
        return stackPtr[S_top--];
    }

    bool isEmpty() const { return S_top < 0; }
    bool isFull() const { return S_top >= S_size - 1; }
    int top() const { return S_top; }
    int size() const { return S_size; }
};
