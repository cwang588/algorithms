#include<bits/stdc++.h>
using namespace std;
int a[100005],sum[100005],remain[100005];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int y){
	while(x<=100001){
		sum[x]+=y;
		x+=lowbit(x);
	}
}
int ask(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
bool usd[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			usd[i]=false;
		}
		for(int i=1;i<=n;++i)if(a[i]<=q)usd[i]=true;
		int ans=0,start=1,cnt=0;
		for(int i=n;i>=1;--i){
			if(a[i]<=q){
				b[i]=q-a[i];
				if(b[i]<=100000)add(b[i]+1,1);
			}
			else{
				++cnt;
				if(cnt==q){
					start=i;
					break;
				}
			}
		}
		int now=0,ans=0,pos;
		for(int i=1;i<start;++i)if(a[i]<=q)++now;
		for(int i=start;i<=n;++i){
			if(a[i]<=q){
				++now;
				if(b[i]<=100000)add(b[i],-1);
				int tmp=now+cnt+query()
			}
			else 
		}
		cout<<"\n";
	}
	
	
	return 0;
}