impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        
        if m == 0 || n == 0 {
            return false;
        }
        
        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == target {
                    return true;
                }
            }
        }
        
        false
    }
}