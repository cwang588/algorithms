#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
multiset<int>s;
struct Trie
{
	int num;
	int next[2];
}trie[2][3000005];
int cnt;
char tmp[35];
void insert(int now)
{
	int cur=0;
	for(int i=0;tmp[i]!=' ';++i)
	{
		int pos=trie[now][cur].next[tmp[i]-'0'];
		if(!pos)
			pos=trie[now][cur].next[tmp[i]-'0']=++cnt;
		cur=pos;
	}
	++trie[now][cur].num;
}
int finda(int now)
{
	work(now);
}
void work(int num)
{
	memset(tmp,0,sizeof(tmp));
	bitset<35>bit(num);
	for(int j=30;j>=0;--j)tmp[30-j]=bit[j]?'1':'0';
}
int ans[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			work(a[i]);
			s.insert(a[i]);
			insert(0);
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&b[i]);
			work(b[i]);
			insert(1);
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(int i=1;i<=n;++i)
		{
			auto noww=s.begin();
			int tmp1=a[*noww],tmp2=findb(tmp1),cntab=0;
			while(tmp1!=tmp2)
			{
				tmp1=tmp2;
				if(cntab%2)tmp2=findb(tmp1);
				else tmp2=finda(tmp1);
				++cntab;
			}
			s.erase(a[i]);
			ans[i]=tmp2^tmp1;
			work(tmp1);
			Delete(0);
			work(tmp2);
			Delete(1);
		}
		sort(ans+1,ans+1+n);
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
