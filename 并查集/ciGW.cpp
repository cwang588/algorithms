
#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

#include<stdlib.h>

#include<queue>

#include<map>

#include<vector>

#include<math.h>

const int INF = 0x3f3f3f3f;

using namespace std;

typedef long long ll;

typedef double ld;

typedef unsigned long long ull;

 

const int maxn=10000+5;

 

int p[maxn];//power值

 

//并查集

int fa[maxn];

int findset(int x)

{

    return fa[x]==-1? x:fa[x]=findset(fa[x]);

}

int bind(int u,int v)

{

    int fu=findset(u);

    int fv=findset(v);

    if(fu != fv)

    {

        if(p[fu]>p[fv] || (p[fu]==p[fv] && fu<fv) )//fu是根

        {

            fa[fv]=fu;

        }

        else//fv是根

        {

            fa[fu]=fv;

        }

        return 1;

    }

    return 0;

}

 

//边

struct Edge

{

    int u,v;

    Edge() {}

    Edge(int u,int v):u(u),v(v) {}

 

    bool operator<(const Edge &rhs)const

    {

        return u<rhs.u || (u==rhs.u && v<rhs.v);

    }

} edges[20000+5];

bool vis[20000+5];

 

//命令

struct command

{

    int type;

    int v;

} coms[50000+5];

 

int main()

{

    int n,m,Q;

    bool first=true;

    while(scanf("%d",&n)==1)

    {

        if(!first)

            printf("\n");

        first=false;

        for(int i=0; i<n; i++)

            scanf("%d",&p[i]);

        scanf("%d",&m);

        map<Edge,int> mp;//边与边的编号的映射

        for(int i=0; i<m; i++)

        {

            int u,v;

            scanf("%d%d",&u,&v);

            if(u>v)

                swap(u,v);

            edges[i]=Edge(u,v);//可优化

            mp[edges[i]]=i;

        }

        memset(vis,0,sizeof(vis));//vis[i]==true表第i条边已被删除

        scanf("%d",&Q);

        for(int i=0; i<Q; i++)

        {

            char str[100];

            int u,v;

 

            scanf("%s",str);

            if(str[0]=='q')

            {

                scanf("%d",&u);

 

                coms[i].type=0;

                coms[i].v=u;

            }

            else if(str[0]=='d')

            {

                scanf("%d%d",&u,&v);

                if(u>v) swap(u,v);

                int id=mp[Edge(u,v)];//获取对应边的编号

 

                vis[id]=1;//删除此边

                coms[i].type = 1;

                coms[i].v=id;

            }

        }

        //连通所有未被删除的边

        memset(fa,-1,sizeof(fa));

        for(int i=0; i<m; i++)if(vis[i]==false)

            {

                bind(edges[i].u,edges[i].v);

            }

        //逆序处理所有命令并将query结果保存在vc中

        vector<int> vc;

        for(int i=Q-1; i>=0; i--)

        {

            if(coms[i].type == 0)//query命令

            {

                int root = findset(coms[i].v);

                if(p[root]>p[coms[i].v])

                    vc.push_back(root);

                else

                    vc.push_back(-1);

            }

            else//destroy命令

            {

                int u=edges[coms[i].v].u, v=edges[coms[i].v].v;

                bind(u,v);

            }

        }

        for(int i=vc.size()-1; i>=0; i--)

            printf("%d\n",vc[i]);

    }

    return 0;

}


