class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1){ //special case
            return (gas[0]-cost[0])>=0? 0:-1;
        }
        vector<int> arr(gas.size()*2,0);
        for(int i=0;i<gas.size();i++){ //for circular
            int t=gas[i]-cost[i];
            arr[i]=t;
            arr[i+gas.size()]=t;
        }
        int cnt=1, local_max=arr[0];
        //compute max_subarray
        for(int i=1;i<arr.size();i++){
            local_max += arr[i];
            if(local_max >= arr[i]){ //max_subarray[i]=max_subarray[i-1]+a[i]
                if(local_max>=0) cnt++; //be non-negative to go to next GS
            }
            else{ //max_subarray[i]=a[i] -> new start
                local_max = arr[i];
                cnt = 1;
            }
            if(cnt>=gas.size()) return i-gas.size()+1; //go through every GS
        }
        return -1;
    }
};