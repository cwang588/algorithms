#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("data.in","w",stdout);
	srand((unsigned)time(0));
	int n=rand()%20+5,m=rand()%10+5;
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=m;++i)
	{
		int t=rand()%2+1;
		cout<<t<<' ';
		if(t==1)cout<<rand()%n+1<<endl;
		else 
		{
			int x=rand()%n+1;
			int y=rand()%(n-x+1)+1;
			cout<<x<<' '<<y<<endl;
		}
	}
	return 0;
}
