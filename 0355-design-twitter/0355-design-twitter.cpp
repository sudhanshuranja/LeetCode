#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Twitter {
private:
    int timeStamp;
    
    // user -> list of (timestamp, tweetId)
    unordered_map<int, vector<pair<int,int>>> tweets;
    
    // follower -> set of followees
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // max heap: (timestamp, tweetId, userId, index)
        priority_queue<tuple<int,int,int,int>> pq;

        // user should see his own tweets
        following[userId].insert(userId);

        for (int followee : following[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                auto [time, tweetId] = tweets[followee][idx];
                pq.push({time, tweetId, followee, idx});
            }
        }

        while (!pq.empty() && result.size() < 10) {
            auto [time, tweetId, user, idx] = pq.top();
            pq.pop();

            result.push_back(tweetId);

            if (idx > 0) {
                auto [prevTime, prevTweet] = tweets[user][idx - 1];
                pq.push({prevTime, prevTweet, user, idx - 1});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};