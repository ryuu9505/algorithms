#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <random>

using namespace std;

int main()
{
	int n;
	random_device rd;
	mt19937 gen(rd());
	ofstream fout;

	fout.open("D:/random_file_name.txt");

	uniform_int_distribution<int> dis(0, 2);
	uniform_int_distribution<int> dis_digit(0, 9);
	uniform_int_distribution<int> dis_uppercase(65, 90);
	uniform_int_distribution<int> dis_lowercase(97, 122);

	for (int j = 0; j < 10000; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			n = dis(gen);
			if (n == 0)
				fout << dis_digit(gen);
			else if (n == 1)
				fout << char(dis_uppercase(gen));
			else if (n == 2)
				fout << char(dis_lowercase(gen));
		}
		fout << endl;
	}
	fout.close();
}