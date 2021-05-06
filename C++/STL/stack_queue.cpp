#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    
    while(!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}