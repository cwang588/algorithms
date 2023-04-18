#include<bits/stdc++.h>
using namespace std;
int check(int a,int b,int c,int d,int e,int f,int g,int h){
	int cnt1=0,cnt2=0;
	if(a>e)++cnt1;
	else if(a<e)++cnt2;
	else;
	if(a>f)++cnt1;
	else if(a<f)++cnt2;
	else;
	if(a>g)++cnt1;
	else if(a<g)++cnt2;
	else;
	if(a>h)++cnt1;
	else if(a<h)++cnt2;
	else;
	if(b>e)++cnt1;
	else if(b<e)++cnt2;
	else;
	if(b>f)++cnt1;
	else if(b<f)++cnt2;
	else;
	if(b>g)++cnt1;
	else if(b<g)++cnt2;
	else;
	if(b>h)++cnt1;
	else if(b<h)++cnt2;
	else;
	if(c>e)++cnt1;
	else if(c<e)++cnt2;
	else;
	if(c>f)++cnt1;
	else if(c<f)++cnt2;
	else;
	if(c>g)++cnt1;
	else if(c<g)++cnt2;
	else;
	if(c>h)++cnt1;
	else if(c<h)++cnt2;
	else;
	if(d>e)++cnt1;
	else if(d<e)++cnt2;
	else;
	if(d>f)++cnt1;
	else if(d<f)++cnt2;
	else;
	if(d>g)++cnt1;
	else if(d<g)++cnt2;
	else;
	if(d>h)++cnt1;
	else if(d<h)++cnt2;
	else;
	if(cnt1>cnt2)return 1;
	else if(cnt2>cnt1)return 2;
	else return 3;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d,e,f,g,h;
		cin>>a>>b>>c>>d>>e>>f>>g>>h;
		if(check(a,b,c,d,e,f,g,h)==3){
			cout<<"no\n";
			continue;
		}
		if(check(a,b,c,d,e,f,g,h)==2){
			swap(a,e);
			swap(b,f);
			swap(c,g);
			swap(d,h);
		}
		bool ky=false;
		for(int i=1;i<=10;++i){
			for(int j=i;j<=10;++j){
				for(int k=j;k<=10;++k){
					for(int o=k;o<=10;++o){
						int tmp1=check(i,j,k,o,a,b,c,d),tmp2=check(i,j,k,o,e,f,g,h);
						if(tmp1==1&&tmp2==2){
							ky=true;
							cout<<"yes\n";
							goto bkx;
						}
					}
				}
			}
		}
		bkx:if(!ky)cout<<"no\n";
	}
	
	
	return 0;
}