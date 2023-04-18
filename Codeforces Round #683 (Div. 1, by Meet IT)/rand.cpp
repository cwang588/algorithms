#include<bits/stdc++.h>
using namespace std;
int tri_type(int a,int b,int c) {
	if(a+b<=c||b+c<=a||a+c<=b||a<=0||b<=0||c<=0)return 4;
	if(a==b&&b==c)return 1;
	else if(a==b||b==c||a==c)return 2;
	else return 3;
}
int main(){
	srand((unsigned)time(0)); 
	freopen("test.txt","w",stdout);
	for(int a=-10;a<=10;++a){
		for(int b=-10;b<=10;++b){
			for(int c=-10;c<=10;++c){
				cout<<'"'<<a<<','<<b<<','<<c<<','<<tri_type(a,b,c)<<'"'<<',';
			}
		}
	}
	return 0;
}
