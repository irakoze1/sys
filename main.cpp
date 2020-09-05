//
//  main.cpp
//  C++Pro
//
//  Created by Tititof Irakoze on 9/5/20.
//  Copyright © 2020 Tititof Irakoze. All rights reserved.
//
#include <iostream>
#include <cassert>
#include "Stundets.h"
#include <vector>
#include <cstring>
#include "TextTable.h"
using namespace std;

void menu_Display();
void handle();
void print_vec(vector<int> v);
int lenght = 0;

void change_character( Student S);
vector<Student>
stundent_manage_creat();
void student_manage_display(vector<Student>, int j);
void student_manage_av(vector<Student>);
void student_manage_best(vector<Student>);
void student_best_mark_course(vector<Student>);
void student_bad_mark_course(vector<Student>);
void student_display_av(vector<Student>);
void student_manage();
void student_manage_menu();

void course_credit_manage();
void marks_menu();
Course * marks_manage_create();
void marks_Display(Course *size);
Course * marks_modify(Course *size, int j);
int marks_av(Course *size);
int marks_best(Course *size);
int marks_bad(Course *size);
vector<int>
marks_bellow_av(Course *size);
vector<int>
marks_above_av(Course *size);


void course_credit_manage()
{
    cout << "------- Course Credit Manage --------- \n";
    int size = 0;
    do {
        cout << "Enter Size [6,15]:";
        cin >> size;
    } while (size < 6 && size > 16);
    int n = size + 1;
    int sum = 0;
    Course C[size];
    while (size > 0) {
        cout << "--------- Course N0" << n - size << "------------"<< endl;
        cout << "Enter The Credit:";
        cin >> C[n - size - 1].credit;
        cout << "Enter The Title: ";
        cin >> C[n - size - 1].Title;
        
        sum += C[n - size - 1].credit;
        size--;
    }
    assert(sum == 30 && "Credit Must be equal 30");
    size = n - 1;
    
    cout << "-----------------Result--------------"<<endl;
    while (size > 0) {
        cout << "Course " << n - size << "Title" << C[n - size - 1].Title;
        cout << "Course " << n -size << " Credit: "<< C[n- size - 1].credit;
        
    }
}


// Manage Marks
Course *
marks_manage_create()
{
    lenght = 0;
    int size = 0;
    Course *C = new Course();
    cout << "--------- Course Marks To Manage -----"<<endl;
    cout << "Enter Number of Course:";
    cin >> size;
    int n = size + 1;
    while (size){
        cout << "Enter The Title of Course " << n - size << ":"<< C[n - size].Title<<endl;
        cout << "Enter The Mark of the Student in Course" << n- size << ":"<< C[n - size].Mark<<endl;
        lenght += 1;
        size --;
    }
    return C;
}
void marks_Display(Course *size)
{
    int l = lenght;
    while (l) {
        cout << lenght - l + 1 << "Title:" << size[lenght - l].Title << ", Marks: " << size[lenght - l].Mark << endl;
        l--;
    }
}

Course *
marks_modify(Course *size, int j)
{
    cout << "New Mark:";
    cin >> size[j].Mark;
    return size;
}


int marks_av(Course *size)
{
    int l = lenght;
    int total = 0;
    while (l) {
      total += size[lenght - l].Mark;
       l--;
    }
    return total / lenght;
}


int marks_best(Course *size)
{
    int l = lenght;
    int best = 0;
    while (l) {
        if (size[lenght - 1].Mark > best) {
            best = size[lenght - 1].Mark;
        }
        l--;
    }
    return best;
}


int marks_bad(Course *size)
{
    int l = lenght;
    int bad = 0;
    while (l) {
        if (size[lenght - 1].Mark < bad) {
            bad = size[lenght - 1].Mark;
        }
        l--;
    }
    return bad;
}

vector<int>
marks_bellow_av(Course *size)
{
    vector<int> bel_av;
    int l = lenght;
    int av = marks_av(size);
    while (l) {
        if (size[lenght -1].Mark < av) {
            bel_av.push_back(size[lenght -  l].Mark);
        }
        l--;
    }
    return bel_av;
}

vector<int>
marks_above_av(Course *size)
{
    vector<int> ab_av;
    int l = lenght;
    int av = marks_av(size);
    while (l) {
        if (size[lenght -1].Mark < av) {
            ab_av.push_back(size[lenght -  l].Mark);
        }
        l--;
    }
    return ab_av;
}






