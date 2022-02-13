// E
#include "student.h"
#include <array>
#include "degree.h"
class Roster {    
public:    
    Student* classRosterArray[5] = {nullptr};
    void add(string studentID, string firstName, string lastName, string email, int age, int firstCourse, int secondCourse, int thirdCourse, Degree degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degree);
    int rosterSize = 0;
    
    ~Roster();
};


