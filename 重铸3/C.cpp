#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool usd[100005];
int main(){
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=1;i<=k;++i)cin>>a[i],usd[a[i]]=true;
	sort(a+1,a+1+n);
	int ans=0,l=1,r=0,cnt=0;
	while(r<m){
		++r;
		if(usd[r])++cnt;
	}
	if(cnt<2){
		if(cnt==1){
			++ans;
			++cnt;
			if(usd[r])usd[r-1]=true;
			else usd[r]=true;
		}
		else{
			ans+=2;
			cnt+=2;
			int tmp=0;
			for(int i=r;i>=l;--i){
				if(!usd[i]){
					++tmp;
					usd[i]=true;				
				}
				if(tmp==2)break;
			}
		}
	}
	while(r<n){
		++r;
		if(usd[r])++cnt;
		if(usd[l])--cnt;
		++l;
		if(cnt<2){
			if(cnt==1){
				++ans;
				++cnt;
				if(usd[r])usd[r-1]=true;
				else usd[r]=true;
			}
			else{
				ans+=2;
				cnt+=2;
				int tmp=0;
				for(int i=r;i>=l;--i){
					if(!usd[i]){
						++tmp;
						usd[i]=true;				
					}
					if(tmp==2)break;
				}
			}
		} 
	}
	cout<<ans<<endl;
	return 0;
}
