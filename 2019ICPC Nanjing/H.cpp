#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==1&&b==0&&c==0)return !printf("YES\n0\n");
	if(a<=b+c)return !printf("NO\n");
	printf("YES\n%d\n",2*(b+c)+1);
	return 0;
}
