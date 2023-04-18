#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
int a[1000005];
long long num[1050005];
void FWT_or(long long a[],int n){
    for(int i=2;i<=n;i<<=1)
        for(int p=i>>1,j=0;j<n;j+=i)
            for(int k=j;k<j+p;k++)
                a[k+p]+=a[k];
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],++num[a[i]];
		FWT_or(num,1048576);
		long long ans=0;
		for(int i=1;i<=n;++i)ans+=num[a[i]];
		cout<<ans<<"\n";
		for(int i=0;i<=1050000;++i)num[i]=0;
	}
	
	return 0;
}