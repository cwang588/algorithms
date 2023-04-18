#include<bits/stdc++.h>
using namespace std;
char s[100005];
int a[100005];
int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k>>(s+1);
		int num=0,tot=k*2,now=0,cnt=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='W'){
				++tot;
				if(s[i-1]=='W')++tot;
			}
			else{
				++cnt;
				if(s[i-1]=='W')now=i;
				if(s[i+1]=='W'&&now)a[++num]=i-now+1;
			}
		}
		if(cnt<=k){
			printf("%d\n",2*n-1);
			continue;
		}
		if(cnt==n){
			printf("%d\n",k?2*k-1:0);
			continue;
		}
		sort(a+1,a+1+num);
		for(int i=1;i<=num;++i){
			if(k>=a[i])++tot,k-=a[i];
			else break;
		}
		printf("%d\n",tot);
	}
	
	return 0;
}
