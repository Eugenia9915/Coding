class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> v;
        int num1, num2;
        for(auto t:tokens){
            if(t == "+"){
                num2 = v[v.size()-1];
                v.pop_back();
                num1 = v[v.size()-1];
                v.pop_back();
                v.push_back(num1 + num2);
            }
            else if(t == "-"){
                num2 = v[v.size()-1];
                v.pop_back();
                num1 = v[v.size()-1];
                v.pop_back();
                v.push_back(num1 - num2);
            }
            else if(t == "*"){
                num2 = v[v.size()-1];
                v.pop_back();
                num1 = v[v.size()-1];
                v.pop_back();
                v.push_back(num1 * num2);
            }
            else if(t == "/"){
                num2 = v[v.size()-1];
                v.pop_back();
                num1 = v[v.size()-1];
                v.pop_back();
                v.push_back(num1 / num2);
            }
            else{
                num1 = 0;
                int j = 0;
                bool neg = false;
                if(t[j] == '-'){
                    neg = true;
                    j = 1;
                }
                for(;j<t.length();j++){
                    num1 *= 10;
                    num1 += (t[j]-'0');
                }
                v.push_back(neg ? -1*num1 : num1);
            }
        }
        return v[v.size()-1];
    }
};