#ifndef STARCUBE_H
#define STARCUBE_H

#include <map>
#include <vector>
#include <string>
#include <cstring>
#include "startree.h"

class StarCube
{
    public:

    int condition;

	std::map<std::string , int> cuboid_key;

	std::vector<std::vector<std::string> > csv_data;

    std::vector<TreeNode* >  add_leaf(TreeNode *root);

	StarCube(std::vector<std::vector<std::string> > csv_data, int condition);

    TreeNode* insert(TreeNode * root, std::string val,int count);
	bool all_stars_childs(TreeNode* root);
	void star_cubing(TreeNode *root, TreeNode* leaf, int floor );
	void star_bucks(StarTree startree, TreeNode *root, TreeNode* cnode, int floor, std::string cuboid[], std::vector<TreeNode*> subtree);
	bool isleaf(TreeNode* root);
	void print_cuboid();
	void print_keys();
    void print_cuboid(int seed);


};

#endif // STARCUBE_H

