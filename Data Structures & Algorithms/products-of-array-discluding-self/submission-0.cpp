class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero = 0;
        int n = nums.size();
        long long productAll = 1;
        vector<int> ans;
        for(auto &num : nums){
            if(num == 0) countZero++;
            else productAll *= num;
        }
        if(countZero == 0){
            vector<int> ans(n, 0);
            for(int i=0;i<n;i++) ans[i] = productAll/nums[i];
            return ans;
        }else if(countZero == 1){
            vector<int> ans(n, 0);
            for(int i=0;i<n;i++) if(nums[i] == 0) ans[i] = productAll;
            return ans;
        }else{
            vector<int> ans(n, 0);
            return ans;
        }
    }
};
