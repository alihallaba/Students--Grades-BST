#include <string>
#include <iostream>
#include "Grade.h"
using namespace std;


GradeLinkedList::GradeLinkedList() {
    head = nullptr;
}

GradeLinkedList::GradeNode::GradeNode() {
    grade = INT_MIN;
    next = nullptr;
}

void GradeLinkedList::insertGrade(int newGrade) {
    GradeNode* newNode = new GradeNode();
    newNode->grade = newGrade;

    if (head == nullptr){
        head = newNode;
        return;
    }
    else if(head->grade >= newGrade) {
        newNode->next = head;
        head = newNode;
        return;
    }

    GradeNode* currentNode = head;
    while (currentNode->next->grade < newGrade) {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}
void GradeLinkedList::printList() {
    GradeNode* currentNode = head;
    int sum=0;
    int count= 0;
    int avg;
    while(currentNode!= nullptr){
        sum+=currentNode->grade;
        currentNode = currentNode->next;
        count++;
    }
    avg=sum/count;

    GradeNode* tempNode = head;
    while (tempNode) {
        cout << tempNode->grade << " ";
        tempNode = tempNode->next;
    }
    cout<<endl;
    cout<<"The average grade is : "<<avg<<endl;

    cout<<endl;
}
void GradeLinkedList::removeGrade(int _grade) {
    if (head == nullptr) {
        cout << "No elements in the linked list";
        return;
    }

    GradeNode* temp = head;
    GradeNode* prev = nullptr;

    while (temp) {
        if (temp->grade == _grade) {
            if (prev == nullptr) {
                // If the grade to be removed is in the head node
                head = temp->next;
            } else {
                // If the grade to be removed is in a non-head node
                prev->next = temp->next;
            }

            delete temp;
            return;
        } else if (temp->grade < _grade) {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Grade Not found";
}
int GradeLinkedList::maxGrade() {
    int maxGradeValue = INT_MIN;

    GradeNode* current = head;
    while (current) {
        maxGradeValue = max(maxGradeValue, current->grade);
        current = current->next;
    }

    return maxGradeValue;
}
bool GradeLinkedList::findGrade(int findgrade) {
    GradeNode* curr = head;
    while(curr){
        if(curr->grade==findgrade)
            return true;
        else
            curr=curr->next;
    }
    return false;
}

