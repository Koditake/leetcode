use std::cmp::Ordering::{Less,Greater,Equal};
impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        
        if target < matrix[0][0] || matrix[m - 1][n - 1] < target {
            // target is overmatched by matrix
            return false;
        }
        
        let (mut i, mut j) = (0, m * n - 1);
        
        while i <= j {
            let x = (i + (j - i)/2) as usize;
            let v = matrix[x/n][x%n];
            if target == v {
                return true;
            } else if target > v {
                i = x + 1;
            } else {
                j = x - 1;
            }
        }
        
        false
    }
}