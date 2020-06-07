class Solution {
private:
    unordered_map<string,string> translator {
        {"&quot;", "\""}, 
        {"&apos;", "'"}, 
        {"&amp;", "&"}, 
        {"&gt;", ">"}, 
        {"&lt;", "<"}, 
        {"&frasl;", "/"}
    };
public:
    string entityParser(string text) {
        string res = "";
        
        int idx = 0;
        while (idx < text.length()) {
            
            // & 开头
            if (text[idx] == '&') {
                
                int ss = idx + 1; // search semicoloon
                while (ss < text.length() && text[ss] != ';') {
                    ++ss;
                }
                
                // ; 结尾
                if (ss < text.length() && text[ss] == ';') {
                    string symbol = text.substr(idx, ss - idx + 1);
                    if (translator.count(symbol)) {
                        string replace = translator[symbol];
                        res += replace;
                        idx = ss + 1;
                        continue;
                    }
                }
                
                
                if (ss == text.length()) {
                    return res + text.substr(idx);
                } else {
                    res += text.substr(idx, ss - idx + 1);
                    idx = ss + 1;
                    continue;
                }
                
                // assert(0) --> program never executes to here
                assert(0);
            }
            
            res += text[idx];
            ++idx;
        }
        return res;
    }
};