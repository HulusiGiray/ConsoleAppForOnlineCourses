#ifndef CART_H
#define CART_H

#include <iostream>
#include "OnlineCourse.h"
#include "Student.h"

using namespace std;

class Cart {
private:
    OnlineCourse* selectedCourses[3]; // Array for max 3 selected course(s)
    int courseCount;
    bool isConfirmed; // Check if cart is confirmed

public:
    Cart() : courseCount(0), isConfirmed(false) {} // Constructor. courseCourse from 0 and isConfrimed from false

    bool addCourse(OnlineCourse* course, const Student& student) {
        if (isConfirmed) {// If your cart is confirmed, you can not add any other course(s)
            cout << "Cart is already confirmed. You can not add more courses." << endl;
            return false;
        }
        if (courseCount >= 3) { // Max 3 course
            cout << "You can only enroll in 3 courses." << endl;
            return false;
        }
        for (int i = 0; i < courseCount; i++) { // You can not add same course
            if (selectedCourses[i] == course) {
                cout << "Course is already in your cart." << endl;
                return false;
            }
        }
        selectedCourses[courseCount++] = course; // The message for when you confirm to course(s)
        cout << "The course has been added to your cart." << endl;
        return true;
    }

    bool removeCourse(OnlineCourse* course) {
        if (isConfirmed) { // If you confirmed to your cart, you can not remove any course(s)
            cout << "Cart is already confirmed. You can not remove courses." << endl;
            return false;
        }
        for (int i = 0; i < courseCount; i++) {
            if (selectedCourses[i] == course) {
                for (int j = i; j < courseCount - 1; j++) {
                    selectedCourses[j] = selectedCourses[j + 1];
                }
                courseCount--;
                cout << "The course removed from your cart..." << endl;
                return true;
            }
        }
        cout << "The course is not found in your cart..." << endl;
        return false;
    }

    void confirmCart(Student& student) {
        if (isConfirmed) {
            cout << "Cart is already confirmed!\n";
            return;
        }

        for (int i = 0; i < courseCount; i++) {
            student.enrollInCourse(selectedCourses[i]); // All courses adding to students by student.enrollInCourse() method.
        }

        isConfirmed = true; // Confirm cart
        cout << "\nThe cart is confirmed. Courses have been added to your account.\n";
    }

    void simulatePayment(Student& student) {
        if (courseCount == 0) {
            cout << "Your cart is empty. Add courses before proceeding to payment.\n";
            return;
        }

        double totalOriginalPrice = 0.0;
        double totalDiscountedPrice = 0.0;

        // STUDENT ÝNFO
        cout << "\n------------ Payment Summary ------------\n";
        cout << "Student Name: " << student.getName() << " " << student.getSurname() << endl;
        cout << "Email: " << student.getEmail() << endl;

        // CALCULATE TOTAL PRÝCE
        cout << "\nPayment Summary:\n";
        for (int i = 0; i < courseCount; i++) {
            double originalPrice = selectedCourses[i]->getPrice();
            double discountedPrice = selectedCourses[i]->calculateDiscountedPrice(); // Use the updated function

            cout << i + 1 << ". " << selectedCourses[i]->getCourseName()
                << " - Original Price: $" << originalPrice
                << ", Discounted Price: $" << discountedPrice << endl;

            totalOriginalPrice += originalPrice;
            totalDiscountedPrice += discountedPrice;
        }

        cout << "------------------------------------------\n";
        cout << "Total Original Price: $" << totalOriginalPrice << endl;
        cout << "Total Discounted Price: $" << totalDiscountedPrice << endl;

        
        string cardNumber;
        cout << "\nEnter your 16-digit card number to complete the payment: ";
        cin >> cardNumber;

        if (cardNumber.length() == 16) {
            cout << "\nPayment successful! You have been charged $" << totalDiscountedPrice << ".\n";
            confirmCart(student);
        }
        else {
            cout << "Invalid card number! Please enter a valid 16-digit number.\n";
        }
    }

    bool isCourseInCart(OnlineCourse* course) const {
        for (int i = 0; i < courseCount; i++) { // Check the courses in your cart 
            if (selectedCourses[i] == course) {
                return true; // You have course(s) in your cart
            }
        }
        return false; // There is no course(s) in your cart
    }


    void displayCart() const {
        if (courseCount == 0) { // If your cart is empty, there is an message for student
            cout << "--------------------" << endl;
            cout << "Your cart is empty. You do not have any courses." << endl;
            cout << "--------------------" << endl;
            return;
        }
        cout << "Courses in your Cart:\n";
        double totalOriginalPrice = 0.0;

        for (int i = 0; i < courseCount; i++) { // Loop for all courses in the cart one by one
            selectedCourses[i]->displayInfo(); // selectedCourses[i] holds pointers to the courses in the cart.
            cout << "Price: $" << selectedCourses[i]->getPrice() << "\n";
            totalOriginalPrice += selectedCourses[i]->getPrice(); // totalOriginalPrice variable holds the total price of all course(s) in the cart. 
        }

        cout << "----------------------------\n";
        cout << "Total Price: $" << totalOriginalPrice << endl;
    }


};

#endif