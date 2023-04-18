#include<bits/stdc++.h>
using namespace std;
int a[300005],sum[600005];
int lowbit(int x){
	return x&(-x);
}
int n;
int query(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void add(int x){
	while(x<=n*2){
		++sum[x];
		x+=lowbit(x);
	}
}
int main(){
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i],v.push_back(a[i]),v.push_back(k/a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	long long ans1=0,ans2=0,ans3=0;
	for(int i=1;i<=n;++i){
		if(k%a[i]){
			long long tmp=k/a[i];
			int now=query(getid(tmp));
			ans1+=now;
			ans3+=i-1-now;
		}
		else{
			long long tmp=k/a[i];
			int now1=query(getid(tmp)),now2=query(getid(tmp)-1);
			ans1+=now2;
			ans2+=now1-now2;
			ans3+=i-1-now1;
		}
		add(getid(a[i]));
	}
	cout<<ans3<<" "<<ans2<<" "<<ans1;
	return 0;
}