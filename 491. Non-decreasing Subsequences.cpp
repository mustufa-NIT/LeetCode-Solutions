// this question solve by recursion + backtracing + hashset//
class Solution {
public:
int n;
set<vector<int>> st;
void solve(int i,vector<int>& nums,vector<int>& temp,int p){
  
    if(i>=n){
      if(temp.size()>=2){
        st.insert(temp);
      }
      return;

    }
    if(p==-1 || nums[p]<=nums[i]){
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,i);
        temp.pop_back();

    }
solve(i+1,nums,temp,p);


}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        solve(0,nums,temp,-1);
       return vector<vector<int>>(st.begin(),st.end());
        
    }
};
