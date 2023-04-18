#include <stdio.h>
#include <windows.h>
using namespace std;
int main()
{
    int t=100;
    while(t--)
	{
        system("sj>a+b.in");
        system("C<a+b.in>force.out");
        system("´ò±í<a+b.in>force2.out");
        if(system("fc force.out force2.out")) break;
    }
    system("pause");
    return 0;
}
