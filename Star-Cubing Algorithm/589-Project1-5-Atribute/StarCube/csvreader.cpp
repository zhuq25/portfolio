#include "csvreader.h"
#include "logger.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <iomanip>

using namespace std;

extern string CIC0_val, SM1_val, GATS1i_val, NdsCH_val, NdssC_val, MLOGP_val, LC50_val;
extern int CIC0_index, SM1_index, GATS1i_index, NdsCH_index, NdssC_index, MLOGP_index, LC50_index;

vector<vector<string> > CsvReader :: read_csv(map<string, map<string, int> >& freq_table)
{

	INFOLOG("Start reading csv file for input.\n");
	vector<vector<string> > csv_data;
	vector<string> tuple;
	string CIC0, SM1, GATS1i, NdsCH, NdssC, MLOGP,LC50;
	string csv_file_name = "C:/Users/zheng_000/Desktop/589-Project1-5-Atribute/StarCube/input/sample.csv";


    ifstream csv_file(csv_file_name);

    if(!csv_file.is_open())
    {
		ERRORLOG("Problem in file open()\n");
		return csv_data;
	}

    getline ( csv_file, CIC0_val, ',' );
    freq_table[CIC0_val] = map<string, int>();
    CIC0_index = 0;

    getline ( csv_file, SM1_val, ',' );
    freq_table[SM1_val] = map<string, int>();
    SM1_index = 1;

    getline ( csv_file, GATS1i_val, ',' );
    freq_table[GATS1i_val] = map<string, int>();
    GATS1i_index = 2;

    getline ( csv_file, NdsCH_val, '\n' );
    freq_table[NdsCH_val] = map<string, int>();
    NdsCH_index = 3;

		string  info_log = "CIC0 : " +  CIC0_val +  ", SM1 : " + SM1_val + ", GATS1i : "+ GATS1i_val + ", NdsCH : " +NdsCH_val;

         const char *log_string = info_log.c_str();
         INFOLOG("%s\n",log_string);


    while ( csv_file.good() )
	{

        getline ( csv_file, CIC0, ',' );
	     tuple.push_back(CIC0);

        getline ( csv_file, SM1, ',' );
	     tuple.push_back(SM1);

	     getline ( csv_file, GATS1i, ',' );
	     tuple.push_back(GATS1i);

	     getline ( csv_file, NdsCH, '\n' );
	     tuple.push_back(NdsCH);

         csv_data.push_back(tuple);
	     tuple.clear();

         string  info_log = "CIC0 : " +  CIC0 +  ", SM1 : " + SM1 + ", GATS1i : "+ GATS1i + ", NdsCH : " +NdsCH;

         const char *log_string = info_log.c_str();
         INFOLOG("%s\n",log_string);

	     freq_table[CIC0_val][CIC0]++;
	     freq_table[SM1_val][SM1]++;
	     freq_table[GATS1i_val][GATS1i]++;
	     freq_table[NdsCH_val][NdsCH]++;

        }

	return csv_data;
}


void CsvReader :: printdata(vector<vector<string> > &csvdata)
{

    cout << "---------------------------------------------"<<endl;

    int size = (int) csvdata.size();
    for(int i = 0; i < size ; i++ )
    {
        cout << "|" << setw(6)<< csvdata[i][0]  <<" | "<< setw(6)<< csvdata[i][SM1_index] << " | "<< setw(6) <<csvdata[i][GATS1i_index] <<" | "<< setw(6)<<csvdata[i][NdsCH_index] <<" | "<< setw(6)<<csvdata[i][NdsCH_index+1]<< " |"<<endl;
		cout << "|-------|--------|--------|--------|--------|"<<endl;

    }
}



