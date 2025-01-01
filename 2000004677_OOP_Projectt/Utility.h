// This file calculates discount price and define template function.

#ifndef UTILITY_H
#define UTILITY_H

#include "OnlineCourse.h"
#include <iostream>

using namespace std;

template <typename T> //This function can running with any class, object or data types.
double calculateDiscountedPrice(const T& course, double discountRate) {
    if (discountRate < 0 || discountRate > 1) { // Check if discount rate is valid. Discount rate must be between 0 and 1.
        cout << "Invalid discount rate! Must be between 0 and 1.\n";
        return course.getPrice(); // Return original price if discount is involid
    }
    return course.getPrice() * (1 - discountRate); // Add discount and return new price
}

#endif