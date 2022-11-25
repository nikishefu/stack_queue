#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

#include "ll.hpp"


template <class T> class Queue : public LinkedList<T> {
public:
    Queue(): LinkedList<T>() {}
    Queue(const Queue& q) {
        if (q.isEmpty()) {
            this->top = nullptr;
            return;
        }
        this->top = new node<T>(q.top->data);

        node<T>* target = this->top;
        node<T>* source = q.top->next;
        while (source != nullptr) {
            target->next = new node<T>(source->data);

            target = target->next;
            source = source->next;
        }
        tail = target;
    }
    Queue(const Queue&& s): LinkedList<T>(s), tail(s.tail) {}
    Queue& operator=(const Queue& q) {
        delete this->top;
        Queue<T>* t = new Queue(q);
        this->top = t->top;
        this->tail = t->tail;

        t->top = nullptr;
        delete t;

        return *this;
    };
    
    T pop() override {
        T data = LinkedList<T>::pop();
        if (this->top == nullptr) tail = nullptr;
        return data;
    }

    void push(T elem) override {
        if (this->isEmpty()) {
            this->top = new node<T>(elem);
            tail = this->top;
        } else {
            tail->next = new node<T>(elem);
            tail = tail->next;
        }
    }
protected:
    node<T>* tail;

    void print(std::ostream &os) const override{
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
