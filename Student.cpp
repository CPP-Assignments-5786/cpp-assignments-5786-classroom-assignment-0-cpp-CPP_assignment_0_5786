#include "Student.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

Student::Student(const std::string& name)
    : name(name), coffeeCount(0), assignmentsDue(0),
      hoursSlept(8.0), panicLevel(0) {}

void Student::drinkCoffee() {
    coffeeCount++;
    panicLevel = std::min(10, panicLevel + 1);
}

void Student::addAssignment() {
    assignmentsDue++;
    panicLevel = std::min(10, panicLevel + 1);
}

void Student::submitAssignment() {
    if (assignmentsDue <= 0) return;
    assignmentsDue--;
    panicLevel = std::max(0, panicLevel - 1);
}

void Student::sleep(double hours) {
    hoursSlept += hours;
    panicLevel = std::max(0, panicLevel - static_cast<int>(hours) / 2);
}

void Student::cramForExam() {
    coffeeCount += 3;
    hoursSlept = std::max(0.0, hoursSlept - 3.0);
    panicLevel = std::min(10, panicLevel + 4);
}

std::string Student::getName()           const { return name; }
int         Student::getCoffeeCount()    const { return coffeeCount; }
int         Student::getAssignmentsDue() const { return assignmentsDue; }
double      Student::getHoursSlept()     const { return hoursSlept; }
int         Student::getPanicLevel()     const { return panicLevel; }

std::string Student::getMood() const {
    if (panicLevel <= 2) return "Zen Master";
    if (panicLevel <= 5) return "Getting Nervous";
    if (panicLevel <= 8) return "Send Help";
    return "DROPPING OUT";
}

void Student::print() const {
    std::cout << "[" << name << "]"
              << " | Coffee: "          << coffeeCount    << " cups"
              << " | Assignments Due: " << assignmentsDue
              << " | Sleep: "           << std::fixed << std::setprecision(1) << hoursSlept << "h"
              << " | Panic: "           << panicLevel << "/10"
              << " | Mood: "            << getMood()
              << "\n";
}