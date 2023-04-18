#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>cnt;
        for(auto s:words)++cnt[s];
        bool ky=false;
        int ans=0;
        for(int i=0;i<26;++i){
            string s;
            s+=(char)(i+'a');
            s+=(char)(i+'a');
            ans+=cnt[s]/2*2;
            if(!ky&&cnt[s]%2){
                ky=true;
                ans+=2;
            }
        }
        for(int i=0;i<26;++i){
            for(int j=i+1;j<26;++j){
                string s,t;
                s+=(char)(i+'a');
                s+=(char)(j+'a');
                t+=(char)(j+'a');
                t+=(char)(i+'a');
                if(cnt[s]==0||cnt[t]==0)continue;
                int now=min(cnt[s],cnt[t]);
                ans+=now*2;
            }
        }
        return ans;
    }
};
int main(){
	Solution solution;
	vector<string>s={"lc","cl","gg"};
	cout<<solution.longestPalindrome(s);
	return 0;
}