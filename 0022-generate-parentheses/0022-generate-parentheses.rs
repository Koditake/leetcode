impl Solution {
    fn helper(o: i32, c: i32, str: String, res: &mut Vec<String>) {
        if o == 0 && c == 0 {
            res.push(str);
            return;
        }
        
        if c > o {
            Solution::helper(o, c - 1, str.clone() + ")", res);
        }
        
        if o > 0 {
            Solution::helper(o - 1, c, str + "(", res);
        }
    }
    
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut res:Vec<String> = Vec::new();
        Solution::helper(n, n, String::new(), &mut res);
        res
    }
}