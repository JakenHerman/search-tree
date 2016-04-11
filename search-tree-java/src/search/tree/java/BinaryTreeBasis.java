package search.tree.java;

/**
 *
 * @author jaken herman
 */
public abstract class BinaryTreeBasis<T> {
    protected TreeNode<T> root;
    
    public BinaryTreeBasis() {
        root = null;
    } //end default constructor
    
    public BinaryTreeBasis(T rootItem) {
        root = new TreeNode<T>(rootItem, null, null);
    } //end constructor
    
    public boolean isEmpty() {
        return root == null;
    } //end isEmpty
    
    public void makeEmpty() {
        //remove all nodes from the tree
        root = null;
    } //end makeEmpty
    
    public T getRootItem() throws TreeException {
        //returns the item in the trees root.
        boolean empty = isEmpty();
        if (empty){
            throw new TreeException("Empty Tree");
        }
        else {
            return root.item;
        } //end if/else
    }// end getRootItem
    
    public abstract void setRootItem(T newItem);
     // Throws UnsupportedOperationException if operation is not supported
} //end BinaryTreeBasis
