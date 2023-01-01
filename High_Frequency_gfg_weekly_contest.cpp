class Solution 
{
  public:
    string solve(int n, string s) 
    {
        // code here
        if(n == 1){return s;}
        string str = "";
        int hash[26] = {0};
        for(int i = 0; i < n; i++)
        {
            hash[s[i]-97]++;
        }
        
        int max_freq = INT_MIN;
        int ind = 0;
        for(int i = 0; i < 26; i++)
        {
            if(hash[i] > max_freq)
            {
                max_freq = hash[i];
                ind = i;
            }
        }
        str += (ind+97);
        
        return str;
    }
};
