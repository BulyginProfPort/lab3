#pragma once
#ifndef Tree_hpp
#define Tree_hpp
#include <iostream>

using namespace std;

template <class T>
class Tree{
private:
    class List{
    private:
        T value;
        List* right;
        List* left;
        // DIFFRENT WAYS OF BYPASS FOR PRINT
        //(LRoR)    (RLRo)  (RRoL)  (LRRo)  (RoRL)  (RoLR)
        void LeftRootRight()const{
            if (left){
                left->LeftRootRight();
            }
            cout<<value<<endl;
            if (right){
                right->LeftRootRight();
            }
        }
        void RightLeftRoot()const{
            if (right){
                right->RightLeftRoot();
            }
            if (left){
                left->RightLeftRoot();
            }
            cout<<value<<endl;
        }
        void RightRootLeft()const{
            if (right){
                right->RightRootLeft();
            }
            cout<<value<<endl;
            if (left){
                left->RightRootLeft();
            }
        }
        void LeftRightRoot()const{
            if (left){
                left->LeftRightRoot();
            }
            if (right){
                right->LeftRightRoot();
            }
            cout<<value<<endl;
        }
        void RootRightLeft()const{
            cout<<value<<endl;
            if (right){
                right->RootRightLeft();
            }
            if (left){
                left->RootRightLeft();
            }
        }
        void RootLeftRight()const{
            cout<<value<<endl;
            if (left){
                left->RootLeftRight();
            }
            if (right){
                right->RootLeftRight();
            }
        }
        
        //DIFFRENT WAYS FOR GETTING STRING OF TREE
        //(RoLR)    (RoRL)   (LRoR)   (LRRo)    (RLRo)   (RRoL)   
        void RootLeftRight(List *list, T **resultString, int *i){
            if (list){
                (*resultString)[(*i)++] = list->value;
                if (list->left){
                    list->left->RootLeftRight(list->left, &(*resultString), &(*i) );
                }
                if (list->right){
                    list->right->RootLeftRight(list->right, &(*resultString), &(*i) );
                }
            }
        }
        void RootRightLeft(List *list, T **resultString, int *i){
            if (list){
                (*resultString)[(*i)++] = list->value;
                if (list->right){
                    list->right->RootRightLeft(list->right, &(*resultString), &(*i) );
                }
                if (list->left){
                    list->left->RootRightLeft(list->left, &(*resultString), &(*i) );
                }
            }
        }
        void LeftRightRoot(List *list, T **resultString, int *i){
            if (list){
                if (list->left){
                    list->left->LeftRightRoot(list->left, &(*resultString), &(*i) );
                }
                if (list->right){
                    list->right->LeftRightRoot(list->right, &(*resultString), &(*i) );
                }
                (*resultString)[(*i)++] = list->value;
            }
        }
        void LeftRootRight(List *list, T **resultString, int *i){
            if (list){
                if (list->left){
                    list->left->LeftRootRight(list->left, &(*resultString), &(*i) );
                }
                (*resultString)[(*i)++] = list->value;
                if (list->right){
                    list->right->LeftRootRight(list->right, &(*resultString), &(*i) );
                }
            }
        }
        void RightLeftRoot(List *list, T **resultString, int *i){
            if (list){
                if (list->right){
                    list->right->RightLeftRoot(list->right, &(*resultString), &(*i) );
                }
                if (list->left){
                    list->left->RightLeftRoot(list->left, &(*resultString), &(*i) );
                }
                (*resultString)[(*i)++] = list->value;
                
            }
        }
        void RightRootLeft(List *list, T **resultString, int *i){
            if (list){
                if (list->right){
                    list->right->RightRootLeft(list->right, &(*resultString), &(*i) );
                }
                (*resultString)[(*i)++] = list->value;
                if (list->left){
                    list->left->RightRootLeft(list->left, &(*resultString), &(*i) );
                }
            }
        }

    public:
        List(){
            right = left = nullptr;
        }
        T getValue(){
            return value;
        }
        void SetValue(T x){
            value = x;
        }
        //SEARCHERS IN TREE
        bool searchElement(T data, List **list){
            if (*list){
                if (data > (*list)->value){
                    return searchElement(data, &(*list)->right);
                    
                }
                else if (data < (*list)->value){
                    return searchElement(data, &(*list)->left);
                }
                else if (data == (*list)->value){
                    return true;
                }
            }
            return false;
        }
        bool searchSubList(List *list1, List *list2){
            
        }
        
        //ADD ELEMENT IN TREE
        void add(T value, List** tmp){
            if (*tmp){
                if (value > (*tmp)->value){
                    if ( (*tmp)->right){
                        add(value, &(*tmp)->right);
                    }
                    else{
                        (*tmp)->right = new struct List;
                        (*tmp)->right->value = value;
                        (*tmp)->right->left = (*tmp)->right->right = nullptr;
                    }
                }
                else if (value < (*tmp)->value){
                    if ( (*tmp)->left){
                        add(value,&(*tmp)->left);
                    }
                    else{
                        (*tmp)->left = new struct List;
                        (*tmp)->left->value = value;
                        (*tmp)->left->left = (*tmp)->left->right = nullptr;
                    }
                }
                else if (value == (*tmp)->value){
                    return;
                }
            }
            else{
                *tmp = new List;
                (*tmp)->value = value;
                (*tmp)->left = (*tmp)->right = nullptr;
            }
        }
        
