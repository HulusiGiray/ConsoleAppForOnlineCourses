// BASE CLASS
// This class holds to courses info and  virtual methods for the derived class

//If ONLINECOURSE_H is already defined, the code inside will not be processed again.
#ifndef ONLINECOURSE_H
#define ONLINECOURSE_H

#include <iostream>
#include <string>

using namespace std;

// Base class for all online courses
class OnlineCourse {
protected:
    string courseName;
    string instructor;
    int capacity;
    int enrolledStudents;
    double price;
    double discountRate;
    string level;
    string prerequisites[5]; // Array to hold course prerequisites
    int prereqCount = 0;
    int totalDuration;

    static double averageRating;
    static int ratingCount; // Total rating

public:
    OnlineCourse(const string& name, const string& inst, int cap, double cost, const string& lvl, int duration); // Constructor
    
    virtual ~OnlineCourse(); // Virtual destructor
    
    virtual void displayInfo() const = 0; // Pure virtual function for the display course info
    
    virtual bool addStudent() = 0; // Pure virtual function for add student to the course
    
    virtual bool checkCapacity() const = 0; // Pure virtual function for the checking if the course has available capacity

    void setDiscountRate(double rate); // Declaration for discountRate, for the definiton see OnlineCourse.cpp

    double calculateDiscountedPrice() const; // Declaration for calculateDiscountPrice, for the definiton see OnlineCourse.cpp


    // getter function to access private and protected
    const string& getCourseName() const; //return courseName variable and you can not change it
    const string& getInstructor() const; // return instructor name and this func does not change any variable
    int getCapacity() const; //return capacity
    int getEnrolledStudents() const; // return enrolledStudents
    double getPrice() const; // return price of course (yani "price" deðiþekni)
    int getTotalDuration() const; // return totalDuration


    void rateCourse(int rating); // Declaration
    double getAverageRating() const;

};

#endif