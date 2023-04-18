#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
long long num(long long l,long long r,long long k)
{
	return r/k-(l-1)/k; 
}
int main()
{
	while(cin>>a>>b>>c>>d)
	{
		long long ans=1;
		ans*=num(a,b,3)+num(a,b,673)-num(a,b,2019);
		ans*=num(c,d,3)+num(c,d,673)-num(c,d,2019);
		cout<<ans<<endl;
	}
	return 0;
}
