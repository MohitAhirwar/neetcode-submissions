class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int cur=nums[i];
            if(i>0&&cur==nums[i-1]) continue;

            int lo = i+1, hi = n-1;
            while(lo < hi){
                int sum = nums[lo] + nums[hi] + cur;
                if(sum > 0){
                    hi--;
                }else if(sum < 0){
                    lo++;
                }else{
                    if(ans.size() == 0 || (ans.back() != vector<int>{nums[i],nums[lo],nums[hi]}))ans.push_back({nums[i],nums[lo],nums[hi]});
                    lo++,hi--;
                }
            }
        }
        


        return ans;
    }
};
