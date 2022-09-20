class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string str = "";
        int i=n, j=m;
        while(i>0 and j>0){
            // if(i==0 and j==0)
            //     break;
            // if(i==0 and j>0){
            //     str = str2[j-1] + str;
            //     break;
            // }
            // else if(j==0 and i>0){
            //     str = str1[i-1] + str;
            //     break;
            // }
            if(str1[i-1]==str2[j-1]){
                str = str1[i-1] + str;
                i--, j--;
            }
            else{
                if(dp[i][j-1]<=dp[i-1][j]){
                    str = str1[i-1] + str;
                    i--;
                }
                else{
                    str = str2[j-1] + str;
                    j--;
                }
            }
        }
        while(i>0){
            str = str1[i-1] + str;
            i--;
        }
        while(j>0){
            str = str2[j-1] + str;
            j--;
        }
        return str;
    }
};