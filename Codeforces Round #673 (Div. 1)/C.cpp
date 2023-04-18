#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005],sum[300005],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	long long ansnum=0,tmp=0;
	for(int i=29;i>=0;--i){
		int now=(1<<i);
		long long num1=0,num2=0;
		for(int l=1,r;l<=n;l=r+1){
			int cnt1=0,cnt2=0;
			for(r=l;r+1<=n&&(a[r]&tmp)==(a[r+1]&tmp);++r);
			for(int j=l;j<=r;++j){
				if(a[j]&now){
					++cnt2;
					num2+=cnt1;
				}
				else{
					++cnt1;
					num1+=cnt2;
				}
			}
		}
		if(num1<=num2){
			ansnum+=num1;
			int num=0;
			for(int l=1,r;l<=n;l=r+1){
				for(r=l;r+1<=n&&(a[r]&tmp)==(a[r+1]&tmp);++r);
				for(int j=l;j<=r;++j)if(!(a[j]&now))b[++num]=a[j];
				for(int j=l;j<=r;++j)if(a[j]&now)b[++num]=a[j];
			} 
		}
		else{
			ansnum+=num2;
			ans+=now;
			int num=0;
			for(int l=1,r;l<=n;l=r+1){
				for(r=l;r+1<=n&&(a[r]&tmp)==(a[r+1]&tmp);++r);
				for(int j=l;j<=r;++j)if(a[j]&now)b[++num]=a[j]^now;
				for(int j=l;j<=r;++j)if(!(a[j]&now))b[++num]=a[j]^now;
			} 
		} 
		tmp+=now;
		for(int j=1;j<=n;++j)a[j]=b[j];
	}
	printf("%lld %d\n",ansnum,ans);
	return 0;
}