//Stundent Manage
void student_manage()
{
    Date D;
    cout << "-------- Student Manage------------" << endl;
    cout << "Enter Year:";
    cin >> D.year;
    cout << "Enter Month:";
    cin >> D.month;
    cout << "Enter Day:";
    cin >> D.day;
    assert(D.Valid() && "The date is note Valid");
    D.print();
    cout << " --------------------Create Student---------------------- ";
    cout << "Enter Name:";
    string name;
    cin >> name;
    cout << "Enter Username:";
    string username;
    cin >> username;
    cout << "Enter Address:";
    string address;
    cin >> address;
    cout << "Enter The Registrat Number:";
    int r = 0;
    cin >> r;
    int size =  0;
    int n = size + 1;
    do {
        cout << "Enter Size [6,15]:";
        cin >> size;
    } while (size > 6 && size < 15);
    
    Course cc[size];
    while (size > 0) {
        cout << "------ Course N "<< n - size << endl;
        cout << "Enter The Credit :";
        cin >> cc[n - size - 1].credit;
        cout << "Enter The Title: ";
        cin >> cc[n - size - 1].Title;
        cout << "Enter Mark:";
        cin >> cc[n - size -1].Mark;
        size--;
    }
    Student S = Student(r, name, username, address, cc, D);
    cout << "Name:" << S.name << endl;
    cout << "UserName:" << S.username << endl;
    cout << "Address:" << S.address << endl;
    cout << "Registration Number:" << S.regstNum << endl;
    S.date_Birth.print();
    cout << "Do You Wish To Modify Student Characteristics?Yes/No";
    string Answer;
    cin >> Answer;
    if (Answer == "yes" || Answer == "y" || Answer == "Yes") {
        change_character(S);
    }
}

void change_character(Student S)
{
    cout << "Name:";
    cin >> S.name;
    cout << "UserName:";
    cin >> S.username;
    cout << "Address:";
    cin >> S.address;
    cout << "Registrat Number:";
    cin >> S.regstNum;
    cout << "Year:";
    cin >> S.date_Birth.year;
    cout << "Month:";
    cin >> S.date_Birth.month;
    cout << "Day:";
    cin >> S.date_Birth.day;
}

vector<Student>
stundent_manage_creat()
{
    vector<Student> all;
    cout << "Enter The Number of Students:";
    int n;
    cin >> n;
    int m = n + 1;
    int regstNum = 0;
    char *name = new char();
    char *surname = new char();
    char *address = new char();
    Date dt;
    Course *course_marks = new Course();
    assert(n > 0 && "Size must be greater than 0");
    while (n) {
        cout<< "---- Student number ----" << m - n << "\n";
        cout<< "Enter the name:";
        cin >> name;
        cout<< "Enter the surname:";
        cin >> surname;
        cout<< "Enter the Registration Number:";
        cin >> regstNum;
        cout<< "Enter the day of birth:";
        cin >> dt.day;
        cout<< "Enter the month of birth:";
        cin >> dt.month;
        cout<< "enter the year of birth:";
        cin >> dt.year;
        course_marks = marks_manage_create();
        all.push_back(
            Student(regstNum, name, surname, address, course_marks, dt));
        n--;
    }
    return all;
}

void student_manage_display(vector<Student> v, int n)
{
    cout << "------------- Diplay " << n << " Students ----------"<< endl;
    int m = n;
    while (m) {
        cout << "Student Number " << n - m + 1 << endl;
        cout << "Name:" << v[n - m].name << endl;
        cout << "UserName:" << v[n - m].username << endl;
        cout << "Address:" << v[n - m].address << endl;
        v[n - m].date_Birth.print();
        cout << "--------------- Course ------------"<<endl;
        marks_Display(v[n - m].courseMark);
        m--;
        
    }
}

void student_av_mark_course(vector<Student> v)
 {
     int n = v.size();
     int m = n;
     while (m) {
         cout << "The Average Mark of " << v[n - m].name << " "
         << v[n - m].username << " is "<< marks_av(v[n - m].courseMark);
              m--;
     }
 }


 void
student_best_mark_course(vector<Student> v)
 {
     int n = v.size();
     int m = n;
     while (m) {
         cout << "The Best Mark of " << v[n - m].name << " "
         << v[n - m].username<< " is "
         << marks_best(v[n - m].courseMark);
              m--;
     }
 }


 void
student_bad_mark_course(vector<Student> v)
 {
     int n = v.size();
     int m = n;
     while (m) {
         cout << "The Bad Mark of " << v[n - m].name << " "
              << v[n - m].username << " is "
         << marks_bad(v[n - m].courseMark)<<endl;
              m--;
     }
 }
