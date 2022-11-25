#ifndef LL_HPP_INCLUDED
#define LL_HPP_INCLUDED

#include <stdexcept>
#include "node.hpp"

template <class T> class LinkedList {
public:
    LinkedList(): top(nullptr) {}

    LinkedList(const LinkedList& s) {
        if (s.isEmpty()) {
            top = nullptr;
            return;
        }
        top = new node<T>(s.top->data);

        node<T>* target = top;
        node<T>* source = s.top->next;
        while (source != nullptr) {
            target->next = new node<T>(source->data);

            target = target->next;
            source = source->next;
        }
    }

    LinkedList(const LinkedList&& s): top(s.top) {s.top = nullptr;}
    virtual ~LinkedList() {delete top;}

    LinkedList& operator=(const LinkedList& s) {
        delete top;
        if (s.isEmpty()) {
            top = nullptr;
            return *this;
        }
        top = new node<T>(s.top->data);

        node<T>* target = top;
        node<T>* source = s.top->next;
        while (source != nullptr) {
            target->next = new node<T>(source->data);

            target = target->next;
            source = source->next;
        }
        return *this;
    }

    LinkedList& operator=(const LinkedList&& s) {
        delete top;
        top = s.top;
        s.top = nullptr;
        return *this;
    }

    virtual void push(T elem) = 0;
    virtual T pop() {
        if (isEmpty()) throw std::out_of_range("list is empty");

        T data = top->data;
        node<T>* t = top;
        top = top->next;
        
        t->next = nullptr;
        delete t;

        return data;
    }
    virtual node<T>* getFront() {return top;}
    virtual bool isEmpty() const {return top == nullptr;}

    virtual std::size_t size() const {
        node<T>* t = top;
        std::size_t counter = 0;

        while (t != nullptr) {
            t = t->next;
            ++counter;
        }
        return counter;
    }

    friend std::ostream& operator << (std::ostream &os, const LinkedList<T>& s) {
        s.print(os);
        return os;
    }

    friend std::ostream& operator >> (std::ostream &is, const LinkedList<T>& s) {
        T t;
        is >> t;
        s.push(t);
        return is;
    }

protected:
    node<T>* top;

    virtual void print(std::ostream &os) const {
        os << "LinkedList[";

        node<T>* t = top;
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

#endif //LL_HPP_INCLUDED