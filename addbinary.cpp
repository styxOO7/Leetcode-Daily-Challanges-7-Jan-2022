class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        
        int i = a.size()-1;
        int j = b.size()-1;
        
        int extra = 0;
        while(i >= 0 and j >= 0){
            if(a[i] == '0' and b[j] == '0'){
                if(extra){
                    ans += "1";
                    extra = 0;
                } 
                else ans += "0";
            }
            else if((a[i] == '0' and b[j] == '1') or (a[i] == '1' and b[j] == '0')){
                if(extra){
                    ans += "0";
                    extra = 1;
                } 
                else ans += "1";
            }
            else if(a[i] == '1' and b[j] == '1'){
                if(!extra){
                    ans += "0";
                    extra = 1;
                }
                else{
                    ans += "1";
                    extra = 1;
                }
            }
            
            i--;j--;
            
        }
        
        // if anyone alive:
        while(i >= 0){
            if(a[i] == '0'){
                if(extra){
                    ans += "1";
                    extra = 0;
                }
                else ans += "0";
            }
            else{
                if(extra){
                    ans += "0";
                    extra = 1;
                }
                else ans += "1";
            }
            i--;
        }
        while(j >= 0){
            if(b[j] == '0'){
                if(extra){
                    ans += "1";
                    extra = 0;
                }
                else ans += "0";
            }
            else{
                if(extra){
                    ans += "0";
                    extra = 1;
                }
                else ans += "1";
            }
            j--;
        }
        
        if(extra) ans += "1";
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};