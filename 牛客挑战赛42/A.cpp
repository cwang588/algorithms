#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		int l=s.size();
		if(s[l-2]=='A'&&s[l-1]=='K')
		{
			for(int j=0;j<l-2;++j)
				cout<<s[j];
			return 0;
		}
	}
	return 0;
}
