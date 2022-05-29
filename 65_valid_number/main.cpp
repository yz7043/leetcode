class Solution {
public:
    string digit = "digit";
    string sign = "sign";
    string dot = "dot";
    string exp = "exp";
    bool isNumber(string s) {
        vector<unordered_map<string, int>> dfa;
        vector<int> validList = {1, 4, 7};
        dfa.push_back({{digit, 1}, {sign, 2}, {dot, 3}});
        dfa.push_back({{digit, 1}, {dot, 4}, {exp, 5}});
        dfa.push_back({{digit, 1}, {dot, 3}});
        dfa.push_back({{digit, 4}});
        dfa.push_back({{digit, 4}, {exp, 5}});
        dfa.push_back({{sign, 5}, {digit, 7}});
        dfa.push_back({{digit, 7}});
        dfa.push_back({{digit, 7}});
        int curState = 0;
        for(auto& c : s){
            string group = "";
            if(isdigit(c)){
                group = digit;
            }else if(c == 'e' || c == 'E'){
                group = exp;
            }else if(c == '.'){
                group = dot;
            }else if(c == '+' || c == '-'){
                group = sign;
            }else{
                return false;
            }
            if(dfa[curState].find(group) == dfa[curState].end()){
                return false;
            }
            curState = dfa[curState][group];
        }
        for(auto& valid : validList){
            if(curState == valid) return true;
        }
        return false;
    }
};
