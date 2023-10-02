#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {
    // if(s.length()==1) return 0;
    bool failed;
    for(int i=0,j=s.length()-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            int t_i = i, t_j = j;
            if(s[i+1]==s[j]){
                failed = false;
                int r = i;
                i++;
                while(i<j){
                    if(s[i]!=s[j]){
                        failed = true;
                        break;
                    }
                    i++;
                    j--;
                }
                if(!failed) return r;
            }
            i=t_i;
            j=t_j;
            if(s[j-1]==s[i]){
                // failed = false
                int r = j;
                j--;
                while(i<j){
                    if(s[i]!=s[j]) return -1;
                    i++;
                    j--;
                }
                return r;
            }
        }
    }
 return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

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
