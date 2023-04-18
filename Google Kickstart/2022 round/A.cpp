#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,l;
		cin>>l>>n;
		long long ans=0;
		long long now=0;
		int last=0;
		for(int i=1;i<=n;++i){
			int x;
			char y;
			cin>>x>>y;
			if(y=='C'){
				if(last==0)last=1;
				if(last!=1){
					if((l-now)%l<=x){
						x-=(l-now)%l;
						now=0;
						last=1;
					}
					else{
						now+=x;
						continue;
					}
				}				
				now+=x;
				ans+=now/l;
				now%=l;
			}
			else{
				if(last==0)last=-1;
				if(last!=-1){
					if(now<=x){
						x-=now;
						now=0;
						last=-1;
					}
					else{
						now-=x;
						continue;
					}
				}
				long long tmp=(l-now)%l;				
				tmp+=x;
				ans+=tmp/l;
				tmp%=l;
				now=(l-tmp)%l;
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}