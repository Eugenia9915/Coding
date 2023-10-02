class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1, carry=0;;
        string s="";
        while(i>=0 && j >=0){
            if(a[i]=='1' && b[j]=='1'){
                if(carry) s = '1'+s; 
                else s = '0'+s;
                carry=1;
            }
            else if((a[i]=='0' && b[j]=='1') || (a[i]=='1' && b[j]=='0')){
                if(carry){
                    s = '0'+s;
                    carry=1;
                }
                else{
                    s = '1'+s;
                    carry=0;
                }
            }
            else{
                if(carry){
                   s = '1'+s;
                }
                else{
                   s = '0'+s;
                }
                carry=0;
            }
            i--;j--;
        }
        if(i>=0){
            while(i>=0){
                if(a[i]=='1' && carry){
                    s = '0'+s;
                    carry=1;
                }
                else if(a[i]=='1' && !carry){
                   s = '1'+s;
                    carry=0;
                }
                else if(a[i]=='0' && carry){
                   s = '1'+s;
                    carry=0;
                }
                else{
                    s = '0'+s;
                    carry=0;
                }
                i--;
            }
        }
        else if(j>=0){
            while(j>=0){
                if(b[j]=='1' && carry){
                   s = '0'+s;
                    carry=1;
                }
                else if(b[j]=='1' && !carry){
                    s = '1'+s;
                    carry=0;
                }
                else if(b[j]=='0' && carry){
                    s = '1'+s;
                    carry=0;
                }
                else{
                    s = '0'+s;
                    carry=0;
                }
                j--;
            }
        }
        if(carry)s = '1'+s;
        // cout<<s<<endl;
        // string s1 = "0";
        // cout<<s1+'1'<<" "<<'1'+s1<<endl;
        return s;
    }
};