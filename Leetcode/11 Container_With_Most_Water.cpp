class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int left = 0, right = height.size()-1;
        while(left < right){
            maxA = max(maxA, (right-left)*min(height[left], height[right]));
            if(height[left]<height[right]) left++;
            else if(height[left]>height[right])right--;
            else{
                left++;
                right--;
            }
        }
        return maxA;
    }
};