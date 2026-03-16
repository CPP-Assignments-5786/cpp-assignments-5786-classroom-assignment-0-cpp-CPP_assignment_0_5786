#pragma once
#include <string>

class Student {
private:
    std::string name;
    int         coffeeCount;
    int         assignmentsDue;
    double      hoursSlept;
    int         panicLevel;

public:
    Student(const std::string& name);

    void drinkCoffee();
    void addAssignment();
    void submitAssignment();
    void sleep(double hours);
    void cramForExam();

    std::string getName()           const;
    int         getCoffeeCount()    const;
    int         getAssignmentsDue() const;
    double      getHoursSlept()     const;
    int         getPanicLevel()     const;
    std::string getMood()           const;

    void print() const;
};