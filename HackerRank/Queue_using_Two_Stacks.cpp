#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<long long> q;
    int query;
    cin>>query;
    int action;
    long long num;
    for(int i=0;i<query;i++){
        cin>>action;
        switch(action){
            case 1:
            cin>>num;
            q.push_back(num);
            break;
            case 2:
            q.erase(q.begin());
            break;
            case 3:
            cout<<q[0]<<endl;
            break;
        }
    }
    
    return 0;
}
