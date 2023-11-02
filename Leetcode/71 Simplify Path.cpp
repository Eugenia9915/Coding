class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        while(path!=""){
            if(path.find('/') == 0){
                path = path.substr(1);
            }
            else if(path.find('/') == -1){
                if(path == ".."){
                    if(v.size()>0)
                        v.pop_back();
                }
                else if(path == "."){}
                else{
                    v.push_back(path);
                }
                break;
            }
            else{
                if(path.substr(0, path.find('/')) == ".."){
                    if(v.size()>0)
                        v.pop_back();
                    path = path.substr(path.find('/')+1);
                }
                else if(path.substr(0, path.find('/')) == "."){
                    path = path.substr(path.find('/')+1);
                }
                else{
                    v.push_back(path.substr(0, path.find('/')));
                    path = path.substr(path.find('/')+1);
                }
            }
        }
        string ans = "/";
        for(int i=0;i<v.size();i++){
            ans += v[i];
            if(i+1 != v.size()) ans = ans + "/";
        }
        return ans;
    }
};