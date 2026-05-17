class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ascii(256,0);

        int left = 0, right = 0, n = s.size(), ans = 0;

        while(right < n){
            ascii[s[right]]++;

            while(left <= right && ascii[s[right]] > 1){
                ascii[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right ++;
        }
        return ans;

    }
};
