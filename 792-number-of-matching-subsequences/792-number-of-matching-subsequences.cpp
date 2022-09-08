class Solution {
public:
//     void findvalues(string s,unordered_map<string,int>&mp,int &count,string output)
//     {
//         if(s.length()==0)
//         {
//             if(mp.find(output)!=mp.end())
//             {
//                count+=mp[output];
                
//                 mp.erase(output);
//             }
               
//              return;
                
//         }
        
//         findvalues(s.substr(1),mp,count,output+s[0]);
//         findvalues(s.substr(1),mp,count,output);
        
        
//     }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<string,int>mp;
        for(auto x:words)
        {
            mp[x]++;
        }
        int count=0;
        // int i=0;
        // string output="";
        // findvalues(s,mp,count,output);
       
        for(auto x:mp)
        {
            string mp_string=x.first;
             int i=0,j=0;
            while(i<mp_string.length() and j<s.length())
            {
                if(mp_string[i]==s[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            if(i==mp_string.length())
            {
                count+=x.second;
            }
            
        }
        return count;
        
    }
};