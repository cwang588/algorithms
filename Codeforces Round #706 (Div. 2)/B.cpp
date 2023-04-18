#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,bool>m;
set<long long>s;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		s.clear();
		m.clear();
		long long Max=0;
		for(int i=1;i<=n;++i){
			long long tmp;
			scanf("%I64d",&tmp);
			s.insert(tmp);
			Max=max(Max,tmp);
			m[tmp]=true;
		}
		int Mex=0;
		while(m[Mex])++Mex;
		if(Max<Mex){
			printf("%d\n",Max+k+1);
			continue;
		}
		long long last=-1;
		while(k--){
			long long now=(Max+Mex-1)/2+1;
			Max=max(Max,now);
			m[now]=true;
			while(m[Mex])++Mex;
			s.insert(now);
			if(last==now)break;
			last=now;
		}
		printf("%d\n",s.size());
	}
	return 0;
}
