//
// Created by abdel on 1/1/2024.
//

#ifndef STUDEEENNT_GRADDDESS_BST_H
#define STUDEEENNT_GRADDDESS_BST_H
#include "Grade.h"
#include <string>
using namespace std;

class BSTNode {
private:
    static BSTNode* root; // static root for the entire tree
    string subject;
    GradeLinkedList* gradeList; // linked list of grades
    BSTNode* left;
    BSTNode* right;

public:
    BSTNode();
    BSTNode(const string& _subject);

    void insertSubject(string newSubject);
    void insertGradeForSubject(const string& subject, int newGrade);
    void printSubjects();
    bool findSubject(const string& searchSubject);
    void removeSubject(const string& subjectToRemove);
    void removeGradeForSubject(const string& subject, int grade);
    int maxGradeInAll();
    int maxGradeInAllRecursive(BSTNode* node);


private:
    void printSubjectsAndGrades(BSTNode* node);
};
#endif //STUDEEENNT_GRADDDESS_BST_H
