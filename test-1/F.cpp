#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	bool ky=false;
	for(int i=0;5*i<=n;++i)
		for(int j=0;5*i+3*j<=n;++j)
			if(n-i-j==(n-5*i-3*j)*3)
			{	
				cout<<i<<' '<<j<<' '<<n-i-j<<"\n";
				ky=true;
			}
	if(!ky)cout<<"No Answer.\n";
	return 0;
}
