#include <iostream>

using namespace std;

int main()
{
	int a;
	a = 4;
	int* p = &a;
	p += 2;
	cout << a << endl;
}