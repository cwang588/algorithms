//stl rope
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int maxn=1e6+7;//1e5¿É¹ý£¬1e6¿Õ¼äÕ¨ÁÑ 
rope<int> *r[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	r[0]=new rope<int>();	
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		r[0]->push_back(t);
	}
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		r[i]=new rope<int>(*r[x]);
		if(y==1)
		{
			int t;
			scanf("%d",&t);
			r[i]->replace(z-1,t);
		}
		else
			printf("%d\n",r[x]->at(z-1));
	}
	return 0;
}
