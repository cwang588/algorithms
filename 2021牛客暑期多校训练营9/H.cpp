#include<bits/stdc++.h>
using namespace std;
long long a[100005],bkx[4],mi[1004];
int work(int &n){
	long long tot=0;
	for(int i=1;i<=20;++i){
		tot+=mi[i];
		if(tot>=n){
			n-=tot-mi[i];
			return i;
		}
	}
}
int main(){
	int n,cnt=0;
	cin>>n;
	mi[0]=1;
	for(int i=1;i<=20;++i)mi[i]=mi[i-1]*3;
	bkx[0]=2;
	bkx[1]=3;
	bkx[2]=6;
	int num=work(n);
	--n;
	while(n){
		a[++cnt]=n%3;
		n/=3;
	}
	for(int i=num;i>=1;--i)cout<<bkx[a[i]];
	return 0;
}
