#include<bits/stdc++.h>
using namespace std;
char a[25],b[25];
bool judgea(int now,int tot){
	a[0]=a[now];
	for(int i=now+1;i<=tot;++i){
		if(a[i%now]!=a[i])return false;
	}
	return true;
}
bool judgeb(int now,int tot){
	b[0]=b[now];
	for(int i=now+1;i<=tot;++i){
		if(b[i%now]!=b[i])return false;
	}
	return true;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>(a+1)>>(b+1);
		int n,m,len1=strlen(a+1),len2=strlen(b+1);
		for(int i=1;i<=len1;++i){
			if(len1%i==0&&judgea(i,len1)){
				n=i;
				break;
			}
		}
		for(int i=1;i<=len2;++i){
			if(len2%i==0&&judgeb(i,len2)){
				m=i;
				break;
			}
		}
		if(n!=m){
			printf("-1\n");
			continue;
		}
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i]){
				ky=false;
				break;
			}
		}
		if(!ky){
			printf("-1\n");
			continue;
		}
		int num=(len1*len2/n/m)/gcd(len1/n,len2/m);
		for(int i=1;i<=num;++i){
			for(int j=1;j<=n;++j)cout<<a[j];
		}
		cout<<"\n";
	}	
	return 0;
}
