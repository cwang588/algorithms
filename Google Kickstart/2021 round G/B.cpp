#include<bits/stdc++.h>
using namespace std;
struct point{
	long long pos;
	bool type;
}x[200005],y[200005];
bool cmp(point a,point b){
	return a.pos<b.pos;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			long long xa,ya,xb,yb;
			cin>>xa>>ya>>xb>>yb;
			x[2*i-1]={xa,false};
			x[2*i]={xb,true};
			y[2*i-1]={ya,false};
			y[2*i]={yb,true};
		}
		sort(x+1,x+1+n*2,cmp);
		sort(y+1,y+1+n*2,cmp);
		long long ansx=1926081719260817,ansy=1926081719260817,posx,posy;
		long long numl=0,numr=0,suml=0,sumr=0;
		for(int i=1;i<=n*2;++i){
			if(!x[i].type){
				++numl;
				suml+=x[i].pos;
			}
		}
		for(int i=1;i<=n*2;++i){
			long long now=x[i].pos*numr-sumr+suml-x[i].pos*numl;
			if(now<ansx){
				posx=x[i].pos;
				ansx=now;
			}
			if(!x[i].type){
				--numl;
				suml-=x[i].pos;
			}
			else{
				++numr;
				sumr+=x[i].pos;
			}
		}
		numl=0,numr=0,suml=0,sumr=0;
		for(int i=1;i<=n*2;++i){
			if(!y[i].type){
				++numl;
				suml+=y[i].pos;
			}
		}
		for(int i=1;i<=n*2;++i){
			long long now=y[i].pos*numr-sumr+suml-y[i].pos*numl;
			if(now<ansy){
				posy=y[i].pos;
				ansy=now;
			}
			if(!y[i].type){
				--numl;
				suml-=y[i].pos;
			}
			else{
				++numr;
				sumr+=y[i].pos;
			}
		}
		cout<<"Case #"<<Case<<": "<<posx<<" "<<posy<<"\n";
	}
	
	return 0;
}