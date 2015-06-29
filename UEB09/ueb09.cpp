#include <iostream>
#include "FileReport.h"
using namespace std;

const string ERROR_WRONG_PARAM = "Fehlerhafte uebergabe Parameter\n";
const int VALID_PARAM = 2;
const int FIRST_PARAM = 1;
/**
* @brief runFileReport
* @param argc Anz der ueb Elem
* @param argv Ueb Elem
*/
void runFileReport(int argc, char *argv[]){
	int durchlaufeneDateien = FIRST_PARAM;
	FileReport fileReport = FileReport();
	do{
		if (argc > durchlaufeneDateien){
			
				string fileName = argv[durchlaufeneDateien];
				fileReport.parseFile(fileName);
				cout << fileReport.toString();
			}
		else {
			cout << ERROR_WRONG_PARAM;
		}
		durchlaufeneDateien++;

	} while (argc < durchlaufeneDateien && argc != 1);
}
/**
* @brief Main Function
*/
int main(int argc, char *argv[]){
	runFileReport(argc, argv);
}


