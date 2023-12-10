### **Practice Question 1: Design a Normalized Database Schema**

**Requirement:**
Design a normalized database schema for the following requirement:

A university wants to maintain the record of students, courses, and enrollments in a database. Each student has a unique student ID, name, date of birth, and email. Each course has a unique course ID, title, and credit hours. Students can enroll in multiple courses, and each enrollment has a unique enrollment ID, the student ID of the enrolled student, the course ID of the enrolled course, and the enrollment date.

**Your Task:**
1. Create a normalized database schema with proper tables, columns, column types, and constraints.
### **Database Schema:**

```plaintext
STUDENT (Student_ID, Name, Date_of_Birth, Email)
COURSE (Course_ID, Title, Credit_Hours)
ENROLLMENT (Enrollment_ID, Student_ID, Course_ID, Enrollment_Date)
```

**Constraints:**
- `Student_ID` is the primary key in the STUDENT table.
- `Course_ID` is the primary key in the COURSE table.
- `Enrollment_ID` is the primary key in the ENROLLMENT table.
- `Student_ID` in the ENROLLMENT table is a foreign key referencing the STUDENT table.
- `Course_ID` in the ENROLLMENT table is a foreign key referencing the COURSE table.
- `Enrollment_Date` should be constrained to ensure a valid date.

---
## Syntax

```sql Student table
-- Student Table
CREATE TABLE Student(
	Student_id VARCHAR(8) PRIMARY KEY, 
	Name VARCHAR(20), 
	Date_of_birth DATE, 
	Email VARCHAR(20)
);

-- Course Table
CREATE TABLE Course(
	Course_id VARCHAR(8) PRIMARY KEY, 
	Title VARCHAR(20), 
	Credit_hours NUMBER(3)
);

-- Enrollment Table
CREATE TABLE Enrollment(
	Enrollment_id VARCHAR(8) PRIMARY KEY, 
	Student_id VARCHAR(8), 
	Course_id VARCHAR(8),
	Enrollment_date DATE NOT NULL,
	FOREIGN KEY (Student_id) REFERENCES Student(Student_id),
	FOREIGN KEY (Course_id) REFERENCES Course(Course_id)
);
```

## Output

```plain-text
SQL> CREATE TABLE Student(
  2     Student_id VARCHAR(8) PRIMARY KEY,
  3     Name VARCHAR(20),
  4     Date_of_birth DATE,
  5     Email VARCHAR(20)
  6  );

Table created.

SQL> DESC Student
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 STUDENT_ID                                NOT NULL VARCHAR2(8)
 NAME                                               VARCHAR2(20)
 DATE_OF_BIRTH                                      DATE
 EMAIL                                              VARCHAR2(20)

SQL> CREATE TABLE Course(
  2     Course_id VARCHAR(8) PRIMARY KEY,
  3     Title VARCHAR(20),
  4     Credit_hours NUMBER(3)
  5  );

Table created.

SQL> DESC Course
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 COURSE_ID                                 NOT NULL VARCHAR2(8)
 TITLE                                              VARCHAR2(20)
 CREDIT_HOURS                                       NUMBER(3)

SQL> CREATE TABLE Enrollment(
  2     Enrollment_id VARCHAR(8) PRIMARY KEY,
  3     Student_id VARCHAR(8),
  4     Course_id VARCHAR(8),
  5     Enrollment_date DATE NOT NULL,
  6     FOREIGN KEY (Student_id) REFERENCES Student(Student_id),
  7     FOREIGN KEY (Course_id) REFERENCES Course(Course_id)
  8  );

Table created.

SQL> DESC Enrollment
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 ENROLLMENT_ID                             NOT NULL VARCHAR2(8)
 STUDENT_ID                                         VARCHAR2(8)
 COURSE_ID                                          VARCHAR2(8)
 ENROLLMENT_DATE                           NOT NULL DATE

SQL>
```

## Viva-Voice Questions

1. **Normalization:**
   - Explain the concept of normalization and how it applies to the design of the university database schema.
   - Which normal form(s) does the university database schema adhere to, and why is normalization important?

2. **Primary Keys and Foreign Keys:**
   - Why is it important to have primary keys in the tables, and how are they defined in the university database schema?
   - Describe the role of foreign keys in the database schema. Give examples of foreign keys in the Enrollment table.

3. **Data Types and Constraints:**
   - Explain the choice of data types for columns like `Date_of_birth`, `Enrollment_date`, and `Credit_hours`.
   - Why is it essential to include constraints like `NOT NULL` in the `Enrollment_date` column?

4. **ER Diagram:**
   - How does the university database schema translate into an Entity-Relationship (ER) diagram?
   - Discuss the relationships between entities in the ER diagram and how they are represented.

5. **Table Relationships:**
   - Explain the relationships between the `Student`, `Course`, and `Enrollment` tables.
   - How are referential integrity and relationships maintained in the database schema?

6. **Normalization Process:**
   - Walk through the steps of the normalization process for a specific table in the university database schema.
   - Discuss any trade-offs or considerations made during the normalization process.

7. **Enrollment Process:**
   - Describe the enrollment process for a student in the university. How does it translate into database operations?
   - How does the `Enrollment` table capture information about student enrollment in courses?

8. **Data Integrity:**
   - How does the university database schema ensure data integrity, especially with respect to foreign keys?
   - What steps can be taken to prevent or handle data inconsistencies in the database?

9. **Query Scenarios:**
   - Given the database schema, provide a SQL query to retrieve the list of students enrolled in a specific course.
   - Write a query to find courses with the highest number of enrollments.

10. **Schema Modification:**
    - If a new requirement arises, such as adding a new field to the `Student` table, how would you modify the database schema?
    - Discuss the potential challenges and considerations in modifying the schema.