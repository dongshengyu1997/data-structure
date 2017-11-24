#include <iostream>
template <typename T>
class BSTnode
{
public:
    T key;
    BSTnode *left;
    BSTnode *right;
    BSTnode *parent;
    BSTnode(T key ,BSTnode *lchild = NULL,BSTnode *rchild = NULL,BSTnode *parent = NULL):
    key(key),left(lchild),right(rchild),parent(parent){};

};
template <typename T>
class BSTree
{
    BSTnode<T> *root;
public:
    BSTree();
    ~BSTree()= default;
    void insert(T key);
    BSTnode<T>* serach(T key);
    void preOrder()  ;
    void inOrder() ;
    void postOrder() ;
    BSTnode<T>* predecessor(BSTnode<T>* z);
    BSTnode<T>* sucessor(BSTnode<T> *z);
    T maxnum();
    T minnum();
    void remove(T key);
    void destory();
    void print();

private:
    void preOrder(BSTnode<T> *tree);
    void inOrder(BSTnode<T> *tree);
    void postOrder(BSTnode<T> *tree);
    BSTnode<T>* search(BSTnode<T>* tree,T key);
    void insert(BSTnode<T> *tree,BSTnode<T> *z);
    void remove(BSTnode<T> *tree, T key);
    void destory(BSTnode<T> *key);
    void print(BSTnode<T> *key);
    T maxnum(BSTnode<T>* tree);
    T minnum(BSTnode<T>* tree);



};
template <typename T>
BSTree<T>::BSTree() {
    root = NULL;

}
template <typename T>
void BSTree<T>::preOrder(BSTnode<T> *tree) {
    if(tree != NULL)
    {
        std::cout<<tree->key<<" ";
        preOrder(tree->left);
        preOrder(tree->right);

    }

}
template <typename T>
void BSTree<T>::preOrder() {
    preOrder(root);
}
template <typename T>
void BSTree<T>::inOrder(BSTnode<T> *tree)
{
    if (tree != NULL)
    {
        inOrder(tree->left);
        std::cout<<tree->key<<" ";
        inOrder(tree->right);
    }
}
template <typename T>
void BSTree<T>::inOrder()
{
    inOrder(root);
}

