#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,t,xl,xr,yd,yw;
	scanf("%d%d%d%d%d%d%d",&n,&k,&t,&xl,&yd,&xr,&yw);
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i){
		bool ky1=false,ky2=false;
		int now=0;
		for(int j=1;j<=t;++j){
			int x,y;
			scanf("%d%d",&x,&y);
			if(xl<=x&&x<=xr&&yd<=y&&y<=yw)++now,ky2=true;
			else{
				if(now>=k)ky1=true;
				now=0;
			}
		}
		if(now>=k)ky1=true;
		if(ky1)++ans1; 
		if(ky2)++ans2; 
	}
	printf("%d\n%d\n",ans2,ans1);
	return 0;
}
