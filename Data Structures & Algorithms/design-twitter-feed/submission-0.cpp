class Twitter {
private:
    map<int,set<int>> following;
    map<int,vector<pair<int,int>>> userPosts;
    int timer = 0;
public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<array<int,4>> pq;


        following[userId].insert(userId);

        for(auto &f : following[userId]){
            auto lst = userPosts[f];
            if(lst.size()){
                pq.push({
                    lst.back().first,
                    lst.back().second,
                    f,
                    (int)lst.size()-1
                });
            }
        }

        while(ans.size() < 10 && pq.size()){
            auto cur = pq.top(); pq.pop();
            ans.push_back(cur[1]);

            int idx = cur[3] - 1;
            if(idx >= 0){
                int user = cur[2];
                
                pq.push({
                    userPosts[user][idx].first,
                    userPosts[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
