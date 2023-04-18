#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
struct Trie
{
	int num,fail;
	int next[26];
	Trie()
	{
		this->num=0;
		this->fail=-1;
		for(int i=0;i<26;++i)
			this->next[i]=0;
	}
}trie[40*N];
int cnt;
char t[200005];
char S[2000005];
void insert(char *s)
{
	int cur=0;
	for(int i=0;s[i]!=' ';++i)
	{
		int pos=trie[cur].next[s[i]-'a'];
		if(!pos)
			pos=trie[cur].next[s[i]-'a']=++cnt;
		cur=pos;
	}
	++trie[cur].num;
}
void build()
{
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=0;i<26;++i)
		{
			int &cur=trie[t].next[i];
			
		}
	}
}
int main()
{
	int n;
	cin>>S;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>t;
		insert(t);
	}
	build();
	return 0;
}
