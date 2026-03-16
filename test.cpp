#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Student.hpp"

// ============================================================
//  test.cpp — Grader tests for the Student assignment
//  Topic: Freshman Survival Simulator
//  DO NOT MODIFY THIS FILE
// ============================================================

// ---- Construction & Initial State --------------------------

TEST_CASE("Student construction sets correct initial values") {
    Student s("Charlie");

    SUBCASE("name is set correctly") {
        CHECK(s.getName() == "Charlie");
    }
    SUBCASE("coffee count starts at 0") {
        CHECK(s.getCoffeeCount() == 0);
    }
    SUBCASE("assignments due starts at 0") {
        CHECK(s.getAssignmentsDue() == 0);
    }
    SUBCASE("hours slept starts at 8.0") {
        CHECK(s.getHoursSlept() == doctest::Approx(8.0));
    }
    SUBCASE("panic level starts at 0") {
        CHECK(s.getPanicLevel() == 0);
    }
    SUBCASE("initial mood is Zen Master") {
        CHECK(s.getMood() == "Zen Master");
    }
}

TEST_CASE("Different students have independent state") {
    Student s1("Alice");
    Student s2("Bob");
    s1.drinkCoffee();
    s1.drinkCoffee();

    CHECK(s1.getCoffeeCount() == 2);
    CHECK(s2.getCoffeeCount() == 0);
    CHECK(s1.getPanicLevel() == 2);
    CHECK(s2.getPanicLevel() == 0);
}

// ---- drinkCoffee -------------------------------------------

TEST_CASE("drinkCoffee increments coffee count") {
    Student s("Test");
    s.drinkCoffee();
    CHECK(s.getCoffeeCount() == 1);
    s.drinkCoffee();
    CHECK(s.getCoffeeCount() == 2);
    s.drinkCoffee();
    CHECK(s.getCoffeeCount() == 3);
}

TEST_CASE("drinkCoffee increments panic level by 1 per cup") {
    Student s("Test");
    s.drinkCoffee();
    CHECK(s.getPanicLevel() == 1);
    s.drinkCoffee();
    CHECK(s.getPanicLevel() == 2);
}

TEST_CASE("drinkCoffee clamps panic level at 10") {
    Student s("Test");
    for (int i = 0; i < 15; ++i) {
        s.drinkCoffee();
    }
    CHECK(s.getPanicLevel() == 10);
    CHECK(s.getCoffeeCount() == 15); // coffee count is NOT clamped
}

// ---- addAssignment -----------------------------------------

TEST_CASE("addAssignment increments assignments due") {
    Student s("Test");
    s.addAssignment();
    CHECK(s.getAssignmentsDue() == 1);
    s.addAssignment();
    CHECK(s.getAssignmentsDue() == 2);
}

TEST_CASE("addAssignment increments panic level by 1") {
    Student s("Test");
    s.addAssignment();
    CHECK(s.getPanicLevel() == 1);
    s.addAssignment();
    CHECK(s.getPanicLevel() == 2);
}

TEST_CASE("addAssignment clamps panic level at 10") {
    Student s("Test");
    for (int i = 0; i < 15; ++i) {
        s.addAssignment();
    }
    CHECK(s.getPanicLevel() == 10);
    CHECK(s.getAssignmentsDue() == 15); // due count is NOT clamped
}

// ---- submitAssignment --------------------------------------

TEST_CASE("submitAssignment decrements assignments due") {
    Student s("Test");
    s.addAssignment();
    s.addAssignment();
    s.submitAssignment();
    CHECK(s.getAssignmentsDue() == 1);
}

TEST_CASE("submitAssignment decrements panic level by 1") {
    Student s("Test");
    s.addAssignment(); // panic = 1
    s.submitAssignment(); // panic = 0
    CHECK(s.getPanicLevel() == 0);
}

TEST_CASE("submitAssignment does not allow assignments due to go below 0") {
    Student s("Test");
    s.submitAssignment(); // nothing to submit
    CHECK(s.getAssignmentsDue() == 0);
    s.submitAssignment(); // still nothing
    CHECK(s.getAssignmentsDue() == 0);
}

TEST_CASE("submitAssignment does not allow panic to go below 0") {
    Student s("Test");
    s.submitAssignment(); // panic is already 0
    CHECK(s.getPanicLevel() == 0);
}

// ---- sleep -------------------------------------------------

TEST_CASE("sleep adds hours to total sleep") {
    Student s("Test");
    s.sleep(6);
    CHECK(s.getHoursSlept() == doctest::Approx(14.0));
}

TEST_CASE("sleep reduces panic by 1 per every 2 hours") {
    Student s("Test");
    // bring panic up to 6
    for (int i = 0; i < 6; ++i) s.drinkCoffee();
    CHECK(s.getPanicLevel() == 6);

    s.sleep(4); // should reduce panic by 2
    CHECK(s.getPanicLevel() == 4);

    s.sleep(2); // should reduce panic by 1
    CHECK(s.getPanicLevel() == 3);
}

