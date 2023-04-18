#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt[1005];
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans=0;
        n=artifacts.size();
        map<pair<int,int>,int>usd;
        for(int i=0;i<n;++i){
            for(int j=artifacts[i][0];j<=artifacts[i][2];++j){
                for(int k=artifacts[i][1];k<=artifacts[i][3];++k){
                    usd[pair{i,j}]=i+1;
                    ++cnt[i];
                }
            }
        }
        for(auto x:dig){
            pair<int,int>now(x[0],x[1]);
            if(usd[now]){
                --cnt[usd[now]-1];
            }
        }
        for(int i=0;i<n;++i)if(!cnt[i])++ans;
        return ans;
        
    }
};
int main(){
	Solution s;
	vector<vector<int> >a={{0,0,0,0},{0,1,1,1}},b={{0,0},{0,1},{1,1}};
	cout<<s.digArtifacts(2,a,b);
	return 0;
}
