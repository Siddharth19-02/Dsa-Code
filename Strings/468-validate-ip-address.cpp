class Solution {
public:
    string validIPAddress(string queryIP) {
        
        string res = "Neither";
        int n = queryIP.size();
        
        bool ipv4 = true;
        
        for(int i=0;i<n;i++)
        {
            if(queryIP[i] == '.')
            {
                break;
            }
            if(queryIP[i]==':')
            {
                ipv4 = false;
                break;
            }
        }
        
        if(ipv4)
        {
            int ans = 0;
            int count = 0;
            int total = 0;
            for(int i=0;i<n;i++)
            {
                if(queryIP[i]=='.')
                {
                    if(count == 0)
                        return res;
                    ans = 0;
                    count = 0;
                    total++;
                }
                else if(queryIP[i]>='0' and queryIP[i]<='9')
                {
                    if(count>0 and ans==0)
                        return res;
                    ans = ans*10 + (queryIP[i]-'0');
                    if(ans == 0 and count>0)
                        return res;
                    if(ans>255)
                        return res;
                    count++;
                }
                else
                    return res;
            }
            if(total!=3 or count == 0 or count>4)
                return res;
            return "IPv4";
        }
        else
        {
            int count = 0;
            int total = 0;
            for(int i=0;i<n;i++)
            {
                if(queryIP[i]==':')
                {
                    if(count == 0 or count>4)
                        return res;
                    count = 0;
                    total++;
                }
                else if((queryIP[i]>='0' and queryIP[i]<='9')||(queryIP[i]>='A' and queryIP[i]<='F')||(queryIP[i]>='a' and queryIP[i]<='f'))
                {
                   count++;
                }
                else
                    return res;
            }
            if(total!=7 or count == 0 or count>4 )
                return res;
            return "IPv6";
        }
        
        return res;
    }
};
