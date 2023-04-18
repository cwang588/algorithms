#include<bits/stdc++.h>
using namespace std;
int a[5][5];
bool check(int a,int b,int c){
	return a+c==b*2;
}
int calc(){
	int re=0;
	if(check(a[1][1],a[2][2],a[3][3]))++re;
	if(check(a[3][1],a[2][2],a[1][3]))++re;
	if(check(a[2][1],a[2][2],a[2][3]))++re;
	if(check(a[1][2],a[2][2],a[3][2]))++re;
	return re;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		for(int i=1;i<=3;++i)cin>>a[1][i];
		cin>>a[2][1]>>a[2][3];
		for(int i=1;i<=3;++i)cin>>a[3][i];
		int num=0;
		if(check(a[1][1],a[1][2],a[1][3]))++num;
		if(check(a[3][1],a[3][2],a[3][3]))++num;
		if(check(a[1][1],a[2][1],a[3][1]))++num;
		if(check(a[1][3],a[2][3],a[3][3]))++num;
		int ans=num;
		a[2][2]=(a[1][1]+a[3][3])/2;
		ans=max(ans,num+calc());
		a[2][2]=(a[3][1]+a[1][3])/2;
		ans=max(ans,num+calc());
		a[2][2]=(a[1][2]+a[3][2])/2;
		ans=max(ans,num+calc());
		a[2][2]=(a[2][1]+a[2][3])/2;
		ans=max(ans,num+calc());
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}