TEST_CASE("sleep with odd hours rounds down for panic reduction") {
    Student s("Test");
    for (int i = 0; i < 5; ++i) s.drinkCoffee(); // panic = 5
    s.sleep(3); // reduces by 3/2 = 1
    CHECK(s.getPanicLevel() == 4);
}

TEST_CASE("sleep clamps panic at 0 — cannot sleep your way to negative panic") {
    Student s("Test");
    s.sleep(100);
    CHECK(s.getPanicLevel() == 0);
}

TEST_CASE("sleep hours accumulate across multiple calls") {
    Student s("Test");
    s.sleep(3);
    s.sleep(3);
    CHECK(s.getHoursSlept() == doctest::Approx(14.0));
}

// ---- cramForExam -------------------------------------------

TEST_CASE("cramForExam increases coffee count by 3") {
    Student s("Test");
    s.cramForExam();
    CHECK(s.getCoffeeCount() == 3);
    s.cramForExam();
    CHECK(s.getCoffeeCount() == 6);
}

TEST_CASE("cramForExam decreases sleep by 3 hours") {
    Student s("Test");
    s.cramForExam();
    CHECK(s.getHoursSlept() == doctest::Approx(5.0));
}

TEST_CASE("cramForExam increases panic by 4") {
    Student s("Test");
    s.cramForExam();
    CHECK(s.getPanicLevel() == 4);
}

TEST_CASE("cramForExam clamps panic at 10") {
    Student s("Test");
    s.cramForExam(); // panic = 4
    s.cramForExam(); // panic = 8
    s.cramForExam(); // panic = 12 -> clamped = 10
    CHECK(s.getPanicLevel() == 10);
}

TEST_CASE("cramForExam clamps sleep at 0 — cannot sleep negative hours") {
    Student s("Test");
    s.cramForExam(); // sleep = 5
    s.cramForExam(); // sleep = 2
    s.cramForExam(); // sleep = -1 -> clamped = 0
    CHECK(s.getHoursSlept() == doctest::Approx(0.0));
}

// ---- getMood -----------------------------------------------

TEST_CASE("getMood returns correct string for each panic range") {
    SUBCASE("Zen Master: panic 0-2") {
        Student s("Test");
        CHECK(s.getMood() == "Zen Master");   // panic = 0
        s.drinkCoffee();
        CHECK(s.getMood() == "Zen Master");   // panic = 1
        s.drinkCoffee();
        CHECK(s.getMood() == "Zen Master");   // panic = 2
    }
    SUBCASE("Getting Nervous: panic 3-5") {
        Student s("Test");
        for (int i = 0; i < 3; ++i) s.drinkCoffee();
        CHECK(s.getMood() == "Getting Nervous"); // panic = 3
        s.drinkCoffee();
        CHECK(s.getMood() == "Getting Nervous"); // panic = 4
        s.drinkCoffee();
        CHECK(s.getMood() == "Getting Nervous"); // panic = 5
    }
    SUBCASE("Send Help: panic 6-8") {
        Student s("Test");
        for (int i = 0; i < 6; ++i) s.drinkCoffee();
        CHECK(s.getMood() == "Send Help"); // panic = 6
        s.drinkCoffee();
        CHECK(s.getMood() == "Send Help"); // panic = 7
        s.drinkCoffee();
        CHECK(s.getMood() == "Send Help"); // panic = 8
    }
    SUBCASE("DROPPING OUT: panic 9-10") {
        Student s("Test");
        for (int i = 0; i < 9; ++i) s.drinkCoffee();
        CHECK(s.getMood() == "DROPPING OUT"); // panic = 9
        s.drinkCoffee();
        CHECK(s.getMood() == "DROPPING OUT"); // panic = 10
    }
}

// ---- Compound scenarios ------------------------------------

TEST_CASE("Full semester simulation") {
    Student s("Diana");

    // Syllabus week
    s.addAssignment();
    s.addAssignment(); // panic = 2, due = 2

    // Study and submit
    s.drinkCoffee();   // panic = 3
    s.submitAssignment(); // panic = 2, due = 1
    CHECK(s.getAssignmentsDue() == 1);
    CHECK(s.getPanicLevel() == 2);
    CHECK(s.getMood() == "Zen Master");

    // Exam crunch
    s.cramForExam(); // panic = 6, sleep = 5, coffee = 4
    CHECK(s.getMood() == "Send Help");

    // Recovery sleep
    s.sleep(6); // panic = 6 - 3 = 3, sleep = 11
    CHECK(s.getMood() == "Getting Nervous");
    CHECK(s.getHoursSlept() == doctest::Approx(11.0));
}