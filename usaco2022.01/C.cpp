#include<bits/stdc++.h>
using namespace std;
struct cow{
	int a,b,id;
}c[100005];
bool cmp(cow x,cow y){
	if(x.a!=y.a)return x.a<y.a;
	return x.b<y.b;
}
bool usd[100005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>c[i].a>>c[i].b,c[i].id=i;
	int cnt=0;
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;++i){
		if(!usd[c[i].a]){
			usd[c[i].a]=true;
		}
		else{
			if(!usd[c[i].b]){
				usd[c[i].b]=true;
			}
			else ++cnt;
		}
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=n;++i)cout<<c[i].id<<"\n";
	return 0;
}