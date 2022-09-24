class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>vc;
        int k=p.size();
        map<char,int>mp;
        for(int i=0;i<p.length();i++){
            mp[p[i]]++;
        }
        int count=mp.size();
        int i=0,j=0;
        int n=s.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if((j-i+1)<k){
                j++;
            }
            else if((j-i+1)==k){
                if(count==0){
                    vc.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        
        return vc;
    }
};