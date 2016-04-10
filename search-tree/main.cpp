#include <iostream>

template <class T>
class Tree
{
    // Internal class which stores only Node related information.
    struct TreeNode
    {
        T name_data;
        T num_data;
        TreeNode * left;
        TreeNode * right;
        
        TreeNode(T val, T num):name_data(val), num_data(num), left(NULL),right(NULL)
        {
        }
    };
    TreeNode * root;
    void print(TreeNode*);
    void freeMemory(TreeNode*);
    
    
public:
    Tree();
    ~Tree();
    void insert(T, T);
    void print();
};

template <class T>
Tree<T>::Tree():root(NULL){}

template <class T>
Tree<T>::~Tree()
{
    freeMemory(root);
}

template <class T>
void Tree<T>::freeMemory(Tree::TreeNode *node)
{
    if (node==NULL)
        return;
    if (node->left)
        freeMemory(node->left);
    if (root->right)
        freeMemory(node->right);
    delete node;
}

template <class T>
//make it return value?
void Tree<T>::insert(T val, T num)
{
    TreeNode * treeNode = NULL;
    try
    {
        treeNode = new TreeNode(val, num); // handle exception necessary?
    } catch (std::bad_alloc &exception)
    {
        std::cerr << "bad_alloc caught: " << exception.what() << std::endl;
        EXIT_FAILURE;
    }
    TreeNode *temp=NULL;
    TreeNode *prev=NULL;
    
    temp = root;
    while(temp)
    {
        prev = temp;
        if (temp->name_data < treeNode->name_data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    if (prev==NULL)
        root = treeNode;
    else
    {
        if (prev->name_data<treeNode->name_data)
            prev->right = treeNode;  // use setter function?
        else
            prev->left = treeNode;
    }
}

template <class T>
void Tree<T>::print(TreeNode *root)
{
    if (root==NULL)
        return ;
    print(root->left);
    std::cout << root->name_data << std::endl; // sorted name data
    std::cout << root->num_data << std::endl; // unsorted num data

    print(root->right);
}

template <class T>
void Tree<T>::print()
{
    print(root);
}


int main()
{
    Tree<int> tree;
    tree.insert(14, 28);
    tree.insert(12, 26);
    tree.insert(6, 7);
    tree.insert(17, 16);
    tree.insert(8, 16);
    tree.print();
    
}