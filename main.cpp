#include "BST.h"
#include <iostream>

int main()
{
    BSTNode bst;

    char choice;
    do {
        cout << "Enter 1 to add a new subject\n"
             << "Enter 2 to add a new grade in a subject\n"
             << "Enter 3 to print all subjects with grades in each subject\n"
             << "Enter 4 to find a subject\n"
             << "Enter 5 to remove a subject\n"
             << "Enter 6 to remove a grade from a subject\n"
             << "Enter 7 to find the maximum grade in all subjects\n"
             << "Enter 8 to exit\n"
             << "Enter your choice: ";

        int menuChoice;
        cin >> menuChoice;

        switch (menuChoice)
        {
            case 1: {
                string newSubject;
                cout << "Please enter the subject name: ";
                cin >> newSubject;
                bst.insertSubject(newSubject);
                cout << "Done" << endl;
                break;
            }
            case 2: {
                string subject;
                int newGrade;
                cout << "Please enter the subject name: ";
                cin >> subject;
                cout << "Please enter the new grade: ";
                cin >> newGrade;
                bst.insertGradeForSubject(subject, newGrade);
                cout << "Done" << endl;
                break;
            }
            case 3:
                cout << "Subjects and Grades:" << endl;
                bst.printSubjects();
                break;
            case 4: {
                string searchSubject;
                cout << "Please enter the subject name to find: ";
                cin >> searchSubject;
                if (bst.findSubject(searchSubject)) {
                    cout << searchSubject << " found in the BST." << endl;
                } else {
                    cout << searchSubject << " not found in the BST." << endl;
                }
                break;
            }
            case 5: {
                string subjectToRemove;
                cout << "Please enter the subject name to remove: ";
                cin >> subjectToRemove;
                bst.removeSubject(subjectToRemove);
                break;
            }
            case 6: {
                string subject;
                int gradeToRemove;
                cout << "Please enter the subject name: ";
                cin >> subject;
                cout << "Please enter the grade to remove: ";
                cin >> gradeToRemove;
                bst.removeGradeForSubject(subject, gradeToRemove);
                break;
            }
            case 7:
                cout << "Maximum grade in all subjects: " << bst.maxGradeInAll() << endl;
                break;
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Would you want to continue (Y or N): ";
        cin >> choice;

    } while (choice == 'Y');

    return 0;
}