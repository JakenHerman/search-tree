class BinaryTreeNode {
    BinaryTreeNode left, right;
    private String name;
    
    public BinaryTreeNode( String nam )
    { name = new String(nam); left = right = null; }
    
    public synchronized void insertBinaryTreeNode(String nam)
    {
        if (nam.compareTo(name) < 0) {
            if(left == null)
                left = new BinaryTreeNode(nam);
            else
                left.insertBinaryTreeNode(nam);
        }
        else if (nam.compareTo(name) >= 0) {
            if (right == null)
                right = new BinaryTreeNode(nam);
            else
                right.insertBinaryTreeNode(nam);
        }
    }
    
    public synchronized String getName() { return name; }
    
}
