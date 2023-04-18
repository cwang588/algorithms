#include<bits/stdc++.h>
#define LL long long int
using namespace std;
const int maxn=1000005,INF=2000000000,P=1000000007;
int K,M;
bool vis[maxn];
void bfs()
{
	queue<LL> q;
	queue<vector<int> > q2;
	vector<int> s;
	for(int i=1;i<K;i++)
	{
		q.push(i%M);
		vis[i%M]=true;
		s.push_back(i);
		q2.push(s);
		s.pop_back();
	}
	LL u,k;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		s=q2.front();
		q2.pop();
		for(int i=0;i<K;i++)
		{
			k=(u*10+i)%M;
			s.push_back(i);
			if(!k){

				for(unsigned int j=0;j<s.size();j++) 
					printf("%d",s[j]);
				cout<<endl;
				return;
			}
			else if(!vis[k])
			{
				vis[k]=true;
				q.push(k);
				q2.push(s);
			}
			s.pop_back();
		}
	}
}
int main()
{
	cin>>K>>M;
	bfs();
	return 0;
}

