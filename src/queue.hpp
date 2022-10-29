#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

#include "ll.hpp"


template <class T> class Queue : public LinkedList<T> {
public:
    int pop(T* target) {
        if (this->isEmpty()) return 1;
        if (this->top->next == nullptr) {
            *target = this->top->data;
            delete this->top;
            this->top = nullptr;
            return 0;
        }

        node<T>* t = this->top;
        while (t->next->next != nullptr) t = t->next; 

        *target = t->next->data;
        delete t->next;
        t->next = nullptr;

        return 0;
    }
protected:
    virtual void print(std::ostream &os) const {
        os << "Queue[";

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

#endif // QUEUE_HPP_INCLUDED
