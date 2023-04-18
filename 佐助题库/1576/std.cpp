#include<bits/stdc++.h>
using namespace std;
int cnt[250];
int main(){
///	freopen("1576.in","r",stdin);
//	freopen("1576.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		memset(cnt,0,sizeof(cnt)); 
		int n=s.length(),Max=0;
		for(int i=0;i<n;++i){
			if(i==0||s[i]!=s[i-1])cnt[i]=1;
			else cnt[i]=cnt[i-1]+1;
			Max=max(Max,cnt[i]);
		}
		for(int i=0;i<n;++i){
			if(cnt[i]==Max){
				cout<<s[i]<<' '<<cnt[i]<<"\n";
				break;
			}
		}
	}
	return 0;
}
