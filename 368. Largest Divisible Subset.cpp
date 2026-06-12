// this is code solve by DP recursion + meroization//
class Solution {
public:
    vector<int> dp[1001][1001];
    bool vis[1001][1001];

    vector<int> solve(int i, int p, vector<int>& nums) {

        if (i >= nums.size())
            return {};

        if (vis[i][p + 1])
            return dp[i][p + 1];

        vis[i][p + 1] = true;

        vector<int> take;
        vector<int> not_take;

        if (p == -1 || nums[i] % nums[p] == 0) {

            take = solve(i + 1, i, nums);

            take.insert(take.begin(), nums[i]);
        }

        not_take = solve(i + 1, p, nums);

        if (take.size() > not_take.size())
            return dp[i][p + 1] = take;

        return dp[i][p + 1] = not_take;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        memset(vis, false, sizeof(vis));

        return solve(0, -1, nums);
    }
};
