#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char tu[55][55];
int main()
{
	int a,b,c,d,hang;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	--c;
	int tot=a+b+c;
	if(tot%25)
		hang=(tot/25+1);
	else
		hang=(tot/25);
	int num=hang*2,now=0;
	for(int i=1;i<=hang;++i)
		for(int j=1;j<=50;++j)
			tu[i*2][j]='D';
	for(int i=1;i<=hang;++i)
		for(int j=1;j<=50;++j)
		{
			if(j%2)
			{
				++now;
				if(now<=a)
					tu[i*2-1][j]='A';
				else if(now<=a+b)
					tu[i*2-1][j]='B';
				else if(now<=a+b+c)
					tu[i*2-1][j]='C';
				else
					tu[i*2-1][j]='D';
			}
			else
				tu[i*2-1][j]='D';
		}
	now=0;
	--d;
	int h;
	if(!d)
		h=1;
	else
	{
		if(d%25)
			h=(d/25+1);
		else
			h=(d/25);
	}
	for(int i=hang+1;i<=hang+h;++i)
		for(int j=1;j<=50;++j)
			tu[i*2-1][j]='C';
	for(int i=hang+1;i<=hang+h;++i)
		for(int j=1;j<=50;++j)
		{
			if(j%2)
			{
				++now;
				if(now<=d)
					tu[i*2][j]='D';
				else
					tu[i*2][j]='C';
			}
			else
				tu[i*2][j]='C';
		}
	printf("%d 50\n",2*(hang+h));
	for(int i=1;i<=2*(hang+h);++i)
	{
		for(int j=1;j<=50;++j)
			cout<<tu[i][j];
		cout<<endl;
	}
	return 0;
}
