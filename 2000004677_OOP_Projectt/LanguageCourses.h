// This class is derived class of OnlineCourse.h
// #ifndef, #define, #endi; prevents the file from being included more than once

#ifndef LANGUAGECOURSES_H
#define LANGUAGECOURSES_H

#include "OnlineCourse.h"
#include <iostream>
#include <string>

using namespace std;

class LanguageCourses : public OnlineCourse { // inheritance
private:
    string foreignLanguage;
    bool isNativeSpeaker; // Is the instructor a native speaker?

public:
    // Constructor
    LanguageCourses(const string& name, const string& inst, int cap, double cost, const string& lvl, const string& lang, bool nativeSpeaker, int duration)
        : OnlineCourse(name, inst, cap, cost, lvl, duration), foreignLanguage(lang), isNativeSpeaker(nativeSpeaker) {} // OnlineCourse calls the base class constructor

    void displayInfo() const override { // If we do not use override, the error will not be noticed if you acciedemtally change the function.
        // For example, we wrote "displayinfo" with small i. And the compiler might be not notice this. But since we used override, the compiler noticed this more easily...
        cout << "\nCourse Name: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Capacity: " << capacity << ", Enrolled: " << enrolledStudents << endl;
        cout << "Price: $" << price << ", Level: " << level << endl;
        cout << "Duration: " << totalDuration << " hours" << endl;
        cout << "Language: " << foreignLanguage << endl;
        cout << "Native Speaker: " << (isNativeSpeaker ? "Yes" : "No") << endl;
    }

    bool addStudent() override {
        if (checkCapacity()) {
            enrolledStudents++;
            return true;
        }
        cout << "you can not add student, course is full!" << std::endl;
        return false;
    }

    bool checkCapacity() const override {
        return enrolledStudents < capacity; // Checks if the number of enrolled students is less than the course capacity
    }
};

#endif