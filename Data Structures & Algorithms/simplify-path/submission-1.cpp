class Solution {
public:
    string simplifyPath(string path) {
        stack<string> directories;
        
        for(int i = 0; i < path.size(); i++){
            int r = i;
            if(path[i] != '/'){
                while(r < path.size() && path[r] != '/'){
                    r++;
                }
                string directory = path.substr(i, r-i);
                
                if(directory == ".."){
                    if(!directories.empty()){
                        directories.pop();
                    }
                }else if(directory != "."){
                    directories.push(directory);
                }
                i = r;
            }
        }
        if(directories.empty()){
            return "/";
        }
        stack<string> d;
        while(!directories.empty()){
            d.push(directories.top()); directories.pop();
        }
        string simple = "/" + d.top();
        d.pop();
        while(!d.empty()){
            simple += "/";
            simple += d.top(); 
            d.top();
            d.pop();
        }
        return simple;
    }
};