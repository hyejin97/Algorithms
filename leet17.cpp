class Solution {
public:
    vector<string> res;
    vector<string> tel;
    vector<string> letterCombinations(string digits) {
        tel.push_back(""); //0
        tel.push_back(""); //1
        tel.push_back("abc");
        tel.push_back("def");
        tel.push_back("ghi");
        tel.push_back("jkl");
        tel.push_back("mno");
        tel.push_back("pqrs");
        tel.push_back("tuv");
        tel.push_back("wxyz");
        
        //backtracking
        if(digits.length()) backtrack(digits, "");
        return res;
    }
    
    void backtrack(string& digits, string curr){
        if(curr.length() == digits.length()) res.push_back(curr);
        else{
            int idx = digits[curr.length()] - '0';
            for(int i = 0; i < tel[idx].length(); i++){
                backtrack(digits, curr + tel[idx][i]);
            }
        }
    }
};
