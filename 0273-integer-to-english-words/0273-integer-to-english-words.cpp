class Solution {
public:
    string result(vector<string> &vstr) {
        string res;
        for (int i = vstr.size() - 1; i >= 0; --i) {
            res += vstr[i];
            if (i > 0) res += " ";
        }
        return res;
    }
    
    void solve(int num, int mag, vector<string> &res) {
        if (num == 0) {
            res.push_back("Zero"); return;
        }
        
        while (num > 0) {
            if (num % 1000 == 0) {
                mag += 3;
                num /= 1000;
            } else {
                //hangle mag-10 scale
                switch (mag) {
                    case (3):
                        res.push_back("Thousand");
                        break;
                    case (6):
                        res.push_back("Million");
                        break;
                    case (9):
                        res.push_back("Billion");
                        break;
                    case (12):
                        res.push_back("Thousand Billion");
                        break;
                    default:
                        //num < 999
                        break;
                } 
                int tmp;
                /**
                *   special case: when last digits is "10-19"
                */
                if (9 < num % 100 && num % 100 < 20) {
                    tmp = num % 100;
                    switch (tmp) {
                        case (11): res.push_back("Eleven"); break;
                        case (12): res.push_back("Twelve"); break;    
                        case (13): res.push_back("Thirteen"); break;
                        case (14): res.push_back("Fourteen"); break;
                        case (15): res.push_back("Fifteen"); break;
                        case (16): res.push_back("Sixteen"); break;
                        case (17): res.push_back("Seventeen"); break;
                        case (18): res.push_back("Eighteen"); break;
                        case (19): res.push_back("Nineteen"); break;
                        default:
                            res.push_back("Ten");
                            break;
                    }
                    mag += 2;
                    num /= 100;
                } else {
                    // handle mag-1, from 0-9
                    tmp = num % 10;
                    switch(tmp) {
                        case (1): res.push_back("One"); break;
                        case (2): res.push_back("Two"); break;
                        case (3): res.push_back("Three"); break;
                        case (4): res.push_back("Four"); break;
                        case (5): res.push_back("Five"); break;
                        case (6): res.push_back("Six"); break;
                        case (7): res.push_back("Seven"); break;
                        case (8): res.push_back("Eight"); break;
                        case (9): res.push_back("Nine"); break;
                        default:
                            break;
                    };
                    mag += 1;
                    num /= 10;

                    // handle mag-2, from 20-90
                    tmp = num % 10;
                    switch(tmp) {
                        // case (1): s += "one"; break;
                        case (1): res.push_back("Ten"); break;
                        case (2): res.push_back("Twenty"); break;
                        case (3): res.push_back("Thirty"); break;
                        case (4): res.push_back("Forty"); break;
                        case (5): res.push_back("Fifty"); break;
                        case (6): res.push_back("Sixty"); break;
                        case (7): res.push_back("Seventy"); break;
                        case (8): res.push_back("Eighty"); break;
                        case (9): res.push_back("Ninety"); break;
                        default:
                            break;
                    };
                    mag += 1;
                    num /= 10;
                }

                // hangle mag-3, from 100-900
                tmp = num % 10;
                switch(tmp) {
                    case (1): res.push_back("One Hundred"); break;
                    case (2): res.push_back("Two Hundred"); break;
                    case (3): res.push_back("Three Hundred"); break;
                    case (4): res.push_back("Four Hundred"); break;
                    case (5): res.push_back("Five Hundred"); break;
                    case (6): res.push_back("Six Hundred"); break;
                    case (7): res.push_back("Seven Hundred"); break;
                    case (8): res.push_back("Eight Hundred"); break;
                    case (9): res.push_back("Nine Hundred"); break;
                    default:
                        break;
                };
                mag += 1;
                num /= 10;    
            }
            
            
            
        }
    }
    
    string numberToWords(int num) {
        /***
        *   Ideas:
        *   -> every 1000 increase the "word" from "" to maximum "thousand billion"
        *   -> magnitude "" 1-3 (0-999) -> "thounsand" 4-6 (1,000-999,999) -> "million" 7-9 (1,000,000-999,999,999)
        *   -> "billion" 10-12 (1,000,000,000-999,999,999,999) 
        *   -> "thounsand billion" 13 (1,000,000,000,000-2,147,483,647)
        *   We only need to calculate the calling for every 3-digits block and tack on the magnitude calling
        */
        
        vector<string> vstr;
        solve(num, 0, vstr);
        return result(vstr);
    }
};