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
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::evaluate_tree_impl(&root)
    }

    fn evaluate_tree_impl(root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        let node = root.as_ref().unwrap().borrow();
        match node.val {
            3 => Self::evaluate_tree_impl(&node.left) && Self::evaluate_tree_impl(&node.right),
            2 => Self::evaluate_tree_impl(&node.left) || Self::evaluate_tree_impl(&node.right),
            1 => true,
            _ => false,
        }
    }
}