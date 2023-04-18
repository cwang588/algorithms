#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	if(c-a-b>0&&a*b*(long long)4<(c-a-b)*(c-a-b))printf("Yes\n");
	else printf("No\n");	
	return 0;
}
