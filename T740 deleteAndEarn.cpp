class Solution {
    int rob(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2;i <= n;++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > mx) mx = nums[i];
        }
        vector<int> ans(mx + 1, 0);
        for (size_t i = 0; i < nums.size(); ++i) {
            ans[nums[i]] += nums[i];
        }
        
        return rob(ans);
    }
};
