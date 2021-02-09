#include "RenameParsingStrategy.h"
using namespace std;

vector<string> RenameParsingStrategy::parse(string filename) {
	vector<string> rename;
	int space = filename.find(' ');
	if (space == string::npos) {
		//no space found
		return rename;
	}
	string existing_file = filename.substr(0, space);
	rename.push_back(filename); //both old and new file names index 0
	rename.push_back(existing_file); //old file name index 1
	return rename;
}
