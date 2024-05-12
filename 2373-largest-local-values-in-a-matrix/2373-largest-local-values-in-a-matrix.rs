use std::cmp::max;

impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = grid.len();
        let mut res = vec![vec![0 as i32;n - 2];n - 2];
        
        for i in 0..n - 2 {
            for j in 0..n - 2 {
                for ii in i..i + 3 {
                    for jj in j..j + 3 {
                        res[i][j] = res[i][j].max(grid[ii][jj]);
                    }
                }
            }
        }
        
        res
    }
}