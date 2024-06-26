class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1);
        istringstream v2(version2);
        
        string num1, num2;
        
        while (!v1.eof() || !v2.eof()) {
            if (!v1.eof()) {
                getline(v1, num1, '.');
            } else {
                num1 = "0";
            }
            
            if (!v2.eof()) {
                getline(v2, num2, '.');
            } else {
                num2 = "0";
            }
            
            int n1 = stoi(num1), n2 = stoi(num2);
            
            if (n1 == n2)    
                continue;
            
            return (n1 > n2)? 1:-1;
        }
        
        return 0;
    }
};