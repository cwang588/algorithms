#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n){
		if(n/1000){
			int a=n/1000;
			n%=1000;
			for(int i=1;i<=a;++i)cout<<"M";
		}
		if(n/100){
			int a=n/100;
			if(a==9)cout<<"CM";
			else{
				if(a>=5)a-=5,cout<<"D";
				if(a==4)cout<<"CD";
				else for(int i=1;i<=a;++i)cout<<"C";
			}
			n%=100;
		}
		if(n/10){
			int a=n/10;
			if(a==9)cout<<"XC";
			else{
				if(a>=5)a-=5,cout<<"L";
				if(a==4)cout<<"XL";
				else for(int i=1;i<=a;++i)cout<<"X";
			}
			n%=10;
		}
		if(n){
			int a=n;
			if(a==9)cout<<"IX";
			else{
				if(a>=5)a-=5,cout<<"V";
				if(a==4)cout<<"IV";
				else for(int i=1;i<=a;++i)cout<<"I";
			}
		}
		cout<<endl;
		cin>>n;
	}
	
	return 0;
}
