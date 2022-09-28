class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>wordlist;
        for(auto x:wordList)
        {
            wordlist.insert(x);
        }
        set<string>s;
        s.insert(beginWord);
        queue<string>q;
        q.push(beginWord);
        int cnt=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string word=q.front();
                cout<<word<<" ";
                q.pop();
                if(word==endWord)
                {
                    return cnt;
                }
                
                for(int i=0;i<word.length();i++)
                {
                    for(int k='a';k<='z';k++)
                    {
                    
                        string p=word;
                        p[i]=char(k);
                        if(wordlist.find(p)!=wordlist.end() and s.find(p)==s.end())
                        {
                            q.push(p);
                            s.insert(p);
                            
                        }
                    }
                }
                
            }
            cnt++;
        }
        return 0;
        
        
    }
};