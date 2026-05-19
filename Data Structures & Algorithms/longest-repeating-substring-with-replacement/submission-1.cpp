class Solution {
private:
    map<char,int> mp;

    bool ok(int k){
        int mxFreq = 0;
        int windowSize = 0;
        for(auto &it : mp){
            windowSize += it.second;
            mxFreq = max(mxFreq, it.second);
        }

        return (windowSize - mxFreq) <= k;
    }

public:
    int characterReplacement(string s, int k) {
        mp.clear();
        int left = 0, right = 0, n = s.size();
        int ans = 0;
        while(right < n){
            mp[s[right]]++;
            while(left <= right && !ok(k)){
                int f = mp[s[left]];
                if(f >=2) mp[s[left]]--;
                else mp.erase(s[left]);
                left++;
            }

            ans = max(ans,right - left + 1);
            right++;
        }
        return ans;
    }
};
