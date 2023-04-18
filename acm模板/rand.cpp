#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL)); 
	int n=rand()%5+5,m=rand()%10+1;
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=m;++i)
	{
		int t=rand()%3+1;
		cout<<t<<' ';
		int l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		cout<<l<<' '<<r;
		if(t==1)cout<<' '<<rand();
		cout<<endl;
	}
	return 0;
}
