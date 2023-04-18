#include<cstdio>
#include<algorithm>
using namespace std;
char x[200005];
int tong[26];
int main()
{
	int cnt=0;
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",x);
	int now=0;
	while(now<n)
	{
		bool you=true;
		for(int i=1;i<k;++i)
			if(x[now+i]!=x[now])
			{
				you=false;
				now+=i;
				break;
			}
		if(you)
		{
			++tong[x[now]-'a'];
			cnt=max(cnt,tong[x[now]-'a']);
			now+=k;
		}
	}
	printf("%d",cnt);
	return 0;
}
