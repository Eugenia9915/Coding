#include <bits/stdc++.h>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    vector<char> st;
    bool failed = false;
    for(unsigned i=0;i<s.length();i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') st.push_back(s[i]);
        else if(st.size()!=0 && st[st.size()-1] == '{' && s[i] == '}'){
            st.pop_back();
        }
        else if(st.size()!=0 && st[st.size()-1] == '(' && s[i] == ')'){
            st.pop_back();
        }
        else if(st.size()!=0 && st[st.size()-1] == '[' && s[i] == ']'){
            st.pop_back();
        }
        else {
            failed = true;
            break;
        }
    }
    if(!failed && st.size()==0) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
