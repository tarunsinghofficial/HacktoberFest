GFG : https://practice.geeksforgeeks.org/problems/naive-pattern-search-1587115620/1/
Leetcode : https://leetcode.com/problems/implement-strstr/


bool search(string pat, string txt) 
{ 
	
	// Your code here
	int m = txt.size();
	int n = pat.size();
	
	for(int i=0; i<=(m-n) ;i++){
	    
	    bool isBool = true;
	    for(int j=0; j<n ;j++){
	        if(pat[j]!=txt[j+i]){
	            isBool = false;
	            break;
	        }
	    }
	    
	    if(isBool){
	        return true;
	    }
	    
	}
	
	return false;
}
