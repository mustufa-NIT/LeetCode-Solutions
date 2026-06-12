//this code is solve by DP recursion+memoization//
class Solution {
public:
int n;
int t[2501][2501];
int solve(int i,vector<int>& nums,int p){
     n=nums.size();
    if(i>=n) return 0;
    int take=0;
    int Not_take=0;
    if(p!=-1 && t[i][p]!=-1) return t[i][p];
    if(p==-1 || nums[p]<nums[i]){
         take=1+solve(i+1,nums,i);
    }
     Not_take=solve(i+1,nums,p);
     if(p!=-1){
        return t[i][p]=max(take,Not_take);
     }
    return max(take,Not_take);
}
    int lengthOfLIS(vector<int>& nums) {
         n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,-1);
        
    }
};
