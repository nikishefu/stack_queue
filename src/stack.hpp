#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include "ll.hpp"


template <class T> class Stack : public LinkedList<T> {
public:
    void push(T elem) override{
        this->top = new node<T>(elem, this->top);
    }
protected:
    void print(std::ostream &os) const override {
        os << "Stack[";

        node<T>* t = this->top;
        if (t != nullptr) {
            os << t->data;
            t = t->next;
        }
        while (t != nullptr) {
            os << ", " << t->data;
            t = t->next;
        }
        os << "]";
    }
};

#endif // STACK_HPP_INCLUDED
