#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum1[500005],sum2[500005],num[500005][3][3];
int main(){
	int n;
	cin>>n;
	num[0][0][0]=1;
	long long ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]%=3;
		sum1[i]=(sum1[i-1]+a[i])%3;
		sum2[i]=(sum2[i-1]+a[i]*a[i])%3;
		for(int j=0;j<=2;++j){
			for(int k=0;k<=2;++k)num[i][j][k]=num[i-1][j][k];
		}
		if(!sum1[i]){
			if(!sum2[i])ans+=num[i][0][0]+num[i][1][2]+num[i][2][2];
			else if(sum2[i]==1)ans+=num[i][0][1]+num[i][1][0]+num[i][2][0];
			else ans+=num[i][0][2]+num[i][1][1]+num[i][2][1];
		}
		else if(sum1[i]==1){
			if(!sum2[i])ans+=num[i][0][2]+num[i][1][0]+num[i][2][2];
			else if(sum2[i]==1)ans+=num[i][0][0]+num[i][1][1]+num[i][2][0];
			else ans+=num[i][0][1]+num[i][1][2]+num[i][2][1];
		}
		else{
			if(!sum2[i])ans+=num[i][0][2]+num[i][1][2]+num[i][2][0];
			else if(sum2[i]==1)ans+=num[i][0][0]+num[i][1][0]+num[i][2][1];
			else ans+=num[i][0][1]+num[i][1][1]+num[i][2][2];
		}
		++num[i][sum1[i]][sum2[i]];
	}	
	cout<<ans<<endl;
	return 0;
}
