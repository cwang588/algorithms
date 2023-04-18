#include<bits/stdc++.h>
using namespace std;
bool a[100005];
bool judge(int x)
{
	if(!a[x/2]||!a[(x-1)/2+1])return true;
	return false;
}
int main()
{
	a[1]=false;
	for(int i=2;i<=1000;++i)a[i]=judge(i);
	for(int i=1;i<=1000;++i)printf("%3d:%d\n",i,a[i]?1:0);	
	return 0;
}
