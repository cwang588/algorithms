#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n,m;
unsigned long long h[1000006],mi[1000006],b=19260817;
unsigned long long gethash(int l,int r){
	return h[r]-h[l-1]*mi[r-l+1];
}
bool check(int len,int x,int y){
	return gethash(x,x+len-1)==gethash(y,y+len-1);
}
bool cmp(int x,int y){
	int l=0,r=m+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid,x,y))l=mid;
		else r=mid;		
	}
	if(l<m&&s[x+l]<s[y+l])return true;
	return false;
}
int main(){
	mi[0]=1;
	for(int i=1;i<=1000000;++i)mi[i]=mi[i-1]*b;
	int t;
	cin>>t;
	while(t--){
		unordered_map<unsigned long long,int>cnt;
		cin>>(s+1)>>m;
		n=strlen(s+1);
		for(int i=1;i<=n;++i)h[i]=h[i-1]*b+s[i];
		for(int i=1;i+m-1<=n;++i)++cnt[gethash(i,i+m-1)];
		int Max=0,pos;
		for(int i=1;i+m-1<=n;++i){
			unsigned long long nowhash=gethash(i,i+m-1);
			if(cnt[nowhash]>Max){
				Max=cnt[nowhash];
				pos=i;
			}
			else if(cnt[nowhash]<Max);
			else{
				if(cmp(i,pos))pos=i;
			}
		}
		for(int i=1;i<=m;++i)cout<<s[pos+i-1];
		cout<<" "<<Max<<"\n";
	}
	return 0;
}