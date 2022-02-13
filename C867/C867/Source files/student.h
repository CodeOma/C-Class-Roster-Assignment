#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"

using namespace std;

class Student {
    //D1) 
protected: 
    string  firstName, lastName, studentID, email;
    int age;
    int daysToCourseCompletion[3];
    Degree degree;
    
public:
 
    //D2a) Accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    Degree getDegree();
    Degree getDegreeProgram();
    int getAge();
    int *getDaysToCourseCompletion();
    
    //D2b)  Mutators 
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysToCourseCompletion(int firstCourse, int secondCourse, int thirdCourse);
    void setDegree(Degree degree);

    //D2d) Class Constructor      
    Student(string studentID, string firstName, string lastName, string email, int age, int* daysToCourseCompletion, Degree degree);
    
    //D2e) Virtual functions to print specific data
    virtual void print();
    virtual void printStudentID();
	virtual void printFirstName();
	virtual void printLastName();
	virtual void printEmail();
	virtual void printAge();
	virtual void printDaysToCourseCompletion();


    
    

    
    virtual ~Student();
};

#endif

