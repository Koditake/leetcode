impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut r = 0 as i32;
        let mut c = cols as i32 - 1;
        while r < rows as i32 && c as i32 >= 0 {
            let curr = matrix[r as usize][c as usize];
            if curr == target {
                return true;
            } else if curr < target {
                r += 1;
            } else {
                c -= 1;
            }
        }
        false
    }
}