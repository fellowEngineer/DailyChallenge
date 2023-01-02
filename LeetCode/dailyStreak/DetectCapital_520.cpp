/*
520. Detect Capital

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.


Input: word = "USA"
Output: true

Input: word = "FlaG"
Output: false

word consists of lowercase and uppercase English letters.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    bool detectCapitalUse(string word) 
    {
        int len = word.size();
        if(len == 1) {return true;}

        if(word[0] <= 90)
        {
            if(word[1] <= 90)
            {
                for(int b = 1; b < len; b++)
                {
                    if(word[b] > 90)
                    {
                        return false;
                    }
                }
                return true;
            }
            else
            {
                for(int c = 1; c < len; c++)
                {
                    if(word[c] < 97)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        else
        {
            /// means first letter is small
            for(int a = 1; a < len; a++)
            {
                /// if any of them is not small / capital
                /// then false;
                if(word[a] < 97)
                {
                    return false;
                }
            }
            return true;
        }
    }
};
