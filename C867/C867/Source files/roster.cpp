#include "degree.h"
#include "roster.h"
#include "list.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Function that adds student to Roster object
//E2 & EB & E3A)
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int firstCourse, int secondCourse, int thirdCourse, Degree degree) {
    int daysToCourseCompletion[3] = {firstCourse, secondCourse, thirdCourse};

    if(degree == 0 )  classRosterArray[rosterSize++] =  new Student(studentID, firstName, lastName, email, age, daysToCourseCompletion, Degree::SECURITY) ;
    if(degree == 1 ) classRosterArray[rosterSize++] = new Student(studentID, firstName, lastName, email, age, daysToCourseCompletion, Degree::NETWORK);
    if(degree == 2 ) classRosterArray[rosterSize++] =   new Student(studentID, firstName, lastName, email, age, daysToCourseCompletion, Degree::SOFTWARE);
    if(degree > 2 || degree < 0 )cout << "Error: Not a valid Degree. Student could not be added. \n";
    
}

//E3B Remove student from roster by studentID
void Roster::remove(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr){
        if(studentID == (*classRosterArray[i]).getStudentID()) {
            classRosterArray[i] = nullptr;
            cout << "Student "<< studentID << " removed."; 
            };
        } else if (classRosterArray[i] == nullptr) {
            cout << "Student "<< studentID << " does not exist." ;
        }
    }
}

//E3C Print all student's info in roster
void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            (*classRosterArray[i]).print();
                        cout << "\n";
        }
    }
}

//E3D Iterates through each student and prints their average days required
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; i++) {
        //using getter for ID
        if (studentID == (*classRosterArray[i]).getStudentID()) {
            //using getter for days to completion
            int* days = (*classRosterArray[i]).getDaysToCourseCompletion();
            double avg = ((double)days[0] + (double)days[1] + (double)days[2]) / 3.0;
            
            cout << fixed << setprecision(1);
            cout << studentID << ": " << avg << " days" << endl;
        }
    }
}

//E3E Function that informs user of invalid email addresses in Roster object
void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; i++) {
        string email = (*classRosterArray[i]).getEmail();

        size_t atSign = email.find("@");
        if (atSign == string::npos) {
            
            cout <<"Error: Invalid email Missing '@'\t";
            cout <<email + "\n";
        }

        size_t period = email.find(".");
        if (period == string::npos) {
            cout <<"Error: Invalid email. Missing '.'.\t";
            cout <<email + "\n";
        }

        size_t whiteSpace = email.find(" ");
        if (whiteSpace != string::npos) {
            cout <<"Error: Invalid email. No spaces allowed.\t";
            cout <<email + "\n";
        }
    }
}

//E3F Print student's info with degree
void Roster::printByDegreeProgram(Degree degree) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && (*classRosterArray[i]).getDegreeProgram() == SOFTWARE) {
            (*classRosterArray[i]).print();
            cout << "\n";
        }
    }
}




// Entry point of the program
int main() { 
    Degree degree;   

    //F1
    cout << "Course: C867 Scripting and Programming Applications  \n" ;
    cout << "Programming Language: C++ \n";
    cout << "Student ID: #009580996 \n";
    cout << "Name: Omar Ahmed\n" ;

    //F2
    Roster classRoster;

    //F3
    // Getting studentData and storing into a vector
    for (int i = 0; i < 5; i++) {
        stringstream ss(studentData[i]);
        vector<string> result;

        while (ss.good()) {
            string subString;
            getline(ss, subString, ',');
            result.push_back(subString);
        }
        Degree degree;
        if (result[8] == "SECURITY") {
            degree = SECURITY;
        }
        if (result[8] == "SOFTWARE") {
            degree = SOFTWARE;
        }
        if (result[8] == "NETWORK") {
            degree = NETWORK;
        }
     
        // Add vector results to classRoster object
        classRoster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
                stoi(result[6]), stoi(result[7]), degree);
    }


    //F4
    cout << "\n\n";
    cout << "-----------------------------------------";
    cout << "\n\n";
    cout <<"Print Roster";

    cout << "-----------------------------------------";
    cout << "\n\n";
    classRoster.printAll();
    cout << "\n\n";

    cout << "-----------------------------------------";
    cout << "\n\n";

    cout << "Invalid Emails" << endl;
    classRoster.printInvalidEmails();
    cout << "\n\n";

      cout << "-----------------------------------------";
    cout << "\n\n";

    cout << "Print average time to complete class" << endl;
    for (int i = 0; i < 5; i++) {
        string tempString = "A" + to_string(i + 1);
        classRoster.printAverageDaysInCourse(tempString);
    }
    cout << "\n\n";
  cout << "-----------------------------------------";
    cout << "\n\n";

    cout << "Print students with SOFTWARE degree" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << "\n\n";

  cout << "-----------------------------------------";
    cout << "\n\n";

    cout << "Remove student with ID A3" << endl;
    classRoster.remove("A3");
    cout << "\n\n";
  cout << "-----------------------------------------";
    cout << "\n\n";
    cout << "Print ALL after Removal of ID A3" << endl;
    classRoster.printAll();
    cout << "\n\n";
  cout << "-----------------------------------------";
    cout << "\n\n";

    cout << "Trying to remove student with ID A3 Again" << endl;
    classRoster.remove("A3");
    
    return 0;
}

//F5
Roster::~Roster() {}
