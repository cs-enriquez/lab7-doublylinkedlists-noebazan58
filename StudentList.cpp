
	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {
    head = nullptr;
    tail = nullptr;
    numStudents = 0;
    }
	// return the number of students currently in the list
	int StudentList::listSize() {
		return numStudents;
	    }

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
    Node * newNode = new Node (s, head, nullptr);
    if(head == nullptr){
    tail = newNode;
        }
    else {
    head->prev = newNode;
        }
    head = newNode;
    numStudents++;
        }

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
    Node* newNode = new Node (s, nullptr, tail);
    if(tail == nullptr){
    head = newNode;
        }
    else{
    tail->next = newNode;
        }
    tail = newNode;
    numStudents++;
        }

	//Print out the names of each student in the list.
	void StudentList::printList() {
    Node * current = head;
    while (current != nullptr){
    cout << current->data.name << " " << current->data.id << " " << current->data.GPA << endl;
    current = current->next;
        }
        }

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
    if(tail == nullptr){
    cout << "Error\n";
    return;
        }
    Node * temp = tail;
    tail = tail->prev;
    if(tail == nullptr){
    head = nullptr;
        }
    else {
    tail->next = nullptr;    
        }
    delete temp;
    numStudents--;
        }

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
    if (head == nullptr){
    cout << "Error\n";
    return;
        }
    Node * temp = head;
    head = head->next;
    if(head == nullptr){
    tail = nullptr;
        }
    else{
    head->prev = nullptr;
        }  
    delete temp;
    numStudents--;
        }

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
    if (index < 0 || index > numStudents){
    cout << "Error\n";
    addBack(s);
    return;
        }
    Node * newNode = new Node(s, nullptr, nullptr);
    Node * current = head;
    for (int j = 0; j < index; j++){
    current = current->next;
        }
    newNode->next = current;
    newNode-> prev = current->prev;
    if( current ->prev == nullptr){
    head = newNode;
        }
    else{
    current->prev->next=newNode;
        }
    current->prev = newNode;
    numStudents++;
        }

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
	Node * current = head;
    while(current != nullptr){
    if(current->data.id == idNum){
    return current->data;
        }
    current = current->next;
        }
    cout << "No Match\n";
	Student dummy;
    dummy.id = -1;
    return dummy;
	    }

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {
    Node * current = head;
    while(current != nullptr){
    if ( current->data.id == idNum){
    if ( current->prev == nullptr){
    popFront();
        }
    else if ( current->next == nullptr){
    popBack();
        }
    return;
        }
    current = current->next;
        }
    cout << "Student with ID: " << idNum << " not found\n";
        }

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {
    Node * current = head;
    while (current != nullptr){
    if(current->data.id == idNum){
    current->data.GPA = newGPA;
    return;
        }
    current = current->next;
        }
        }

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {
    Node * current = otherList.head;
    while ( current != nullptr){
    addBack(current->data);
    current = current -> next;
        }
    otherList.head = nullptr;
    otherList.tail = nullptr;
    otherList.numStudents = 0;
        }

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
	StudentList newList;
    Node * current = head;
    while ( current != nullptr){
    if ( current->data.GPA >= minGPA){
    newList.addBack(current->data);
        }
    current = current->next;
        }
	return newList;
	    }
