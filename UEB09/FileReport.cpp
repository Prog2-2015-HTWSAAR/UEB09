/**
 * FileReport.cpp
 *
 *  Created on: 23.06.2015
 *      Author: sbastian
 */

#include "FileReport.h"
#include <math.h>

const string FileReport::FILE_NAME = "Dateiname: ";
const string FileReport::LINES = "Zeilen";
const string FileReport::COMMENT_LINES = "Kommentarzeilen";
const string FileReport::COMMENT_DENSITY = "Kommentardichte";
const string FileReport::UPPER_CASE = "Grossbuchstaben";
const string FileReport::LOWER_CASE = "Kleinbuchstaben";
const string FileReport::NUMERIC = "Ziffern";
const string FileReport::SPECIAL_CHARS = "Sonderzeichen";
const string FileReport::SEMICOLON = "; ";
const string FileReport::TILDE = "~";
const string FileReport::CSV_ENDING = ".csv";

const int FileReport::SLASH = 47;
const char FileReport::PERCENT = 37;
const int FileReport::UPPER_CASE_LOWER_BORDER = 65;
const int FileReport::UPPER_CASE_UPPER_BORDER = 90;
const int FileReport::LOWER_CASE_LOWER_BORDER = 97;
const int FileReport::LOWER_CASE_UPPER_BORDER = 122;
const int FileReport::DIGIT_LOWER_BORDER = 48;
const int FileReport::DIGIT_UPPER_BORDER = 57;
const int FileReport::SPECIAL_CHAR_LOWER_BORDER = 33;
const int FileReport::SPECIAL_CHAR_UPPER_BORDER = 126;


const string FileReport::TABULATOR = "\t";

/**
* @brief Konstruktor
*/
FileReport::FileReport() {
	initReport();
}
/**
* @brief Konstruktor
* @param fileName Dateiname
*/
FileReport::FileReport(string& fileName){
	initReport();
	parseFile(fileName);
}
/**
* @brief Dekonstruktor
*/
FileReport::~FileReport() {}
/**
* @brief initReport Init Report
*/
void FileReport::initReport(){
	name = "";
	lines = 0;
	commentLines = 0;
	commentDensity = 0.0;
	upperCaseLetters = 0;
	lowerCaseLetters = 0;
	digits = 0;
	specialCharacters = 0;
}
/**
* @brief parseFile
* @param fileName Filename
*/
void FileReport::parseFile(string& fileName){
	const char* constName = fileName.c_str();
	string line;
	fstream file;
	if(!fileExists(fileName)){
		throw "File does not exist!";
	}
	file.open(constName);
	name = fileName;
	while (getline(file, line)){
		analyseLine(line);
	}
	computeCommentDensity();
	toCSVFile(fileName);
}
/**
* @brief analyseLine
* @param line Zeile für analyse
*/
void FileReport::analyseLine(string& line){
	int length = line.length();
	checkComment(line);
	for (int i = 0; i < length; ++i) {
		if (checkUpperCase(line[i])){
			continue;
		}
		if (checkLowerCase(line[i])){
			continue;
		}
		if (checkDigit(line[i])){
			continue;
		}
		checkSpecialCharacter(line[i]);
	}
	computeCommentDensity();
	lines++;
}
/**
* @brief checkComment
* @param line Zeile für analyse
*/
bool FileReport::checkComment(string& line){
	if (line.length() >= 2){
		if (line[0] == SLASH && line[1] == SLASH){
			commentLines++;
			return true;
		}
	}
	return false;
}
/**
* @brief checkUpperCase
* @param character character
*/
bool FileReport::checkUpperCase(char character){
	if (character >= UPPER_CASE_LOWER_BORDER && character <= UPPER_CASE_UPPER_BORDER){
		upperCaseLetters++;
		return true;
	}
	return false;
}
/**
* @brief checkLowerCase
* @param character character
*/
bool FileReport::checkLowerCase(char character){
	if (character >= LOWER_CASE_LOWER_BORDER && character <= LOWER_CASE_UPPER_BORDER){
		lowerCaseLetters++;
		return true;
	}
	return false;
}
/**
* @brief checkDigit
* @param character character
*/
bool FileReport::checkDigit(char character){
	if (character >= DIGIT_LOWER_BORDER && character <= DIGIT_UPPER_BORDER){
		digits++;
		return true;
	}
	return false;
}
/**
* @brief checkSpecialCharacter
* @param character character
*/
bool FileReport::checkSpecialCharacter(char character){
	if (character >= SPECIAL_CHAR_LOWER_BORDER && character <= SPECIAL_CHAR_UPPER_BORDER){
		specialCharacters++;
		return true;
	}
	return false;
}
/**
* @brief computeCommentDensity Berechet Kommentardichte
*/
void FileReport::computeCommentDensity(){
	if (lines != 0){
		commentDensity = (((double)commentLines / lines) * 100);
		commentDensity = round(commentDensity, 2);
	}
}
/**
* @brief toCSVFile
* @param fileName Filename
*/
void FileReport::toCSVFile(string& fileName){
	fileName = fileName + CSV_ENDING;
	const char* constName = fileName.c_str();
	ofstream file;
	if (fileExists(fileName)){
		file.open(constName, std::fstream::trunc);
	}
	else {
		file.open(constName);
	}
	file << LINES << SEMICOLON << COMMENT_LINES << SEMICOLON << COMMENT_DENSITY << SEMICOLON << UPPER_CASE
		<< SEMICOLON << LOWER_CASE << SEMICOLON << NUMERIC << SEMICOLON << SPECIAL_CHARS << SEMICOLON << endl
		<< lines << SEMICOLON << commentLines << SEMICOLON << commentDensity << PERCENT << SEMICOLON << upperCaseLetters
		<< SEMICOLON << lowerCaseLetters << SEMICOLON << digits << SEMICOLON << specialCharacters << SEMICOLON
		<< endl;
	file.close();

}
/**
* @brief toString
*/
string FileReport::toString(){
	ostringstream o;
	o << FILE_NAME << name << endl;
	o << LINES << TABULATOR << COMMENT_LINES << TABULATOR << COMMENT_DENSITY << TABULATOR
		<< UPPER_CASE << TABULATOR << LOWER_CASE << TABULATOR << NUMERIC << TABULATOR
		<< SPECIAL_CHARS << endl;
	o << lines << TABULATOR << commentLines << TABULATOR << TABULATOR << commentDensity << PERCENT
		<< TABULATOR << TABULATOR << upperCaseLetters << TABULATOR << TABULATOR << lowerCaseLetters
		<< TABULATOR << TABULATOR << digits << TABULATOR << specialCharacters << TABULATOR << endl;
	return o.str();
}
/**
* @brief fileExists
* @param fileName Filename
*/
bool FileReport::fileExists(string fileName) {
	const char* constName = fileName.c_str();
	ifstream infile(constName);
	return infile.good();
}
/**
* @brief round
* @param Zahl Zahl zum Runden
* @param Stellen Stelle zum runden
*/
double FileReport::round(double Zahl, int Stellen){
	double v[] = { 1, 10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8 };
	return floor(Zahl * v[Stellen] + 0.5) / v[Stellen];
}
