#include<bits/stdc++.h>
using namespace std;
int a[250],b[250];
int main()
{
	int n,la,lb;
	cin>>n>>la>>lb;
	for(int i=1;i<=la;++i)
	{
		cin>>a[i];
		a[i]++;
	}
	for(int i=1;i<=lb;++i)
	{
		cin>>b[i];
		b[i]++;
	}
	int tota=0,totb=0;
	for(int i=1;i<=n;++i)
	{
		int nowa,nowb;
		nowa=i%la;
		if(nowa==0)
			nowa=la;
		nowb=i%lb;
		if(nowb==0)
			nowb=lb;
		if(a[nowa]==1)
		{
			if(b[nowb]==3||b[nowb]==4)
				++tota;
			if(b[nowb]==2||b[nowb]==5)
				++totb;
		}	
		if(a[nowa]==2)
		{
			if(b[nowb]==4||b[nowb]==1)
				++tota;
			if(b[nowb]==3||b[nowb]==5)
				++totb;
		}
		if(a[nowa]==3)
		{
			if(b[nowb]==5||b[nowb]==2)
				++tota;
			if(b[nowb]==4||b[nowb]==1)
				++totb;
		}
		if(a[nowa]==4)
		{
			if(b[nowb]==5||b[nowb]==3)
				++tota;
			if(b[nowb]==2||b[nowb]==1)
				++totb;
		}
		if(a[nowa]==5)
		{
			if(b[nowb]==1||b[nowb]==2)
				++tota;
			if(b[nowb]==3||b[nowb]==4)
				++totb;
		}
	}
	cout<<tota<<' '<<totb;
	return 0;
}
