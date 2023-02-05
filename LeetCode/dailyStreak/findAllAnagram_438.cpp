/*
438. Find All Anagrams in a String
Medium
10.4K
301
Companies
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> ans;

        int psize = p.size(), ssize = s.size();
        int hash_p[26] = {0};
        for(char ch : p)
        {
            hash_p[ch-97]++;
        }
        

        for(int i = 0; (i+psize) <= ssize; i++)
        {
            string tmpstr = s.substr(i,psize);
            int hash_tmp[26] = {0};
            bool isEnter = false;

            for(char ch : tmpstr)
            {
                hash_tmp[ch-97]++;
            }

            for(int i = 0; i < 26; i++)
            {
                if(hash_p[i] != hash_tmp[i])
                {
                    isEnter = true;
                    break;
                }
            }

            if(!isEnter)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};