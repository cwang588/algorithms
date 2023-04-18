#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int inf=2147483647;
    double get_avg(int a,int b,int c,int d){
    	int Max1=max(a,b),Max2=min(a,b);
    	if(c>Max1){
    		Max2=Max1;
    		Max1=c;
		}
		else if(c>Max2)Max2=c;
		else;
		if(d>Max1){
    		Max2=Max1;
    		Max1=d;
		}
		else if(d>Max2)Max2=d;
		else;
		return 1.0*(Max1+Max2)/2;
	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())swap(nums1,nums2);
        auto f=[&](int k,vector<int>&a)->int{
            if(k<0)return -inf;
            if(k>=a.size())return inf;
            return a[k];
        };
        int n=nums1.size(),m=nums2.size(),l=-1,r=n+1;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(f(mid,nums1)<=f((n+m+1)/2-mid-1,nums2))l=mid;
            else r=mid;
        }
        if((n+m)%2)return max(f(l,nums1),f((n+m)/2-l-1,nums2));
        return 1.0*(max(f(l,nums1),f((n+m)/2-l-2,nums2))+min(f(l+1,nums1),f((n+m)/2-l-1,nums2)))/2;
    }
};
int main(){
	Solution s;
	vector<int>a={1,2},b={3,4};
	cout<<s.findMedianSortedArrays(a,b);
	return 0;
}