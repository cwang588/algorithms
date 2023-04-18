#include<bits/stdc++.h>
using namespace std;
string to_str(long long x){
	string re;
	while(x){
		re+=(char)(x%10+'0');
		x/=10;
	}
	reverse(re.begin(),re.end());
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		if(l<10){
			cout<<l<<"\n";
			continue;
		}
		string a=to_str(l),b=to_str(r);
		if(a.length()<b.length()){
			for(int i=1;i<=a.length();++i)cout<<"9";
			cout<<"\n";
		}else{
			int gap=10,pos=0;
			string ans;
			while(pos<a.length()&&a[pos]==b[pos])++pos;
			if(pos==a.length()){
				cout<<a<<"\n";
			}else{
		//		cout<<"pos:"<<pos<<"\n";
				if(b[pos]-a[pos]>1){
					int Min=a[pos]-'0'+1,Max=a[pos]-'0'+1;
					for(int i=0;i<pos;++i){
						int tmp=a[i]-'0';
						Min=min(Min,tmp),Max=max(Max,tmp);
						ans+=a[i];
					}
					gap=Max-Min;
					for(int i=pos;i<a.length();++i)ans+=a[pos]+1;
				}
			//	cout<<gap<<"\n";
				int Max=0,Min=10;
				for(int i=0;i<pos;++i){
					int tmp=a[i]-'0';
					Min=min(Min,tmp),Max=max(Max,tmp);
				}
				
				for(int i=pos;i<a.length();++i){
					if(i>0&&a[i]<a[i-1]){
						if(Max-Min<gap){
			//				cout<<Min<<" "<<Max<<"\n";
							gap=Max-Min;
							ans=a.substr(0,i);
							for(int j=i;j<a.length();++j)ans+=a[i-1];
						}
						break;
					}
					int tmp=a[i]-'0';
					Min=min(Min,tmp),Max=max(Max,tmp);
				}
				if(Max-Min<gap){
					gap=Max-Min;
					ans=a;
				}
				Max=0,Min=10;
				for(int i=0;i<pos;++i){
					int tmp=b[i]-'0';
					Min=min(Min,tmp),Max=max(Max,tmp);
				}
				for(int i=pos;i<b.length();++i){
					if(i>0&&b[i]>b[i-1]){
					//	cout<<Max<<" "<<Min<<" "<<gap<<"\n";
						if(Max-Min<gap){
							ans=b.substr(0,i);
							gap=Max-Min;
							for(int j=i;j<b.length();++j)ans+=b[i-1];
						}
						break;
					}
					int tmp=b[i]-'0';
					Min=min(Min,tmp),Max=max(Max,tmp);
				}
				if(Max-Min<gap)ans=b;
				cout<<ans<<"\n";
			}
		}
	}
	
	
	return 0;
}
