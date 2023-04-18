#include<cstdio>
#include<iostream>
using namespace std;
char t[10005];
int main()
{
	int k,num=0;
	scanf("%d",&k);
	cin>>t;
	while(t[0]!='E')
	{
		++num;
		if(num==k+1)
		{
			printf("%s\n",t);
			num=0;
			cin>>t;
			continue;
		}
		if(t[0]=='C')
			printf("Bu\n");
		else if(t[0]=='B')
			printf("JianDao\n");
		else
			printf("ChuiZi\n");
		cin>>t;
	}
	return 0;
}
