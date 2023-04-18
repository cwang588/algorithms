#include<bits/stdc++.h>
using namespace std;
long long s[105][105];
int main()
{
	for(int i=0;i<=26;++i)
		s[i][0]=1;
	for(int i=1;i<=26;++i)
	{
		for(int j=1;j<=i;++j)
			s[i][j]=s[i-1][j-1]+j*s[i-1][j],cout<<s[i][j]<<' '; 
		cout<<endl;
	}
	return 0;
}
