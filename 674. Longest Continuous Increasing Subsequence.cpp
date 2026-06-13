//this question based simple array that this question solve by for loop + max condition//
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int slow=0;
        int count=1;
        int ans=0;
        for(int fast=1;fast<n;fast++){
            if(nums[slow] < nums[fast]){
                count++;
            }
            else{
                ans=max(ans,count);
                count=1;
            }
            slow++;

        }
        ans=max(ans,count);
        return ans;
        
    }
};
