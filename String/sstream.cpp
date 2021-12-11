#include <iostream>
#include <sstream>  /*HEADER*/
using namespace std;

int main()
{
    // declare a stringstream object
    std::stringstream ss;

    // put the string in the stream
    ss.str("Hello World!");

    // get the string from stream
    cout << ss.str();  // Hello
    cout << ss.str();  // World
    
    foo();
}


void foo()
{
    std::stringstream ss("Hello World!");    
    char c = ss.get();  // ss is "ello World!" (c is 'H')
    ss.unget();  // ss is "Hello World!"
}