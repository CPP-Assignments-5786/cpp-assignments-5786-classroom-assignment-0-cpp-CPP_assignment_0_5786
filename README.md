[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=23154155&assignment_repo_type=AssignmentRepo)
# מטלה ראשונה - סימולטור שרידות סטודנט 🎓☕

## יושרה אקדמית

במהלך העבודה על המטלות, מותר להתייעץ עם סטודנטים אחרים ולחפש מידע באינטרנט. עם זאת, חל איסור להעתיק קטעי קוד שלמים ממקורות חיצוניים, כולל סטודנטים אחרים, אתרי אינטרנט ומודלי בינה מלאכותית (כגון ChatGPT).

יש לדווח על כל עזרה שקיבלתם, בין אם מדובר בהתייעצות עם סטודנטים אחרים או במידע שנמצא באינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).
**במקרה של שימוש בכלי בינה מלאכותית (AI), יש לצרף את הפרומפטים שהוזנו ואת התשובות שהתקבלו**.

## הקדמה

מטלה זו היא חלק מהקורס "C++ תכנות מתקדם" ומטרתה להדגים את היתרונות והתכונות המיוחדות של שפת C++ בהשוואה לשפות תכנות אחרות כגון C ו-Java. המטלה מתמקדת ביישום מחלקה פשוטה המייצגת סטודנט אקדמי ואת מסע הישרדותו האמיץ לאורך הסמסטר.

> *"חשבתי ש-C++ זה 'C, אבל טוב יותר'. עכשיו אני מבין שזה 'C, אבל עם השלכות'."*
> — כל סטודנט, שבוע שני

## מבנה המטלה

במטלה זו תתבקשו להשלים קוד חסר בקבצים שמממשים את המחלקה `Student`. המחלקה מדמה סטודנט שנה א' ומנהלת את מצבו הנפשי לאורך הסמסטר — כמות הקפה שצרך, מספר המטלות הפתוחות, שעות השינה, ורמת הפאניקה הכללית.

## דרישות והנחיות

- להשלים את הקוד החסר בקבצים שסופקו
- לוודא שהקוד מתקמפל ופועל ללא שגיאות
- להקפיד על כתיבה תקנית ותיעוד מתאים

## תכונות C++ שיש להדגים

1. **מחלקות (Classes)** - הגדרת מחלקה עם שדות פרטיים ומתודות ציבוריות
2. **בנאי (Constructor)** - אתחול אובייקט עם ערכי ברירת מחדל
3. **מתודות (Methods)** - פונקציות הפועלות על נתוני המחלקה
4. **גטרים (Getters)** - גישה מבוקרת לשדות פרטיים
5. **קלט/פלט זרמים (Streams)** - שימוש ב-`iostream` ו-`iomanip` לפלט מעוצב
6. **הפרדה בין הצהרה למימוש** - שימוש נכון בקבצי `.hpp` ו-`.cpp`
7. **טיפוסי נתונים (Data Types)** - שימוש ב-`double`, `int`, `std::string`
8. **בדיקות יחידה (Unit Testing)** - שימוש בספריית doctest לבדיקות

## קבצים במטלה

### קבצים שסופקו:

- **main.cpp** - תוכנית ראשית המדגימה שימוש בכל המתודות עם הערות המציינות את הפלט הצפוי
- **test.cpp** - קובץ בדיקות יחידה לבדיקת נכונות המימוש
- **doctest.h** - ספרייה לביצוע בדיקות אוטומטיות
- **Makefile** - קובץ לקימפול והרצה אוטומטית של הפרויקט

### קבצים שעליכם ליצור ולממש:

- **Student.hpp** - קובץ המכיל את הצהרת המחלקה `Student`, שדותיה ומתודותיה
- **Student.cpp** - קובץ מימוש המכיל את הגדרות כל המתודות של המחלקה

## מפרט המחלקה `Student`

### שדות פרטיים

| שדה | טיפוס | ערך התחלתי | תיאור |
|-----|-------|------------|-------|
| `name` | `std::string` | (מהבנאי) | שם הסטודנט |
| `coffeeCount` | `int` | `0` | מספר כוסות הקפה שנצרכו |
| `assignmentsDue` | `int` | `0` | מספר המטלות הפתוחות |
| `hoursSlept` | `double` | `8.0` | סך שעות השינה שנצברו |
| `panicLevel` | `int` | `0` | רמת הפאניקה הנוכחית, **מוגבלת לתחום [0, 10]** |

> **חשוב:** `panicLevel` חייב **תמיד** להישאר בין 0 ל-10 (כולל), ללא קשר לפעולות שמבוצעות.
> אין הגבלה עליונה על `coffeeCount` ו-`assignmentsDue`.
> `hoursSlept` **לעולם לא יורד מתחת ל-0.0**.

### בנאי

```cpp
Student(const std::string& name);
```

מאתחל סטודנט עם השם הנתון וערכי ברירת המחדל המפורטים בטבלה.

### מתודות

#### `void drinkCoffee()`
- מגדיל את `coffeeCount` ב-1.
- מגדיל את `panicLevel` ב-1 (מוגבל ל-10).

#### `void addAssignment()`
- מגדיל את `assignmentsDue` ב-1.
- מגדיל את `panicLevel` ב-1 (מוגבל ל-10).

