#include<bits/stdc++.h>
using namespace std;
int cnt[15],a[6],ans[6];
map<char,int>m;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		for(int i=1;i<=4;++i)a[i]=i;
		long long Max=-1;
		do{
			m['A']=a[1];
			m['T']=a[2];
			m['O']=a[3];
			m['N']=a[4];
			for(int i=1;i<=4;++i)cnt[i]=0;
			long long tot=0;
			for(int i=0;i<n;++i){
				for(int j=m[s[i]]+1;j<=4;++j)tot+=cnt[j];
				++cnt[m[s[i]]];
			}
			if(Max<tot){
				Max=tot;
				for(int i=1;i<=4;++i)ans[i]=a[i];
			}
			if(!next_permutation(a+1,a+5))break;
		}while(1);
		m['A']=ans[1];
		m['T']=ans[2];
		m['O']=ans[3];
		m['N']=ans[4];
		for(int i=1;i<=4;++i){
			for(int j=0;j<n;++j){
				if(m[s[j]]==i)cout<<s[j];
			}
		}
		cout<<endl;
	}
	return 0;
}
