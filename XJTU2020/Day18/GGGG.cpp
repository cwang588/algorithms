#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
using namespace std;
map<string,int>mp;
bool G[222][222];
int laspos[222];
vector<int>to[MAXN];
int idx[MAXN];
int indu[MAXN];
string name[222];
struct SS
{
    int id,val;
    bool operator<(const SS&R)const
    {
        return val>R.val;
    }
};
void work() 
{
    int S,L,n;
    cin>>S>>L>>n;
    for(int i=1;i<=S;i++)
    {
        string str;cin>>str;
        mp[str]=1;laspos[i]=-1;
    }
    int cntm=0;
    for(auto &x:mp)
    {
        x.second=++cntm;
        name[cntm]=x.first;
    }
    for(int i=1;i<=L;i++)
    {
        string str;
        cin>>str;
        int u=mp[str];
        cin>>str;
        int v=mp[str];
        G[u][v]=G[v][u]=1;
    }
    for(int i=1;i<=n;i++)
    {
        string str;cin>>str;
        int now=mp[str];idx[i]=now;
        for(int j=1;j<=S;j++)
        {
            if(G[j][now])continue;
            if(laspos[j]==-1)continue;
            to[laspos[j]].push_back(i);
            indu[i]++;
        }
        laspos[now]=i;
    }
    priority_queue<SS>pq;
    for(int i=1;i<=n;i++)
    {
        if(indu[i]==0)pq.push({i,idx[i]});
    }
    int cntb=0;
    while(!pq.empty())
    {
        cntb++;
        SS tmp=pq.top();pq.pop();
        cout<<name[tmp.val]<<' ';
        for(int i=0;i<to[tmp.id].size();i++)
		{
            int v=to[tmp.id][i];
            indu[v]--;
            if(indu[v]==0)pq.push({v,idx[v]});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}
