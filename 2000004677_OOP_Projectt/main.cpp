//Hulusi Giray Güzel - 2000004677 - OOP Project

#include <iostream>
#include <string>
#include "SoftwareCourses.h"
#include "LanguageCourses.h"
#include "ProfessionalDevelopmentCourses.h"
#include "ComputerScienceCourses.h" // The fourth course I created
#include "Student.h"
#include "Cart.h"
#include "Utility.h" //Discount function


using namespace std;

void showMenu() { // MENU
    cout << "\n********** Online Course Management System **********\n" << endl;
    cout << "1. View Available Courses\n";
    cout << "2. Add a Course to Cart\n";
    cout << "3. Remove a Course from Cart\n";
    cout << "4. View Cart\n";
    cout << "5. Confirm Cart\n";
    cout << "6. Simulate Payment\n";
    cout << "7. Show Purchased Courses\n";
    cout << "8. Rate a Course\n";
    cout << "9. Apply Discount to a Course\n";
    cout << "10. New User\n";
    cout << "11. Exit\n";
    cout << "\nEnter your choice: ";
}

int main() {

    bool exitProgram = false;
    
    while (!exitProgram) {
        
        string userName, userSurname, userEmail;

        cout << "\n********** Online Course Management System **********\n" << endl;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, userName);
        cout << "Enter your surname: ";
        getline(cin, userSurname);
        cout << "Enter your email: ";
        getline(cin, userEmail);

        Student student(userName, userSurname, userEmail);
        Cart cart;


        string projectTopics[5] = { "Planning", "Budgeting", "Risk Management", "Scheduling", "Leadership" };
        string timeTopics[5] = { "Prioritization", "Goal Setting", "Productivity Tools", "Stress Management", "Focus Techniques" };

        // ALL AVAILABLE COURSES
        SoftwareCourses fullStackCourse("Full Stack Web Development", "Büþra Kocaçýnar", 25, 200.0, "Intermediate", "JavaScript", "Visual Studio Code", 60);
        LanguageCourses businessEnglishCourse("Business English", "Ebru Temiz", 20, 150.0, "Advanced", "English", true, 30);
        ProfessionalDevelopmentCourses projectManagementCourse("Project Management Fundamentals", "Ýrem Aksoy", 15, 180.0, "Intermediate", true, projectTopics, 5, 40);
        SoftwareCourses mobileAppCourse("Mobile App Development", "Wisam Elmasry", 30, 220.0, "Advanced", "Flutter", "Android Studio", 50);
        LanguageCourses russianCourse("Russian for Beginners", "Natali Demirkapýlý", 18, 130.0, "Beginner", "Russian", true, 25);
        ProfessionalDevelopmentCourses timeManagementCourse("Time Management Skills", "OKtay Aydýnlar", 20, 160.0, "Beginner", true, timeTopics, 5, 30);
        ComputerScienceCourses aiCourse("Introduction to AI", "Öznur Þengel", 20, 180.0, "Advanced", 50, true, 5);

        const int COURSE_COUNT = 7;
        OnlineCourse* availableCourses[COURSE_COUNT] = {
            &fullStackCourse, &businessEnglishCourse, &projectManagementCourse,
            &mobileAppCourse, &russianCourse, &timeManagementCourse, &aiCourse
        };

        int choice;
        bool newUser = false;

        do {
            showMenu();
            cin >> choice;

            switch (choice) {
            case 1: { // View All Available Courses
                cout << "\nAvailable Courses:\n\n";
                for (int i = 0; i < COURSE_COUNT; ++i) { // Loop as many as available courses
                    cout << i + 1 << ". "; // cout for number of course number
                    availableCourses[i]->displayInfo(); // displayInfo with using polimorfizm
                    cout << endl;
                }
                break;
            }

            case 2: { // Add a Course own cart
                cout << "Enter the course number you want to add to your cart: ";
                int courseNum;
                cin >> courseNum;
                if (courseNum >= 1 && courseNum <= COURSE_COUNT) { // In this line, we checking a number entered by the user is a valid or not...?
                    cart.addCourse(availableCourses[courseNum - 1], student); // add course to cart
                }
                else {
                    cout << "Invalid course number!" << endl; // If the user enter invalid course number, there is an error message
                }
                break;
            }

            case 3: { // Remove a Course from Cart
                cout << "Enter the course number you want to remove from your cart: ";
                int courseNum;
                cin >> courseNum;

                if (courseNum >= 1 && courseNum <= COURSE_COUNT) { // Checking to number of course by user
                    cart.removeCourse(availableCourses[courseNum - 1]); // Remove the course from cart
                }
                else {
                    cout << "Invalid course number!!!" << endl; // If the user enter invalid course number, there is an error message
                }
                break;
            }

            case 4: { // View Cart
                cart.displayCart();
                break;
            }

            case 5: { // When the user confirm own card, user can not add or remove any courses in own card.
                cart.confirmCart(student);
                break;
            }

            case 6: { // Payment Statement
                cart.simulatePayment(student);
                cout << "\nReturning to main menu...\n"; // Info message
                break;
            }

            case 7: { // Show us the purchased course(s)
                student.displayPurchasedCourses();
                break;
            }

            case 8: { // Rate a course
                // Check if user has purchased any courses
                if (student.getEnrolledCourseCount() == 0) { // No courses enrolled
                    cout << "You have not purchased any courses yet.\n";
                    break; // Return to the main menu
                }

                student.displayPurchasedCourseNames(); // Display purchased course names

                cout << "Enter the course number to rate: ";
                int courseIndex;
                cin >> courseIndex;

                if (courseIndex >= 1 && courseIndex <= COURSE_COUNT) {
                    if (student.hasPurchasedCourse(availableCourses[courseIndex - 1])) {
                        int rating;
                        cout << "Enter your rating (1-5): ";
                        cin >> rating;

                        student.rateCourse(availableCourses[courseIndex - 1], rating);
                    }
                    else {
                        cout << "You can not rate this course because you have not purchased it yet.\n";
                    }
                }
                else {
                    cout << "Invalid course number!\n";
                }
                break;
            }


            case 9: { // Apply discount to a course in the cart
                cout << "Choose a course to apply a discount:\n";

                // Show course(s) in user's cart
                bool hasCourses = false;
                for (int i = 0; i < COURSE_COUNT; ++i) {
                    if (cart.isCourseInCart(availableCourses[i])) { // List only course(s) available in cart
                        cout << i + 1 << ". " << availableCourses[i]->getCourseName() << endl;
                        hasCourses = true;
                    }
                }

                if (!hasCourses) {
                    cout << "Your cart is empty! Add courses to your cart before applying discounts.\n";
                    break;
                }

                int courseChoice;
                cout << "Enter the course number: ";
                cin >> courseChoice;

                if (courseChoice >= 1 && courseChoice <= COURSE_COUNT) {
                    if (cart.isCourseInCart(availableCourses[courseChoice - 1])) { // Check if the course is in the cart
                        double discountRate;
                        cout << "Enter discount rate 0.0 to 1.0 (0.2 for 20%): ";
                        cin >> discountRate;

                        if (discountRate >= 0.0 && discountRate <= 1.0) {
                            availableCourses[courseChoice - 1]->setDiscountRate(discountRate);
                            cout << "Discount applied successfully to \""
                                << availableCourses[courseChoice - 1]->getCourseName() << "\"!\n";
                        }
                        else {
                            cout << "Invalid discount rate. Must be between 0.0 and 1.0.\n";
                        }
                    }
                    else {
                        cout << "You can only apply discounts to courses in your cart.\n";
                    }
                }
                else {
                    cout << "Invalid course choice!\n";
                }
                break;
            }

            case 10: { // New User
                cout << "Returning to the new user creation...\n";
                newUser = true;
                break;
            }

            case 11: { // Exit
                cout << "Exiting the program...\n";
                exitProgram = true;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 11." << endl; // If the user enter invalid choice, there is an error message
            }
        }while (!newUser && choice != 11);

        if (newUser) {
            continue;
        }
        else if (exitProgram) {
            break;
        }
    }

    return 0;
}