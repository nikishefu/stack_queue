#include <string>  
#include <iostream> 
#include <sstream> 

#include "stack.hpp"

int main() {
    Stack<int> s1 = Stack<int>();

    s1.push(1);
    s1.push(2);

    Stack<int> s2 = Stack<int>(s1);

    s1.push(3);

    Stack<int> s3 = s1;

    s3.push(4);

    int a;
    std::stringstream out;

    while (!s1.pop(&a)) out << a;
    out << s2 << s3;
    out << s3.getFront()->data;
    out << s3.size();

    std::cout << out.str();
    return (out.str() != "321Stack[2, 1]Stack[4, 3, 2, 1]44");
}