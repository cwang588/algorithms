#include<bits/stdc++.h>
using namespace std;
//bool check(long long a,long long b){
//	vector<int>v1,v2;
//	long long tmp=a;
//	while(a){
//		v1.push_back(a&1);
//		a>>=1;
//	}
//	while(b){
//		v2.push_back(b&1);
//		b>>=1;
//	}
//	reverse(v1.begin(),v1.begin());
//	reverse(v2.begin(),.begin());
//	long long now=0;
//	for(int i=0;i<v2.size();++i){
//		if(a[i]!=b[i]){
//			now<<=(v1.size()-i-1);
//			if(tmp-now)return false;
//			return true;
//		}
//		now=now*2+a[i];
//	}
//	return true;
//}
long long calc(long long a,long long b){
	long long cnt=0;
	while(a*2<=b){
		++cnt;
		a<<=1;
	}
	long long ans=cnt;
	for(int i=cnt;i>=0;--i){
		if(a+(1<<i)<=b){
			ans+=(b-a)/(1<<i);
			a+=(b-a)/(1<<i)*(1<<i);
		}
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		long long cnt=0;
		if(a==b){
			cout<<"0\n";
			continue;
		}
		long long tmp=0,ans=1000000000000000000;
		for(int i=1;i<=100;++i){
			if(a>b){
				if(a&1){
					++tmp;
					++a;
				}
				++tmp;
				a>>=1;
			}
			else{
				ans=min(ans,calc(a,b)+tmp);
				if(a&1){
					++tmp;
					++a;
				}
				++tmp;
				a>>=1;
			}
			
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}