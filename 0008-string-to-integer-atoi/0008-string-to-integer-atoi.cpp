class Solution {
public:
    int myAtoi(string s) { 
        long ans=0;
        int sign=1;
        int cnt=0;
        int idx=0;
        while(s[idx]==' ' && idx<s.length()) 
        {
            idx++;
        }
        if(s[idx]=='-' && idx<s.length() && cnt<1)
        {
            sign=-1;
            cnt++;
            idx++;
        }
        if(s[idx]=='+' && idx<s.length() && cnt<1)
        {
            sign=1;
            cnt++;
            idx++;
        }
        if(isdigit(s[idx])==false && idx<s.length())
        {
            return 0;
        }
        while(isdigit(s[idx])==true && idx<s.length()) 
        {
            ans=ans*10+(s[idx]-'0');
            if(sign*ans<INT_MIN)
                return INT_MIN;
            if(sign*ans>INT_MAX)
                return INT_MAX;
            idx++;
        }
        return sign*ans;
    }
};