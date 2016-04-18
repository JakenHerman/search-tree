public class BinaryTree{
    private BinaryTreeNode root;
    
    public BinaryTree() { root = null; }
    
    public synchronized void insertNode( String nam){
        if (root == null)
            root = new BinaryTreeNode(nam);
        else
            root.insertBinaryTreeNode(nam);
    }
    
    public void preorderTraversal() { preorder(root); }
    private void preorder(BinaryTreeNode nodePt){
        if (nodePt == null) return;
        System.out.println(nodePt.getName());
        preorder(nodePt.left);
        preorder(nodePt.right);
    }
    
    public void inorderTraversal() { inorder(root); }
    private void inorder( BinaryTreeNode nodePt){
        if (nodePt == null) return;
        inorder( nodePt.left);
        System.out.println(nodePt.getName());
        inorder(nodePt.right);
        
    }
    
    public void postorderTraversal() {
        postorder(root);
    }
    
    private void postorder(BinaryTreeNode nodePt){
        if (nodePt == null) return;
        postorder( nodePt.left);
        postorder(nodePt.right);
        System.out.println(nodePt.getName());
    }
    
}
