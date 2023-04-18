#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	for(int i=1;i<=k;++i)
	{
		if((a%100==0&&a%400==0)||(a%100&&a%4==0))
		{
			if(b==2&&c==29)c=1,++b;
			else if(b==12&&c==31)c=1,b=1,++a;
			else if((b==2||b==4||b==6||b==9||b==11)&&c==30)c=1,++b;
			else if((b==1||b==3||b==5||b==7||b==8||b==10)&&c==31)c=1,++b;
			else ++c;
		}
		else
		{
			if(b==2&&c==28)c=1,++b;
			else if(b==12&&c==31)c=1,b=1,++a;
			else if((b==2||b==4||b==6||b==9||b==11)&&c==30)c=1,++b;
			else if((b==1||b==3||b==5||b==7||b==8||b==10)&&c==31)c=1,++b;
			else ++c;
		}
	}
	printf("%d-%02d-%02d\n",a,b,c);
	return 0;
}
