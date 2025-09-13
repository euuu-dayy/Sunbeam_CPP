#include<iostream> 
#include<vector> 
using namespace std;

class Course {
private: 
    int cid; 
    string name; 
    double fees; 
public: 
    Course() { }
    Course(int cid , string name , double fees) {
        this->cid = cid; 
        this->name = name; 
        this->fees = fees; 
    }
    void acceptCourse() {
        cout << "Enter Course ID: "; 
        cin >> cid; 
        cout << "Enter Course Name: "; 
        cin >> name; 
        cout << "Enter Course Fees: "; 
        cin >> fees; 
    }
    void displayCourse() {
        cout << "Cid : " << cid << endl; 
        cout << "Name : " << name << endl; 
        cout << "Fees : " << fees << endl; 
    }
    int getCid() {
        return this->cid; 
    }
}; 

class Student {
private: 
    int roll; 
    string name; 
    vector<Course*> course_taken; 
public: 
    Student() { }
    Student(int roll , string name) {
        this->roll = roll; 
        this->name = name; 
    }
    void acceptStudent() {
        cout << "Enter Roll No: "; 
        cin >> roll; 
        cout << "Enter Name: "; 
        cin >> name; 
    }
    void displayStudent() {
        cout << "Roll : " << roll << endl; 
        cout << "Name : " << name << endl; 
    }
    void addCourse(Course* course) {
        course_taken.push_back(course); 
    }
    int getRoll() {
        return this->roll; 
    }
    vector<Course*> &getCourseTaken() {
        return course_taken; 
    }
}; 

void displayAllCourses(vector<Course*> &course_list) {
    for(int i = 0 ; i < course_list.size() ; i++)
        course_list[i]->displayCourse(); 
}

void purchaseCourse(vector<Course*> &course_list, vector<Student*> &student_list) {
    bool found = false; 
    int roll; 
    cout << "Enter the roll : "; 
    cin >> roll; 
    for(int i = 0 ; i < student_list.size(); i++) {
        if(roll == student_list[i]->getRoll()) {
            found = true; 
            displayAllCourses(course_list); 
            int cid; 
            cout << "Enter the cid : "; 
            cin >> cid; 
            for(int j = 0 ; j < course_list.size(); j++) {
                if(cid == course_list[j]->getCid()) {
                    student_list[i]->addCourse(course_list[j]); 
                }
            }
            break; 
        }
    }
    if(!found)
        cout << "Student not found" << endl; 
}

void displayAllStudentsAlongWithCourseTaken(vector<Student*> &student_list) {
    for(int i = 0 ; i < student_list.size(); i++) {
        student_list[i]->displayStudent(); 
        displayAllCourses(student_list[i]->getCourseTaken());  
    }
}

void courseTakenBySpecificStudent(vector<Student*> &student_list) {
    int roll; 
    cout << "Enter roll: "; 
    cin >> roll; 
    for(int i = 0 ; i < student_list.size(); i++) {
        if(roll == student_list[i]->getRoll()) {
            student_list[i]->displayStudent(); 
            displayAllCourses(student_list[i]->getCourseTaken()); 
        }
    }
}

int main() {
    int choice; 
    vector<Course*> course_list; 
    vector<Student*> student_list; 

    do {
        cout << "**********************************************" << endl;
        cout << "0. EXIT" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. Display All Courses" << endl;
        cout << "3. Add Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Purchase a Course" << endl;
        cout << "6. Display all students with their course taken" << endl;
        cout << "7. Display courses taken by the specific student" << endl;
        cout << "Enter your choice - ";
        cin >> choice;
        cout << "**********************************************" << endl;

        switch (choice) {
        case 1: {
            Course* c = new Course();
            c->acceptCourse();
            course_list.push_back(c);
            break;
        }
        case 2: 
            displayAllCourses(course_list); 
            break; 
        case 3: {
            Student* s = new Student();
            s->acceptStudent();
            student_list.push_back(s);
            break; 
        }
        case 4: 
            for(int i = 0 ; i < student_list.size(); i++)
                student_list[i]->displayStudent(); 
            break; 
        case 5: 
            purchaseCourse(course_list, student_list); 
            break; 
        case 6: 
            displayAllStudentsAlongWithCourseTaken(student_list); 
            break; 
        case 7: 
            courseTakenBySpecificStudent(student_list); 
            break; 
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while(choice != 0);

    return 0;
}
