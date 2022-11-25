#include <iostream>
#include "../src/stack.hpp"

using namespace std;

int main()
{
    int t;
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1 << endl;         // 3->2->1
    cout << s1.size() << endl;
    
    Stack<int> s2 (s1), s3;

    t = s1.pop();    
    s1.push(4);
    s1.push(5);
    
    t = s2.pop();
    s2.push(6);

    cout << s1 << endl;         // 5->4->2->1
    cout << s1.size() << endl;  
    
    cout << s2 << endl;         // 6->2->1
    cout << s2.size() << endl;
    
    s3 = s1;
    
    t = s1.pop();    
    s1.push(7);
    s1.push(8);
    
    t = s3.pop();
    s3.push(9);

    cout << s1 << endl;         // 8->7->4->2->1
    cout << s1.size() << endl;
    
    cout << s2 << endl;         // 6->2->1
    cout << s2.size() << endl;
    
    cout << s3 << endl;         // 9->4->2->1
    cout << s3.size() << endl;

}
