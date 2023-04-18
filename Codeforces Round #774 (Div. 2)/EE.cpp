#include<bits/stdc++.h>
using namespace std;
long long mi(int x,int y){
	long long re=1;
	for(int i=1;i<=y;++i)re*=x;
	return re;
}
int main(){
	for(int i=1;i<=12;++i){
		for(int j=1;j<=12;++j){
			set<long long>s;
			for(int k=1;k<=i;++k){
				for(int o=1;o<=j;++o)s.insert(mi(k,o));
			}
			cout<<s.size()<<" ";
		}
		cout<<"\n";
	}	 
	
	
	return 0;
}