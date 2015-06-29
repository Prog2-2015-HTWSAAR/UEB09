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

	/**
	* @brief Konstruktor
	*/
	FileReport();
	/**
	* @brief Konstruktor
	* @param fileName Dateiname
	*/
	FileReport(string& fileName);
	/**
	* @brief Dekonstruktor
	*/
	virtual ~FileReport();
	/**
	* @brief parseFile
	* @param fileName Filename
	*/
	void parseFile(string& fileName);
	/**
	* @brief toCSVFile
	* @param fileName Filename
	*/
	void toCSVFile(string& fileName);
	/**
	* @brief toString
	*/
	string toString();
	/**
	* @brief fileExists
	* @param fileName Filename
	*/
	bool fileExists(string fileName);
	/**
	* @brief round
	* @param Zahl Zahl zum Runden
	* @param Stellen Stelle zum runden
	*/
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
	* @brief analyseLine
	* @param line Zeile für analyse
	*/
	void analyseLine(string& line);
	/**
	* @brief checkComment
	* @param line Zeile für analyse
	*/
	bool checkComment(string& line);
	/**
	* @brief computeCommentDensity Berechet Kommentardichte
	*/
	void computeCommentDensity();
	/**
	* @brief checkUpperCase
	* @param character character
	*/
	bool checkUpperCase(char character);
	/**
	* @brief checkLowerCase
	* @param character character
	*/
	bool checkLowerCase(char character);
	/**
	* @brief checkDigit
	* @param character character
	*/
	bool checkDigit(char character);
	/**
	* @brief checkSpecialCharacter
	* @param character character
	*/
	bool checkSpecialCharacter(char character);

};

#endif /* UEB09_FILEREPORT_H_ */
