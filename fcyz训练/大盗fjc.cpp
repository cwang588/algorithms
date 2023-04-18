#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(0));
		freopen("sb10.in","w",stdout);
		int n=100000-rand(),m=n-rand();
		cout<<n<<' '<<m<<endl;
		for(int j=1;j<=n;++j)cout<<(rand()*rand())%n+1<<' ';
		cout<<endl;
		for(int j=2;j<=n;++j)
		{
			cout<<j<<' ';
			int t=j-(rand()%j);
			if(!t)++t;
			if(t==j)--t;
			cout<<t<<endl;
		}
		for(int j=1;j<=m;++j)cout<<rand()*rand()%n+1<<' '<<endl;
	return 0;
}
