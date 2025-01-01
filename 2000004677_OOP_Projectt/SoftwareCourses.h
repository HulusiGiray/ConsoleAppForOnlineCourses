// This class is derived class of OnlineCourse.h

#ifndef SOFTWARECOURSES_H
#define SOFTWARECOURSES_H

#include "OnlineCourse.h"
#include <iostream>
#include <string>

using namespace std;


class SoftwareCourses : public OnlineCourse { // inheritance
private:
    string programmingLanguage;
    string developmentEnvironment;

public:
    // Constructor
    SoftwareCourses(const string& name, const string& inst, int cap, double cost, const string& lvl, const string& lang, const string& env, int duration)
        : OnlineCourse(name, inst, cap, cost, lvl, duration), programmingLanguage(lang), developmentEnvironment(env) {} // Firstly run OnlineCourse constructor

    void displayInfo() const override { // Override displayInfo() to see course infos
        cout << "\nCourse Name: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Capacity: " << capacity << ", Enrolled: " << enrolledStudents << endl;
        cout << "Price: $" << price << ", Level: " << level << endl;
        cout << "Duration: " << totalDuration << " hours" << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Development Environment: " << developmentEnvironment << endl;
    }

    bool addStudent() override {
        if (checkCapacity()) { // If course capacity is not full, student add to course
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