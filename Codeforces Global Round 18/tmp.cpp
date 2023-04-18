#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
class Solution {
public:
    const unsigned long long mod1=1000000000000,mod2=100000;

    string abbreviateProduct(int left, int right) {
        unsigned long long cnt=0,now1=1,now2=1;
        int cnt2=0,cnt5=0;
        for(int i=left;i<=right;++i){
            a[i]=i;
            while(a[i]%10==0){
                ++cnt;
                a[i]/=10;
            }
            while(a[i]%2==0){
                a[i]/=2;
                ++cnt2;
            }
            while(a[i]%5==0){
                a[i]/=5;
                ++cnt5;
            }
        }
        cnt+=min(cnt2,cnt5);
        bool ky=false;
        long long tmpp=1;
        for(int i=1;i<=cnt2-cnt5;++i){
            tmpp*=2;
            if(tmpp>=10000000000)ky=true;
			now1=now1*2%mod1;
            now2=now2*2%mod2;
        }
        for(int i=1;i<=cnt5-cnt2;++i){
        	tmpp*=5;
            if(tmpp>=10000000000)ky=true;
            now1=now1*5%mod1;
            now2=now2*5%mod2;
        }
        for(int i=left;i<=right;++i){
        	tmpp*=a[i];
            if(tmpp>=10000000000)ky=true;
            now1=now1*a[i]%mod1;
            now2=now2*a[i]%mod2;
        }
        if(!ky)return to_string(now1)+"e"+to_string(cnt);
        string tmp=to_string(now1);
        string ans="";
        for(int i=0;i<5;++i)ans+=tmp[i];
        ans+="..."+to_string(now2)+"e"+to_string(cnt);
        return ans;
    }
};
int main(){
	Solution s;
	cout<<s.abbreviateProduct(999998,1000000)<<"\n";
	return 0;
}