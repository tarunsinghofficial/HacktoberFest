/**

Given an integer numRows, return the first numRows of Pascal's triangle.
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
**/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i].resize(i+1); 
            ans[i][0]=ans[i][i]=1; 
            
            for(int j=1;j<i;j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
            }
        }       
        
        return ans;
    }
};
