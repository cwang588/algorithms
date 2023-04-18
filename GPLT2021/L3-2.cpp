#include<bits/stdc++.h>
using namespace std;
vector<int>nxt[100005];
int cd[105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int num;
		scanf("%d",&num);
		while(num--){
			int tmp;
			scanf("%d",&tmp);
			nxt[i].push_back(tmp);
		}
	}
	int point=1;
	for(int i=1;i<=m;++i){
		int type,now;
		scanf("%d%d",&type,&now);
		if(type==0)point=nxt[point][now-1];
		else if(type==1){
			cd[now]=point;
			printf("%d\n",point);
		}
		else point=cd[now];
	}
	printf("%d\n",point);
	return 0;
}
