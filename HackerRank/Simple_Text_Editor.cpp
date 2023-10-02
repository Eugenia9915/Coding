#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long Q;
    cin>>Q;
    int action, index;
    string s="", tmp;
    vector<string> prev;
    prev.push_back(s);
    for(long long i=0;i<Q;i++){
        cin>>action;
        switch(action){
            case 1:
                cin>>tmp;
                s+=tmp;
                prev.push_back(s);
                break;
            case 2:
                cin>>index;
                tmp = "";
                for(int i=0;i<s.length()-index;i++){
                    tmp+=s[i];
                }
                s = tmp;
                prev.push_back(s);
                break;
            case 3:
                cin>>index;
                cout<<s[index-1]<<endl;
                break;
            case 4:
                if(prev.size()>1) prev.pop_back();
                s = prev[prev.size()-1];
                break;
        }
    }  
    return 0;
}
