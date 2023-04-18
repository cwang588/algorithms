#include<bits/stdc++.h>
using namespace std;
int a[15][15];
bool usd[15];
bool check1(){
	for(int i=1;i<=9;++i){
		memset(usd,0,sizeof(usd));
		for(int j=1;j<=9;++j){
			if(!a[i][j])continue;
			if(usd[a[i][j]])return false;
			usd[a[i][j]]=true;
		}
	}
	return true;
}
bool check2(){
	for(int i=1;i<=9;++i){
		memset(usd,0,sizeof(usd));
		for(int j=1;j<=9;++j){
			if(!a[j][i])continue;
			if(usd[a[j][i]])return false;
			usd[a[j][i]]=true;
		}
	}
	return true;
}
bool check3(){
	for(int i=1;i<=9;i+=3){
		for(int j=1;j<=9;j+=3){
			memset(usd,0,sizeof(usd));
			for(int x=0;x<3;++x){
				for(int y=0;y<3;++y){
					if(!a[i+x][j+y])continue;
					if(usd[a[i+x][j+y]])return false;
					usd[a[i+x][j+y]]=true;
				}
			}
		}
	}
	return true;
}
int main(){
	for(int i=1;i<=9;++i){
		for(int j=1;j<=9;++j)cin>>a[i][j];
	}
	cout<<(check1()&&check2()&&check3())<<"\n";
	return 0;
}