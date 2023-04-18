#include<bits/stdc++.h>
using namespace std;
int op[105][105];
int main(){
	for(int n=1;n<=10;++n){
		int num=n;
		for(int i=0;i<n;++i)op[i][0]=1;
		cout<<'0'<<" ";
		int cnt=1;
		while(num){
			++cnt;
			int x=0,y=0;
			while(x+y<n){
				op[x][y]=1-op[x][y];
				if(op[x][y])++x,++num;
				else ++y,--num;
			}
			cout<<y<<" ";
		}
		cout<<endl<<cnt<<endl;
	}
	
	return 0;
}
