#include<bits/stdc++.h>
using namespace std;
char s[200005];
int last[15],num[15];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>(s+1);
		int n=strlen(s+1);
		memset(last,0,sizeof(last));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;++i)last[s[i]-'0']=i;
		int now=1;
		for(int i=0;i<=9;++i){
			for(int j=1;j<=num[i];++j)cout<<i;
			if(last[i]<now)continue;
			for(int j=now;j<=last[i];++j){
				if(s[j]-'0'==i)cout<<i;
				else ++num[min(s[j]-'0'+1,9)];
			}
			now=last[i]+1;
		}
		cout<<"\n";
	}
	
	
	return 0;
}