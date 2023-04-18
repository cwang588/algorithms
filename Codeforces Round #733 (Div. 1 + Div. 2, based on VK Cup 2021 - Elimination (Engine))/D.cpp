#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
bool usd[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)usd[i]=false,b[i]=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			if(!usd[a[i]]){
				b[i]=a[i];
				usd[a[i]]=true;
				++ans;
			}
		}
		int now=1;
		for(int i=1;i<=n;++i){
			if(!b[i]){
				while(usd[now])++now;
				b[i]=now++;
			}
		}
		int last=0;
		for(int i=1;i<=n;++i){
			if(b[i]==i){
				if(last){
					swap(b[last],b[i]);
					last=0;
				}
				else last=i;
			}
		}
		if(last){
			for(int i=1;i<=n;++i){
				if(a[i]!=b[i]){
					if(b[i]!=last&&b[last]!=i){
						swap(b[i],b[last]);
						break;
					}
				}
				else{
					if(last!=i&&a[i]==a[last]){
						swap(b[i],b[last]);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;++i)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
