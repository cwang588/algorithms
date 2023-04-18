#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		int num=n-(n>>2);
		int tota=0,totb=0;
		for(int i=1;i<=num;++i){
			tota+=a[i];
			totb+=b[i];
		}
		if(tota>=totb){
			cout<<"0"<<endl;
			continue;
		}
		int nn=n,nowb=num,nowa=num;
		while(true){
			++nn;
			if(nn%4){
				tota+=100;
				++nowb;
				if(nowb<=n)totb+=b[nowb];
			}
			else{
				if(nowa>=1)tota-=a[nowa];
				tota+=100;
				--nowa;
			}
			if(tota>=totb)break;
		}
		cout<<nn-n<<endl;
	}
	return 0;
}
