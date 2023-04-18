#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool usd[1005];
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        for(int i=1;i<n;++i){
            if(nums[i]-nums[0]==0||(nums[i]-nums[0])%2)continue;
            ans.clear();
            memset(usd,0,sizeof(usd));
            map<int,int>now;
            map<int,vector<int> >pos;
            for(int j=0;j<n;++j)pos[nums[j]].push_back(j);
            ++now[nums[0]],++now[nums[i]];
            ans.push_back((nums[0]+nums[i])/2);
            usd[0]=usd[i]=true;
            bool ky=true;
            for(int j=1;j<n;++j){
                if(usd[j])continue;
                if(now[nums[j]+nums[i]-nums[0]]==pos[nums[j]+nums[i]-nums[0]].size()){
                    ky=false;
                    break;
                }
                ans.push_back(nums[j]+(nums[i]-nums[0])/2);
                usd[j]=usd[pos[nums[j]+nums[i]-nums[0]][now[nums[j]+nums[i]-nums[0]]]]=true;
                ++now[nums[j]],++now[nums[j]+nums[i]-nums[0]];
            }
            if(ky)break;
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int>now={11,6,3,4,8,7,8,7,9,8,9,10,10,2,1,9};
	auto ans=s.recoverArray(now);
	
	return 0;
}