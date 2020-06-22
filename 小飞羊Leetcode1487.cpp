class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {        
        unordered_map<string, int> versions;
        vector<string> res;
        for (auto name : names) {
            if (versions.count(name)) {
                int ver = versions[name];
                while (versions.count(name + "(" + to_string(ver) + ")")) {
                    ++ver;
                }
                string new_name = name + "(" + to_string(ver) + ")";
                versions[name] = ver;
                
                versions[new_name] = 1;
                res.push_back(new_name);
            } else {
                versions[name] = 1;
                res.push_back(name);
            }
        }
        return res;
    }
};