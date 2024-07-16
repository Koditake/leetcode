use std::cmp::Ordering;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let (row, col) = (matrix.len(), matrix[0].len());
        
        // check if target overshoot matrix
        if target < matrix[0][0] || matrix[row - 1][col - 1] < target {
            return false;
        }
        
        //check if target is at begin/end matrix
        if target == matrix[0][0] || matrix[row - 1][col - 1] == target {
            return true;
        }
        
        let mut l = 0;
        let mut r = row * col - 1;
        
        while l < r {
            let m = l + (r - l)/2;
            let v = matrix[m / col][m % col];
            
            match target.cmp(&v) {
                Ordering::Less => r = m,
                Ordering::Greater => l = m + 1,
                Ordering::Equal => return true,
            }
        }
        
        false
    }
}