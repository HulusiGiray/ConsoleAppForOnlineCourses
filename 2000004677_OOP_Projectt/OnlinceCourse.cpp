// Ýncludes definitons of functions in the OnlineCourse.h

#include "OnlineCourse.h"

using namespace std;

double OnlineCourse::averageRating = 0.0;
int OnlineCourse::ratingCount = 0;

// Constructor
OnlineCourse::OnlineCourse(const string& name, const string& inst, int cap, double cost, const string& lvl, int duration)
    : courseName(name), instructor(inst), capacity(cap), enrolledStudents(0), price(cost), discountRate(0.0), level(lvl), totalDuration(duration) {}


OnlineCourse::~OnlineCourse() {} // Destructor

void OnlineCourse::setDiscountRate(double rate) { // Set the discount rate for the course(s)
    discountRate = rate;
}

double OnlineCourse::calculateDiscountedPrice() const { // Sets the discount rate, namely calculate the discounted price for course
    return price * (1 - discountRate);
} // For example, if price is 100 and discount rate is 0.2(20%), so the result is 100* (1 - 0.2) = 80



// getter functions are only read data(in private and protected)
const string& OnlineCourse::getCourseName() const { // get the course name
    return courseName;
}

const string& OnlineCourse::getInstructor() const { //get the instructor's name
    return instructor;
}

int OnlineCourse::getCapacity() const { //get the course capacity
    return capacity;
}

int OnlineCourse::getEnrolledStudents() const { // Get the number of students enrolled
    return enrolledStudents;
}

double OnlineCourse::getPrice() const { // Get the price of the course
    return price;
}

int OnlineCourse::getTotalDuration() const { // Get the total duration of the course
    return totalDuration;
}

// Rate course
void OnlineCourse::rateCourse(int rating) {
    if (rating >= 1 && rating <= 5) {
        averageRating = (averageRating * ratingCount + rating) / (ratingCount + 1); // Update average
        ratingCount++;
        cout << "Thank you for rating! The new average rating is: " << averageRating << endl;
    }
    else {
        cout << "Invalid rating! Please enter a value between 1 and 5.\n";
    }
}

// Get average rating
double OnlineCourse::getAverageRating() const {
    return averageRating;
}