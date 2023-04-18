#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time);
	for(int i=1;i<=10;++i)
		printf("%c",rand()%5+'a');
	printf("\n");
	for(int i=1;i<=2;++i)
		printf("%c",rand()%5+'a');	
	printf("\n");
	for(int i=1;i<=3;++i)
		printf("%c",rand()%5+'a');	
	return 0;
}
