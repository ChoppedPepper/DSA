class Solution {
public:
    int countSubstrings1(string s) {        
        int sum = 0;
        
        // substring with odd characters
        for(int i = 0; i < s.size(); ++i){         
            int j = 0;  // from i extend to two sides for j step 
            while(i - j >= 0 && i + j <= s.size() - 1){                
                if(s[i-j] == s[i+j]){
                    ++sum;
                    ++j;                    
                }else{
                    break;
                }                
            }
        }
        
        // substring with even characters
        for(int i = 0; i < s.size() - 1; ++i){  
            int j = 0;  // from i and i+1 extend to two sides for j step
            while(i - j >= 0 && i + 1 + j <= s.size() - 1){
                if(s[i-j] == s[i+1+j]){
                    ++sum;
                    ++j;
                }else{
                    break;
                }    
            }            
        }
        
        return sum;
    }


    int countSubstrings2(string s) {        
        int sum = 0;
        
        for(int i = 1; i <= 2 * s.size() - 1; ++i){
            int left = (i - 1) / 2, right = i / 2;  // from 0,0; 0,1; 1,1... to extend
            while(left >= 0 && right <= s.size() - 1){
                if(s[left] == s[right]){
                    ++sum;
                    --left;
                    ++right;
                }else{
                    break;
                }
            }
        }
        
        return sum;
    }    


    int countSubstrings(string s) {            
        // s transfer to str
        string str = "@";
        for(auto a : s){
            str += '#';
            str += a;
        }
        str += "#$";
        
        // r[i] record the max radius when str[i] as the center
        vector<int> r(str.size(), 0);
        
        // 用于记录当前s_right的中心位置和最右端位置
        int center = 0, right = 0;          
        // str中各字符str[i](从i = 1至i = r.size() - 2)依次作为中心点，计算r[i]
        for(int i = 1; i <= r.size() - 2; ++i){
            // 利用对称性减少一部分两端比较的操作，核心步骤
            if(i < right){
                r[i] = min(right-i, r[2*center-i]);
            }
            // 常规两端比较
            while(str[i+r[i]+1] == str[i-r[i]-1]){
                ++r[i];
            }
            
            // update center,right
            if(i+r[i] > right){
                center = i;
                right = i + r[i];
            }
        }
        
        int sum = 0;
        for(auto a : r){
            sum += (a + 1) / 2;
        }
        
        return sum;
    }
};