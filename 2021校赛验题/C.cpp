#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n,Max=-2147483647,Min=2147483647;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		int x=0,len=s.length();
		for(int i=2;i<len;++i)x=x*10+s[i]-'0';
		if(s[0]=='B')x*=-1;
		Max=max(Max,x);
		Min=min(Min,x);
	}
	if(n==1)return !printf("1\n");
	int ans=Max-Min;
	if(Max*Min>0)++ans;
	printf("%d\n",ans);
	return 0;
}
