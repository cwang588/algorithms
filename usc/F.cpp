#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		int n;
		cin>>n;
		int nowx=0,nowy=0,xx=0,yy=0;
		while(n--){
			char t;
			int m;
			cin>>t>>m;
			if(t=='u'){
				nowy=min(b-1,nowy+m);
				yy+=m;
			}else if(t=='d'){
				nowy=max(0,nowy-m);
				yy-=m;
			}else if(t=='l'){
				nowx=max(0,nowx-m);
				xx-=m;
			}else{
				nowx=min(a-1,nowx+m);
				xx+=m;
			}
		}
		cout<<"Robot thinks "<<xx<<" "<<yy<<"\n";
		cout<<"Actually at "<<nowx<<" "<<nowy<<"\n";
	}
	
	
	return 0;
}