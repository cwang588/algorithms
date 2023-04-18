#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sb10.in","w",stdout);
	srand((unsigned)time(0));
	int n;
	n=300000;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
	{
		int t=rand()*rand();
		t%=1048576;
		++t;
		cout<<t<<' ';
	}
	cout<<endl;
	return 0;
}
