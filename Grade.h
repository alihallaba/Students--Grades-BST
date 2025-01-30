//
// Created by abdel on 1/1/2024.
//

#ifndef STUDEEENNT_GRADDDESS_GRADE_H
#define STUDEEENNT_GRADDDESS_GRADE_H
class GradeLinkedList{
public:
    class GradeNode {
    public:
        int grade;
        GradeNode* next;
        GradeNode();

    };
    GradeNode* head;
    // Constructor to initialize the linked list
    GradeLinkedList();
    void insertGrade(int newGrade);
    void removeGrade(int _grade);
    void printList();
    int maxGrade();
    bool findGrade(int findgrade);
};
#endif //STUDEEENNT_GRADDDESS_GRADE_H
