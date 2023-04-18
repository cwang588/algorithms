#include<bits/stdc++.h>
using namespace std;
struct answer{
	int x,y;
}ans[400006];
struct tmp1{
	int x,y;
	friend bool operator <(const tmp1 &a,const tmp1 &b){
		return a.x<b.x;
	}
};
struct tmp2{
	int x,y;
	friend bool operator <(const tmp2 &a,const tmp2 &b){
		return a.y<b.y;
	}
};
int a[10005],b[10005];
bool usda[10005],usdb[10005];
set<int>s;
set<tmp1>s1;
set<tmp2>s2;
bool cmp(answer p,answer q){
	if(p.x==q.x)return p.y<q.y;
	return p.x<q.x;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		s.clear(),s1.clear(),s2.clear();
		for(int i=1;i<=n;++i)usda[i]=usdb[i]=false;
		for(int i=1;i<=m;++i){
			cin>>a[i]>>b[i],usda[a[i]]=true,usdb[b[i]]=true;
			s1.insert(tmp1{a[i],b[i]});
			s2.insert(tmp2{a[i],b[i]});
		}
		for(int i=1;i<=n;++i){
			if(!usdb[i])s.insert(i);
		}
		int num=2*n-m,cnt=0;
		for(int i=1;i<=n;++i){
			if(!usda[i]){
				int now=*s.begin();
				s.erase(now);
				ans[++cnt]={i,now};
				s1.insert(tmp1{i,now});
				s2.insert(tmp2{i,now});
			}
		}
		for(int i=1;i<n;++i){
			tmp1 now1=*s1.begin();
			s1.erase(s1.begin());
			s2.erase(tmp2{now1.x,now1.y});
			tmp2 now2=*s2.begin();
			s2.erase(s2.begin());
			s1.erase(tmp1{now2.x,now2.y});
			ans[++cnt]={now1.x,now2.y};
			s1.insert(tmp1{now2.x,now1.y});
			s2.insert(tmp2{now2.x,now1.y});
		}
		tmp1 now=*s1.begin();
		ans[++cnt]={now.x,now.y};
		sort(ans+1,ans+1+cnt,cmp);
	//	assert(cnt==num);
		cout<<num<<"\n";
		for(int i=1;i<=num;++i)cout<<ans[i].x<<" "<<ans[i].y<<"\n";
	}
	return 0;
}