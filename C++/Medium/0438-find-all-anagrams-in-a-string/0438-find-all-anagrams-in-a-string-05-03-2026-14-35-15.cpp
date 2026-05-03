class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        vector<int> t1(26);
        for(int i=0;i<p.size();i++)
        {
            t1[p[i]-'a']++;
        }
        vector<int> t2(26);
        for(int i=0;i<p.size();i++)
        {
            t2[s[i]-'a']++;
        }
        if(isSame(t1,t2)==true) ans.push_back(0);
        int l=0;
        int r=p.size();
        while(r<s.size())
        {
            t2[s[r]-'a']++;
            t2[s[l]-'a']--;
            if(isSame(t1,t2)==true) ans.push_back(l+1);
            l++;
            r++;
        }
        return ans;
    }
    bool isSame(vector<int>t1, vector<int>t2)
    {
        for(int i=0;i<26;i++)
        {
            if(t1[i]!=t2[i]) return false;
        }
        return true;
    }
//please upvote...
};