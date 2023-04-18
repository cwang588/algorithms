#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n=rand()%5+2,m=rand()%5+2;
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cout<<rand()%15<<' ';
		cout<<endl;
	}
	return 0;
}
