#include <iostream>
#include <iomanip>
#include <Vector>
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <string>
#include <fstream>

#include <algorithm>
using namespace std;

void initializeBugs(vector<Bug*> &bug_Vector)
{
	

	ifstream input;
	Crawler* cptr;
	Hopper* hptr;
	string s;
	input.open("bugs.txt");
	if (input.is_open())
	{
		while (true)
		{
			vector<string> bugDetails;
			char delimiter = ';';

			int x = 0;
			getline(input, s);

			if (input.eof())
			{
				break;
			}
			int y = s.find(delimiter);
			bool hopper = false;
			int lengthOfDetails = 5;
			string type = s.substr(x, (y - x));
			if (type == "C")
			{
				hopper = false;
			}
			else if (type == "H")
			{
				hopper = true;
				lengthOfDetails++;
			}
			for (int j = 0; j <= lengthOfDetails; j++)
			{
				string data = s.substr(x, (y - x));
				bugDetails.push_back(data);
				x = ++y;
				y = s.find(delimiter, y);

			}
			if (hopper)
			{
				pair<int, int> coords;
				list<pair<int, int>> path;
				coords.first = stoi(bugDetails[2]);
				coords.second = stoi(bugDetails[3]);
				hptr = new Hopper(stoi(bugDetails[1]), coords, stoi(bugDetails[4]), stoi(bugDetails[5]), true, path, stoi(bugDetails[6]));
				bug_Vector.push_back(hptr);
			}
			else
			{
				pair<int, int> coords;
				list<pair<int, int>> path;
				coords.first = stoi(bugDetails[2]);
				coords.second = stoi(bugDetails[3]);
				cptr = new Crawler(stoi(bugDetails[1]), coords, stoi(bugDetails[4]), stoi(bugDetails[5]), true, path);
				bug_Vector.push_back(cptr);
			}
		}
	}
	else
	{
		cerr << "Could not find the specified file" << endl;
		exit(1);
	}
}

void showAllBugs(vector<Bug*> &bug_Vector)
{
	/*Bug* ptr;
	ptr = bug_Vector[0];
	*/
	for (int i = 0; i < bug_Vector.size(); i++)
	{	
		bug_Vector[i]->toString();
	}
	
	
}

void findBugByID(vector<Bug*>& bug_Vector, int searchID)
{
	bool found = false;
	for (int i = 0; i < bug_Vector.size(); i++)
	{
		if (searchID == bug_Vector[i]->getId())
		{
			bug_Vector[i]->toString();
			found = true;
		}
		
	}
	if (found == false)
	{
	
		cout << "Bug Not Found" << endl;
	
	}
}

void moveAllBugs(vector<Bug*>& bug_Vector)
{
	for (int i = 0; i < bug_Vector.size(); i++)
	{
		bug_Vector[i]->move();
	}
}

void displayAllBugsHistory(vector<Bug*>& bug_Vector)
{
	for (int i = 0; i < bug_Vector.size(); i++)
	{
		bug_Vector[i]->showLife();
	}
}

bool writeAllBugsToFile(vector<Bug*> &bug_Vector)
{
	ofstream out;
	out.open("bugsLife.txt", ios::app);

	for (int i = 0; i < bug_Vector.size(); i++)
	{
		bug_Vector[i]->showLife();
	}

	return true;
	
}




int main()
{
	vector<Bug*> bug_Vector;
	bool validInput = false;
	int choice;
	string i;
	do {
		cout << "1:\t Initialize Bug Board" << endl;
		cout << "2:\t Show All Bugs" << endl;
		cout << "3:\t Find A Bug" << endl;
		cout << "4:\t Tap the Bug Board" << endl;
		cout << "5:\t Display Bugs History and Life" << endl;
		cout << "7:\t Exit and write to file" << endl;
		
		cin >> choice;
		while (validInput == false) {

			validInput = true;
			if (cin.fail())
			{
				validInput = false;
				cin.clear();
				cin.ignore();
				cout << "Please enter a valid number" << endl;

			}

		}
		switch (choice)
		{
		case 1:
			initializeBugs(bug_Vector);
			break;
		case 2:
			showAllBugs(bug_Vector);
			break;
		case 3:
			int searchID;
			cin >> searchID;
			findBugByID(bug_Vector, searchID);
			break;
		case 4:
			moveAllBugs(bug_Vector);
			break;
		case 5:
			displayAllBugsHistory(bug_Vector);
			break;
		case 7:
			if (writeAllBugsToFile(bug_Vector))
			{
				cout << "Bugs written to file" << endl;
				exit(1);
			}
			else
			{
				cout << "Unable to write bugs to file" << endl;
			}
			break;


		}



			
	} while (choice != 0);
	return 0;
}