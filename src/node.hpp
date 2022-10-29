#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

template <class T> class node
{
public:
    T data;
    node<T>* next;

    node(T _data, node<T>* _next=nullptr): data(_data), next(_next) {}
    node(): next(nullptr) {}
    ~node() {delete next;}
};

#endif // NODE_HPP_INCLUDED
