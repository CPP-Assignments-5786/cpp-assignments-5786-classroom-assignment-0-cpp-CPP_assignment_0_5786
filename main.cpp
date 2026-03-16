#include "Student.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "=== CS101: Intro to C++ (and Existential Dread) ===" << endl;
    cout << "Week 1, Day 1. You are full of hope. Cherish this moment." << endl;
    cout << endl;

    // Create a new student — bright-eyed, bushy-tailed, 0 regrets
    Student alice("Alice");
    alice.print();
    // Expected output:
    // [Alice] | Coffee: 0 cups | Assignments Due: 0 | Sleep: 8.0h | Panic: 0/10 | Mood: Zen Master

    cout << endl;
    cout << "--- Syllabus Day: the professor casually drops 3 assignments ---" << endl;
    alice.addAssignment();
    alice.addAssignment();
    alice.addAssignment();
    alice.print();
    // Expected output:
    // [Alice] | Coffee: 0 cups | Assignments Due: 3 | Sleep: 8.0h | Panic: 3/10 | Mood: Getting Nervous

    cout << endl;
    cout << "--- Alice decides coffee is the answer (it is not) ---" << endl;
    alice.drinkCoffee();
    alice.drinkCoffee();
    alice.print();
    // Expected output:
    // [Alice] | Coffee: 2 cups | Assignments Due: 3 | Sleep: 8.0h | Panic: 5/10 | Mood: Getting Nervous

    cout << endl;
    cout << "--- Alice submits the easy assignment (the 'Hello World' one) ---" << endl;
    alice.submitAssignment();
    alice.print();
    // Expected output:
    // [Alice] | Coffee: 2 cups | Assignments Due: 2 | Sleep: 8.0h | Panic: 4/10 | Mood: Getting Nervous

    cout << endl;
    cout << "--- Midterm week. Alice crams. Twice. ---" << endl;
    alice.cramForExam();
    alice.cramForExam();
    alice.print();
    // Expected output:
    // [Alice] | Coffee: 8 cups | Assignments Due: 2 | Sleep: 2.0h | Panic: 10/10 | Mood: DROPPING OUT

    cout << endl;
    cout << "--- Alice sleeps for 10 hours straight ---" << endl;
    alice.sleep(10);
    alice.print();
    // Expected output:
    // [Alice] | Coffee: 8 cups | Assignments Due: 2 | Sleep: 12.0h | Panic: 5/10 | Mood: Getting Nervous

    cout << endl;
    cout << "--- Bob joins the course on Week 3, confident he can catch up ---" << endl;
    Student bob("Bob");
    bob.addAssignment();
    bob.addAssignment();
    bob.addAssignment();
    bob.addAssignment();
    bob.addAssignment(); // 5 missed assignments
    bob.cramForExam();
    bob.cramForExam();
    bob.cramForExam(); // 3 crams
    bob.print();
    // Expected output:
    // [Bob] | Coffee: 9 cups | Assignments Due: 5 | Sleep: 0.0h | Panic: 10/10 | Mood: DROPPING OUT

    cout << endl;
    cout << "Good luck this semester, everyone." << endl;
    cout << "(You're going to need it.)" << endl;

    return 0;
}