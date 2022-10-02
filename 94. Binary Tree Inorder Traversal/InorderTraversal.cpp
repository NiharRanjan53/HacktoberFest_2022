/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public List<Integer> inOrderList = new ArrayList<>();
    
    public void inOrderTraversalUtil(TreeNode root) {
        
        if(root == null) {
            return;
        }
            
        inOrderTraversalUtil(root.left);
        
        inOrderList.add(root.val);
        
        inOrderTraversalUtil(root.right);
            
    }
    
    public List<Integer> inorderTraversal(TreeNode root) {
        
        inOrderTraversalUtil(root);
        
        return inOrderList;
        
    }
}