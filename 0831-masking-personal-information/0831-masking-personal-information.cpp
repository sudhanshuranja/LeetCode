class Solution {
public:
    string maskPII(string s) {
        
        // EMAIL CASE
        if(s.find('@') != string::npos) {
            
            // Convert to lowercase
            for(char &c : s) {
                c = tolower(c);
            }
            
            int at = s.find('@');
            string name = s.substr(0, at);
            string domain = s.substr(at);
            
            return string(1, name[0]) + "*****" + name.back() + domain;
        }
        
        // PHONE CASE
        
        string digits = "";
        
        for(char c : s) {
            if(isdigit(c)) {
                digits += c;
            }
        }
        
        string local = digits.substr(digits.length() - 4);
        int country = digits.length() - 10;
        
        string result = "";
        
        if(country > 0) {
            result += "+";
            result += string(country, '*');
            result += "-";
        }
        
        result += "***-***-" + local;
        
        return result;
    }
};