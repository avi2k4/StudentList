/*
Student List by Avighnash Kumar. 9/30/22.
Add, view, and delete students in a list!
*/

#include <iostream>
#include <vector>

using namespace std;

// Student struct
struct Student {
	char firstName[25];
	char lastName[25];
	int id;
	float gpa;
};

bool running = true;
vector<Student> students;

int main() {
	cout << "Commands: [ADD] to add student, [DELETE] to delete student, [PRINT] to print student list, [QUIT] to quit program." << endl;

	while (running) {
		char input[7];
		cin >> input;

		if (strcmp(input, "ADD") == 0) {
			Student student;

			// Inputting student info
			cout << "Enter the student's first name:" << endl;
			cin >> student.firstName;
			cout << "Enter the student's last name:" << endl;
			cin >> student.lastName;
			cout << "Enter the student's ID:" << endl;
			cin >> student.id;
			cout << "Enter the students GPA:" << endl;
			cin >> student.gpa;

			// Add student to vector
			students.insert(students.begin(), student);

			cout << "Added " << student.firstName << " " << student.lastName << " to the list!" << endl; 
		}
		else if (strcmp(input, "DELETE") == 0) {
			cout << "Enter the ID of the student you want to delete form the list:" << endl;
			int id;
			cin >> id;

			// Iterate over the vector until item with matching id is found, then erase and break.
			for (std::vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
				if ((*it).id == id) {
					cout << "Deleted student with ID " << id << " from the list!";
					students.erase(it);
					break;
				}
			}
		}
		else if (strcmp(input, "PRINT") == 0) {
			cout << "STUDENT LIST: " << endl;

			// Iterate over every item in the vector and print
			for (std::vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
				cout << (*it).firstName << " " << (*it).lastName << ", " << (*it).id << ", " << printf("%.2f", (*it).gpa) << endl;
			}
		}
		else if (strcmp(input, "QUIT") == 0) {
			// Break while loop
			running = false;
		}
	}	

	return 0;
};
