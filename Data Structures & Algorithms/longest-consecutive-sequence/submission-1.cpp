class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> dp;
        int ans = 0;
        for(int i=0;i<n;i++){
            int cur = nums[i];
            if(dp.find(cur-1) != dp.end()){
                dp[cur] = dp[cur-1] + 1;
            }else{
                dp[cur] = 1;
            }
            ans = max(ans,dp[cur]);
        }
        return ans;
    }
};
