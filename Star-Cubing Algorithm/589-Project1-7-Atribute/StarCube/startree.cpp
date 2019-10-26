#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include "logger.h"
#include "startable.h"
#include "startree.h"

using namespace std;

int index_array[] = {0,1,2,3,4,5,6};


TreeNode* StarTree:: insert(int index_row , vector<string> row , TreeNode* root)
{

	if(index_row  < row.size() - 1)
    {
		if(root)
        {

			if(root->val.compare(row[index_array[index_row]]) != 0)
            {
				root->sibling = insert(index_row, row, root->sibling);
			}
			else
            {
				root->count = root->count + stoi(row[7]) ;
				insert(index_row+1 ,  row, root->child);
			}

			return root;
		}
		else
        {
			TreeNode* node = new TreeNode();
			node->val = row[index_array[index_row]];
			node->count = stoi(row[7]);
			node->child = insert(index_row+1, row, node->child);
			return node;
		}
	}
	else
    {
		return NULL;
	}
}

TreeNode* StarTree::get_tree(vector<vector<string> > &table, TreeNode* root, int index_row)
{
	for(int i = 0 ; i <  table.size() ;i++)
    {
		root->count = root->count + stoi(table[i][7]);
		root->child = insert(index_row , table[i] ,  root->child);
	}

	this->root = root;

	if(DEBUG)
    {
		TreeNode *temp = root->child;
		TreeNode *temp1 ;
		TreeNode *temp2 ;
		TreeNode *temp3 ;
        TreeNode *temp4 ;
		TreeNode *temp5 ;
		TreeNode *temp6 ;

		temp = root->child;

		while(temp)
        {
			cout <<  temp->val << ":"<< temp->count << ",  "  <<  endl;
			temp1 = temp->child;
			while(temp1)
			{
					cout <<  "  "<<  temp1->val << ":"<< temp1->count << ",  " << endl ;
					temp2 = temp1->child;
					while(temp2)
					{
						cout <<  "    "<<  temp2->val << ":"<< temp2->count << ",  " ;
						temp3 = temp2->child;
						while(temp3)
						{
							cout <<  "  "<<  temp3->val << ":"<< temp3->count << ",  " << endl ;
							temp4 = temp3->child;
							while(temp4)
                            {
                                cout <<  "  "<<  temp4->val << ":"<< temp4->count << ",  " << endl ;
                                temp5 = temp4->child;
                                while(temp5)
                                {
                                    if(temp6->child == NULL)
                                    {
                                        cout <<  "     null"<<  endl ;
                                    }
                                    else
                                    {
                                        cout <<  "     notnull"<<  endl ;
                                    }
                                    temp6 = temp6->sibling;

                                    cout <<endl;
                                }
                                temp4 = temp4->sibling;
                            }
                            temp3 = temp3->sibling;
						}

						temp2 = temp2->sibling;
						cout <<endl;
					}
					temp1 = temp1->sibling;
					cout <<endl;
				}

			temp = temp->sibling;
			cout <<endl;
	  }

	}

	return root;

}

