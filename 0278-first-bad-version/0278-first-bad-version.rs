// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let mut l = 0;
        let mut r = n;
        while l < r {
            let mut g = l + (r-l) / 2;
            if self.isBadVersion(g) {
                if g - 1 >= 0 {
                    if self.isBadVersion(g-1) {
                        r = g - 1;
                    } else {
                        return g;
                    }
                } else {
                    return g;
                }
            } else {
                l = g + 1;
            } 
        }
        
        l
    }
}