        //FOR GETTING STRING
        void string(string byPass,List* list,T** resultString,int *i){
            if (byPass == "LeftRootRight"){
                LeftRootRight(list, &(*resultString), &(*i) );
            }
            if (byPass == "RightLeftRoot"){
                RightLeftRoot(list, &(*resultString), &(*i) );
            }
            if (byPass == "RightRootLeft"){
                RightRootLeft(list, &(*resultString), &(*i) );
            }
            if (byPass == "LeftRightRoot"){
                LeftRightRoot(list, &(*resultString), &(*i) );
            }
            if (byPass == "RootRightLeft"){
                RootRightLeft(list, &(*resultString), &(*i) );
            }
            if (byPass == "RootLeftRight"){
                RootLeftRight(list, &(*resultString), &(*i) );
            }
        }
        
        //MAP WHERE MERGE
        void map(function<T(T)> f, List *list, Tree &b){
            if(list){
                b.add(f(list->value));
                map(f, list->right, b);
                map(f,list->left,b);
            }
        }
        void where(function<bool(T)> f,List *list, Tree &b){
            if(list){
                if ( f(list->value) ){
                    b.add(list->value);
                }
                where(f,list->left, b);
                where(f, list->right, b);
            }
        }
        void merge(List **list1, List **list2){
            if  (*list1){
                (*list2)->add( (*list1)->getValue(), &(*list2) );
                merge( &(*list1)->left, &(*list2) );
                merge( &(*list1)->right, &(*list2));
            }
        }
        
        //COMPARING TWO TREES (FOR TESTS)
        bool equalityTree(List **list1, List **list2){
            if ( (*list1) == (*list2) ){
                return true;
            }
            return ( ( (*list1)->value == (*list2)->value ) && equalityTree( &(*list1)->left, &(*list2)->left) && equalityTree( &(*list1)->right, &(*list2)->right) );
        }
        
        void print(std::string &byPass) const {
            if (byPass == "LeftRootRight"){
                LeftRightRoot();
            }
            if (byPass == "RightLeftRoot"){
                RightLeftRoot();
            }
            if (byPass == "RightRootLeft"){
                RightRootLeft();
            }
            if (byPass == "LeftRightRoot"){
                LeftRightRoot();
            }
            if (byPass == "RootRightLeft"){
                RootRightLeft();
            }
            if (byPass == "RootLeftRight"){
                RootLeftRight();
            }
        }
        

        //GETTING TREE BY VALUE
        List* getTreeByElement(List **list1, T value){
            if ( (*list1) ){
                if ( (*list1)->value == value){
                    return (*list1);
                }
                else if ( value < (*list1)->value ){
                    return getTreeByElement( &(*list1)->left, value);
                }
                else if (value > (*list1)->value) {
                    return getTreeByElement( &(*list1)->right, value);
                }
            }
                return nullptr;
        }
        
        void extraction(List **list1, List **list2,T value){
            if (getTreeByElement( &(*list1), value) != nullptr){
                (*list2) = getTreeByElement( &(*list1), value);

            }
        }
        void freeTree(List** list){
            if (*list){
                freeTree( &(*list)->right);
                freeTree( &(*list)->left);
                delete (*list);
            }
        }
        ~List(){}
    };
    
    List* root;
    int size;
    
public:
    //CONSTRUCTORS
    Tree(){
        root = nullptr;
        size = 0;
    }
    
    //GETS
    T getvalue(){
        return root->getValue();
    }
    int getSize(){
        return size;
    }
    void getString(std::string &byPass, T **resultString){
        if (root){
            int i = 0;
            root->string(byPass, root, &(*resultString), &i);
        }

    }
    
    //SETS
    void setRoot(T data){
        root->setValue(data);
    }
    void setSize(int newSize){
        size = newSize;
    }
    void add(T value){
        root->add(value, &root);
        size++;
    }
    //MAP WHERE MERGE
    void map(function<T(T)> f, Tree &nB){
        if (root){
            root->map(f, root, nB);
        }
    }
    void where(function<bool(T)> f, Tree& nB){
        if (root){
            root->where(f, root, nB);
        }
    }
    void merge(Tree &b){
        if (root){
            root->merge(&root, &b.root);
        }
    }
    void extraction(T value, Tree &a){
        if (root){
            root->extraction(&root, &a.root, value);
        }
    }
    //SEARCHERS
    bool searchElement(T data){
        if ( root->searchElement(data, &root) ){
            cout<<"True"<<endl;
            return true;
        }
        else{
            cout<<"False"<<endl;
            return false;
        }
    }
    void print(std::string &byPass)const {
        if (root){
            root->print(byPass);
        }
    }
    
    //OPERATORS
    bool operator == ( class Tree<T> &b){
        if (root->equalityTree(&root, &b.root) ){
            return true;
        }
        else{
            return false;
        }
    }
    ~Tree(){
        if (root){
            root->freeTree(&root);
        }
    }
};


#endif /* LinkedList_hpp */
