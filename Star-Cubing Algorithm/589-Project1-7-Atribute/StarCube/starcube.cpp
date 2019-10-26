#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include "csvreader.h"
#include "logger.h"
#include "startable.h"
#include "startree.h"
#include "starcube.h"

using namespace std;

int condition = 500;
int floor = 0;

string cuboid_val[] = {"*", "*" , "*", "*","*", "*", "*", "*"};

StarCube ::StarCube(vector<vector<string> > csv_data, int condition)
{
	this->csv_data = csv_data;
	this->condition = condition;
	cuboid_key.clear();
}

void StarCube :: print_keys()
{
	cout <<  "This is the function to print key value\n";
	for(auto it = cuboid_key.begin(); it != cuboid_key.end();it++)
    {
		cout <<it->first <<  " : " << it->second<< endl;
	}
}

void StarCube :: print_cuboid(int kids)
{
	string key = cuboid_val[0] + "," +  cuboid_val[1] + "," + cuboid_val[2] + "," + cuboid_val[3] + "," + cuboid_val[4] + "," + cuboid_val[5]+ "," + cuboid_val[6] + "," + cuboid_val[7];
	if(cuboid_key.find(key) == cuboid_key.end())
    {
		cuboid_key.insert(pair<string ,int>(key, kids));
	}
	else if(cuboid_key.find(key) != cuboid_key.end() && cuboid_key[key] < kids)
    {
		cuboid_key[key] = kids;
	}
}

bool StarCube :: all_stars_childs(TreeNode* root)
{
	if(root)
    {
		vector<TreeNode* >  leaf_chain = add_leaf(root);
		int size = leaf_chain.size();
		for(int m  = 0 ; m < size  ; m++)
		{
			if(leaf_chain[m]->val.compare("*")!= 0)
			{
				return false;
			}
			all_stars_childs(leaf_chain[m]);
		}

		return true;
	}
	return false;
}

TreeNode* StarCube :: insert(TreeNode * root, string val, int count)
{

	if(root)
    {

		if(root->val.compare(val) == 0)
        {
			cout << "Plus : " <<  root-> val << ", " <<  root->count << "+" <<  count <<  endl;
			root->count = root->count + count;
			return root;
		}
		else
        {
			if(root->val.substr(1) == val.substr(1)){
				TreeNode * tnote = root;
				while(tnote->sibling != NULL)
				{
					tnote = tnote->sibling;
				}
				tnote->sibling = new TreeNode();
				tnote->sibling->val = val;
				tnote->sibling->count = count;
				return root;
			}
			else
            {
				root->child = insert(root->child ,  val, count);
				return root;
			}
		}

	}
	else
    {
		root = new TreeNode();
		root->val = val;
		root->count = count;
		return root;
	}
}
void StarCube :: star_bucks(StarTree startree, TreeNode *root, TreeNode* leaf, int floor, string cuboid[], vector<TreeNode*> subtree)
{

	if(leaf)
    {
		TreeNode *new_root = NULL;
		StarTree new_startree;

		if(leaf->count >= this->condition)
        {
			if(leaf !=  startree.root)
			{
				cuboid_val[floor] = leaf->val;
				print_cuboid(leaf->count);
			}

			if(isleaf(leaf))
            {
				cuboid_val[floor] = leaf->val;
				print_cuboid(leaf->count);
			}
			else
            {
				new_root = new TreeNode();
				string base = " ";
				for(int i = 1 ; i <  8 ; i++)
				{
					if(i < floor + 1 )
					{
					    base = base + cuboid_val[i];
					}
					else if(i > floor + 1)
                    {
						base = base + cuboid[i];
					}

				}

				new_root->val = leaf->val;;
				new_root->count = leaf->count;
				startree.root = new_root;
				subtree.push_back(new_root);
			}
		}

		if(!isleaf(leaf))
        {
			cuboid_val[floor] = leaf->val;
			star_bucks(startree,  root, leaf->child, floor + 1, cuboid, subtree);
			cuboid_val[floor] = "*";
			star_bucks(startree,  root, leaf->child, floor + 1, cuboid, subtree);
		}

		if(new_root)
        {
			cuboid_val[floor] = "*";
			star_bucks(new_startree,  new_root, new_root, floor, cuboid, subtree);
			subtree.pop_back();
		}

		if(leaf->sibling)
        {
			cuboid_val[floor] = leaf->sibling->val;
			star_bucks(startree,  root, leaf->sibling, floor, cuboid,subtree);
		}

		cuboid_val[floor] = "*";

	}

}


void StarCube :: star_cubing(TreeNode *root, TreeNode* leaf, int floor)
{
	if(leaf)
    {
        vector<TreeNode* >  leaf_chain = add_leaf(leaf);
        int size = leaf_chain.size();
        for(int i  = 0 ; i < size  ; i++)
        {
            if(leaf_chain[i]->count >= condition)
            {
                if(!isleaf(leaf_chain[i]))
                {
                    if( leaf_chain[i]->val.compare("*") != 0)
                    {
                        cuboid_val[floor] = leaf_chain[i]->val;
                        star_cubing(root, leaf_chain[i] ,  floor + 1);
                        cuboid_val[floor] = "*";
                        star_cubing(root, leaf_chain[i] ,  floor + 1);
                    }
                    else
                    {
                        cuboid_val[floor] = "*";
                        star_cubing(root, leaf_chain[i] ,  floor + 1);
                    }
                }
                else
                {
                    cuboid_val[floor] = leaf_chain[i]->val;
                    print_cuboid(leaf->count);
                }
            }

        }

		print_cuboid(leaf->count);

	}

}


void  StarCube ::  print_cuboid()
{
	for(auto it = cuboid_key.begin();it != cuboid_key.end() ; it++)
    {
		char * m = strdup(it->first.c_str());
    	char * n = strtok(m, ",");
		n = strtok(NULL, ",");
    	while(n != NULL)
    	{
			cout << " " <<setw(2) <<  n;
        	n = strtok(NULL, ",");
    	}

		cout <<   " : " <<  it->second << endl;
		free(n);
		free(m);
	}
}

vector<TreeNode* > StarCube :: add_leaf(TreeNode *root)
{
	vector<TreeNode* > leaf_chain;
	if(root)
    {
		TreeNode * child;
		child = root->child;
		while(child)
		{
			leaf_chain.push_back(child);
			child = child->sibling;
		}

	}
	return leaf_chain;
}


bool StarCube :: isleaf(TreeNode* root)
{
	return root->child == NULL;
}

