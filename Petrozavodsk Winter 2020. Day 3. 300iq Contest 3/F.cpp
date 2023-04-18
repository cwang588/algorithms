#include<bits/stdc++.h>
using namespace std;
long long h[300005],l[300005],r[300005];
int main(){
	int n;
	cin>>n;
	long long a,b;
	cin>>a>>b;
	for(int i=1;i<=n;++i){
		cin>>h[i];
		r[i]=(h[i]-1)/b+1;
		int re=h[i]%b;
		if(!re)re+=b;
		l[i]=(h[i]-re)/b-((re-1)/a+1);
	}
	int ans=n;
	priority_queue<long long>q;
	long long t1=0,t2=0;
	for(int i=1;i<=n;++i){
		q.push(r[i]-l[i]);
		t1-=l[i];
		while(t1>t2+1){
			t2+=q.top();
			q.pop();
			--ans;
		}
	}
	cout<<ans<<"\n";
	return 0;
}