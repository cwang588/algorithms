#include<bits/stdc++.h>
using namespace std;
int getlen(int x){
	int re=0;
	while(x){
		++re;
		x/=10;
	}
	return re;
}
void cmp(int a,int b){
	vector<int>v1,v2;
	while(a){
		v1.push_back(a%10);
		a/=10;
	}
	while(b){
		v2.push_back(b%10);
		b/=10;
	}	
	reverse(v1.begin(),v1.end());
	reverse(v2.begin(),v2.end());
	int len1=v1.size(),len2=v2.size();
	if(len1<len2){
		for(int i=1;i<=len2-len1;++i)v1.push_back(0);
	}
	else{
		for(int i=1;i<=len1-len2;++i)v2.push_back(0);
	}
	for(int i=0;i<v1.size();++i){
		if(v1[i]<v2[i]){
			cout<<"<\n";
			return;
		}
		else if(v1[i]>v2[i]){
			cout<<">\n";
			return;
		}
		else;
	}
	cout<<"=\n";
}
int main(){
	int t;
	cin>>t;	
	while(t--){
		int X1,p1,X2,p2;
		cin>>X1>>p1>>X2>>p2;
		if(X1==0&&X2==0)cout<<"=\n";
		else if(X1==0)cout<<"<\n";
		else if(X2==0)cout<<">\n";
		else{
			int len1=getlen(X1)+p1,len2=getlen(X2)+p2;
			if(len1>len2)cout<<">\n";
			else if(len1<len2)cout<<"<\n";
			else cmp(X1,X2);
		}
	}
	
	return 0;
}