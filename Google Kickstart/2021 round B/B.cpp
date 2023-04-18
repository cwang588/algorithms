#include<bits/stdc++.h>
using namespace std;
int a[300005],l[300005],r[300005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		cout<<"Case #"<<Case<<": ";
		if(n==2){
			cout<<"2\n";
			continue;
		}
		if(n==3){
			cout<<"3\n";
			continue;
		}
		l[1]=1,l[2]=2;
		for(int i=3;i<=n;++i){
			if(a[i]-a[i-1]==a[i-1]-a[i-2])l[i]=l[i-1]+1;
			else l[i]=2;
		}
		r[n]=1,r[n-1]=2;
		for(int i=n-2;i>=1;--i){
			if(a[i]-a[i+1]==a[i+1]-a[i+2])r[i]=r[i+1]+1;
			else r[i]=2;
		}
		int ans=0;
		l[0]=r[n+1]=0;
		for(int i=1;i<=n;++i){
			ans=max(ans,l[i-1]+1);
			ans=max(ans,r[i+1]+1);
			if(i==1||i==n)continue;
			if(i==2){
				if(a[1]%2==a[3]%2&&(a[3]-a[4])*2==a[1]-a[3])ans=max(ans,r[3]+2);
			}
			else if(i==n-1){
				if(a[n]%2==a[n-2]%2&&(a[n-2]-a[n-3])*2==a[n]-a[n-2])ans=max(ans,l[n-2]+2);
			}
			else{
				if(a[i-1]%2==a[i+1]%2){
					ans=max(ans,3);
					if(a[i+1]-a[i-1]==(a[i+2]-a[i+1])*2)ans=max(ans,r[i+1]+2);
					if(a[i+1]-a[i-1]==(a[i-1]-a[i-2])*2)ans=max(ans,l[i-1]+2);
					if(a[i+1]-a[i-1]==(a[i-1]-a[i-2])*2&&a[i+1]-a[i-1]==(a[i+2]-a[i+1])*2)ans=max(ans,l[i-1]+r[i+1]+1);			
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}