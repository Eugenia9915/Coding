#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fibonacciModified' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER t1
 *  2. INTEGER t2
 *  3. INTEGER n
 */

string pplus(string s1, string s2){
    int d = 0;
    string s = "";
    char c;
    for(int i=s1.length()-1, j=s2.length()-1;i>=0 && j>=0;i--,j--){
        d += s1[i] - '0' + s2[j] - '0';
        c = '0' + (d%10);
        s = c + s;
        d/=10;
        
        if(i==0){
            j--;
            while(j>=0){
                d += s2[j] - '0';
                c = '0' + (d%10);
                s = c + s;
                d/=10;
                j--;
            }
            // cout<<"d="<<d<<endl;
            if(d != 0) s = to_string(d) + s;
        }
        else if(j==0){
            i--;
            while(i>=0){
                d += s1[i] - '0';
                c = '0' + (d%10);
                s = c + s;
                d/=10;
                i--;
            }
            // cout<<"d="<<d<<endl;
            if(d != 0) s = to_string(d) + s;
        }
    }
    return s;
}

string mul(string s1, char ch){
    int d = 0;
    string s = "";
    int m = ch -'0';
    char c;
    for(int i=s1.length()-1;i>=0;i--){
        d += (s1[i]-'0')*m;
        c = '0' + (d%10);
        s = c + s;
        d/=10;
    }
    if(d != 0) s = to_string(d) + s;

    return s;
}

string cal(string n1, string n2){
    string s = "", t, ten = "";
    char c;
    for(int i=n2.length()-1;i>=0;i--){
        t = mul(n2, n2[i]);
        t = t + ten;
        if(s == "") s = t;
        else s = pplus(s, t);
        ten += "0";
    }
    s = pplus(s, n1);
    return s;
}


string fibonacciModified(int t1, int t2, int n) {
    string dp[n];
    dp[0] = to_string(t1);
    dp[1] = to_string(t2);
    for(int i=2;i<n;i++){
        dp[i] = cal(dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int t1 = stoi(first_multiple_input[0]);

    int t2 = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    string result = fibonacciModified(t1, t2, n);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
