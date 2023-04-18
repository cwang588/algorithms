#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	void sort(int c[]);
	int a[3], b[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	sort(a);
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
void sort(int a[])
{
	int a1, b1, c1;
	a1 = a[0] % 7;
	b1 = a[1] % 7;
	c1 = a[2] % 7;
	if (a1 > b1)swap(a[0], a[1]);
	if (a1 > c1)swap(a[0], a[2]);
	if (b1 > c1)swap(a[1], a[2]);
}
//void swap(int *a, int *b)
//{
//	int *c;
//	c = a;
//	a = b;
//	b = c;
//}
