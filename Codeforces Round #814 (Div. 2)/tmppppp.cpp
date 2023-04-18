#include<bits/stdc++.h>
using namespace std;
int parse_string(string &in,vector<int>&out){
	int l=0,r=0;
	bool usd=false;
	for(auto x:in){
		if(x==','){
			if(usd){
				for(int i=l;i<=r;++i)out.push_back(i);
			}
		}
		if(x=='-'){
			usd=true;
			continue;
		}
	}
}
int main(){
	
	
	
	return 0;
}