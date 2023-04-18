#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	if(s=="10")return !printf("1\n");
	int n=s.size();
	bool ky=false;
	for(int i=1;i<n;++i)
	{
		if(s[i]=='1')
		{
			ky=true;
			break;
		}
	}
	int ans=(n-1)/2+1;
	if(!ky&&n%2)--ans;
	printf("%d\n",ans);
	return 0;
}
