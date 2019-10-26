#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/log/trivial.hpp>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <chrono>
#include "csvreader.h"
#include "logger.h"
#include "startable.h"
#include "startree.h"
#include "starcube.h"
#include <sys/time.h>
#include <sys/resource.h>


using namespace std;

struct rusage  r_usage;

string CIC0_star_val = "*";
string SM1_star_val = "*";
string GATS1i_star_val = "*";
string NdsCH_star_val = "*";
string NdssC_star_val = "*";
string MLOGP_star_val = "*";
string LC50_star_val = "*";

//Setting up Data attributes
string CIC0_val, SM1_val, GATS1i_val, NdsCH_val, NdssC_val, MLOGP_val, LC50_val;

int CIC0_index, SM1_index, GATS1i_index, NdsCH_index, NdssC_index, MLOGP_index, LC50_index;

int main()
{
    int ice;
    printf("Please enter ice-berg condition: ");
    scanf("%d", &ice);
    double dur;
    clock_t start, end;
    start=clock();
    map<string, map<string, int> > freq_table;
    map<string, string> star_table;
    map<string, string> CIC0_star_table;
    map<string, string> SM1_value_star_table;
    vector<vector<string> > csv_data;

    CsvReader reader;

	StarTable startable(ice);
	StarTree startree;

	csv_data = reader.read_csv(freq_table);
	StarCube starcube(csv_data, ice);

    if(csv_data.size() == 0)
    {
		ERRORLOG("Invalid data input. Please input correct data\n");
		return 0;
	}

    startable.generate_attrs_stars(freq_table[CIC0_val], csv_data, CIC0_index, CIC0_star_val, startable.condition);
    startable.generate_attrs_stars(freq_table[SM1_val], csv_data, SM1_index, SM1_star_val, startable.condition);
    startable.generate_attrs_stars(freq_table[GATS1i_val], csv_data, GATS1i_index, GATS1i_star_val, startable.condition);
    startable.generate_attrs_stars(freq_table[NdsCH_val], csv_data, NdsCH_index, NdsCH_star_val, startable.condition);
    startable.generate_attrs_stars(freq_table[NdssC_val], csv_data, NdssC_index, NdssC_star_val, startable.condition);
    startable.generate_attrs_stars(freq_table[MLOGP_val], csv_data, MLOGP_index, MLOGP_star_val, startable.condition);
    startable.generate_attrs_stars(freq_table[LC50_val], csv_data, LC50_index, LC50_star_val, startable.condition);

    cout <<  "Table before compress : " <<  csv_data.size() <<  ",  Characteristics : " <<  csv_data[0].size() << endl;;

    csv_data = startable.compress_star_table(csv_data);

    end = clock();
    dur = (double)(end - start);
    printf("CPU Time Cost:%f\n",(dur/CLOCKS_PER_SEC));
    cout << "Table after compressed : " <<  csv_data.size() << endl;;
    cout << "Freq table size : " << (int)freq_table.size() <<  endl;


    getrusage(RUSAGE_SELF, &r_usage);
    cout << r_usage.ru_maxrss << endl;
	cout << r_usage.ru_ixrss << endl;

	//reader.printdata(csv_data);

    TreeNode* root  = new TreeNode();
    root->val = "*";
    startree.get_tree(csv_data, root, 0);


    printf("\n                                  \n");
	printf("|----------------------------------|\n");
	printf("|----------------------------------|\n");
	printf("|@@@@ Star Cubing Algorithm   @@@@|\n");
	printf("|----------------------------------|\n");
	printf("|----------------------------------|\n");

	cout << "Number of the Roots: " <<  root->count <<endl;

	string cuboid[] = {"*", "A" , "B", "C", "D", "E", "F", "G"};

	vector<TreeNode*> subtree;
    starcube.star_bucks(startree, root, startree.root, 0, cuboid, subtree);
    //starcube.print_cuboid();

    return 0;
}



