class Twitter {
    int timer = 0;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets; // pair = {timestamp, tweetId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        timer++;
        tweets[userId].push_back({timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        follows[userId].insert(userId); // Include user's own tweets

        for(int followee : follows[userId]){
            if(tweets[followee].empty()) continue;
            int idx = tweets[followee].size()-1;
            pq.push({
                tweets[followee][idx].first,   // timestamp
                tweets[followee][idx].second,  // tweetId
                followee,
                idx
            });
        }
        vector<int> ans;
        while(!pq.empty() && ans.size()<10){
            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);
            idx--;
            if(idx >= 0){
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        follows[followerId].erase(followeeId);
    }
};