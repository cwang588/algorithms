#include <bits/stdc++.h>
#define maxn 30000000
using namespace std;
typedef vector<int> vi;
bool notp[maxn + 5];
int p[maxn + 5], minf[maxn + 5], cntp;
void shai() {
	for (int i = 2; i <= maxn; ++i) {
		if (!notp[i]) {
			p[cntp++] = i;
			minf[i] = i;
		}
		for (int j = 0; j < cntp && i * p[j] <= maxn; ++j) {
			notp[i * p[j]] = true;
			minf[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}
vi factor(int x) {
	vi ret;
	while (x > 1) {
		ret.push_back(minf[x]);
		x /= minf[x];
	}
	return ret;
}
//map<long long,long long>m;
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
const double eps = 1e-10;
long long pfg(long long x){
	double rt = sqrt(x);
	return (long long)(rt + eps);
}
int main()
{
//	for(int i=1;i<=20000000;++i)m[1ll*i*i]=i;
	shai();
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int p,q;
		cin>>p>>q;
		if(p<q*2){
			cout<<"0 0\n";
			continue;
		}
		else if(p==q*2){
			cout<<"1 1\n";
			continue;
		}
		auto v1=factor(p+2*q),v2=factor(p-2*q);
		set<int>s1,s2;
		for(auto x:v1){
			if(s1.count(x))s1.erase(x);
			else s1.insert(x);
		}
		for(auto x:v2){
			if(s2.count(x))s2.erase(x);
			else s2.insert(x);
		}
		bool ky=true;
		int ans=1;
		for(auto x:s1){
			if(!s2.count(x)){
				ky=false;
				break;
			}
			else ans*=x;
		}
		for(auto x:s2){
			if(!s1.count(x)){
				ky=false;
				break;
			}
		}
		if(!ky)cout<<"0 0\n";
		else{
			long long xx=pfg(1ll*(p+2*q)*ans)+pfg(1ll*(p-2*q)*ans),yy=pfg(1ll*(p+2*q)*ans)-pfg(1ll*(p-2*q)*ans),g=gcd(xx,yy);
			cout<<xx/g<<" "<<yy/g<<"\n";
		}
	}
	return 0;
}