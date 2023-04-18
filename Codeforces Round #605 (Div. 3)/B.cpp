#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
	int n;	
	scanf("%d",&n);
	while(n--)
	{
		memset(s,0,sizeof(s));
		cin>>(s+1);
		int l=strlen(s+1);
		int a,b,c,d;
		a=b=c=d=0;
		for(int i=1;i<=l;++i)
		{
			if(s[i]=='L')++a;
			else if(s[i]=='R')++b;
			else if(s[i]=='U')++c;
			else ++d;
		}
		int num1=min(a,b),num2=min(c,d);
		if(num1&&num2)
		{
			printf("%d\n",2*num1+2*num2);
			for(int i=1;i<=num1;++i)printf("L");
			for(int i=1;i<=num2;++i)printf("U");
			for(int i=1;i<=num1;++i)printf("R");
			for(int i=1;i<=num2;++i)printf("D");
		}
		else if(!num1&&!num2)printf("0\n");
		else
		{
			printf("2\n");
			if(num1)printf("LR");
			else printf("UD");
		}
		printf("\n");
	}
	return 0;
}
