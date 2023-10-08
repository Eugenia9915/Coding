class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, end = s.length()-1;
        while(front<end){
            while(!(s[front]>='A' && s[front]<='Z') && !(s[front]>='a' && s[front]<='z') && !(s[front]>='0' && s[front]<='9')&& front<end) front++;
            while(!(s[end]>='A' && s[end]<='Z') && !(s[end]>='a' && s[end]<='z') && !(s[end]>='0' && s[end]<='9') && front<end) end--;
            if(s[front]>='A' && s[front]<='Z') s[front] += 32;
            if(s[end]>='A' && s[end]<='Z') s[end] += 32;
            cout<<s[front]<<" "<<s[end]<<endl;
            if(s[front]!=s[end]) return false;
            else{
                front++;
                end--;
            }
        }
        return true;
    }
};