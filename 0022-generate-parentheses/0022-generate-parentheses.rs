impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut vecstr:Vec<String> = Vec::new();
        Self::helper(n,n,String::new(),&mut vecstr);
        return vecstr;
    }
    
    fn helper(o:i32, c:i32, str:String, vecstr: &mut Vec<String>) {
        if o == 0 && c == 0 {
            vecstr.push(str);
            return;
        }
        
        if (o < c) {
            Self::helper(o, c - 1, str.clone() + ")", vecstr);
        }
        
        if (o > 0) {
            Self::helper(o - 1, c, str.clone() + "(", vecstr);
        }
    }
}