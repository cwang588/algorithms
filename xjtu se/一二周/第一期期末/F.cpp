#include<bits/stdc++.h>
using namespace std;
char a[2000005],b[2000005];
long long num[50];
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b;
	int l1=strlen(a),l2=strlen(b);
	long long ans=(long long)l1*l2;
	for(int i=0;i<l2-1;++i)++num[b[i]-'a'];
	for(int i=1;i<l1;++i)ans-=num[a[i]-'a'];
	printf("%lld\n",ans);
	return 0;
}
