#ifndef STARTREE_H
#define STARTREE_H

#include <map>
#include <vector>
#include <cstring>

typedef struct TreeNode
{
	   std::string val;
	   int count;
	   TreeNode *sibling;
	   TreeNode *child;

}TreeNode;

class StarTree
{
    public:
        TreeNode* root;

        TreeNode* get_tree(std::vector<std::vector<std::string> > &table, TreeNode* root , int row_idx );
        TreeNode* insert(int row_idx , std::vector<std::string> row , TreeNode* root);

};

#endif // STARTREE_H

