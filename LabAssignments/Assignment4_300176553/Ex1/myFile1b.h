/*myFile1b.h, Ex1 a4 CSI2372A*/


#include <iostream>
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	// Constructor
	Student(int iD, int maxNumCourses) : numID(iD), nbCourses(0), maxCourses(maxNumCourses){
		List_courses = new Course*[maxNumCourses];
		List_grades = new int[maxNumCourses];
	}
	
	// Destructor
	~Student(){
		delete[] List_courses;
		delete[] List_grades;
	}
	
	//Calculating the average grade of the student
	double average() const{
		if (nbCourses == 0) return 0.0;
		int totalNumGrades = 0;
		
		for (int t = 0; t < nbCourses; t++){
			totalNumGrades = totalNumGrades + List_grades[t];
		}
		
		return static_cast<double>(totalNumGrades) / nbCourses;
	}
	
	// Calculating the total hours of all courses that the student is taking
	int totalHours() const {
		int hrs = 0;
		
		for(int t = 0; t < nbCourses; t++){
			hrs = hrs + List_courses[t]->getHours();
		}
		
		return hrs;	
	}
	
	// Adding the course and the corresponding grade to the student's course list
	bool addCourse(Course* courseCode, int gradeOfCourse){
		if(nbCourses < maxCourses){
			List_courses[nbCourses] = courseCode;
			List_grades[nbCourses] = gradeOfCourse;
			nbCourses++;
			return true;
		}
		
		return false; //If course list is full
	}
};
