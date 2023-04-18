#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		double w,d,tot=acos(-1);
		cin>>w>>d;
		if(w<d)swap(w,d);
		int ans=0,dmax=tot/d,xmax=tot/sqrt(d*d+w*w);
		double xie=sqrt(d*d+w*w);
		for(int i=0;i<=min(6000,dmax);++i){
			double re=tot-d*(dmax-i);
			int now=re/xie;
			if(xie*now+d*i>tot)--now;
			ans=max(ans,now*3+2*(dmax-i));
		}
		for(int i=0;i<=min(6000,xmax);++i){
			double re=tot-xie*(xmax-i);
			int now=re/d;
			if(d*now+xie*i>tot)--now;
			ans=max(ans,now*2+3*(xmax-i));
		}
		cout<<ans+4<<endl;
	}
	return 0;
}
