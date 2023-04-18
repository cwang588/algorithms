#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=2;
	cout<<t<<endl;
	while(t--)
	{
		srand((unsigned)time(NULL));
		int n=rand()%10+5,m=rand()%5+3;
		cout<<n<<' '<<m<<endl;
		while(m--)
		{
			int l=rand()%n+1,r=rand()%n+1;
			cout<<min(l,r)<<' '<<max(l,r)<<endl;
		}
	}
	return 0;
}
