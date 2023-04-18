#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main()
{
	cin>>a;
	int ans=0;
	for(int i=1;i<strlen(a);++i)
		if(a[i]!=a[i-1])
			++ans;
	if(a[strlen(a)-1]=='0')
		++ans;
	cout<<ans;
	return 0;
}
