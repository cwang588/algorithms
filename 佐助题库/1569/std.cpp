#include<bits/stdc++.h>
using namespace std;
int cnt[10005];
int main(){
//	freopen("15692.in","r",stdin);
//	freopen("15692.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;++i)++cnt[s[i]];
	for(int i=0;i<n;++i){
		if(cnt[s[i]]==1)return !printf("%c\n",s[i]);
	}
	printf("no\n");
	return 0;
}
