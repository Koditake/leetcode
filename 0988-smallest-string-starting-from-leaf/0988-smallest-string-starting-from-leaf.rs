// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut smallest_string = "~".to_owned();
        let mut stack = vec![(root.unwrap(), vec![])];
        while !stack.is_empty() {
            let (node, mut letters) = stack.pop().unwrap(); // safety in case stack is non-empty
            let node_ref = node.borrow();
            letters.insert(0, node_ref.val as u8 + b'a');
            if node_ref.left.is_none() && node_ref.right.is_none() { // leaf node
                let string = String::from_utf8(letters).unwrap();
                smallest_string = smallest_string.min(string);
            } else {
                if let Some(left) = node_ref.left.clone() {
                    stack.push((left, letters.clone()));
                }
                if let Some(right) = node_ref.right.clone() {
                    stack.push((right, letters));
                }
            }
        }
        smallest_string
    }
}