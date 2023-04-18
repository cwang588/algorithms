#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	freopen("semipal.in","r",stdin);
	freopen("semipal.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long k;
		cin>>n>>k;
		--k;
		k*=2;
		bitset<63>bit(k);
		if(bit[n-1]!=bit[0])
			bit^=1;
		for(int i=n-1;i>=0;--i)
		{
			if(bit[i])
				cout<<'b';
			else
				cout<<'a';
		}
		cout<<endl;
	}
	return 0;
}
