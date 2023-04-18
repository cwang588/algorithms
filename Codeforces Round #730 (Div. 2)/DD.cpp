#include<bits/stdc++.h>
using namespace std;
int yihuo[105];
int jian(int x,int y,int k){
	vector<int>xx,yy;
	while(x){
		xx.push_back(x%k);
		x/=k;
	}
	while(y){
		yy.push_back(y%k);
		y/=k;
	}
	int base=1,re=0;
	for(int i=0;i<min(xx.size(),yy.size());++i){
		re+=base*((xx[i]-yy[i]+k)%k);
		base*=k;
	}
	if(xx.size()>yy.size()){
		for(int i=yy.size();i<xx.size();++i){
			re+=base*xx[i];
			base*=k;
		}
	}
	else{
		for(int i=xx.size();i<yy.size();++i){
			re+=base*((k-yy[i])%k);
			base*=k;
		}
	}
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;++i){
			if(!i)cout<<i<<endl;
			else{
				if(i%2==0)cout<<jian(i,i-1,k)<<endl;
				else cout<<jian(i-1,i,k)<<endl;
			}
			fflush(stdout);
			int tmp;
			cin>>tmp;
			if(tmp)break;
		}
	}
	return 0;
}
