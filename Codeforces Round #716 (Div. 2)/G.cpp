#include<bits/stdc++.h>
using namespace std;
char a[105],b[105];
int work(char s1[],char s2[]){
	int n=strlen(s1),m=strlen(s2);
	for(int i=0;i<n;++i){
		if(s1[i]>s2[i])return 1;
		if(s1[i]<s2[i])return -1;
	}
	if(n==m)return 0;
	return -1;
}
int main(){
	cin>>a>>b;
	cout<<work(a,b);
    return 0;
}
