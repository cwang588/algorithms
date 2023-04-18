#include<bits/stdc++.h>
using namespace std;
struct ship{
	int t,k;
	vector<int>x;
}sh[100005];
set<int>s;
map<int,int>tong;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&sh[i].t,&sh[i].k);
		for(int j=1;j<=sh[i].k;++j){
			int tmp;
			scanf("%d",&tmp);
			sh[i].x.push_back(tmp);
		}
	}
	int l=1,r=1;
	for(int i=0;i<sh[1].x.size();++i)s.insert(sh[1].x[i]),++tong[sh[1].x[i]];
	printf("%d\n",s.size());
	for(int i=2;i<=n;++i){
		int nowt=sh[i].t;
		while(!(nowt-86400<sh[l].t)){
			for(int j=0;j<sh[l].x.size();++j){
				--tong[sh[l].x[j]];
				if(!tong[sh[l].x[j]])s.erase(sh[l].x[j]);
			}
			++l;
		}
		++r;
		for(int j=0;j<sh[r].x.size();++j)s.insert(sh[r].x[j]),++tong[sh[r].x[j]];
		printf("%d\n",s.size());
	}
	return 0;
}
