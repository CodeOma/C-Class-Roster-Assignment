#include "student.h"
#include <iostream>
#include "degree.h"

using namespace std;

//D2
// getters functions
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName(){
    return lastName;
}

string Student::getEmail(){
    return email;
}

int Student::getAge(){
    return age;
}

Degree Student::getDegree(){
    return degree;
}
int *Student::getDaysToCourseCompletion(){
    return daysToCourseCompletion;
}


// Mutator functions
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}
Degree Student::getDegreeProgram() {
    return degree;
}


void Student::setDaysToCourseCompletion(int firstCourse, int secondCourse, int thirdCourse) {
    Student::daysToCourseCompletion[0] = firstCourse;
    Student::daysToCourseCompletion[1] = secondCourse;
    Student::daysToCourseCompletion[2] = thirdCourse;
}

void Student::setDegree(Degree degree) {
    this->degree = degree;
}

// Class Constructor
Student::Student(string studentID,string firstName, string lastName,  string email, int age, int* daysToCourseCompletion, Degree degree) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentID = studentID;
    this->email = email;
    this->age = age;
    this->daysToCourseCompletion[0] = daysToCourseCompletion[0];
    this->daysToCourseCompletion[1] = daysToCourseCompletion[1];
    this->daysToCourseCompletion[2] = daysToCourseCompletion[2];
    this->degree = degree;

}

// Print specific student data
void Student::printFirstName() {
	cout << "First Name: " << firstName;
}
void Student::printLastName() {
	cout << "Last Name: " << lastName;
}
void Student::printStudentID() {
	cout << "Student ID: " << studentID;
}
void Student::printEmail() {
	cout << "Email: " << email;
}
void Student::printAge() {
	cout << "Age: " << age;
}
void Student::printDaysToCourseCompletion() {
	cout << "Days left: ";
	for (int i = 0; i < 3; i++)
	{
		cout << "Course " << i + 1 << daysToCourseCompletion[i];
		if (i < 2) {
			cout << ", ";
		}
	}
}

char* DegreeToString(Degree degree)
{
    char* degrees[3] = { "SECURITY","NETWORK", "SOFTWARE"};

    return degrees[degree];
}


void Student::print() {
  cout << "Student Id: " << getStudentID();
    cout << "\nFirst Name: " << getFirstName();
    cout << "\nLast Name: " << getLastName();
    cout << "\nAge: " << getAge();
    cout << "\nEmail: " << getEmail();

    int* daysLeft = getDaysToCourseCompletion();    
	cout << "\nDays left: ";
	for (int i = 0; i < 3; i++)
	{
		cout << "Course " << i + 1 << ": " << daysLeft[i];
        cout << " ";
		if (i < 2) {
			cout << ", ";
		}
	}     
    cout << "\nDegree: "  << DegreeToString(degree) << endl;
  
}; 

// Destructor
Student::~Student() {}