/*
 * FileReport.h
 *
 *  Created on: 23.06.2015
 *      Author: sbastian
 */

#ifndef UEB09_FILEREPORT_H_
#define UEB09_FILEREPORT_H_
#include <fstream>
#include <sstream>
using namespace std;
class FileReport {
public:
	FileReport();
	FileReport(string fileName);
	virtual ~FileReport();
	void parseFile(string fileName);
	string toString();
private:
	string name;
	unsigned int lines;
	unsigned int commentLines;
	double commentDensity;
	unsigned int upperCaseLetters;
	unsigned int lowerCaseLetters;
	unsigned int digits;
	unsigned int specialCharacters;

	void initReport();
	void analyseLine(string line);
	bool checkComment(string line);
	void computeCommentDensity();
	bool checkUpperCase(char character);
	bool checkLowerCase(char character);
	bool checkDigit(char character);
	bool checkSpecialCharacter(char character);
};

#endif /* UEB09_FILEREPORT_H_ */
