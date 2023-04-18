#include<bits/stdc++.h>
using namespace std;
int a[100008],l[100005],r[100005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	stack<int>s;
	a[0]=a[n+1]=-1;
	s.push(0);
	for(int i=1;i<=n;++i){
		while(a[s.top()]>=a[i])s.pop();
		l[i]=i-s.top();
		s.push(i);
	}
	while(!s.empty())s.pop();
	s.push(n+1);
	for(int i=n;i>=1;--i){
		while(a[s.top()]>=a[i])s.pop();
		r[i]=s.top()-i;
		s.push(i);
	}
	long long ans=0;
	int pos;
	for(int i=n;i>=1)
	return 0;
}