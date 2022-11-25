#include <string>  
#include <iostream> 
#include <sstream> 
#include <cassert>

#include "stack.hpp"

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
    Stack<int> s1 = Stack<int>();
    s1.push(1);
    s1.push(2);

    Stack<int> s2 = Stack<int>(s1);

    s1.push(3);

    Stack<int> s3;
    s3 = s1;
    s3.push(4);

    assert(s1.pop() == 3);
    assert(s1.pop() == 2);
    assert(s1.pop() == 1);

    bool empty = false;
    try {s1.pop();} catch (const std::out_of_range&) {empty = true;}
    assert(empty);

    assert(check_output(s2, "Stack[2, 1]"));
    assert(check_output(s3, "Stack[4, 3, 2, 1]"));
    assert(check_output(s3.getFront()->data, "4"));
    assert(check_output(s3.size(), "4"));

    return 0;
}