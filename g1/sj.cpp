#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	srand((unsigned)time(NULL)); 
    int a;
    a=rand()%100000;
    printf("%d\n",a);
    return 0;
}
