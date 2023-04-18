#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	srand((unsigned)time(NULL));
	int n=rand()%5+5,m=rand()%3+5;
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;++i)
	{
		a[i]=rand();
		cout<<a[i]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=m;++i)
	{
		int t=rand()%5+1;
		cout<<t<<' ';
		if(t==3)
			cout<<rand()%n+1<<' '<<rand()<<endl;
		else
		{
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r)swap(l,r);
			cout<<l<<' '<<r<<' ';
			if(t==1)cout<<a[l]<<endl;
			else if(t==2)
			{
				cout<<rand()%(r-l+1)+1<<endl;
			}
			else cout<<rand()<<endl;
		}
	}
	return 0;
}
