// Problem link: https://practice.geeksforgeeks.org/problems/multiply-the-matrices-1587115620/1

vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        // code here
        int n1,m1, n2, m2;
        n1 = A.size();
        n2 = B.size();
        
        //col
        m1 = A[0].size();
        m2 = B[0].size();
        vector<vector<int>> ans;

        if(m1 == n2){
            for(int i=0;i<n1;i++){
                vector<int> temp;
                
                for(int j=0; j<m2;j++){
                    int sum=0;
                    for(int k=0;k<m1;k++){
                        sum = sum + (A[i][k] * B[k][j]);
                    }
                    temp.push_back(sum);
                }
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
