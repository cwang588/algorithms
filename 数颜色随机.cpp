#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	int n=rand()%15+5,m=rand()%15+5;
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;++i)cout<<rand()%15+1<<' ';
	cout<<endl;
	for(int i=1;i<=m;++i)
	{
		int t=rand()%2;
		if(t)
		{
			int l=rand()%n+1,r=rand()%n+1;
			cout<<'Q'<<' '<<min(l,r)<<' '<<max(l,r)<<endl;
		}
		else
			cout<<'R'<<' '<<rand()%n+1<<' '<<rand()%15+1<<endl;
	}
	return 0;
}
