#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n,m;
	cin>>n>>m;
	if(n==1||m==1)return !printf("1\n");
	if((n*m)%2==0)cout<<n*m/2<<endl;
	else cout<<(n*m)/2+1<<endl;
	return 0;
}
