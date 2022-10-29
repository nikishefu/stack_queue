#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include "ll.hpp"


template <class T> class Stack : public LinkedList<T> {
public:
    int pop(T* target) override {
        if (this->isEmpty()) return 1;

        node<T>* t = this->top->next;
        *target = this->top->data;

        this->top->next = nullptr;
        delete this->top;

        this->top = t;

        int si = this->size();

        return 0;
    }
protected:
    virtual void print(std::ostream &os) const {
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
