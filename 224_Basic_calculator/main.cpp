class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                int x = 0, j = i;
                while(j < s.size() && isdigit(s[j])){
                    x = x * 10 + (int)(s[j] - '0');
                    j++;
                }
                i = j-1;
                num.push(int(x));
            }else if(s[i] == '('){
                op.push(s[i]);
            }else if(s[i] == ')'){
                while(op.size() && op.top() != '(') eval(num, op);
                if(op.top() == '(') op.pop();
            }else{
                while(op.size() && op.top() != '(') eval(num, op);
                if(!i || s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-')
                    num.push(0);
                op.push(s[i]);
            }
        }
        while(op.size()) {
            eval(num, op);
        }
        return num.top();
    }

    void eval(stack<int>& num, stack<char>& op){
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();    
        char c = op.top(); op.pop();
        int r;
        if(c == '+') r = a+b;
        else if (c == '-') r = a-b;
        num.push(r);
    }
};

