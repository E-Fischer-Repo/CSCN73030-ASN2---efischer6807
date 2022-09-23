/*
* Name: Eric Fischer
* File: Source.cpp
* Date: 16/09/22
* Description: The purpose of this assignment is to walk through the development process that will be used
during the class project. While going through the development process, you will implement a set of
code that will contain compiler directives for controlling debug, release, and pre-release testing code
using the Visual Studio IDE and C++.
*/


/*	Step #3
	Next you need to implement the main function to read the StudentData.txt file, create student objects and store them into a vector space. 
	Create a struct STUDENT_DATA that contains the first and last names of the students. 
	Each line read from the input file contains a first/last name pair separated by a comma. 
	Parse the data, create an object and push that object into a vector space.
	When you are finished you should have all the students listed in your vector space.
	Commit and push your changes into the repository master.
*/

/*	Step #4
	To help debug the loading of the file update the main function to print out all the student information to the screen. 
	This functionality should only be performed if the application has been compiled in debug mode.
	Commit and push your changes into the repository master.
*/

/*	Step #5
	Your next task is to add new functionality into the software, but in a way where it can be merged, but not executed unless running in a pre-release executable. 
	This new functionality will add email addresses to your student input data. Use the following steps to create a pre-release version of your source code:
	1. Create a branch in Github called PreRelease, commit and push it into your Github Repo
	2. Update the main source code to print out a message to state if the application is running standard or pre-release source code
	3. Update the main source code to read the StudentData_Emails.txt if compiled using a PRE_RELEASE compiler directive, commit and push into your Github Repo PreRelease branch
	4. Perform a “Pull Request” on your PreRelease branch
	a. Merge your PreRelease branch code into your master branch
	5. In Visual Studio, resync your project with Github.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#define PRE_RELEASE

int main() {
	string fileName;
	ifstream fin;
	class Student {
	public:
		struct STUDENT_DATA { // Requested student struct, holding first and last names temporarily before pushing to the vector
			string firstName;
			string lastName;
			string email;
		}data;
	};
	vector<Student> students; // The vector that will dynamically allocate space for the students

	#ifdef PRE_RELEASE
		fileName = "StudentData_Emails.txt";
		cout << "The application is running with pre-release source code" << endl;
	#else
		fileName = "StudentData.txt"; // the file to be opened
		cout << "The application is running with standard source code" << endl;
	#endif

	fin.open(fileName); // opens the given file
	if (fin.is_open()) {
		while (!fin.eof()) {
			Student baseStudent;
			#ifdef PRE_RELEASE
				getline(fin, baseStudent.data.lastName, ',');
				getline(fin, baseStudent.data.firstName, ',');
				getline(fin, baseStudent.data.email);
				#ifdef _DEBUG
					cout << "Student name: " << baseStudent.data.firstName << ", " << baseStudent.data.lastName << ", " << baseStudent.data.email << endl;
				#endif
			#else
				getline(fin, baseStudent.data.lastName, ',');
				//cout << "Last name: " << data.lastName << endl; //This code was used to test if the getline properly went past the delimiter
				getline(fin, baseStudent.data.firstName);
				//cout << "First name: " << data.firstName << endl; //This code was used to test if the getline properly went past the delimiter
				#ifdef _DEBUG
					cout << "Student name: " << baseStudent.data.firstName << "," << baseStudent.data.lastName << endl;
				#endif
			#endif
			
			
			
			

			students.push_back(baseStudent);
		}

	}
	else {
		cout << "Failed to open file!\n" << endl; // Only executes when the file was not oepned properly
	}
	return 1;
}