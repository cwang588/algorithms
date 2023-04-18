#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
struct Martix{
	long long a[8][8];
	Martix(){
		memset(a,0,sizeof(a));
	}
	void init(){
		for(int i=1;i<=6;++i)a[i][i]=1;
	}
	Martix operator *(const Martix &b)const{
		Martix tmp;
		for(int i=1;i<=6;++i){
			for(int j=1;j<=6;++j){
				for(int k=1;k<=6;++k){
					tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return tmp;
	}
};
Martix mi(Martix a,long long b){
	Martix tmp,now=a;
	tmp.init();
	if(b<0)return tmp;
 	while(b){
 		if(b&1)tmp=tmp*now;
		now=now*now;
		b>>=1;	
	}
	return tmp;
}
Martix cy[4],bkx;
void work(){
	cy[0].a[1][1]=1;
	cy[0].a[1][2]=2;
	cy[0].a[1][3]=5;
	cy[0].a[1][4]=4;
	cy[0].a[1][5]=2;
	cy[0].a[1][6]=2;
	cy[0].a[2][1]=1;
	cy[0].a[3][2]=1;
	cy[0].a[4][3]=1;
	cy[0].a[4][4]=1;
	cy[0].a[5][5]=1;
	cy[0].a[6][6]=1;
	cy[1].a[1][1]=1;
	cy[1].a[1][2]=2;
	cy[1].a[1][3]=5;
	cy[1].a[1][4]=2;
	cy[1].a[1][5]=4;
	cy[1].a[1][6]=2;
	cy[1].a[2][1]=1;
	cy[1].a[3][2]=1;
	cy[1].a[5][3]=1;
	cy[1].a[4][4]=1;
	cy[1].a[5][5]=1;
	cy[1].a[6][6]=1;
	cy[2].a[1][1]=1;
	cy[2].a[1][2]=2;
	cy[2].a[1][3]=5;
	cy[2].a[1][4]=2;
	cy[2].a[1][5]=2;
	cy[2].a[1][6]=4;
	cy[2].a[2][1]=1;
	cy[2].a[3][2]=1;
	cy[2].a[6][3]=1;
	cy[2].a[4][4]=1;
	cy[2].a[5][5]=1;
	cy[2].a[6][6]=1;
	bkx=cy[1]*cy[2]*cy[0];
}
int main(){
	int t;
	cin>>t;
	work();
	while(t--){
		long long n;
		cin>>n;
		long long tt=n/3-1;
		if(n<=3){
			if(n==1)cout<<"1\n";
			if(n==2)cout<<"3\n";
			if(n==3)cout<<"10\n";
			continue;
		}
		Martix ans=mi(bkx,tt);
		if(n%3==1)ans=ans*cy[1];
		if(n%3==2)ans=ans*cy[1]*cy[2];
		cout<<(ans.a[1][1]*10+ans.a[1][2]*3+ans.a[1][3]+ans.a[1][4])%mod<<endl;
	}
	return 0;
}
