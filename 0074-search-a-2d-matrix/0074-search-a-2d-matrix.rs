impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        // let (m, n) = (matrix.len(), matrix[0].len());
        let m = matrix.len();
        let n = matrix[0].len();
        
        if target < matrix[0][0] || matrix[m - 1][n - 1] < target {
            // target overmatched matrix
            return false;
        }
    
        let (mut h, mut k) = (0, m - 1);
        while h <= k {
            let mid = h + (k - h)/2;
            if target == matrix[mid][0] || target == matrix[mid][n - 1] {
                return true;
            } else if target < matrix[mid][0] {
                k = mid - 1;
            } else if target > matrix[mid][n - 1] {
                h = mid + 1;
            } else {
                //row found, exit 1st binary search
                h = mid;
                break;
            }
        }    
        
        /*
        // Check if the row has only one element
        if n == 1 {
          return matrix[h][0] == target;
        }
        */
        
        // h is now live and contain the row of target
        let (mut l, mut r) = (0, n - 1);
        
        while l < r {
            let mid = (l + (r - l)/2).wrapping_add(/* usize */ 1);
            let val = matrix[h][mid];
            if target > val {
                l = mid + 1;
            } else if target < val {
                r = mid - 1;
            } else {
                return true;
            }
        }
        
        false
    }
}