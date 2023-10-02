class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int total = nums1.size() + nums2.size();
        int index = 0;
        int arr[2000];


        if(!nums1.size()){ // nums2.size()>=1
            if(total%2){ //odd
                // total/2
                // cout<<nums2[total/2]<<endl;
                return nums2[total/2];
            }
            else{ //even
                // total/2 -1 & total/2
                // cout<<(nums2[total/2-1]+nums2[total/2])/2.0<<endl;
                return (nums2[total/2-1]+nums2[total/2])/2.0;
            }
        }
        else if(!nums2.size()){ // nums1.size()>=1
            if(total%2){ //odd
                // total/2
                // cout<<nums1[total/2]<<endl;
                return nums1[total/2];
            }
            else{ //even
                // total/2 -1 & total/2
                // cout<<(nums1[total/2-1]+nums1[total/2])/2.0<<endl;
                return (nums1[total/2-1]+nums1[total/2])/2.0;
            }
        }
        else{
            while(i < nums1.size() || j < nums2.size()){
                if(i >= nums1.size()){
                    arr[index] = nums2[j];
                    j++;
                }
                else if(j >= nums2.size()){
                    arr[index] = nums1[i];
                    i++;
                }
                else{
                    if(nums1[i]<=nums2[j]){
                        arr[index] = nums1[i];
                        i++;
                    }
                    else{
                        arr[index] = nums2[j];
                        j++;
                    }
                }
                if(total%2 && index == total/2){ //odd
                    // total/2
                    return arr[index];
                }
                else if(total%2==0 && index == total/2){ //even
                    // total/2 -1 & total/2
                    return (arr[index-1]+arr[index])/2.0;
                }
                cout<<arr[index]<<endl;
                index++;
            }
        }
        return -1;
    }
};