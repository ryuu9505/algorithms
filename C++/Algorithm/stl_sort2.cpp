#include <iostream>
#include <algorithm>

#define MAX_SIZE 4

using namespace std;

class Employee
{
public:
	string name;
	int birthyear;

	Employee(string name, int birthyear)
	{
		this->name = name;
		this->birthyear = birthyear;
	}

	bool operator <(Employee& employee)
	{
		return this->birthyear < employee.birthyear; // ascending
	}

	bool operator >(Employee& employee)
	{
		return this->birthyear > employee.birthyear; // desceing
	}


};

bool desc(Employee a, Employee b)
{
	return a > b;
}

int main()
{
	Employee employee[MAX_SIZE] = {
		Employee("설현", 1995),
		Employee("아린", 1999),
		Employee("태연", 1989),
		Employee("제니", 1996)
	};

	// ascending
	sort(employee, employee + MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
		cout << employee[i].name << " " << employee[i].birthyear << endl;

	cout << endl;

	// descending
	sort(employee, employee + MAX_SIZE, desc);
	for (int i = 0; i < MAX_SIZE; i++)
		cout << employee[i].name << " " << employee[i].birthyear << endl;

}