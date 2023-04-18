#include<bits/stdc++.h>
using namespace std;
char s[500005];
int l[500005],r[500006],degree[500005];
long long num[1000005]; 
int main(){
	long long n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>s[i]>>l[i]>>r[i],++degree[l[i]],++degree[r[i]];
	queue<int>q;
	for(int i=1;i<=m;++i)if(!degree[i])q.push(i);
	num[1]=n;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(s[now]=='L'){
			num[l[now]]+=num[now]-num[now]/2;
			num[r[now]]+=num[now]/2;
		}
		else{
			num[r[now]]+=num[now]-num[now]/2;
			num[l[now]]+=num[now]/2;
		}
		--degree[l[now]];
		--degree[r[now]];
		if(l[now]!=r[now]){
			if(l[now]&&!degree[l[now]])q.push(l[now]);
			if(r[now]&&!degree[r[now]])q.push(r[now]);
		}
		else{
			if(l[now]&&!degree[l[now]])q.push(l[now]);
		}
	}
	for(int i=1;i<=m;++i){
		if(num[i]%2==0)cout<<s[i];
		else{
			if(s[i]=='L')cout<<"R";
			else cout<<"L";
		}
	}
	return 0;
}
