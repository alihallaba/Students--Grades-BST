#include <iostream>
#include "BST.h"
#include "Grade.h"

BSTNode* BSTNode::root=nullptr;
BSTNode::BSTNode(){
    subject="";
    gradeList=nullptr;
    left=right=nullptr;
}
BSTNode::BSTNode(const string& _subject) {
    subject = _subject;
    gradeList = nullptr;
    left = right = nullptr;
}

void BSTNode::insertSubject(string newSubject) {
    // If the tree is empty, create a new node and make it the root
    if (root == nullptr) {
        root = new BSTNode(newSubject);
        return;
    }

    // Find the parent node of the new node
    BSTNode* currentNode = root;
    BSTNode* parentNode = nullptr;
    while (currentNode) {
        parentNode = currentNode;
        if (newSubject < currentNode->subject) {
            currentNode = currentNode->left;
        } else if (newSubject > currentNode->subject) {
            currentNode = currentNode->right;
        } else {
            cout << "Subject already exists: " << newSubject << endl;
            return;
        }
    }

    // Create the new node and attach it to the parent node
    currentNode = new BSTNode(newSubject);
    if (newSubject < parentNode->subject) {
        parentNode->left = currentNode;
    } else {
        parentNode->right = currentNode;
    }
}

void BSTNode::insertGradeForSubject(const string& subject, int newGrade) {

    // Find the subject node
    BSTNode* currentNode = root;
    while (currentNode) {
        if (subject < currentNode->subject) {
            currentNode = currentNode->left;
        } else if (subject > currentNode->subject) {
            currentNode = currentNode->right;
        } else {
            break;
        }
    }

    // If the subject node is not found, return
    if (currentNode == nullptr) {
        cout << "Subject not found: " << subject << endl;
        return;
    }

    // Insert the grade into the linked list
    if (currentNode->gradeList == nullptr) {
        currentNode->gradeList = new GradeLinkedList();
    }
    currentNode->gradeList->insertGrade(newGrade);

}

// Helper function to print a single subject and its grades
void printSubjectAndGrades(const string& subject, GradeLinkedList* gradeList) {
    cout << subject << ": ";
    if (gradeList != nullptr) {
        gradeList->printList();
    }
    cout << "\n";
}

// Perform in-order traversal for printing subjects and grades
void BSTNode::printSubjectsAndGrades(BSTNode* node) {
    if (node == nullptr) {
        return;
    }

    printSubjectsAndGrades(node->left);
    printSubjectAndGrades(node->subject, node->gradeList);
    printSubjectsAndGrades(node->right);
}

// Public function to print all subjects and grades
void BSTNode::printSubjects() {
    printSubjectsAndGrades(root);
}



bool BSTNode::findSubject(const string& _subject) {
    BSTNode* cur = root;
    while (cur != nullptr) {
        if (cur->subject == _subject) {
            return true;  // Subject found
        } else if (_subject < cur->subject) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return false;  // Subject not found
}

void BSTNode::removeSubject(const string& rsubject)
{
    BSTNode* current = root;
    BSTNode* parent = nullptr;

    // Find the node to be removed and its parent
    while (current != nullptr && current->subject != rsubject)
    {
        parent = current;
        if (rsubject < current->subject)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // If the subject node is not found, print a message and return
    if (current == nullptr)
    {
        cout << "Subject not found: " << rsubject << endl;
        return;
    }

    // Case 1: Node with no children (leaf node)
    if (current->left == nullptr && current->right == nullptr)
    {
        if (parent == nullptr)
        {
            // Root is the only node in the tree
            delete root;
            root = nullptr;
        } else if (parent->left == current)
        {
            // Node is the left child of its parent
            delete current;
            parent->left = nullptr;
        }
        else
        {
            // Node is the right child of its parent
            delete current;
            parent->right = nullptr;
        }
    }
        // Case 2: Node with one child
    else if (current->left == nullptr)
    {
        // Node has only a right child
        if (parent == nullptr)
        {
            // Root node is being removed
            root = current->right;
        }
        else if (parent->left == current)
        {
            // Node is the left child of its parent
            parent->left = current->right;
        }
        else
        {
            // Node is the right child of its parent
            parent->right = current->right;
        }
        delete current;
    }
    else if (current->right == nullptr)
    {
        // Node has only a left child
        if (parent == nullptr)
        {
            // Root node is being removed
            root = current->left;
        }
        else if (parent->left == current)
        {
            // Node is the left child of its parent
            parent->left = current->left;
        }
        else
        {
            // Node is the right child of its parent
            parent->right = current->left;
        }
        delete current;
    }
        // Case 3: Node with two children
    else
    {
        // Find the in-order successor (smallest node in the right subtree)
        BSTNode* successor = current->right;
        BSTNode* successorParent = current;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace the data of the node to be removed with the successor's data
        current->subject = successor->subject;
        current->gradeList = successor->gradeList;

        // Remove the in-order successor (which is guaranteed to have at most one child)
        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }

        delete successor;
    }
}

void BSTNode::removeGradeForSubject(const string& subject, int grade)
{
    // Find the subject node
    BSTNode* currentNode = root;

    while (currentNode)
    {
        if (subject < currentNode->subject)
        {
            currentNode = currentNode->left;
        }
        else if (subject > currentNode->subject)
        {
            currentNode = currentNode->right;
        }
        else
        {
            // Subject node found
            if (currentNode->gradeList)
            {
                // Check if the grade is present in the linked list
                if (currentNode->gradeList->findGrade(grade))
                {
                    // Remove the grade from the linked list
                    currentNode->gradeList->removeGrade(grade);
                    cout << "Grade " << grade << " removed from subject " << subject << endl;
                }
                else
                {
                    cout << "Grade " << grade << " not found for subject " << subject << endl;
                }
            }
            else
            {
                cout << "No grades found for subject " << subject << endl;
            }

            return;
        }
    }

    // If the subject node is not found
    cout << "Subject not found: " << subject << endl;
}

int BSTNode::maxGradeInAll() {
    return maxGradeInAllRecursive(root);
}

int BSTNode::maxGradeInAllRecursive(BSTNode* node) {
    if (node == nullptr) {
        return INT_MIN;  // Return the smallest possible integer value for an empty tree
    }

    // Get the max grade for the current subject
    int maxGradeForSubject = (node->gradeList) ? node->gradeList->maxGrade() : INT_MIN;

    // Recursively find the maximum grade in left and right subtrees
    int maxGradeInLeftSubtree = maxGradeInAllRecursive(node->left);
    int maxGradeInRightSubtree = maxGradeInAllRecursive(node->right);

    // Return the maximum of the three values
    return max(maxGradeForSubject, max(maxGradeInLeftSubtree, maxGradeInRightSubtree));
}
