#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "Heap.h"

void test()
{
	int a[10] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int> h(a, sizeof(a) / sizeof(a[0]));
	h.Print();

	h.push(20);
	h.Print();
	cout<<h.top()<<endl;

	h.pop();
	h.Print();

	cout << h.top() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}