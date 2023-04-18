#include<bits/stdc++.h>
using namespace std;
char a[55],b[55];
int cnt[50];
int main(){
	int n,x=0,y=0;
	cin>>n>>(a+1)>>(b+1);
	for(int i=1;i<=n;++i){
		if(a[i]==b[i]){
			++x;
		}else{
			++cnt[a[i]-'A'];
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]==b[i])continue;
		if(cnt[b[i]-'A']){
			++y;
			--cnt[b[i]-'A'];
		}
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}