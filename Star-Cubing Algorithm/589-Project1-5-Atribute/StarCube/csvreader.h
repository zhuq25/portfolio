#ifndef CSVREADER_H
#define CSVREADER_H

#include <map>
#include <vector>
#include <string>
#include <cstring>

class CsvReader
{
    public:
	std::vector<std::vector<std::string> > read_csv(std::map<std::string, std::map<std::string, int> >& freq_table);
	void printdata(std::vector<std::vector<std::string> > &csvdata);
};


#endif // CSVREADER_H
