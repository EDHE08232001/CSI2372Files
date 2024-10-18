/*Ex2 - a3 CSI2372A*/

#include <iostream>
#include "myLinkedList.h"
using namespace std;

int main(){
	
	int choice;
	Evaluation* first = NULL;
	int number = 0;
	
	do{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice){
		case 1: 
			display(first);
			break;
		case 2: 
			first = add(first, number);
			break;
		case 3: 
			first = remove(first, number);
			break;
		case 4: 
			average(first, number);
			break;
		case 5: 
			exit(0);
		default:
			cout << "Invalid choice! PLease try again." << endl;
			break;
		}
	} while (1);
	
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number){
	
	int position;
    cout << "After which element you want to insert? (0 for start): ";
    cin >> position;
    
    // Checking if the position is valid
    if (position < 0 || position > number) {
        cout << "Invalid position!" << endl;
        return p;
    }
    
    // Creating a new node
    Evaluation* newEvaluation = new Evaluation;
    cout << "Enter the student: ";
    cin.ignore(); // Clear the input buffer
    cin.getline(newEvaluation -> student, 80);
    cout << "Enter the grade: ";
    cin >> newEvaluation -> grade;
    newEvaluation -> next = NULL;
    
    // Inserting at the start of the list
    if (position == 0) {
        newEvaluation -> next = p;
        p = newEvaluation;
    } else {
        // Traversing to the correct position
        Evaluation* temp = p;
        for (int t = 1; t < position; t++) {
            temp = temp -> next;
        }
        newEvaluation -> next = temp -> next;
        temp -> next = newEvaluation;
    }
    
    number = number + 1; // Incrementing the count of elements
    return p;
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number){
	
	if (number == 0) {
        cout << "List is empty!" << endl;
        return p;
    }

    int position;
    cout << "Enter the position of the element to delete (1 to " << number << "): ";
    cin >> position;

    // Checking if the position is valid
    if (position < 1 || position > number) {
        cout << "Invalid position!" << endl;
        return p;
    }

    Evaluation* temp = p;
    
    // If the first element is to be deleted
    if (position == 1) {
        p = p -> next;  // Moving to the next node
        delete temp;  // Deleting the old head
    } else {
        // Traversing to the node before the one to be deleted
        for (int t = 1; t < position - 1; t++) {
            temp = temp -> next;
        }
        Evaluation* nodeToDelete = temp -> next;  // The node to be deleted
        temp -> next = nodeToDelete -> next;  // Linking previous node to the next one
        delete nodeToDelete;  // Deleting the node
    }
    
    number = number - 1; // Decrementing the count of nodes
    return p;
}



/**
*display() Function *
**/
void display(Evaluation* p){
	
	if (p == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Evaluation* temp = p;
    int indexList = 1;
    
    // Traversing the list and printing each node
    while (temp != NULL) {
        cout << "Student " << indexList << ": " << temp -> student << endl;
        cout << "Grade: " << temp -> grade << endl;
        
        temp = temp -> next;
        indexList = indexList + 1;
    }
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre){
	
    if (nbre == 0) {
        cout << "No students in the list." << endl;
        return 0;
    }
    
    int sumGrade = 0;
    Evaluation* temp = p;
    
    // Traversing the list and summing up the grades
    while (temp != NULL) {
        sumGrade += temp->grade;
        temp = temp->next;
    }
    
    double averageGrade = static_cast<double>(sumGrade) / nbre;
    cout << "The average grade is: " << averageGrade << endl;
    
    return 1;
}

