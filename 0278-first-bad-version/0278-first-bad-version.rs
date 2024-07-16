// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let (mut l, mut r) = (0, n);
        
        while l < r {
            if self.isBadVersion(l + (r - l)/2) {
                r = l + (r - l)/2
            } else {
                l = l + (r - l)/2 + 1
            }
        }
        
        l
    }
}