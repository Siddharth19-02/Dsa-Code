class Solution {
public:
    bool isdigit(char now)
    {
        return (now>='0' and now<='9');
    }
    void allPossibleAns(string word,string str,vector<string> &res,int index)
    {
        if(index == word.length())
        {
            res.push_back(str);
            return;
        }
        
        allPossibleAns(word,str+word[index],res,index+1);


        if(str.size() == 0 || !(isdigit(str[str.size()-1])) )
        {
            allPossibleAns(word,str+'1',res,index+1);
        }
        else
        {
            if(str[str.size()-1] == '9')
            {
                str.pop_back();
                str += "10";
            }
            else
                str[str.size()-1] += 1;
            allPossibleAns(word,str,res,index+1);
        }
            
        
    }
    vector<string> generateAbbreviations(string word) {
        
        vector<string> res;
        string str = "";
        allPossibleAns(word,str,res,0);
        return res;
    }
};

/*

Intuition

If we use 00 to represent a character that is not abbreviated and 11 to represent one that is. Then each abbreviation is mapped to an nn bit binary number and vice versa.

Algorithm

To generate all the 2^n2 
n
  abbreviation with non-repetition and non-omission, we need to follow rules. In approach #1, the rules are coded in the backtracking process. Here we introduce another way.

From the intuition section, each abbreviation has a one to one relationship to a nn bit binary number xx. We can use these numbers as blueprints to build the corresponding abbreviations.

For example:

Given word = "word" and x = 0b0011

Which means 'w' and 'o' are kept, 'r' and 'd' are abbreviated. Therefore, the result is "wo2".

Thus, for a number xx, we just need to scan it bit by bit as if it is an array so that we know which character should be kept and which should be abbreviated.

To scan a number xx bit by bit, one could extract its last bit by b = x & 1 and shift xx one bit to the right, i.e. x >>= 1. Doing this repeatedly, one will get all the nn bits of xx from last bit to first bit.

public class Solution {
    public List<String> generateAbbreviations(String word) {
        List<String> ans = new ArrayList<>();
        for (int x = 0; x < (1 << word.length()); ++x) // loop through all possible x
            ans.add(abbr(word, x));
        return ans;
    }

    // build the abbreviation for word from number x
    private String abbr(String word, int x) {
        StringBuilder builder = new StringBuilder();
        int k = 0, n = word.length(); // k is the count of consecutive ones in x
        for (int i = 0; i < n; ++i, x >>= 1) {
            if ((x & 1) == 0) { // bit is zero, we keep word.charAt(i)
                if (k != 0) { // we have abbreviated k characters
                    builder.append(k);
                    k = 0; // reset the counter k
                }
                builder.append(word.charAt(i));
            }
            else // bit is one, increase k
                ++k;
        }
        if (k != 0) builder.append(k); //don't forget to append the last k if non zero
        return builder.toString();
    }
}

Time complexity : O(n 2^n) Building one abbreviation from the number xx, we need scan all the nn bits. Besides the StringBuilder::toString function is also linear. Thus, to generate all the 2^n2 
n
 , it costs O(n 2^n) time.

Space complexity : O(n). If the return list doesn't count, we only need O(n) auxiliary space to store the characters in StringBuilder.

*/
