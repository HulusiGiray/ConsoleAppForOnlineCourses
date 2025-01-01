// This class is derived class of OnlineCourse.h

#ifndef PROFESSIONALDEVELOPMENTCOURSES_H
#define PROFESSIONALDEVELOPMENTCOURSES_H

#include "OnlineCourse.h"
#include <iostream>
#include <string>

using namespace std;

class ProfessionalDevelopmentCourses : public OnlineCourse { // inhertiance
private:
    bool providesCertification; // Does course provide certification
    string topicsCovered[5]; // Array to hold the topics - max 5 topics
    int topicCount;

public:
    //Constructor
    ProfessionalDevelopmentCourses(const string& name, const string& inst, int cap, double cost, const string& lvl, bool certification, const string topics[5], int tCount, int duration)
        : OnlineCourse(name, inst, cap, cost, lvl, duration), providesCertification(certification), topicCount(tCount) { // Firstly run OnlineCourse constructor
        for (int i = 0; i < topicCount; ++i) {
            topicsCovered[i] = topics[i]; // We copied the elements of the "topics" array to the topicsCovered.
        }
    }

    void displayInfo() const override { // Override displayInfo() to see course infos
        cout << "\nCourse Name: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Capacity: " << capacity << ", Enrolled: " << enrolledStudents << endl;
        cout << "Price: $" << price << ", Level: " << level << endl;
        cout << "Duration: " << totalDuration << " hours" << endl;
        cout << "Provides Certification: " << (providesCertification ? "Yes" : "No") << endl;
        cout << "Topics Covered: ";
        for (int i = 0; i < topicCount; ++i) {
            cout << topicsCovered[i] << (i < topicCount - 1 ? ", " : "");
        }
        cout << endl;
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