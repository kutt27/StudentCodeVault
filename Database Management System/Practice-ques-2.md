### **Practice Question 2: SQL Commands and Database Operations**

**Requirement:**
1. Assume that the university database schema (Student, Course, Enrollment) is already created.
2. Perform the following SQL operations:

    a. Insert three students into the `Student` table.
    b. Insert four courses into the `Course` table.
    c. Enroll two students in two different courses. Provide enrollment dates.
    d. Retrieve a list of all students along with the courses they are enrolled in.

**Your Task:**
1. Write the SQL commands to accomplish the above operations.
2. Provide the expected output or result for each query.

---
## Syntax

```sql
--a.
INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email');

--b.
INSERT INTO Course VALUES ('&Course_id', '&Title', '&Credit_hours');

--c.
INSERT INTO Enrollment VALUES('&Enrollment_id', '&Student_id', '&Course_id', '&Enrollment_date');

SELECT Name, Title
FROM Student
JOIN
	Enrollment ON Enrollment.Student_id = Student.Student_id
JOIN
	Course ON Enrollment.Course_id = Course.Course_id
;
```

## Output

```text
SQL> INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email');
Enter value for student_id: S01
Enter value for name: Arjun
Enter value for date_of_birth: 18-APR-2000
Enter value for email: arjun@something.com
old   1: INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email')
new   1: INSERT INTO Student VALUES('S01', 'Arjun', '18-APR-2000', 'arjun@something.com')

1 row created.

SQL> INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email');
Enter value for student_id: S02
Enter value for name: Sharon
Enter value for date_of_birth: 12-DEC-2001
Enter value for email: sharon@something.com
old   1: INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email')
new   1: INSERT INTO Student VALUES('S02', 'Sharon', '12-DEC-2001', 'sharon@something.com')

1 row created.

SQL> INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email');
Enter value for student_id: S03
Enter value for name: Midhun
Enter value for date_of_birth: 01-Jun-2000
Enter value for email: midhun@something.com
old   1: INSERT INTO Student VALUES('&Student_id', '&Name', '&Date_of_birth', '&Email')
new   1: INSERT INTO Student VALUES('S03', 'Midhun', '01-Jun-2000', 'midhun@something.com')

1 row created.

SQL> INSERT INTO Course VALUES ('&Course_id', '&Title', '&Credit_hours');
Enter value for course_id: C01
Enter value for title: Mathematics
Enter value for credit_hours: 48
old   1: INSERT INTO Course VALUES ('&Course_id', '&Title', '&Credit_hours')
new   1: INSERT INTO Course VALUES ('C01', 'Mathematics', '48')

1 row created.

SQL> /
Enter value for course_id: C02
Enter value for title: English
Enter value for credit_hours: 48
old   1: INSERT INTO Course VALUES ('&Course_id', '&Title', '&Credit_hours')
new   1: INSERT INTO Course VALUES ('C02', 'English', '48')

1 row created.

SQL> /
Enter value for course_id: C03
Enter value for title: Statistics
Enter value for credit_hours: 48
old   1: INSERT INTO Course VALUES ('&Course_id', '&Title', '&Credit_hours')
new   1: INSERT INTO Course VALUES ('C03', 'Statistics', '48')

1 row created.

SQL> /
Enter value for course_id: C04
Enter value for title: Probability
Enter value for credit_hours: 48
old   1: INSERT INTO Course VALUES ('&Course_id', '&Title', '&Credit_hours')
new   1: INSERT INTO Course VALUES ('C04', 'Probability', '48')

1 row created.

SQL> INSERT INTO Enrollment VALUES('&Enrollment_id', '&Student_id', '&Course_id', '&Enrollment_date');

Enter value for enrollment_id: E01
Enter value for student_id: S01
Enter value for course_id: C01
Enter value for enrollment_date: 01-JUN-2020
old   1: INSERT INTO Enrollment VALUES('&Enrollment_id', '&Student_id', '&Course_id', '&Enrollment_date')
new   1: INSERT INTO Enrollment VALUES('E01', 'S01', 'C01', '01-JUN-2020')

1 row created.

SQL> /
Enter value for enrollment_id: E02
Enter value for student_id: S02
Enter value for course_id: C02
Enter value for enrollment_date: 01-JUN-2020
old   1: INSERT INTO Enrollment VALUES('&Enrollment_id', '&Student_id', '&Course_id', '&Enrollment_date')
new   1: INSERT INTO Enrollment VALUES('E02', 'S02', 'C02', '01-JUN-2020')

1 row created.

SQL> SELECT Name, Title
  2  FROM Student
  3  JOIN
  4     Enrollment ON Enrollment.Student_id = Student.Student_id
  5  JOIN
  6     Course ON Enrollment.Course_id = Course.Course_id
  7  ;

NAME                 TITLE
-------------------- --------------------
Arjun                Mathematics
Sharon               English

SQL>
```

## Viva Voice

1. **SQL Query Explanation:**
   - Explain the purpose and functionality of the SQL query you wrote for retrieving students along with their enrolled courses.
   - How does the `JOIN` operation work in this query, and why is it necessary?

2. **Table Relationships:**
   - Describe the relationships between the `Student`, `Enrollment`, and `Course` tables in the context of this query.
   - How are foreign keys utilized to establish these relationships?

3. **Result Analysis:**
   - Given a set of sample data, walk through the expected result of the query and explain each column.
   - How would the result change if there were no enrollments for a particular student?

4. **Alternate Query:**
   - Propose an alternative SQL query that achieves the same result but uses a different syntax or approach.
   - Discuss the pros and cons of your alternative query compared to the original one.

5. **Performance Considerations:**
   - How might the performance of this query be affected as the size of the database tables (Student, Enrollment, Course) grows?
   - What indexes could be added to optimize the performance of this query?

6. **Data Integrity:**
   - How does the query ensure data integrity, particularly when joining tables based on foreign keys?
   - Discuss potential issues that might arise if there were inconsistencies in the data.

7. **Handling NULL Values:**
   - How does the query handle situations where a student is not enrolled in any course or a course has no enrollments?
   - What modifications could be made to the query to address such scenarios?

8. **Projection and Aliases:**
   - Explain why column aliases (`AS Student_Name` and `AS Course_Title`) are used in the SELECT clause of the query.
   - Can you run the query without using aliases? What would be the result?

9. **Extending the Query:**
   - Propose modifications to the query to include additional information, such as enrollment dates or other details.
   - Discuss the impact of these modifications on the query and its results.

10. **Real-world Application:**
    - In a real-world scenario, how could the results of this query be used or displayed in an application or reporting system?
    - Discuss potential user scenarios where this type of query is useful.