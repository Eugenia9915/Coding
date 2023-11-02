class MinStack {
public:
    vector<pair<int,int>> v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()) v.push_back({val,val});
        else{
            int curMin = v[v.size()-1].second;
            if(curMin < val) v.push_back({val,curMin});
            else v.push_back({val,val});
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1].first;
    }
    
    int getMin() {
        return v[v.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */