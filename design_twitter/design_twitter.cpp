/**
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
**/

class Twitter {
private:
int timeStamp;
unordered_map<int, unordered_set<int>> friends;
unordered_map<int, map<int, int, greater<int>>> tweets; // map<int, int> is map<tweetId, timeStamp>

public:
    /** Initialize your data structure here. */
    Twitter() {
        timeStamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId][tweetId] = timeStamp;
        timeStamp += 1;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(map<int, int>::iterator itt = tweets[userId].begin(); itt != tweets[userId].end(); itt++) {
            if(pq.size() < 10) {
                pq.push(make_pair(itt->second, itt->first));
            }
            else {
                if(itt->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(itt->second, itt->first));
                }
            }
        }

        for(unordered_set<int>::iterator it = friends[userId].begin(); it != friends[userId].end(); it++) {
            for(map<int, int>::iterator itt = tweets[*it].begin(); itt != tweets[*it].end(); itt++) {
                //一个user只要10次
                if(pq.size() < 10) {
                    pq.push(make_pair(itt->second, itt->first)); //pair<timeStamp, tweetId>
                }
                else {
                    if(itt->second > pq.top().first) {
                        pq.pop();
                        pq.push(make_pair(itt->second, itt->first));
                    }
                }
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            friends[followerId].insert(followeeId);
        }
        return ;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(friends[followerId].find(followeeId) != friends[followerId].end()) {
            friends[followerId].erase(friends[followerId].find(followeeId));
        }
        return ;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
