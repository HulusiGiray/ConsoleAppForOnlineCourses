// This class holds student info, enrolled course, purchased course and the rating system.

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "OnlineCourse.h"

using namespace std;

class Student {
private:
    string name;
    string surname;
    string email;
    OnlineCourse* enrolledCourses[3]; // Array for max 3 courses
    int enrolledCourseCount;          // Number of enrolled courses

public:
    // Constructor
    Student(const string& studentName, const string& studentSurname, const string& studentEmail)
        : name(studentName), surname(studentSurname), email(studentEmail), enrolledCourseCount(0) {}

    // Return private information
    const string& getName() const { return name; }
    const string& getSurname() const { return surname; }
    const string& getEmail() const { return email; }


    void enrollInCourse(OnlineCourse* course) {
        if (enrolledCourseCount >= 3) { // Course limit control
            cout << "You can not enroll in more than 3 course." << endl;
            return;
        }
        for (int i = 0; i < enrolledCourseCount; i++) { // Prevent adding to same course again
            if (enrolledCourses[i] == course) {
                cout << "You are already enrolled in this course." << endl;
                return;
            }
        }
        enrolledCourses[enrolledCourseCount++] = course; // Add course to array
        cout << "Course successfully enrolled." << endl;
    }

    void displayPurchasedCourses() const {
        if (enrolledCourseCount == 0) {
            cout << "You have not purchased any courses yet.\n"; // If there is no course purchased, this message is shown
            return;
        }

        cout << "\nPurchased Courses:\n";
        for (int i = 0; i < enrolledCourseCount; i++) {
            enrolledCourses[i]->displayInfo();
            cout << "--------------------------\n";
        }
    }

    void displayPurchasedCourseNames() const {
        if (enrolledCourseCount == 0) { // If no course(s) have been purchased, there is an message
            cout << "You have not purchased any courses yet.\n";
            return;
        }

        cout << "\nYour purchased courses:\n";
        for (int i = 0; i < enrolledCourseCount; i++) { // Show just courseName
            cout << i + 1 << ". " << enrolledCourses[i]->getCourseName() << endl;
        }
    }

    void rateCourse(OnlineCourse* course, int rating) {
        bool courseFound = false;

        // Check if the course is in the enrolledCourses array
        for (int i = 0; i < enrolledCourseCount; i++) {
            if (enrolledCourses[i] == course) {
                courseFound = true;
                break;
            }
        }

        if (courseFound) {
            if (rating >= 1 && rating <= 5) {
                course->rateCourse(rating); // Call the course's rateCourse method
            }
            else {
                cout << "Invalid rating! Please enter a value between 1 and 5.\n";
            }
        }
        else {
            cout << "You can not rate this course because you have not purchased it yet.\n";
        }
    }

    bool hasPurchasedCourse(OnlineCourse* course) const {
        for (int i = 0; i < enrolledCourseCount; i++) { // Check the purchased course(s)
            if (enrolledCourses[i] == course) {
                return true; // You have purchased course(s)
            }
        }
        return false; // You have not any purchased courses
    }

    int getEnrolledCourseCount() const {
        return enrolledCourseCount; // Return the number of enrolled courses
    }

    void displayEnrolledCourses() const {
        if (enrolledCourseCount == 0) {
            cout << "No courses enrolled." << endl;
            return;
        }
        cout << "Enrolled Courses:" << endl; // Checks if the student is enrolled in any courses.If yes, it displays the details of all enrolled courses.
        for (int i = 0; i < enrolledCourseCount; i++) {
            enrolledCourses[i]->displayInfo();
        }
    }
};

#endif