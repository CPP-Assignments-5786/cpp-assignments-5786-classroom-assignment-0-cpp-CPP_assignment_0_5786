[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=23177852&assignment_repo_type=AssignmentRepo)
# מטלה 0 — ברוכים הבאים ל-C++ 🎓

## יושרה אקדמית

מותר להתייעץ עם סטודנטים אחרים ולחפש מידע באינטרנט, אך אסור להעתיק קוד ממקורות חיצוניים.
**במקרה של שימוש בכלי AI, יש לצרף את הפרומפטים והתשובות שהתקבלו**.

## מטרת המטלה

מטלה זו נועדה אך ורק להכיר את כלי העבודה של הקורס:
- הרצת פקודות `make`
- הגשה דרך GitHub Classroom ומעבר הבדיקות האוטומטיות

## מה עליכם לעשות

פתחו את הקובץ `Student.cpp` והחליפו את השורה המסומנת:

```cpp
return ""; // REPLACE THIS LINE
```

כך שהפונקציה תחזיר את ההודעה `"Welcome to CPP course, <n>!"`.

לדוגמה: `greet("Alice")` מחזירה `"Welcome to CPP course, Alice!"`

## קבצים

| קובץ | מי כותב | תיאור |
|------|---------|-------|
| `Student.hpp` | סופק | הצהרת הפונקציה |
| `Student.cpp` | **אתם** | מלאו את השורה המסומנת |
| `main.cpp` | סופק | דגמה |
| `test.cpp` | סופק | בדיקות אוטומטיות |

## פקודות

יש להריץ בסביבת לינוקס:

```bash
make        # מקמפל ומריץ את הדמו
make test   # מריץ את הבדיקות
make grade  # בדיקות + clang-tidy (משמש לציון)
make clean  # מנקה קבצי קימפול
```

## הגשה

הגישו את `Student.cpp` בלבד דרך GitHub Classroom.
הבדיקות ירוצו אוטומטית — ודאו שהכל עובר לפני ההגשה.

---
בהצלחה! 🤝
