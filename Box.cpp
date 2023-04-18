#include<bits/stdc++.h>
using namespace std;
long long t[5];
long long w,h;
bool judge()
{
	long long a=t[1],b=t[2],c=t[3];
	if(a+2*c<=w&&2*b+2*c<=h)
		return true;
	if(a+2*c<=h&&2*b+2*c<=w)
		return true;
	if(a+2*c<=w&&a+2*b+c<=h)
		return true;
	if(a+2*c<=h&&a+2*b+c<=w)
		return true;
	if(a+b+c<=w&&a+2*b+c<=h)
		return true;
	if(a+b+c<=h&&a+2*b+c<=w)
		return true;
	if(a+b+c<=w&&2*b+2*c<=h)
		return true;
	if(a+b+c<=h&&2*b+2*c<=w)
		return true;
	if(3*a+b+c<=w&&b+c<=h)
		return true;
	if(3*a+b+c<=h&&b+c<=w)
		return true;
	if(a+b+c<=w&&2*a+b+c<=h)
		return true;
	if(a+b+c<=h&&2*a+b+c<=w)
		return true;	
	if(2*a+2*b<=w&&a+b+2*c<=h)
		return true;
	if(2*a+2*b<=h&&a+b+2*c<=w)
		return true;
	return false;
}
int main()
{
	cin>>t[1]>>t[2]>>t[3]>>w>>h;
	sort(t+1,t+4);
	if(judge())
		return !printf("Yes\n");
	while(next_permutation(t+1,t+4))
		if(judge())
			return !printf("Yes\n");
	printf("No\n");
	return 0;
}
