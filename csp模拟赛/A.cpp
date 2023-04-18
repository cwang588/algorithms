#include<bits/stdc++.h>
using namespace std;
struct point{
	long long x,y;
	char t;
}p[10005];
int main(){
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>p[i].x>>p[i].y>>p[i].t;
	for(int i=1;i<=m;++i){
		long long a,b,c;
		cin>>a>>b>>c;
		bool ky=true;
		char tmp1='C',tmp2='C';
		for(int j=1;j<=n;++j){
			long long now=b*p[j].x+c*p[j].y+a;
			if(now>0){
				if(tmp1=='C')tmp1=p[j].t;
				else{
					if(tmp1!=p[j].t){
						ky=false;
						break;
					}
				}
			}
			else{
				if(tmp2=='C')tmp2=p[j].t;
				else{
					if(tmp2!=p[j].t){
						ky=false;
						break;
					}
				}
			}
		}
		if(ky)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
