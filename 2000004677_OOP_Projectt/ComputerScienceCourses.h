// This class is derived class of OnlineCourse.h

#ifndef COMPUTERSCIENCECOURSES_H
#define COMPUTERSCIENCECOURSES_H

#include "OnlineCourse.h"
#include <iostream>

class ComputerScienceCourses : public OnlineCourse { //inheritance
private:
    bool requiresPracticalLabs; // Does the course need labs?
    int projectCount; // Number of projects to be done in this course

public:
    // Constructor
    ComputerScienceCourses(const string& name, const string& inst, int cap, double cost, const string& lvl, int duration, bool labsRequired, int projects)
        : OnlineCourse(name, inst, cap, cost, lvl, duration), requiresPracticalLabs(labsRequired), projectCount(projects) {} // Firstly run OnlineCourse constructor

    void displayInfo() const override {
        cout << "\nCourse Name: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Capacity: " << capacity << ", Enrolled: " << enrolledStudents << endl;
        cout << "Price: $" << price << ", Level: " << level << endl;
        cout << "Duration: " << totalDuration << " hours" << endl;
        cout << "Requires Practical Labs: " << (requiresPracticalLabs ? "Yes" : "No") << endl;
        cout << "Project Count: " << projectCount << endl;
    }

    bool addStudent() override { // If course capacity is not full, student add to course
        if (checkCapacity()) {
            enrolledStudents++;
            return true;
        }
        cout << "You can not add student, this course is full..." << endl; // Otherwise, you can not add student
        return false;
    }

    bool checkCapacity() const override { // If return true, you can add a student. But if return false, you can not add a student.
        return enrolledStudents < capacity;
    }
};

#endif