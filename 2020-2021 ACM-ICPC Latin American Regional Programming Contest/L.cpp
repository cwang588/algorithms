#include<bits/stdc++.h>
using namespace std;
struct act{
	int s,d;
}a[10005];
int main(){
	int n,x;	
	cin>>n>>x; 
	for(int i=1;i<=n;++i)cin>>a[i].s>>a[i].d;
	int ans=2147483647,pos;
	for(int i=0;i<=480;++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(a[j].s+a[j].d<i)continue;
			if(a[j].s<=i)cnt+=(a[j].d-i+a[j].s)/x+1;
			else cnt+=(a[j].s+a[j].d-i)/x-(a[j].s-i-1)/x;
		}
		if(cnt<ans){
			ans=cnt;
			pos=i;
		}
	} 
	cout<<pos<<" "<<ans<<endl;
	return 0;
}
