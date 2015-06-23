/*
 * FileReport.h
 *
 *  Created on: 23.06.2015
 *      Author: sbastian
 */

#ifndef UEB09_FILEREPORT_H_
#define UEB09_FILEREPORT_H_

using namespace std;
class FileReport {
public:
	FileReport();
	virtual ~FileReport();
	void parseFile(string fileName);
private:
	string name;
	unsigned int lines;
	double commentDensity;
	unsigned int upperCaseLetters;
	unsigned int lowerCaseLetters;
	unsigned int digits;
	unsigned int specialCharacters;

	void analyseLine(string line);
};

#endif /* UEB09_FILEREPORT_H_ */
