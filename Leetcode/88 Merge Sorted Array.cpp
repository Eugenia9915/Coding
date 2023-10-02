class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int k=0;
        while(k<nums1.size()){ 
            if(nums1[k]==0 && nums1.size()-1 >=m)
                nums1.erase(nums1.begin()+k);
            else
                k++;
        }
        k=0;
        while(k<nums2.size()){ 
            if(nums2[k]==0 && nums2.size()-1 >=n)
                nums2.erase(nums2.begin()+k);
            else
                k++;
        }
        if(m==0)nums1=nums2;
        else{
            int i=0;
            while(nums2.size()!=0){
                if(nums1[i]>nums2[0]){
                    nums1.insert(nums1.begin()+i,nums2[0]);
                    nums2.erase(nums2.begin());
                }
                else{ //equal
                    i++;
                }
                if(i>=nums1.size()){
                    while(nums2.size()!=0){
                        nums1.insert(nums1.begin()+i,nums2[0]);
                        nums2.erase(nums2.begin());
                        i++;
                    }
                }
            }
        }
    }
};