void student_manage_menu(){
bool loop=true;
    vector<Student> nst;
    TextTable t('-', '|', '#');
    t.add("Marks Manage Menu");
    TextTable menu('-', ' ', ' ');
    t.endOfRow();
    menu.add("Enter 1 for");
    menu.add("Student Manage Creation");
    menu.endOfRow();
    menu.add("Enter 2 for");
    menu.add("Student Manage Display");
    menu.endOfRow();
    menu.add("Enter 3 for");
    menu.add("Student Manage Average Of Each Student");
    menu.endOfRow();
    menu.add("Enter 4 for");
    menu.add("Best Student Manage Of Each Student");
    menu.endOfRow();
    menu.add("Enter 5 for");
    menu.add("Bad Marks Manage  Of Each Student");
    menu.endOfRow();
    menu.add("Enter 6 for");
    menu.add("Best Student Management Of Each Course");
    menu.endOfRow();
    menu.add("Enter 7 for");
    menu.add("Bad Student Management Of Each Course");
    menu.add("Enter 8 to");
    menu.add("CLose");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout << t << menu;
    int choice;
    int n;
    while (loop) {
        cout << "Enter your choice> ";
        cin >> choice;
        switch (choice) {
            case 1:
                nst=stundent_manage_creat();
                break;
            case 2:
                 cout<< "Enter the number n of students to display> ";
                 cin>>n;
                student_manage_display(nst,n);
                 break;
            case 3:
                student_av_mark_course(nst);
                 break;
            case 4:
                student_best_mark_course(nst);
                 break;
            case 5:
                student_bad_mark_course(nst);
                  break;
            case 6:
                  cout<< "coming soon\n";
                  break;
            case 7:
                  cout<<"coming soon\n";
                  break;
            case 8:
                  loop=false;
                  break;
            default:
                 continue;
                 break;

        }
 
}
}

void menu_Display()
{
    TextTable t('-', '|', '#');
    t.add("List Of Available Operations");
    TextTable menu('-', ' ', ' ');
    t.endOfRow();
    menu.add("Enter 1 for");
    menu.add("Course Credit Management");
    menu.endOfRow();
    menu.add("Enter 2 for");
    menu.add("Student Management");
    menu.endOfRow();
    menu.add("Enter 3 for");
    menu.add("Course Marks Management");
    menu.endOfRow();
    menu.add("Enter 4 for");
    menu.add("Class student Management");
    menu.endOfRow();
    menu.add("Enter 5 to");
    menu.add("Exit");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout << t << menu;
}


void handle()
{
    bool loop = true;
    while (loop) {
        cout << "Enter Choice:";
        int n;
        cin >> n;
        switch (n) {
            case 1:
                course_credit_manage();
                break;
            case 2:
                student_manage();
            case 3:
                marks_menu();
            case 4:
                student_manage_menu();
            case 5:
                loop=false;
                
            default:
                cout << "Choice Invalid";
                break;
        }
    }
}


void
print_vec(std::vector<int> v)
{
    int r = v.size();
    int n = r;
    while (n) {
        cout << v[r - n];
        n--;
    }
    cout << "\n";
}


void
marks_menu()
{
    Course *marks = nullptr;
    std::vector<int> v;
    bool loop = true;
    int capture;
    TextTable t('-', '|', '#');
    t.add("Marks Management Menu");
    TextTable menu('-', ' ', ' ');
    t.endOfRow();
    menu.add("Enter 1 for");
    menu.add("Marks Management Creation");
    menu.endOfRow();
    menu.add("Enter 2 for");
    menu.add("Marks Management Displaying");
    menu.endOfRow();
    menu.add("Enter 3 for");
    menu.add("Marks Management Average");
    menu.endOfRow();
    menu.add("Enter 4 for");
    menu.add("Marks Management Best");
    menu.endOfRow();
    menu.add("Enter 5 for");
    menu.add("Marks Management Worst");
    menu.endOfRow();
    menu.add("Enter 6 for");
    menu.add("Marks Management Above Average");
    menu.endOfRow();
    menu.add("Enter 7 for");
    menu.add("Marks Management Below Average");
    menu.endOfRow();
    menu.add("Enter 8 to");
    menu.add("CLose");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout << t << menu;
    int choice;
    while (loop) {
        cout << "Enter your choice> ";
        cin >> choice;
        switch (choice) {
            case 1:
                marks = marks_manage_create();
                break;
            case 2:
                marks_Display(marks);
                break;
            case 3:
                capture = marks_av(marks);
                cout << "The Average mark is" << capture << "\n";
                break;
            case 4:
                capture = marks_best(marks);
                cout << "The best mark is" << capture << endl;
                break;
            case 5:
                capture = marks_bad(marks);
                cout <<"The Worst mark is" << capture << endl;
                break;
            case 6:
                print_vec(marks_above_av(marks));
                break;
            case 7:
                print_vec(marks_bellow_av(marks));
                break;
            case 8:
                loop = false;
                break;
            default:
                continue;
                break;
        }
    }
}

int main()
{
    cout<< "School Managemt system"<<endl;
    menu_Display();
    handle();
}
