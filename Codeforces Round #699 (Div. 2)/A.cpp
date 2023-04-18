#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,a=0,b=0,c=0,d=0;
		cin>>x>>y;
		string tmp;
		cin>>tmp;
		int n=tmp.length();
		for(int i=0;i<n;++i){
			if(tmp[i]=='U')++a;
			else if(tmp[i]=='D')++b;
			else if(tmp[i]=='L')++c;
			else ++d;
		}
		if(y>=-b&&y<=a&&x>=-c&&x<=d)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
