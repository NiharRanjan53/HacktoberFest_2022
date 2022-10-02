#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct tree_node{
  int data;
  tree_node* left_child;
  tree_node* right_child;
};

tree_node* new_tree_node(int data){
  tree_node* node = new tree_node();
  node->data = data;
  node->left_child = NULL;
  node->right_child = NULL;
  return(node);
}
/*
struct tree_node
{
  int data;
  tree_node* left_child;
  tree_node* right_child;
};
Above is the definition of the structure for tree. */

void printInorder(tree_node* tree_node)
{
  if (tree_node == NULL)
    return;

  // do the In-Order traversal of left_child
  printInorder(tree_node->left_child);

  // then print the data of tree_node
  cout<<tree_node->data<<' ';

  // do the In-Order traversal of right_child
  printInorder(tree_node->right_child);
}

int main()
{
  // create the root tree_node
  struct tree_node *root = new_tree_node(0);

  root->left_child = new_tree_node(1);   // create the left_child child
  root->right_child = new_tree_node(2);   // create the right_child child
  cout<<"Root tree_node is "<<root->data<<endl;
  cout<<"left_child of Root tree_node is "<<root->left_child->data<<endl;
  cout<<"right_child of Root tree_node is "<<root->right_child->data<<endl;

  root->left_child->left_child = new_tree_node(11);   // create the left_child child of left_child
  root->left_child->right_child = new_tree_node(12);   // create the right_child child of left_child
  cout<<"\nleft_child of Root tree_node is "<<root->left_child->data<<endl;
  cout<<"left_child of left_child of Root tree_node is "<<root->left_child->left_child->data<<endl;
  cout<<"right_child of left_child of Root tree_node is "<<root->left_child->right_child->data;

  root->right_child->left_child = new_tree_node(21);   // create the left_child child of right_child
  root->right_child->right_child = new_tree_node(22);   // create the right_child child of right_child
  cout<<"\nright_child of Root tree_node is "<<root->right_child->data<<endl;
  cout<<"left_child of right_child of Root tree_node is "<<root->right_child->left_child->data<<endl;
  cout<<"right_child of right_child of Root tree_node is "<<root->right_child->right_child->data<<endl;

  cout<<"\nInorder traversal of binary tree is \n";
  printInorder(root);

  return 0;
}
