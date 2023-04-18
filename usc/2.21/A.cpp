#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[2005],Max1[2005],Max2[2005];
int lowbit(int x){
	return x&(-x);
}
void add1(int x,int y){
	while(x<=2000){
		Max1[x]=max(Max1[x],y);
		x+=lowbit(x);
	}
}
int ask1(int x){
	int re=0;
	while(x){
		re=max(re,Max1[x]);
		x-=lowbit(x);
	}
	return re;
}
void add2(int x,int y){
	while(x){
		Max2[x]=max(Max2[x],y);
		x-=lowbit(x);
	}
}
int ask2(int x){
	int re=0;
	while(x<=2000){
		re=max(re,Max2[x]);
		x+=lowbit(x);
	}
	return re;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int ans=0;
	for(int i=n;i>=1;--i){
		int now=getid(a[i]),Max1=ask1(now)+1,Max2=ask2(now)+1;
		ans=max(ans,Max1+Max2-1);
		add1(now,Max1);
		add2(now,Max2);
	}		
	cout<<ans<<"\n";
	return 0;
}