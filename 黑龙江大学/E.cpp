#include<bits/stdc++.h>
using namespace std;
char s[5005];
int main()
{
	cin>>s;
	int n=strlen(s),ans=0;
	for(int i=0;i<n-1;++i)
	{
		int now=0;
		for(int j=1;;++j)
		{
			if(i-j+1<0)
				break;
			if(j+i>n-1)
				break;
			if(s[i-j+1]==s[i+j]+'A'-'a'||s[i-j+1]==s[i+j]-'A'+'a')
			{
				++now;
				ans=max(ans,now);
			}
			else
				break;
		}
	}
	printf("%d",2*ans);
	return 0;
}
