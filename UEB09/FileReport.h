/**
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
	friend class Tools;
	static const string FILE_NAME;
	static const string LINES;
	static const string COMMENT_LINES;
	static const string COMMENT_DENSITY;
	static const string UPPER_CASE;
	static const string LOWER_CASE;
	static const string NUMERIC;
	static const string SPECIAL_CHARS;
	static const string SEMICOLON;
	static const string TILDE;
	static const string TABULATOR;
	static const string CSV_ENDING;

	static const int SLASH;
	static const char PERCENT;
	static const int UPPER_CASE_LOWER_BORDER;
	static const int UPPER_CASE_UPPER_BORDER;
	static const int LOWER_CASE_LOWER_BORDER;
	static const int LOWER_CASE_UPPER_BORDER;
	static const int DIGIT_LOWER_BORDER;
	static const int DIGIT_UPPER_BORDER;
	static const int SPECIAL_CHAR_LOWER_BORDER;
	static const int SPECIAL_CHAR_UPPER_BORDER;

	FileReport();
	FileReport(string& fileName);
	virtual ~FileReport();
	void parseFile(string& fileName);
	void toCSVFile(string& fileName);
	string toString();
	bool fileExists(string fileName);
	double round(double Zahl, int Stellen);
private:
	string name;
	unsigned int lines;
	unsigned int commentLines;
	double commentDensity;
	unsigned int upperCaseLetters;
	unsigned int lowerCaseLetters;
	unsigned int digits;
	unsigned int specialCharacters;

	/**
	* @brief initReport Init Report
	*/
	void initReport();
	/**
	* @brief Konstruktor
	* @param inhalt Der Inhalt des Listenelements
	*/
	void analyseLine(string& line);
	/**
	* @brief Konstruktor
	* @param inhalt Der Inhalt des Listenelements
	* @param previous Das Vorangegangene Element
	* @param next Das Nachfolgende Element
	*/
	bool checkComment(string& line);
	void computeCommentDensity();
	bool checkUpperCase(char character);
	bool checkLowerCase(char character);
	bool checkDigit(char character);
	bool checkSpecialCharacter(char character);

};

#endif /* UEB09_FILEREPORT_H_ */
