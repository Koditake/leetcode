/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

use std::cmp::Ordering::{Less, Greater, Equal};

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let (mut l, mut r) = (1, n);
        
        while l <= r {
            let m = l + (r - l)/2;
            
            match guess(m).cmp(&0) {
                Less => r = m,
                Equal => return m,
                Greater => l = m + 1
            }
        }
        
        -1
    }
}