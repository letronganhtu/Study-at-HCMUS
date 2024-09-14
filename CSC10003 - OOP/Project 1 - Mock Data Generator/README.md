# Project 1: Mock data generator

## Full name: Lê Trọng Anh Tú - ID: 20127091

All things I listed below are what I have done in this project:

**1. Read all students saved in the file back into a vector of Student**

- With class `StudentDataReader`, I use one private member is the name of file to know what is the file I want to read them.

- `readAll()` will find the name of file and start to read file, also save data they read into `vector<Student>`.

**2. Generate randomly a number**

- I created class `RandomIntegerGenerator` in `RandomIntegerGenerator.cpp` & `RandomIntegerGenerator.h` to do this task with 3 random versions.

- In `main.cpp`, I use `int n = rng.next(5, 10)` to randomize a number in the range of [5, 10] - which is the last random version of a class (this version creates number in the range of [left, right]).

**3. Generate student randomly**

- To do this task, I created and used class `RandomStudentGenerator`

- Firstly, I have to add class `Student` in `Student.h` and `Student.cpp` to know what is **a student**. **A student** consists of *student's ID, name, GPA, phone number, email, date of birth and address*.

    - I created class `Date` in `Date.cpp` & `Date.h` which includes *day, month and year* to store date of birth of a student.

    - Also I created class `Address` in `Address.h` & `Address.cpp` to store address. `Address` includes *number, name of street, ward, district and city* where student lives.

- As we have created `RandomIntegerGenerator` before, we use it to random *student's ID* in the range of **[2127000, 2127999]**. 

    - Two first digits represent for students who study as the first year at this school in 2021. 
    
    - Two next digits represent what major you study. 
    
    - And the last 3 digit represent each student in this class. It's unique from each others. 

- After that we created `RandomNameGenerator` to random name of the student. 

    - By using 3 array, we can random some integer to allocate as index of the array. 
    
    - Also the name we random is also created 1 unique email for this student. So I use `tuple<string, string>` represent for name and email of student.

- `RandomGPA` to create random GPA in the range of **[0.00, 10.00]**.

- `RandomPhone`: Format of Phone is **09xx-xxx-xxx**, where x is a digit of number so we random x to create phone number.

- `randomDob` to random day and month in 2003.

- `randomStudentAddress` has the same idea as `randomName`, with data I created is an array, we random the number and use it as index in this array.

- Finally, `randomStudent()` will random one student with all above things we have done before.

**4. Overwrite and save the students back to "students.txt"**

- With data I have randomized before, add them into `vector<Student>`.

- Now with class `StudentDataWriter`, I pass the filename into and call `writeAll(vector<Student>)` to write all data which is saved in vector into text file.

**5. Print out the average GPA and all the students have a GPA greater than average GPA**

- At the end of `Student` class, I created 2 function `calculateAverageGPA` and `GreaterThanAverageUIConverter` to do final requirement in the project.

Notice in `main.cpp`:

- Line 36-44, I add code to know what is a data of my student and check if there is any error when I write them into text file.

- In Release forder, you can't run file `*.exe` without any text file. At least you must create `students.txt` or you can keep `*.pdb` I create in Release to let `*.exe` know to create text file by themselves.

Notice in `Date.cpp`:

- If the program can't execute, **right click** in the project, choose **Properties** (the last) -> **C/C++** -> **Preprocessor** -> In the first line (Preprocessor Definitions) we add `_CRT_SECURE_NO_WARNINGS` and then OK. Run program again and it will be execute.

Link video demo: https://youtu.be/Ks6pBYFxYJI

Expect grade in project 1: 10