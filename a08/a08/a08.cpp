/*CS 161 Assignment 8: Records (structs)
Filename: a08.cpp
Author:   Pierce Heyerdahl
Date:     6/14/2017
Summary:  Collects scores from a txt file and stores them in arrays, then calculates and displays the winner along with all contestants and their highest score
Functions:
N/A

Input variables:
ifstream inFile = the file where the scores are located
string fileName = user inputed location of file
char fName[30] = an array in the struct contestantData that stores the player's first name
char lName[30] = an array in the struct contestantData that stores the player's last name
float longestDistance = a variable in the struct contestantData the stores the player's longest fisbee throw
contestantData contestantArray[50] = an array of the contestantData struct type that stores names and scores

Output variables:
float scoreCheck1 = stores throw distance data when reading off the inFile
float scoreCheck2 = stores throw distance data when reading off the inFile
int counter = used to store number of contestants while reading data off the inFile
int winner = used to store the index of the winner of the contest
int numOfContestants = used to store the number of contestants entered

Equations:
if (!inFile.is_open()) than the program displays an error and exits
while (!inFile.eof() && counter < 50) the program reads info from the inFile and stores it in the struct array
for (int i = 0; i < 3; i++) the program compares the four scores for the contestant by storing them in scoreCheck1 and scoreCheck2 and comparing until only the highest score is left
if (scoreCheck1 > contestantArray[winner].longestDistance) the program changes the current winner to the player whose scores are currently being read
for (int j = 0; j < numOfContestants; j++) the program outputs the names and scores of the contestants excluding the winner
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct contestantData
{
	char fName[30];
	char lName[30];
	float longestDistance;
};

int main()
{
	ifstream inFile;
	string fileName;
	contestantData contestantArray[50];
	float scoreCheck1 = 0;
	float scoreCheck2 = 0;
	int counter = 0;
	int winner = 0;
	int numOfContestants = 0;

	cout << "Enter Filename" << endl; // gets file location from user
	getline(cin, fileName);
	cout << endl;
	inFile.open(fileName);

	if (!inFile.is_open()) // validate that file was found
	{
		cout << "Error: No File Detected" << endl << endl;
		exit(1);
	}

	while (!inFile.eof() && counter < 50) // reads student's first name, last name, and scores and stores them in the appropriate arrays
	{
		inFile >> contestantArray[counter].fName;
		inFile >> contestantArray[counter].lName;
		inFile >> scoreCheck1;

		for (int i = 0; i < 3; i++) // gets the contestant's highest score
		{
			inFile >> scoreCheck2;

			if (scoreCheck2 > scoreCheck1)
			{
				scoreCheck1 = scoreCheck2;
			}
		}

		contestantArray[counter].longestDistance = scoreCheck1;
		
		if (scoreCheck1 > contestantArray[winner].longestDistance) // determines if the current contestant is the winner
		{
			winner = counter;
		}
		numOfContestants = counter;
		counter++;
	}

	inFile.close();

	cout << setprecision(2) << fixed;
	cout << left << setw(16) << "First Name" << setw(16) << "Last Name" << setw(16) << "Longest Distance" << endl;
	cout << left << setw(15) << contestantArray[winner].fName << " " << setw(15) << contestantArray[winner].lName << " " << contestantArray[winner].longestDistance << " - WINNER!" << endl; // displays the winner

	for (int j = 0; j < numOfContestants; j++) // displays the rest of the contestants and their highest score
	{
		if (j != winner) // excludes the winner
		{
			cout << left << setw(15) << contestantArray[j].fName << " " << setw(15) << contestantArray[j].lName << " " << contestantArray[j].longestDistance << endl;
		}
	}

	cout << endl;
	return 0;
}