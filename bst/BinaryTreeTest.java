public class BinaryTreeTest{
    public static void main(String args[]){
        BinaryTree tree = new BinaryTree();
        String faculty;
        
        faculty = "Burris"; tree.insertNode(faculty);
        tree.insertNode("Adams"); tree.insertNode("Smith");
        tree.insertNode("Cooper"); tree.insertNode("McCoy");
        tree.insertNode("Adams"); tree.insertNode("McAfee");
        
        System.out.println("\nPreorder Traversal ...");
        tree.preorderTraversal();
        
        System.out.println("\nInorder Traversal ...");
        tree.inorderTraversal();
        
        
    }
}
