#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,sx,sy,ex,ey,cnt=0;
		cin>>n>>m>>sx>>sy>>ex>>ey;
		int dr=1,dc=1;
		while(true){
			if(sx==ex||sy==ey)break;
			if(sx+dr>n||sx+dr<1)dr=-dr;
			if(sy+dc>m||sy+dc<1)dc=-dc;
			sx+=dr,sy+=dc,++cnt;			
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}