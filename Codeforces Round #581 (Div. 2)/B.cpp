#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	int L=min(l,n),R=min(r,n);
	printf("%d %d\n",(int)pow(2,L)-1+n-L,(int)pow(2,R)-1+(n-R)*(int)pow(2,R-1));
	return 0;
}
