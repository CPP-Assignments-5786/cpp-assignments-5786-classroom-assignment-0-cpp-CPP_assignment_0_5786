#include "Student.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

static const double INITIAL_SLEEP    = 8.0;
static const int    MAX_PANIC        = 10;
static const int    MIN_PANIC        = 0;
static const double MIN_SLEEP        = 0.0;
static const int    CRAM_COFFEE      = 3;
static const int    CRAM_SLEEP       = 3;
static const double CRAM_SLEEP_D     = 3.0;
static const int    CRAM_PANIC       = 4;
static const int    MOOD_ZEN_MAX     = 2;
static const int    MOOD_NERVOUS_MAX = 5;
static const int    MOOD_HELP_MAX    = 8;

Student::Student(const std::string& name)
    : name(name), coffeeCount(0), assignmentsDue(0),
      hoursSlept(INITIAL_SLEEP), panicLevel(0) {}

void Student::drinkCoffee() {
    coffeeCount++;
    panicLevel = std::min(MAX_PANIC, panicLevel + 1);
}

void Student::addAssignment() {
    assignmentsDue++;
    panicLevel = std::min(MAX_PANIC, panicLevel + 1);
}

void Student::submitAssignment() {
    if (assignmentsDue <= 0) {
        return;
    }
    assignmentsDue--;
    panicLevel = std::max(MIN_PANIC, panicLevel - 1);
}

void Student::sleep(int hours) {
    hoursSlept += static_cast<double>(hours);
    panicLevel = std::max(MIN_PANIC, panicLevel - hours / 2);
}

void Student::cramForExam() {
    coffeeCount += CRAM_COFFEE;
    hoursSlept   = std::max(MIN_SLEEP, hoursSlept - CRAM_SLEEP_D);
    panicLevel   = std::min(MAX_PANIC, panicLevel + CRAM_PANIC);
}

std::string Student::getName()           const { return name; }
int         Student::getCoffeeCount()    const { return coffeeCount; }
int         Student::getAssignmentsDue() const { return assignmentsDue; }
double      Student::getHoursSlept()     const { return hoursSlept; }
int         Student::getPanicLevel()     const { return panicLevel; }

std::string Student::getMood() const {
    if (panicLevel <= MOOD_ZEN_MAX)     { return "Zen Master"; }
    if (panicLevel <= MOOD_NERVOUS_MAX) { return "Getting Nervous"; }
    if (panicLevel <= MOOD_HELP_MAX)    { return "Send Help"; }
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