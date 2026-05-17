class Solution {
public:
    int trap(vector<int>& heights) {
        int ans = 0;
        int i = 0, j = heights.size() - 1;
        int leftMax = -1e9;
        int rightMax = -1e9;
        while(i < j){
            int mn = min(heights[i], heights[j]);
            leftMax = max(leftMax,heights[i]);
            rightMax = max(rightMax,heights[j]);
            
            if(heights[i] < heights[j]){
                ans += min(leftMax,rightMax) - heights[i];
                i++;
            }else{
                ans += min(leftMax,rightMax) - heights[j];
                j--;
            }
        }
        return ans;
    }
};
