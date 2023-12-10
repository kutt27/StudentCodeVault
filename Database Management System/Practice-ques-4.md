### **Practice Question 4: Advanced SQL Queries**

**Requirement:**
1. Assume that the university database schema (Student, Course, Enrollment) is already created.
2. Perform the following SQL operations:

    a. Retrieve a list of students who are enrolled in more than one course.
    b. Find the course with the highest number of enrollments and retrieve the course details.
    c. Calculate the average credit hours of all courses.

**Your Task:**
1. Write the SQL commands to accomplish the above operations.
2. Provide the expected output or result for each query.
---

## Syntax

```sql
--a.
SELECT 
	Student.Name, 
	Student.Student_id, 
	COUNT(Enrollment.Course_id) 
FROM 
	Student
JOIN
	Enrollment ON Student.Student_id = Enrollment.Student_id;
GROUP BY
	Student.Student_id, Student.Name
HAVING
	COUNT(Enrollment.Course_id) > 1;

--b.
SELECT 
	Course.Course_id,
	Course.Title,
	COUNT(Enrollment.Student_id) AS COUNT
FROM
	Course
LEFT JOIN 
	Enrollment ON Course.Course_id = Enrollment.Course_id
GROUP BY
	Course.Course_id, Course.Title
ORDER BY
	COUNT DESC
FETCH FIRST 1 ROW ONLY;

--c.
SELECT
	AVG(Credit_hours) AS Average_credit_hours
FROM 
	Course;
```

## Output

```text
SQL> SELECT
  2      Student.Student_id,
  3      Student.Name,
  4      COUNT(Enrollment.Course_id) AS Enrolled_Courses_Count
  5  FROM
  6      Student
  7  JOIN
  8      Enrollment ON Student.Student_id = Enrollment.Student_id
  9  GROUP BY
 10      Student.Student_id, Student.Name
 11  HAVING
 12      COUNT(Enrollment.Course_id) > 1;

no rows selected

SQL> SELECT
  2     Course.Course_id,
  3     Course.Title,
  4     COUNT(Enrollment.Student_id) AS COUNT
  5  FROM
  6     Course
  7  LEFT JOIN
  8     Enrollment ON Course.Course_id = Enrollment.Course_id
  9  GROUP BY
 10     Course.Course_id, Course.Title
 11  ORDER BY
 12     COUNT DESC
 13  FETCH FIRST 1 ROW ONLY;

COURSE_I TITLE                     COUNT
-------- -------------------- ----------
C01      Mathematics                   1

SQL> SELECT
  2     AVG(Credit_hours) AS Average_credit_hours
  3  FROM
  4     Course;

AVERAGE_CREDIT_HOURS
--------------------
                  37

SQL>
```

## Viva Voice
### For the Query: Retrieve a list of students who are enrolled in more than one course.

1. **Group By and Aggregate Functions:**
   - Explain the purpose of the `GROUP BY` clause in this query.
   - Why is the `COUNT` function used, and what does it signify in this context?

2. **HAVING Clause:**
   - How does the `HAVING` clause differ from the `WHERE` clause in SQL?
   - Why is the `HAVING` clause used in this specific query?

3. **Result Interpretation:**
   - Given a set of sample data, walk through the expected result of this query.
   - What would happen if the `HAVING` clause condition was set to `COUNT(Enrollment.Course_id) = 1`?

4. **Alternative Approaches:**
   - Propose an alternative way to achieve the same result without using the `HAVING` clause.
   - Discuss the pros and cons of your alternative approach.

### For the Query: Find the course with the highest number of enrollments and retrieve the course details.

1. **LEFT JOIN:**
   - Explain the significance of using a `LEFT JOIN` in this query.
   - How would the result change if an `INNER JOIN` was used instead?

2. **Ordering and Fetching Rows:**
   - Discuss the purpose of the `ORDER BY` clause in this query.
   - Why is the `FETCH FIRST 1 ROW ONLY` clause used instead of `LIMIT 1`?

3. **Result Analysis:**
   - Given a set of sample data, walk through the expected result of this query.
   - How would the result change if multiple courses had the same highest enrollment count?

4. **Performance Considerations:**
   - How might the performance of this query be affected as the size of the `Course` and `Enrollment` tables grows?
   - What indexes could be added to optimize the performance of this query?