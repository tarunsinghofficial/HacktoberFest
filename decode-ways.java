
class Solution {
    public int numDecodings(String s) {
        int dp[]=new int[s.length()];
        if(s.charAt(0)=='0')
        {
            return 0;
        }
        //if the number begins with a zero return 0
       
        dp[0]=1;
        // if the number begins (!=0)
        //then the possible ways of decoding =1 eg. 23468 ->[2]->for 2 its 'b'
        // 45799->[4] for 4 its 'd'
        for(int i=1;i<dp.length;i++)
        {
            if(s.charAt(i-1)=='0' && s.charAt(i)=='0')
            {
                dp[i]=0;   /*
                             ->12100-> lets consider a dp -> so for each index we will                                    store the possible number if ways of decoding it 
                             
                             ->lets consider it for index 4(which contains 0)
                             ->i-1 contains 0 amd i contains 0
                             -> 121-00 and 1210-0 these are ways
                             -> nothing can be decoded since '0' has no value
                             */
                            
             }
            else if(s.charAt(i-1)!='0' && s.charAt(i)=='0')
            {
                
                /*
                
                ->21120 -> consider the index 4 which has ('0')and index(4-1)contains('3')
                in such cases possible ways are-> 211-20 and 2112-0
                -> so for 2112-0(nothing is possible since '0' has no value so all the        possible ways till 2112 ie-> 2-1-1-2,1-1-1-2,2-11-2,21-12,2-1-12) will continue
                
                ->but  for 211-20->sice 20 has a value->'T'
                so if I attach T after all possible ways till 211-20 than we get
                21-1-20,2-1-1-20,2-11-20 -> so dp[i-2] is the answer
                */
                
                
                
             if(s.charAt(i-1)=='1' || s.charAt(i-1)=='2')
                {
                    dp[i]=i>=2?dp[i-2]:1;
                }
            }
            else if(s.charAt(i-1)=='0' && s.charAt(i)!='0')
            {
                dp[i]=i>=2?dp[i-1]:0;
                
                
                /*
                if the number is 21103-> possible ways are (211)-03 ans (2110)-3
                so (211)-03(has no value since '03' cannot be decoded)
                //so (2110)-3 means 'c' will be attached after all possible ways till 2110
                so the answer remains same as (2110)
                */
                
            }
            else
            {
                
               if(Integer.parseInt(s.substring(i-1,i+1))<=26)
               {
                   dp[i]=dp[i-1]+(i>=2?dp[i-2]:1);
               }
                else
                {
                    dp[i]=dp[i-1];
                }
            }
            
            /*21126
            so for i=4 possible ways are (211)-26 and (2112)-6
            so you will get an answer by attaching 'z' after all possible ways of(211) and attaching 'F' after (2112)
            so the ans is dp[i-1]+dp[i-2]
            */
        }
        return dp[dp.length-1];
    
        
    }
}
