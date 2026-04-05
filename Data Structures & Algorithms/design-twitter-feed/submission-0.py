from collections import defaultdict

class Twitter:

    def __init__(self):
        self.tweets = []  # list of (userId, tweetId)
        self.following = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets.append((userId, tweetId))

    def getNewsFeed(self, userId: int) -> list[int]:
        result = []
        allowed = self.following[userId] | {userId}

        # Traverse from most recent to oldest
        for uid, tid in reversed(self.tweets):
            if uid in allowed:
                result.append(tid)
                if len(result) == 10:
                    break

        return result

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)