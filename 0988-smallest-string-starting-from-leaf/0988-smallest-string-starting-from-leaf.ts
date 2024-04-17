/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function smallestFromLeaf(root: TreeNode | null): string {
    const preorder = (root: TreeNode| null, strArr: string[]|null, prev: string="") :void =>{
        if(root === null)
            return;
            
        const str: string = prev + String.fromCharCode(root.val + 97);
        if(root.left === null && root.right === null){
            let t = str.split("").reverse().join("");
            strArr.push(t);
        }
        preorder(root.left, strArr, str);
        preorder(root.right, strArr, str);
    }  

    const leafArr: string[] = [];
    preorder(root, leafArr, "");
    const ans: string = leafArr.reduce((next, prev) => next < prev ? next : prev);
    return ans;
};