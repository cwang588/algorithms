#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[105],n;
int db[15]={1,1,2,6,24,120,720};
struct k
{
	int ans;
	int p[105];
}r[1000000];
bool cmp(k a,k b)
{
	if(a.ans!=b.ans)
		return a.ans>b.ans;
	for(int i=1;i<=n;++i)
		if(a.p[i]!=b.p[i])
			return a.p[i]>b.p[i];
}
int main()
{
	freopen("db.txt","w",stdout);
	int now=1;	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		a[i]=i;
	for(int i=1;i<=n;++i)
		r[now].p[i]=a[i];
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]>a[j])
				++r[now].ans;
	while(next_permutation(a+1,a+1+n))
	{
		++now;
		for(int i=1;i<=n;++i)
			r[now].p[i]=a[i];
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(a[i]>a[j])
					++r[now].ans;
	}
	sort(r+1,r+1+db[n],cmp);
	for(int i=1;i<=db[n];++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",r[i].p[j]);
		printf("%d ",r[i].ans);
		int t=0;
		for(int j=1;j<=n;++j)
			t=t*(n+1)+r[i].p[j];
		printf("%d\n",t);
	}
	return 0;
}
