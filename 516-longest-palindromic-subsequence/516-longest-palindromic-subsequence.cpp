class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
       string s2 = "";
        
        
         int x=s.size();
        for( int i=x-1; i>=0;i--)
        {
            s2.push_back(s[i]);
        }
        
	   
	     int L[x+1 ][x+1]; 
         
      for(int i=0;i<=x;i++)
      {
          L[0][i]=0;
          L[i][0]=0;
      }
    
    for (int i = 1; i <= x; i++) 
    { 
        for (int j = 1; j <= x; j++) 
        { 
      
         if (s[i - 1] == s2[j - 1]) 
         {
            L[i][j] = L[i - 1][j - 1] + 1; 
         }
      
        else
        {
            L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    }
    }

        return L[x][x];
        
    }
};