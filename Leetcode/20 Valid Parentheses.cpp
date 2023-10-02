class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        int len=s.size();
        for(int i=0;i<len;++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                left.push(s[i]);
            else{
                if(left.empty())return false;
                else if(s[i]==')'){
                    if(left.top()=='(') left.pop();
                    else return false;
                }
                else if(s[i]==']'){
                    if(left.top()=='[') left.pop();
                    else return false;
                }
                else if(s[i]=='}'){
                    if(left.top()=='{') left.pop();
                    else return false;
                }
            }
        }
        if(left.empty()) return true;
        return false;
    }
};