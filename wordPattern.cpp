class Solution {
public:
    
    vector<string> extractWords(string &s){
        vector<string> list;
        int n = s.size();
        string tmp = "";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                list.push_back(tmp);
                tmp = "";
            }else tmp += s[i];
            if(i == n-1) list.push_back(tmp);
        }
        
        return list;
        
    }    
    
    bool wordPattern(string p, string s) {    
        unordered_map<char,string> m;
        unordered_map<string,char> mrev;

        vector<string> list = extractWords(s);
        
        if(p.size() != list.size()) return false;
        
        for(int i=0;i<p.size();i++){
            char ch = p[i];
            string cur = list[i];
            
            if((m.find(ch) != m.end() and m[ch] != cur) or (mrev.find(cur) != mrev.end() and mrev[cur] != ch)){
                return false;
            }
            else{
                m[ch] = cur;
                mrev[cur] = ch;
            }
        }
        
        return true;
        
    }
};