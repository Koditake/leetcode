class Solution {
    vector<string> mag00 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> mag10 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> mag11 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> mag20 = {"", "Hundred"};
    vector<string> mag3 = {"", "Thousand", "Million", "Billion"};

    string printresult(vector<string> &vstr) {
        string res;
        for (const auto &s : vstr) {
            if (!s.empty()) {
                if (!res.empty()) res += " ";
                res += s;
            }
        }
        return res;
    }
    
    void solve(int num, vector<string> &vstr, int mag = 0) {
        if (num == 0) {
            vstr.push_back("Zero");
            return;
        }
        
        if (num == 0) return;
        
        while (num > 0) {
            int tmp = num % 1000;
            num /= 1000;
            
            if (tmp > 0) {
                vector<string> parts;
                if (tmp >= 100) {
                    parts.push_back(mag00[tmp / 100]);
                    parts.push_back(mag20[1]); // "Hundred"
                    tmp %= 100;
                }
                
                if (tmp >= 10 && tmp < 20) {
                    parts.push_back(mag11[tmp - 10]);
                } else {
                    if (tmp >= 20) {
                        parts.push_back(mag10[tmp / 10]);
                        tmp %= 10;
                    }
                    if (tmp > 0) {
                        parts.push_back(mag00[tmp]);
                    }
                }
                
                if (mag > 0) {
                    parts.push_back(mag3[mag]);
                }
                
                vstr.insert(vstr.begin(), parts.begin(), parts.end());
            }
            mag++;
        }
    }
    
public:
    string numberToWords(int num) {
        vector<string> vstr;
        solve(num, vstr);
        return printresult(vstr);
    }
};
