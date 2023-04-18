#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main(){
	int t; 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		while(n--){
			int now;
			cin>>now;
			if(s.count(now))++now;
			s.insert(now);
		}
		printf("%d\n",s.size());
		s.clear();
	}
	return 0;
} 
