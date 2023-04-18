#include<bits/stdc++.h>
using namespace std;
const long long MAX=1000000000000000000;
struct query{
	long long n;
	int id;
	long long ans;
}q[100005];
vector<long long>v; 
bool cmp(query x,query y){
	return x.n<y.n;
}
bool cmpp(query x,query y){
	return x.id<y.id;
}
int main(){
	int t; 
	cin>>t;
	for(int i=1;i<=t;++i)cin>>q[i].n,q[i].id=i;
	sort(q+1,q+1+t,cmp);
	for(int i=1;i<=t;++i)v.push_back(q[i].n); 
	for(long long i=2;i<=1000000;++i){
		long long a=i,b=i*i*i;
		while(b<=MAX){
			int now=lower_bound(v.begin(),v.end(),b)-v.begin()+1;
			++q[min(t+1,now)].ans;
			if(i>=10000)break;
			long long tmp=b*i*i-a;
			a=b;
			b=tmp;
		}
	}
	q[0].ans=0;
	for(int i=1;i<=t;++i)q[i].ans+=q[i-1].ans;
	sort(q+1,q+1+t,cmpp);
	for(int i=1;i<=t;++i)cout<<(q[i].ans+1)<<endl;
	return 0;
} 
