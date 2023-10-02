class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first=0,last=numbers.size()-1;
        while(1){
            if(numbers[first]+numbers[last] == target){
                return vector <int> {first+1,last+1};
            }
            else if(numbers[first]+numbers[last]>target){last--;}
            else{first++;}
        }
    }
};