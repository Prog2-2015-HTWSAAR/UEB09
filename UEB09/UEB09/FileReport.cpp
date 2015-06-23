/*
 * FileReport.cpp
 *
 *  Created on: 23.06.2015
 *      Author: sbastian
 */

#include "FileReport.h"

FileReport::FileReport() {
	initReport();
}

FileReport::FileReport(string fileName){
	initReport();
	parseFile(fileName);
}
FileReport::~FileReport() {
	// Nothing to do here!
}

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

void FileReport::parseFile(string fileName){
	const char* constName = fileName.c_str();
	string line;
	fstream file;
	file.open(constName);
	name = fileName;
	while (getline(file, line)){
		analyseLine(line);
	}
	computeCommentDensity();
}

void FileReport::analyseLine(string line){
	int length = line.length();
	bool usualCharacter = false;
	if(!checkComment(line)){
		for (int i = 0; i < length; ++i) {
			if(checkUpperCase(line[i])){
				break;
			}
			if(checkLowerCase(line[i])){
				break;
			}
			if(checkDigit(line[i])){
				break;
			}
			checkSpecialCharacter(line[i]);
		}
	}
}

bool FileReport::checkComment(string line){
	if(line.length() >= 2){
		if(line[0] == '/' && line[1] == '/'){
			commentLines++;
			return true;
		}
	}
	return false;
}

bool FileReport::checkUpperCase(char character){
	if(character >= 'A' && character <= 'Z'){
		upperCaseLetters++;
		return true;
	}
	return false;
}

bool FileReport::checkLowerCase(char character){
	if(character >= 'a' && character <= 'z'){
		lowerCaseLetters++;
		return true;
	}
	return false;
}

bool FileReport::checkDigit(char character){
	if(character >= 0 && character <= 9){
		digits++;
		return true;
	}
	return false;
}

bool FileReport::checkSpecialCharacter(char character){
	if(character >= '!' && character <= '~'){
		return true;
	}
	return false;
}

void FileReport::computeCommentDensity(){
	commentDensity = commentLines / lines;
}

string FileReport::toString(){
	ostringstream o;
	o << "Dateiname: " << name << endl;
	o << "Zeilen\t" << "Kommentarzeilen\t" << endl;
	return o.str();
}
