class Twitter {
public:
    typedef struct user{
        unordered_set<int> following;
        vector<pair<int, int>> posts;
    }user;
    unordered_map<int, user> users;
    int count = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        users[userId].posts.push_back({count, tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> heap;
        vector<int> newsFeed;

        int index = users[userId].posts.size() -1;
        int timeStamp;
        int id;
        if(index >= 0){
            timeStamp = users[userId].posts[index].first;
            id = users[userId].posts[index].second;
            heap.push({timeStamp, id, userId, index});
        }
        for(auto followingId : users[userId].following){
            index = users[followingId].posts.size() - 1;
            if(index >= 0){
                timeStamp = users[followingId].posts[index].first;
                id = users[followingId].posts[index].second;
                heap.push({timeStamp, id, followingId, index});
            }
        }

        while(newsFeed.size() < 10 && !heap.empty()){
            tuple<int, int, int, int> recent = heap.top(); heap.pop();
            index = get<3>(recent) - 1;

            if(index >= 0){
                timeStamp = users[get<2>(recent)].posts[index].first;
                id = users[get<2>(recent)].posts[index].second;
                heap.push({timeStamp, id, get<2>(recent), index});
            }
            newsFeed.push_back(get<1>(recent));
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            users[followerId].following.insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users.contains(followerId) && users.contains(followeeId)){
            users[followerId].following.erase(followeeId);
        }
    }
};
