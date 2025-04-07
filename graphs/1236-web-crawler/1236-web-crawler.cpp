/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    vector<string>result;
    unordered_set<string>visited;
    
    bool startsWith(string &currUrl, string &domain)
    {
        int n = currUrl.size();
        int m = domain.size();

        if(n<m)
            return false;

        for(int i=0,j=0;i<m;i++,j++)
        {
            if(currUrl[i] != domain[j])
                return false;
        }

        return true;
    }

public:
    void crawl(string startUrl, HtmlParser &htmlParser, string &domain)
    {
        visited.insert(startUrl);

        for(string currUrl : htmlParser.getUrls(startUrl))
        {
            if(visited.find(currUrl) != visited.end())
                continue;
            
            if(startsWith(currUrl, domain))
            {
                result.push_back(currUrl);
                crawl(currUrl, htmlParser, domain);
            }
            
        }
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        result.clear();
        visited.clear();

        result.push_back(startUrl);

        string domain = startUrl.substr(0,7);

        for(char ch : startUrl.substr(7))
        {
            if(ch == '/')
                break;
            domain += ch;
        }

        cout<<domain<<endl;

        crawl(startUrl, htmlParser, domain);
        
        return result;
    }
};
