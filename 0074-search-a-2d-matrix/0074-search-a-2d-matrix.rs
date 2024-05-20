impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let what = matrix.binary_search_by(|num| num[0].cmp(&target));
        match what {
            Ok(_) => true,
            Err(0) => false,
            Err(index) => matrix[index -1].binary_search(&target).is_ok()
        }
    }
}