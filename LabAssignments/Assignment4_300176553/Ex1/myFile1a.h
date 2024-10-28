/*myFile1a, Ex1 a4 CSI2372A*/

#include <iostream>
using namespace std;

class Course {
    int num;
    int hours;
public:
    Course(int courseCode, int hrs) : num(courseCode), hours(hrs) {}
    
    int getNum() const {
    	return num;
	}
	
    int getHours() const {
    	return hours;
	}
};
