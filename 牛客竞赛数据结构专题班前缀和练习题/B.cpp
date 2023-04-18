#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b[2000005],c[2000005];
void FWT_or(long long a[],int n){
	for(int i=2;i<=n;i<<=1)
		for(int p=i>>1,j=0;j<n;j+=i)
			for(int k=j;k<j+p;k++)
				a[k+p]+=a[k];
}
void FWT_and(long long a[],int n){
	for(int i=2;i<=n;i<<=1)
		for(int p=i>>1,j=0;j<n;j+=i)
			for(int k=j;k<j+p;k++)
				a[k]+=a[k+p];
}
long long mi[25];
int main(){
	mi[0]=1;
	for(int i=1;i<=23;++i)mi[i]=mi[i-1]*2;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=0;i<mi[n];++i){
		for(int j=1;j<=n;++j){
			if(mi[j-1]&i){
				b[i]^=a[j];
				c[i]^=a[j];
			}
		}
	}
	FWT_or(b,mi[n]);
	FWT_and(c,mi[n]);
	for(int i=1;i<=m;++i){
		int num,tot=0;
		cin>>num;
		while(num--){
			int t;
			cin>>t;
			tot+=mi[t-1];
		}
		cout<<b[tot]<<" "<<c[tot]<<endl;
	}
	return 0;
}
