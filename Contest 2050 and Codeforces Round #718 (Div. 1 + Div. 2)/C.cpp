#include<bits/stdc++.h>
using namespace std;
int a[505],cnt[505],n,ans[505][505],mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool usd[505][505];
set<pair<int,int> >s[505];
int getnext(){
	for(int i=1;i<=n;++i){
	//	printf("%d\n",s[i].size());
		if(cnt[i]<i&&s[i].size()==1)return i;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),ans[i][i]=a[i],usd[i][i]=true,cnt[i]=1;
	s[a[1]].insert(make_pair(2,1));
	s[a[n]].insert(make_pair(n,n-1));
	for(int i=2;i<n;++i){
		s[a[i]].insert(make_pair(i,i-1));
		s[a[i]].insert(make_pair(i+1,i));
	}
	int nxt=getnext();
	while(nxt){
		auto it=s[nxt].begin();
		int x=(*it).first,y=(*it).second;
		ans[x][y]=nxt;
		++cnt[nxt];
		usd[x][y]=true;
		pair<int,int>tmp=make_pair(x,y);
		for(int i=1;i<=n;++i)s[i].erase(tmp);
		//for(int i=1;i<=n;++i)printf("%d\n",s[i].size());
		for(int i=0;i<4;++i){
			int tox=x+mov[i][0],toy=y+mov[i][1];
			if(!usd[tox][toy]&&tox>=toy&&tox<=n&&tox>0&&toy<=n&&toy>0)s[nxt].insert(make_pair(tox,toy));
		}
	//	for(int i=1;i<=n;++i)printf("%d\n",s[i].size());
		nxt=getnext();
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
