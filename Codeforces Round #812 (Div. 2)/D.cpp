#include<bits/stdc++.h>
using namespace std;
int query(int x,int y){
	cout<<"? "<<x<<" "<<y<<"\n";
	fflush(stdout);
	int now;
	cin>>now;
	return now;
}
int work(int a,int b,int c,int d){
	int x=query(a,c);
	if(x==0){
		int y=query(b,d);
		if(y==1)return b;
		else return d;
	}
	else if(x==1){
		int y=query(a,d);
		if(y==1)return a;
		else return d;
	}
	else{
		int y=query(b,c);
		if(y==1)return b;
		else return c;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>now;
		for(int i=1;i<=(1<<n);++i)now.push_back(i);
		while(now.size()>=4){
			vector<int>tmp;
			for(int i=0;i<now.size();i+=4){
				tmp.push_back(work(now[i],now[i+1],now[i+2],now[i+3]));
			}
			now=tmp;
		}
		if(now.size()==1)cout<<"! "<<now[0]<<"\n";
		else{
			int x=query(now[0],now[1]);
			if(x==1)cout<<"! "<<now[0]<<"\n";
			else cout<<"! "<<now[1]<<"\n";
		}
		fflush(stdout);
	}
	
	
	return 0;
}