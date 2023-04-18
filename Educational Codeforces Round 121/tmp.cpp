#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int ans=0;
        for(int i=0;i<(1<<n);++i){
            bool ky=true;
            int now=0;
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    if(((1<<k)&i)==0)continue;
                    if(statements[k][j]!=2&&statements[k][j]!=((i>>j)&1)){
                        ky=false;
                        break;
                    }
                }
                if(((1<<j)&i))++now;
            }
            if(!ky)continue;
            ans=max(ans,now);
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<vector<int>>v={{2,1,2},{1,2,2},{2,0,2}};
	cout<<s.maximumGood(v);
	return 0;
}