template <typename T>
void BSTree<T>::postOrder(BSTnode<T> *tree) {
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout<<tree->key<<" ";
    }
}
template <typename T>
void BSTree<T>::postOrder() {
    postOrder(root);
}
template <typename T>
BSTnode<T>* BSTree<T>::search(BSTnode<T>* tree,T key)
{
    if(tree ==NULL || tree->key == key)
        return tree;
    if(key>tree->key)
        search(tree->right,key);
    else
        search(tree->left,key);
}
template <typename T>
BSTnode<T>* BSTree<T>::serach(T key)
{
    search(root,key);
}
template <typename T>
void BSTree<T>::insert(T key)
{
    BSTnode<T> *y = new BSTnode<T>(key);
    insert(root,y);

}
template <typename T>
void BSTree<T>::insert(BSTnode<T> *tree,BSTnode<T> *z)
{
    BSTnode<T>* parent = NULL;
    BSTnode<T>* temp = tree;

    //寻找插入点
    while(temp!=NULL)
    {
        parent= temp;
        if(z->key>temp->key)
            temp= temp->right;
        else
            temp=temp->left;
    }
    z->parent = parent;
    if(parent==NULL) //如果树本来就是空树，则直接把z节点插入根节点
        tree = z;
    else if(z->key>parent->key) //如果z的值大于其双亲，则z为其双亲的右孩
        parent->right = z;
    else
        parent->left = z;

}
template <typename T>
BSTnode<T>* BSTree<T>::predecessor(BSTnode<T>* z)
{
    if(z != NULL)
    {
        BSTnode<T>* y = z->left;
        while(y->right)
        {
            y = y->right;
        }
        return y;
    }
    return NULL;
}
template <typename T>
BSTnode<T>* BSTree<T>::sucessor(BSTnode<T> *z) {
    if(z != NULL)
    {
        BSTnode<T>* y = z->right;
        while(y->left)
        {
            y = y->left;
        }
        return y;
    }
    return NULL;
}
template <typename T>
T BSTree<T>::maxnum() {
    maxnum(root);
}
template <typename T>
T BSTree<T>::minnum() {
    minnum(root);
}
template <typename T>
T BSTree<T>::maxnum(BSTnode<T> *tree) {

        BSTnode<T> *y = tree;
        while (y->right)
        {
            y=y->right;
        }
        return y->key;


}
template <typename T>
T BSTree<T>::minnum(BSTnode<T> *tree) {
    BSTnode<T> *y = tree;
    while (y->left)
    {
        y=y->left;
    }
    return y->key;
}
template <typename T>
void BSTree<T>::remove(BSTnode<T> *tree, T key)
{

    BSTnode<T>* y=search(tree,key);
    if(!(y->right||y->left))
        delete y;
    else if(y->right&&!(y->left))
    {
        if(y->key > y->parent->key)
        {
            y->parent->right = y->right;
            y->right->parent = y->parent;
            delete y;
        }
        else if(y->key < y->parent->key)
        {
            y->parent->left = y->right;
            y->right->parent = y->parent;
            delete y;
        }

    }
    else if(!(y->right)&&y->left)
    {
        if(y->key > y->parent->key)
        {
            y->parent->right = y->left;
            y->left->parent = y->parent;
            delete y;
        }
        else if(y->key < y->parent->key)
        {
            y->parent->left = y->left;
            y->left->parent = y->parent;
            delete y;
        }
    }
    else
    {
        BSTnode<T>* x = sucessor(y);
        y->key = x->key;
        if(x->right)
        {
            x->parent->left = x->right;
            x->right->parent = x->parent;
            delete x;
        }
        else
            delete x;
    }

}
template <typename T>
void BSTree<T>::remove(T key) {
    remove(root,key);
}template<typename T>
void BSTree<T>::destory(BSTnode<T>*key)
{
    if(key->left!=NULL)
        destory(key->left);
    if(key->right!=NULL)
        destory(key->right);
    if(key->left==NULL&&key->right==NULL)
    {
        delete key;
        key = NULL;
    }
}
template <typename T>
void BSTree<T>::destory() {
    destory(root);
}
template <typename T>
void BSTree<T>::print(BSTnode<T> *key)
{
    if(key !=NULL)
    {
        if(key->left)
        std::cout<<"节点"<<key->key<<"有左节点"<<key->left->key<<" ";
        else
            std::cout<<"节点"<<key->key<<"没有左孩子"<<" ";
        if(key->right)
        {
            std::cout<<"节点"<<key->key<<"有右节点"<<key->right->key<<" ";
        }
        else
        {
            std::cout<<"节点"<<key->key<<"没有右孩子"<<" ";
        }
        print(key->left);
        print(key->right);
    }

}
template <typename T>
void BSTree<T>::print() {
    print(root);
}
int main(){

    BSTree<int>s;
    int a;
    std::cout<<"请输入二叉树结点以构造二叉查找树："<<std::endl;
    while(std::cin>>a )
        s.insert(a);
    std::cin.clear();
    std::cout<<"前序"<<std::endl;
    s.preOrder();
    std::cout<<std::endl;
    std::cout<<"中序"<<std::endl;
    s.inOrder();
    std::cout<<std::endl;
    std::cout<<"后序"<<std::endl;
    s.postOrder();
    std::cout<<std::endl;
    std::cout<<"打印二叉查找树"<<std::endl;
    s.print();
    std::cout<<"请输入删除的节点"<<std::endl;
    while(std::cin>>a)
    {
        s.remove(a);
        std::cout<<"删除都得二叉树"<<std::endl;
    }
    return 0;

}