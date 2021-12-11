#include <iostream>
#include <sstream>  /*HEADER*/
using namespace std;

/*
#loop #extract
*/


// loop with string 
void foo()
{
	string str;  
	stringstream ss("01 23");
	while (ss >> str)
	{
		cout << str << endl;
	}
    /*
    01
    23
    */
}


// loop with char
void foo()
{
	char ch;  
	stringstream ss("01 23");
	while (ss >> ch)
	{
		cout << ch << endl;
	}
    /*
    0
    1
    2
    3
    */
}


// loop with int
void foo()
{
	int n;
	stringstream ss("01 23");
	while (ss >> n)
	{
		cout << n << endl;
	}
    /*
    1
    23
    */
}


// extract 시분초 from string
void foo()
{
    int H, M, S;
    char temp;
    stringstream ss("01:35:26");
    ss >> H >> temp >> M >> temp >> S;  // throw ':' in 'temp'
}


