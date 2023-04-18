#include<bits/stdc++.h>
using namespace std;
int n[10][10];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		for(int i=1;i<=3;++i){
			for(int j=1;j<=4;++j)cin>>n[i][j];
		}
		int a=2147483647,b=2147483647,c=2147483647,d=2147483647;
		for(int i=1;i<=3;++i){
			a=min(a,n[i][1]);
			b=min(b,n[i][2]);
			c=min(c,n[i][3]);
			d=min(d,n[i][4]);
		}
		printf("Case #%d: ",Case);
		if(a+b+c+d<1000000)cout<<"IMPOSSIBLE\n";
		else{
			int re=1000000;
			cout<<a<<" ";
			re-=a;
			cout<<min(re,b)<<" ";
			re-=min(re,b);
			cout<<min(re,c)<<" ";
			re-=min(re,c);
			cout<<min(re,d)<<" ";
			re-=min(re,d);
			cout<<"\n";
		}
	}
	
	return 0;
}