#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("1567.in","r",stdin);
	//freopen("1567.out","w",stdout);
	string s1,s2;
	while(cin>>s1>>s2){
		int n=s1.length(),pos,Max=-1;
		for(int i=0;i<n;++i){
			if(s1[i]>Max){
				Max=s1[i];
				pos=i;
			}
		}
		for(int i=0;i<n;++i){
			cout<<s1[i];
			if(i==pos)cout<<s2;
		}
		cout<<"\n";
	}
	return 0;
} 
