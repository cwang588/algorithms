#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("15781.in","r",stdin);
//	freopen("15781.out","w",stdout);
	string s[1005],tmp;
	int n=0;
	while(cin>>tmp)s[++n]=tmp;
	for(int i=n;i>=1;--i)cout<<s[i]<<' ';
	return 0;
}
