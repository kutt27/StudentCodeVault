### **Practice Question 3: Data Modification and Retrieval**

**Requirement:**
1. Assume that the university database schema (Student, Course, Enrollment) is already created.
2. Perform the following SQL operations:

    a. Update the `Credit_hours` for the course with `Course_id = 'C01'` to 4.
    b. Delete the enrollment of the student with `Student_id = 'S02'` from the `Enrollment` table.
    c. Retrieve the list of courses along with the total number of students enrolled in each course.

**Your Task:**
1. Write the SQL commands to accomplish the above operations.
2. Provide the expected output or result for each query.

---
## Syntax

```sql
UPDATE Course SET Credit_hours = 4 
WHERE Course_id = 'C01';

DELETE FROM Enrollment
WHERE Student_id = 'S02';

SELECT
    Course.Course_id, Course.Title, COUNT(Enrollment.Student_id) AS Total_Students
FROM
    Course
LEFT JOIN
    Enrollment ON Course.Course_id = Enrollment.Course_id
GROUP BY
    Course.Course_id, Course.Title;

```

## Output

```text
SQL> UPDATE Course SET Credit_hours = 4
  2  WHERE Course_id = 'C01';

1 row updated.

SQL> SELECT * FROM Course;

COURSE_I TITLE                CREDIT_HOURS
-------- -------------------- ------------
C01      Mathematics                     4
C02      English                        48
C03      Statistics                     48
C04      Probability                    48

SQL> DELETE FROM Enrollment
  2  WHERE Student_id = 'S02';

1 row deleted.

SQL> SELECT * FROM Enrollment;

ENROLLME STUDENT_ COURSE_I ENROLLMEN
-------- -------- -------- ---------
E01      S01      C01      01-JUN-20

SQL> SELECT
  2      Course.Course_id, Course.Title, COUNT(Enrollment.Student_id) AS Total_Students
  3  FROM
  4      Course
  5  LEFT JOIN
  6      Enrollment ON Course.Course_id = Enrollment.Course_id
  7  GROUP BY
  8      Course.Course_id, Course.Title;

COURSE_I TITLE                TOTAL_STUDENTS
-------- -------------------- --------------
C01      Mathematics                       1
C04      Probability                       0
C02      English                           0
C03      Statistics                        0

SQL>
```

## Viva-Voice

1. **Update Operation:**
   - Explain the purpose of the update operation in the context of the university database schema.
   - How does the `UPDATE` statement modify data in the `Course` table, and what precautions should be taken when using it?
2. **Delete Operation:**
   - Discuss the significance of the delete operation in a database and why it might be necessary.
   - How does the `DELETE` statement remove data from the `Enrollment` table, and what are the potential consequences?
3. **Join Operation in Retrieval:**
   - Explain the role of the `LEFT JOIN` in the third query and why it is used.
   - What would happen if a different type of join (e.g., `INNER JOIN` or `RIGHT JOIN`) were used in this query?
4. **Grouping and Aggregation:**
   - Describe the purpose of the `GROUP BY` clause in the third query.
   - How does the `COUNT` function contribute to obtaining the total number of students enrolled in each course?
5. **Data Modification and Integrity:**
   - How do the update and delete operations impact data integrity in the database?
   - Discuss scenarios where these operations might need to be performed to maintain data accuracy.
6. **Concurrency and Transactions:**
   - How would you handle these data modification operations in a scenario where multiple users are simultaneously interacting with the database?
   - What is the role of transactions in ensuring consistency during data modifications?
7. **Handling Errors:**
   - How should errors during data modification operations be handled to maintain the integrity of the database?
   - Can you think of situations where the update or delete operation might fail?
8. **Security Considerations:**
   - Discuss security considerations related to data modification operations, especially when executed by end-users or applications.
   - What permissions or access controls are typically required to perform these operations?
9. **Real-world Application:**
   - In a real-world application, how might the update and delete operations be triggered? Provide examples of user scenarios.
   - Discuss the importance of accurate data retrieval, especially when presenting information to end-users.
10. **Optimizing Queries:**
    - How would you optimize the third query to improve its performance, especially as the size of the database tables grows?
    - Discuss the use of indexes or other techniques to enhance the efficiency of retrieval operations.