
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

 

int p[maxn];//powerֵ

 

//���鼯

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

        if(p[fu]>p[fv] || (p[fu]==p[fv] && fu<fv) )//fu�Ǹ�

        {

            fa[fv]=fu;

        }

        else//fv�Ǹ�

        {

            fa[fu]=fv;

        }

        return 1;

    }

    return 0;

}

 

//��

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

 

//����

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

        map<Edge,int> mp;//����ߵı�ŵ�ӳ��

        for(int i=0; i<m; i++)

        {

            int u,v;

            scanf("%d%d",&u,&v);

            if(u>v)

                swap(u,v);

            edges[i]=Edge(u,v);//���Ż�

            mp[edges[i]]=i;

        }

        memset(vis,0,sizeof(vis));//vis[i]==true���i�����ѱ�ɾ��

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

                int id=mp[Edge(u,v)];//��ȡ��Ӧ�ߵı��

 

                vis[id]=1;//ɾ���˱�

                coms[i].type = 1;

                coms[i].v=id;

            }

        }

        //��ͨ����δ��ɾ���ı�

        memset(fa,-1,sizeof(fa));

        for(int i=0; i<m; i++)if(vis[i]==false)

            {

                bind(edges[i].u,edges[i].v);

            }

        //���������������query���������vc��

        vector<int> vc;

        for(int i=Q-1; i>=0; i--)

        {

            if(coms[i].type == 0)//query����

            {

                int root = findset(coms[i].v);

                if(p[root]>p[coms[i].v])

                    vc.push_back(root);

                else

                    vc.push_back(-1);

            }

            else//destroy����

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


