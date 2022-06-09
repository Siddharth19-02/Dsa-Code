class Solution {
public:
    unordered_map<string,string>mp;
    int count;
    Solution()
    {
        count=0;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string curr = "http://tinyurl.com/4e9i";
        curr += to_string(count);
        count++;
        
        mp[curr] = longUrl;
        return curr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};
