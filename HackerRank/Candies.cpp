#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    
    if(n==1) return 1;
    // -- FIRST VERSION --
    // int can[n], j;
    // long sum = 0;
    // can[0] = 1;
    // for(int i=1;i<n;i++){
    //     if(arr[i-1] < arr[i]){
    //         can[i] = can[i-1]+1;
    //     }
    //     else if(arr[i-1] == arr[i]){
    //         can[i] = 1;
    //     }
    //     else{ //arr[i-1] > arr[i]
    //         can[i] = 1;
    //         j = i;
    //         while(arr[j]<arr[j-1] && (can[j]>=can[j-1]) && j>0){
    //             can[j-1]++;
    //             j--;
    //             sum++;
    //         }
    //     }
    //     sum += can[i];
    // }

    // return sum;
    
    long sum = 0;
    int can[n];
    can[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i-1] < arr[i]){
            can[i] = can[i-1]+1;
        }
        else can[i] = 1;
    }


    
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            can[i] = max(can[i], can[i+1]+1);
        }
    }
    
    for(int i=0;i<n;i++){
        sum+=can[i];
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

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
