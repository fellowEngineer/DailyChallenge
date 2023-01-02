/* Given a binary tree, find the largest value in each level.

Input:
        1
       / \
      2   3 
Output:
1 3
Explanation:
At 0 level, values of nodes are {1}
                 Maximum value is 1
At 1 level, values of nodes are {2,3}
                Maximum value is 3


Input:
        4
       / \
      9   2
     / \   \
    3   5   7 
Output:
4 9 7
Explanation:
At 0 level, values of nodes are {4}
                 Maximum value is 4
At 1 level, values of nodes are {9,2}
                 Maximum value is 9
At 2 level, values of nodes are {3,5,7}
                 Maximum value is 7


Constraints:
1 ≤ Number of nodes ≤ 10^4
1 ≤ Data of a node ≤ 10^5
*/


#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution 
{
  public:
    vector<int> maximumValue(Node* node) 
    {
        //code here
        vector<int> ans;
        queue<Node *> q;
        q.push(node);
        
        while(!q.empty())
        {
            int curSize = q.size();
            int maxVal = INT_MIN;
            
            while(curSize-- > 0)
            {
                auto curr = q.front();
                q.pop();
                
                maxVal = max(maxVal, curr->data);
                if(curr->left != NULL)
                {
                    q.push (curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};