#include<bits/stdc++.h>
using namespace std;
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
bool judge(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;
}
map<pair<long long,long long>,int>m;
int main(){
	vector<int>p;
	for(int i=1;i<=40000;++i)if(judge(i))p.push_back(i);
	for(int j=0;j<p.size();++j){
//		for(int k=j+1;k<p.size();++k){
			m.clear();
			bool ky=true;
			for(int i=1;i<=100000;++i){
				long long m1=quickpower(i,i,p[j]);
				long long m2=quickpower(i,i,38219);
				if(m[make_pair(m1,m2)]){
					ky=false;
					break;
				}
				m[make_pair(m1,m2)]=i;
			}
			if(ky)return !printf("%d %d\n",p[j],30631);	
//		}
	}

	return 0;
}