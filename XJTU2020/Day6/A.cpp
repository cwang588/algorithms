#include<bits/stdc++.h>
using namespace std;
char s[1000005];
char a[1005][1005],tmp[1005][1005];
int n;
void work0()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int tox=n-j+1,toy=i;
			if(a[tox][toy]=='.')tmp[i][j]='.';
			else if(a[tox][toy]=='>')tmp[i][j]='v';
			else if(a[tox][toy]=='<')tmp[i][j]='^';
			else if(a[tox][toy]=='^')tmp[i][j]='>';
			else tmp[i][j]='<';
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=tmp[i][j];
}
void work1()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int tox=j,toy=n-i+1;
			if(a[tox][toy]=='.')tmp[i][j]='.';
			else if(a[tox][toy]=='<')tmp[i][j]='v';
			else if(a[tox][toy]=='>')tmp[i][j]='^';
			else if(a[tox][toy]=='v')tmp[i][j]='>';
			else tmp[i][j]='<';
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=tmp[i][j];
}
int main()
{
	cin>>n>>(s+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	int l=strlen(s+1);
	for(int i=1;i<=l;++i)
	{
		if(s[i]=='L')work1();
		else work0();
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
