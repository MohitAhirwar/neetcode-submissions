class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<int> dq;
        vector<int> ans;

        int n = A.size();
        
        for(int i=0;i<n;i++){
            
            while(dq.size() && dq.front() <= i-k) dq.pop_front();

            while(dq.size() && A[dq.back()] <= A[i]) dq.pop_back();
            dq.push_back(i);

            if(i >= k-1) ans.push_back(A[dq.front()]);
        }

        return ans;
    }
};
