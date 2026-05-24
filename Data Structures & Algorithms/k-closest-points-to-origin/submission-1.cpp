class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<array<double,3>,vector<array<double,3>>,
            greater<array<double,3>>> pq;

        for(auto &point : points){
            double dis = sqrt(point[0] * point[0] + point[1] * point[1]);
            array<double,3> cur = {dis,(double)point[0],(double)point[1]};
            pq.push(cur); 
        }

        vector<vector<int>> ans;
        while(pq.size() && k){
            k--;
            auto cur = pq.top(); pq.pop();
            ans.push_back({(int)cur[1],(int)cur[2]});
        }
        return ans;
    }
};
