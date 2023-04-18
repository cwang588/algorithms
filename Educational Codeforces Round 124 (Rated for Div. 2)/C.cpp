#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
set<long long>s[2];
long long getans(long long now,int id){
	auto it=s[id].lower_bound(now);
	long long re=abs(*it-now);
	--it;
	re=min(re,abs(*it-now));
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		s[0].clear(),s[1].clear();
		s[0].insert(-214743647000);
		s[0].insert(214743647000);
		s[1].insert(-214743647000);
		s[1].insert(214743647000);
		for(int i=1;i<=n;++i)cin>>a[i],s[0].insert(a[i]);
		for(int i=1;i<=n;++i)cin>>b[i],s[1].insert(b[i]);
		long long ans=min(abs(a[1]-b[1])+abs(a[n]-b[n]),abs(a[n]-b[1])+abs(a[1]-b[n]));
		long long a1=getans(a[1],1),an=getans(a[n],1);
		long long b1=getans(b[1],0),bn=getans(b[n],0);
		ans=min(ans,abs(a[1]-b[1])+an+bn);
		ans=min(ans,abs(a[n]-b[n])+a1+b1);
		ans=min(ans,abs(a[n]-b[1])+a1+bn);
		ans=min(ans,abs(a[1]-b[n])+an+b1);
		ans=min(ans,a1+b1+an+bn);
		cout<<ans<<"\n";
	}
	
	
	return 0;
}