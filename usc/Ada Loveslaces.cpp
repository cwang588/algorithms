#include<bits/stdc++.h>
using namespace std;
vector<double>len;
int n;
double d,s,t,f1,f2;
double calc(int x,int y){
	double a=abs(x-y)*d;
	return 2*sqrt(a*a+s*s);
}
int getans(double x,double y){
	int re=0;
	for(const auto &v:len){
		if(x<=v&&v<=y)++re;
	}
	return re;
//	if(y<len[0])return 0;
//	if(x>len[len.size()-1])return 0;
//	int ans1=0,ans2=0;
//	if(len[0]>=x)ans1=-1;
//	else{
//		int l=0,r=len.size();
//		while(l<r-1){
//			int m=(l+r)>>1;
//			if(len[m]<x)l=m;
//			else r=m;
//		}
//		ans1=l;
//	}
//	if(len[len.size()-1]<=y)ans2=len.size()-1;
//	else{
//		int l=0,r=len.size()-1;
//		while(l<r-1){
//			int m=(l+r)>>1;
//			if(len[m]<=x)l=m;
//			else r=m;
//		}
//		ans2=l;
//	}
//	return ans2-ans1;
}
void dfs(int state,int now,double tot){
	if(now==n-1){
		len.push_back(tot);
		return;
	}
	for(int i=0;i<n;++i){
		if((1<<i)&state)continue;
		dfs(state|(1<<i),i,tot+calc(i,now)+2*t);
		if(i==now-1||i==now+1)dfs(state|(1<<i),i,tot+2*t+2*d);
	}
}
int main(){
	cin>>n>>d>>s>>t>>f1>>f2;
	dfs(1,0,2*t+s);
	sort(len.begin(),len.end());
	double L;
	while(cin>>L){
		double l=L-f2*2,r=L-f1*2;
		cout<<getans(l,r)<<"\n";
	}
	return 0;
}