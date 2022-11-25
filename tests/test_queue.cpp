#include <string>  
#include <iostream> 
#include <sstream> 
#include <cassert>

#include "queue.hpp"

/**
 * if ("cout << object" prints expected string)
 */
template <class T>
bool check_output(T object, std::string expected) {
    std::stringstream out;
    out << object;
    return out.str() == expected;
}

int main() {
    Queue<int> q1 = Queue<int>();
    q1.push(1);
    q1.push(2);

    Queue<int> q2 = Queue<int>(q1);

    q1.push(3);

    Queue<int> q3;
    q3 = q1;
    q3.push(4);

    assert(q1.pop() == 1);
    assert(q1.pop() == 2);
    assert(q1.pop() == 3);

    bool empty = false;
    try {q1.pop();} catch (const std::out_of_range&) {empty = true;}
    assert(empty);

    assert(check_output(q2, "Queue[1, 2]"));
    assert(check_output(q3, "Queue[1, 2, 3, 4]"));
    assert(check_output(q3.getFront()->data, "1"));
    assert(check_output(q3.size(), "4"));

    return 0;
}