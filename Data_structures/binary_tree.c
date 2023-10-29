#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct Tree {
  struct TreeNode *root;
};

void insert(struct Tree *tree, int data)
{
  struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if (tree->root == NULL)
  {
    tree->root = node;
  }
  else 
  {
    struct TreeNode *current = tree->root;
    while (current != NULL)
    {
      if (data < current->data)
      {
        if (current->left == NULL)
        {
          current->left = node;
          break;
        }
        else
        {
          current = current->left;
        }
      } 
      else
      {
        if (current->right == NULL)
        {
          current->right = node;
          break;
        } 
        else
        {
          current = current->right;
        }
      }
    }
  }
}

int main() 
{
  struct Tree tree;
  tree.root = NULL;
  insert(&tree, 10);
  insert(&tree, 5);
  insert(&tree, 15);
  insert(&tree, 3);
  insert(&tree, 7);
  insert(&tree, 12);
  insert(&tree, 17);
  return 0;
}