#### `void submitAssignment()`
- אם `assignmentsDue > 0`, מקטין את `assignmentsDue` ב-1 ואת `panicLevel` ב-1 (מוגבל ל-0).
- אם אין מטלות פתוחות — המתודה לא עושה דבר.

#### `void sleep(int hours)`
- מוסיף את `hours` לסך `hoursSlept`.
- מקטין את `panicLevel` ב-`hours / 2` (חלוקה שלמה, לאחר מכן מוגבל ל-0).
- דוגמאות: `sleep(4)` ← פאניקה -2 | `sleep(3)` ← פאניקה -1 | `sleep(1)` ← פאניקה -0

#### `void cramForExam()`
- מגדיל את `coffeeCount` ב-3.
- מקטין את `hoursSlept` ב-3.0 (מוגבל ל-0.0).
- מגדיל את `panicLevel` ב-4 (מוגבל ל-10).

### גטרים

```cpp
std::string getName()           const;
int         getCoffeeCount()    const;
int         getAssignmentsDue() const;
double      getHoursSlept()     const;
int         getPanicLevel()     const;
std::string getMood()           const;
```

#### `getMood()` — ערכי החזרה לפי `panicLevel`:

| רמת פאניקה | ערך מוחזר |
|------------|-----------|
| 0 – 2 | `"Zen Master"` |
| 3 – 5 | `"Getting Nervous"` |
| 6 – 8 | `"Send Help"` |
| 9 – 10 | `"DROPPING OUT"` |

> ⚠️ המחרוזות חייבות להתאים **במדויק** (רווחים, אותיות גדולות/קטנות, פיסוק) — הבדיקות משתמשות בהשוואת `==`.

### `void print() const`

מדפיסה את מצב הסטודנט המלא אל `std::cout` בפורמט **המדויק** הבא:

```
[Alice] | Coffee: 2 cups | Assignments Due: 3 | Sleep: 8.0h | Panic: 3/10 | Mood: Getting Nervous
```

הערות:
- `hoursSlept` מודפס עם **ספרה עשרונית אחת** (יש להשתמש ב-`std::fixed` ו-`std::setprecision(1)`).
- בסוף השורה יש **ירידת שורה**.

## הוראות קימפול והרצה

### שימוש ב-Makefile:

```bash
make        # מקמפל ומריץ את התוכנית הראשית
make test   # מקמפל ומריץ את בדיקות היחידה
make grade  # מריץ את הבדיקות ואת clang-tidy (משמש לציון)
make clean  # מנקה את כל קבצי הקימפול
```

## דוגמת פלט

הרצת `make` אמורה להפיק את הפלט הבא:

```
=== CS101: Intro to C++ (and Existential Dread) ===
Week 1, Day 1. You are full of hope. Cherish this moment.

[Alice] | Coffee: 0 cups | Assignments Due: 0 | Sleep: 8.0h | Panic: 0/10 | Mood: Zen Master

--- Syllabus Day: the professor casually drops 3 assignments ---
[Alice] | Coffee: 0 cups | Assignments Due: 3 | Sleep: 8.0h | Panic: 3/10 | Mood: Getting Nervous

--- Alice decides coffee is the answer (it is not) ---
[Alice] | Coffee: 2 cups | Assignments Due: 3 | Sleep: 8.0h | Panic: 5/10 | Mood: Getting Nervous

--- Alice submits the easy assignment (the 'Hello World' one) ---
[Alice] | Coffee: 2 cups | Assignments Due: 2 | Sleep: 8.0h | Panic: 4/10 | Mood: Getting Nervous

--- Midterm week. Alice crams. Twice. ---
[Alice] | Coffee: 8 cups | Assignments Due: 2 | Sleep: 2.0h | Panic: 10/10 | Mood: DROPPING OUT

--- Alice sleeps for 10 hours straight ---
[Alice] | Coffee: 8 cups | Assignments Due: 2 | Sleep: 12.0h | Panic: 5/10 | Mood: Getting Nervous

--- Bob joins the course on Week 3, confident he can catch up ---
[Bob] | Coffee: 9 cups | Assignments Due: 5 | Sleep: 0.0h | Panic: 10/10 | Mood: DROPPING OUT

Good luck this semester, everyone.
(You're going to need it.)
```

## טיפים להשלמת המטלה

- קראו היטב את הוראות המטלה והבינו את הדרישות לפני שמתחילים לכתוב קוד
- השלימו את הקוד החסר באופן הגיוני תוך התבססות על מפרט המחלקה
- וודאו שאתם מיישמים נכון את ההגבלות (clamping) על `panicLevel` ו-`hoursSlept`
- בדקו את התוכנית עם מקרי קצה — מה קורה כששולחים מטלה כשאין מטלות פתוחות? מה קורה כש-`cramForExam` נקרא כשיש 0 שעות שינה?
- הקפידו על כתיבת קוד נקי, קריא ומתועד היטב

## הגשה

יש להגיש את הקבצים הבאים:
- `Student.hpp`
- `Student.cpp`

וודאו שהקוד מתקמפל ורץ כראוי לפני ההגשה.

---

בהצלחה! זכרו: המהדר אינו האויב שלכם. הוא חבר כנה במיוחד. 🤝