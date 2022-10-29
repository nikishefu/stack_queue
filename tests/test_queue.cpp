#include <string>  
#include <iostream> 
#include <sstream> 

#include "queue.hpp"

int main() {
    Queue<int> q1 = Queue<int>();

    q1.push(1);
    q1.push(2);

    Queue<int> q2 = Queue<int>(q1);

    q1.push(3);

    Queue<int> q3 = q1;

    q3.push(4);

    int a;
    std::stringstream out;

    while (!q1.pop(&a)) out << a;
    out << q2 << q3;
    out << q3.getFront()->data;
    out << q3.size();

    return (out.str() != "123Queue[2, 1]Queue[4, 3, 2, 1]44");
}