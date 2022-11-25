#include <iostream>
#include "../src/queue.hpp"

using namespace std;

int main()
{
    int t;
    Queue<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1 << endl;          // 1->2->3
    cout << s1.size() << endl;
    
    Queue<int> s2 (s1), s3;

    t = s1.pop();
    s1.push(4);
    s1.push(5);
    
    t = s2.pop();
    s2.push(6);

    cout << s1 << endl;         // 2->3->4->5
    cout << s1.size() << endl;
    
    cout << s2 << endl;         // 2->3->6
    cout << s2.size() << endl;
    
    s3 = s1;
    
    t = s1.pop();                   
    s1.push(7);
    s1.push(8);
    
    t = s3.pop();
    s3.push(9);

    cout << s1 << endl;         // 3->4->5->7->8
    cout << s1.size() << endl;
    
    cout << s2 << endl;         // 2->3->6
    cout << s2.size() << endl;
    
    cout << s3 << endl;
    cout << s3.size() << endl;  // 3->4->5->9

}
