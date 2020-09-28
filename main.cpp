//
//  main.cpp
//  C++Pro
//
//  Created by Tititof Irakoze on 9/5/20.
//  Copyright © 2020 Tititof Irakoze. All rights reserved.
//
#include <iostream>
#include <cassert>
#include "Students.h"
#include <vector>
#include <cstring>
#include "TextTable.h"
#include "progress.h"
#include "rang.hpp"
using namespace std;
using namespace rang;

//Declare All procedure and function we need
void menu_Display();
void principal();
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
void student_display(Student S);
//End off

//create course
void course_credit_manage()
{
    cout << fg::green << "------- Course Credit Manage --------- \n";
    int size = 0;
    int index = 0;
    do {
        cout << fg::green << "Enter Size [6,15]:";
        cin >> size;
    } while (size < 6 || size > 15);
    int n = size + 1;
    
    int sum = 0;
    
    Course C[size];
    while (size > 0) {
        cout << fg::green << "--------- Course N0" << n - size <<" ------------"<< endl;
        
        do{
                cout << rang::fg::green << "Enter The Credit Between 2 And 5 ("<< 30 - sum << " remains): ";
                cin >> C[n - size - 1].credit;
        }while(C[n - size - 1].credit < 2 || C[n - size - 1].credit > 5);
        
        cout << fg::green << "Enter The Title: ";
        cin >> C[n - size - 1].Title;
        sum += C[n - size - 1].credit;
        size--;
    }
    
    size = n - 1;
    
    loop:
    cout << fg::green << "----------------- Result --------------"<<endl;
    for (int i = 0; i<size; i++) {
        cout << fg::green << "Course " << i+1 << " Title: " << C[i].Title << " Credit: "<< C[i].credit<<endl;
    }
    
    if(sum != 30){
        cout <<fg::red << "Credit Must be equal 30 "<<endl;
        cout <<fg::red << "Which Course do you want to Edit?:";
        cin >> index;
        
        Course ti = C[index-1];
        sum -= ti.credit;
        
        cout << fg::green << "Enter new Credit for " << ti.Title << ":";
        cin >> ti.credit;
        C[index-1] = ti;
        
        sum +=ti.credit;
        
        goto loop;
    }
    
}


// Manage Marks
Course *
marks_manage_create()
{
    lenght = 0;
    int size = 0;
    Course *C = new Course();
    cout << rang::fg::green<< "--------- Course Marks To Manage -------"<<endl;
    cout << rang::fg::green<< "Enter Number of Course:";
    cin >> size;
    int n = size + 1;
    while (size){
        cout << rang::fg::green<< "Enter The Title of Course " << n - size << ":"; cin >> C[n - size - 1].Title;

         do{
            cout << rang::fg::green<< "Enter The Mark [0,20] of the Student in Course" << n - size << ":";
            cin >> C[n - size - 1].Mark;
        }while(C[n - size - 1].Mark < 0 || C[n - size - 1].Mark > 20);
        lenght += 1;
        size --;
    }
    return C;
}
void marks_Display(Course *size)
{
    int l = lenght;
    while (l) {
        cout << rang::fg::green<< lenght - l + 1 << ". Title: " << size[lenght - l].Title << ", Marks: " << size[lenght - l].Mark << endl;
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
    int bad = size[0].Mark;
    while (l) {
        if (size[lenght - l].Mark < bad) {
            bad = size[lenght - l].Mark;
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
    if (size[lenght - l].Mark < av) {
        bel_av.push_back(size[lenght - l].Mark);
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
    if (size[lenght - l].Mark < av) {
        ab_av.push_back(size[lenght - l].Mark);
        }
        l--;
    }
    return ab_av;
}

//Stundent Manage
void student_manage()
{
    Date D;
    cout << rang::fg::green<< "-------- Student Manage ------------" << endl;
    cout << rang::fg::green<< "Enter Year:";
    cin >> D.year;
    cout << rang::fg::green<< "Enter Month:";
    cin >> D.month;
    cout << rang::fg::green<< "Enter Day:";
    cin >> D.day;
    if(D.Valid()) cout <<rang::fg::red<< "The date is not Valid"<<endl;
    D.print();
    cout << rang::fg::green<< " -------------------- Create a new Student ----------------------\n ";
    cout << rang::fg::green<< "Enter Name:";
    string name;
    cin >> name;
    cout << rang::fg::green<< "Enter Username:";
    string username;
    cin >> username;
    cout << rang::fg::green<< "Enter Address:";
    string address;
    cin >> address;
    cout << rang::fg::green<< "Enter The Registrat Number:";
    int r = 0;
    cin >> r;
    int size =  0;
      do {
        cout << rang::fg::green<< "Enter Size [6,15] of Course:";
        cin >> size;
    } while (size < 6 || size > 15);
    int n = size + 1;
    Course C[size];
    while (size > 0) {
        cout << rang::fg::green<< "---------- Course N"<< n - size<<" -------------" << endl;

        do{
            cout << rang::fg::green<< "Enter The Credit[2,5] :";
            cin >> C[n - size - 1].credit;
        } while(C[n - size - 1].credit < 2 || C[n - size - 1].credit > 5);
        cout << rang::fg::green<< "Enter The Title: ";
        cin >> C[n - size - 1].Title;

        do{
            cout << rang::fg::green<< "Enter Mark [0,20]:";
            cin >> C[n - size - 1].Mark;
        } while(C[n - size - 1].Mark < 0 || C[n - size - 1].Mark > 20);
       
        size--;
    }
    Student S = Student(r, name, username, address, C, D);
    student_display(S);
    cout << rang::fg::green<< "Do You Wish To Modify Student Characteristics? Yes/No :";
    string Answer;
    cin >> Answer;
    if (Answer == "yes" || Answer == "y"  || Answer == "Y" || Answer == "Yes") {
        change_character(S);
    }
}

void student_display(Student S){
    cout<<"\n\n";
    cout << rang::fg::green<< "Name:" << S.name << endl;
    cout << rang::fg::green<< "UserName:" << S.username << endl;
    cout << rang::fg::green<< "Address:" << S.address << endl;
    cout << rang::fg::green<< "Registration Number:" << S.regstNum << endl;
    S.date_Birth.print();
}

void change_character(Student S)
{
    cout << rang::fg::green<< "Name:";
    cin >> S.name;
    cout << rang::fg::green<< "UserName:";
    cin >> S.username;
    cout << "Address:";
    cin >> S.address;
    cout << rang::fg::green<< "Registrat Number:";
    cin >> S.regstNum;
    cout << rang::fg::green<< "Year:";
    cin >> S.date_Birth.year;
    cout << rang::fg::green<< "Month:";
    cin >> S.date_Birth.month;
    cout << rang::fg::green<< "Day:";
    cin >> S.date_Birth.day;
    student_display(S);
}

vector<Student>
stundent_manage_creat()
{
    vector<Student> all;
    cout << rang::fg::green<< "Enter The Number of Students: ";
    int n;
    cin >> n;
    int m = n + 1;
    int regstNum = 0;
    string name;
    string surname;
    string address;
    Date dt;
    Course *course_marks = new Course();
    if(n < 0 )
        cout << rang::fg::red<< "Size must be greater than 0";
    while (n) {
        cout<< rang::fg::green<< "---------- Student number :" << m - n << " -------------\n";
        cout<< rang::fg::green<< "Enter the name:";
        cin >> name;
        cout<< rang::fg::green<< "Enter the surname:";
        cin >> surname;
        cout<< rang::fg::green<< "Enter the Adrress:";
        cin >> address;
        cout<< rang::fg::green<< "Enter the Registration Number:";
        cin >> regstNum;
        cout<< rang::fg::green<< "Enter the day of birth:";
        cin >> dt.day;
        cout<< rang::fg::green<< "Enter the month of birth:";
        cin >> dt.month;
        cout<< rang::fg::green<< "Enter the year of birth:";
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
    cout << rang::fg::green<< "------------- Diplay " << n << " Students ----------"<< endl;
    int m = n;
    while (m) {
        cout << rang::fg::green<< "Student Number " << n - m + 1 << endl;
        cout << rang::fg::green<< "Name:" << v[n - m].name << endl;
        cout << rang::fg::green<< "UserName:" << v[n - m].username << endl;
        cout << rang::fg::green<< "Address:" << v[n - m].address << endl;
        v[n - m].date_Birth.print();
        cout << rang::fg::green<< "--------------- Course ------------"<<endl;
        marks_Display(v[ n - m ].courseMark);
        m--;
        
    }
}

void student_av_mark_course(vector<Student> v)
 {
     int n = v.size();
     int m = n;
     while (m) {
         cout << rang::fg::green<< "The Average Mark of " << v[n - m].name << " "
         << v[n - m].username << " is "<< marks_av(v[n - m].courseMark)<<endl;
              m--;
     }
 }


 void
student_best_mark_course(vector<Student> v)
 {
     int n = v.size();
     int m = n;
     while (m) {
         cout << rang::fg::green<< "The Best Mark of " << v[n - m].name << " "
         << v[n - m].username<< " is "
         << marks_best(v[n - m].courseMark)<<endl;
              m--;
     }
 }


 void
student_bad_mark_course(vector<Student> v)
 {
     int n = v.size();
     int m = n;
     while (m) {
         cout << rang::fg::green<< "The Bad Mark of " << v[n - m].name << " "
              << v[n - m].username << " is "
         << marks_bad(v[n - m].courseMark)<<endl;
              m--;
     }
 }
void student_manage_menu(){
bool loop=true;
    vector<Student> Nst;
    TextTable t('-', '|', '#');
    t.add("Marks Manage Menu");
    TextTable menu('-', '|', '+');
    t.endOfRow();
    menu.add("Enter 1 for");
    menu.add("Student Manage Creation");
    menu.endOfRow();
    menu.add("Enter 2 for");
    menu.add("Student Manage Display");
    menu.endOfRow();
    menu.add("Enter 3 for");
    menu.add("Student Manage Average Of Each Students");
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
    menu.endOfRow();
    menu.add("Enter 8 to");
    menu.add("Exit");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout << rang::fg::green <<  t << rang::fg::blue <<  menu;
    int choice;
    int n;
    while (loop) {
        cout << rang::fg::red<< "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Nst=stundent_manage_creat();
                break;
            case 2:
                 cout<< rang::fg::cyan << "Enter the number N of students to display: ";
                 cin >> n;
                student_manage_display(Nst,n);
                 break;
            case 3:
                student_av_mark_course(Nst);
                 break;
            case 4:
                student_best_mark_course(Nst);
                 break;
            case 5:
                student_bad_mark_course(Nst);
                  break;
            case 6:
                  cout<<rang::fg::red<< "coming soon\n";
                  break;
            case 7:
                  cout<<rang::fg::red<<"coming soon\n";
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
    TextTable menu('-', '|', '+');
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
    cout << rang::fg::green<< t <<rang::fg::blue<< menu;
}
void principal()
{
    bool loop = true;
    
    while (loop) {
        menu_Display();
        cout << rang::fg::red<< "Enter Your Choice:";
        int n;
        cin >> n;
        switch (n) {
            case 1:
                course_credit_manage();
                break;
            case 2:
                student_manage();
                break;
            case 3:
                marks_menu();
                break;
            case 4:
                student_manage_menu();
                break;
            case 5:
            loop=false;
            break;
            default:
                cout << rang::fg::magenta<< "Good Bye!!!!";
                break;
        }
    }
}


void
print_vec(vector<int> v)
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
    vector<int> v;
    bool loop = true;
    int capture;
    TextTable t('-', '|', '#');
    t.add("Marks Management Menu");
    TextTable menu('-', '|', '+');
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
    menu.add("Exit");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout <<rang::fg::green<< t <<rang::fg::blue<< menu;
    int choice;
    while (loop) {
        cout << rang::fg::red<<"Enter Your Choice: ";
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
                cout << rang::fg::green<< "The Average mark is :" << capture << "\n";
                break;
            case 4:
                capture = marks_best(marks);
                cout << rang::fg::green<< "The best mark is :" << capture << endl;
                break;
            case 5:
                capture = marks_bad(marks);
                cout << rang::fg::green<< "The Worst mark is :" << capture << endl;
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
                cout << rang::fg::magenta<<"Good bye!!!";
                break;
        }
    }
}

int main()
{
    int N = 2000;
        tqdm bar;
        cout<<rang::fg::green<<"Loading..."<<endl;
        bar.set_theme_braille();
        for(int i = 0; i < N; i++) {
            bar.progress(i, N);
            usleep(1000);
        }
        bar.finish();
        string s=R"(
         _______   ______  __    __         ______    __                      __                        __      __       __                                                                              __
        /       \ /      |/  |  /  |       /      \  /  |                    /  |                      /  |    /  \     /  |                                                                            /  |
        $$$$$$$  |$$$$$$/ $$ |  $$ |      /$$$$$$  |_$$ |_    __    __   ____$$ |  ______   _______   _$$ |_   $$  \   /$$ |  ______   _______    ______    ______   _____  ____    ______   _______   _$$ |_
        $$ |__$$ |  $$ |  $$ |  $$ |      $$ \__$$// $$   |  /  |  /  | /    $$ | /      \ /       \ / $$   |  $$$  \ /$$$ | /      \ /       \  /      \  /      \ /     \/    \  /      \ /       \ / $$   |
        $$    $$<   $$ |  $$ |  $$ |      $$      \$$$$$$/   $$ |  $$ |/$$$$$$$ |/$$$$$$  |$$$$$$$  |$$$$$$/   $$$$  /$$$$ | $$$$$$  |$$$$$$$  | $$$$$$  |/$$$$$$  |$$$$$$ $$$$  |/$$$$$$  |$$$$$$$  |$$$$$$/
        $$$$$$$  |  $$ |  $$ |  $$ |       $$$$$$  | $$ | __ $$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$ |  $$ | __ $$ $$ $$/$$ | /    $$ |$$ |  $$ | /    $$ |$$ |  $$ |$$ | $$ | $$ |$$    $$ |$$ |  $$ |  $$ | __
        $$ |__$$ | _$$ |_ $$ \__$$ |      /  \__$$ | $$ |/  |$$ \__$$ |$$ \__$$ |$$$$$$$$/ $$ |  $$ |  $$ |/  |$$ |$$$/ $$ |/$$$$$$$ |$$ |  $$ |/$$$$$$$ |$$ \__$$ |$$ | $$ | $$ |$$$$$$$$/ $$ |  $$ |  $$ |/  |
        $$    $$/ / $$   |$$    $$/       $$    $$/  $$  $$/ $$    $$/ $$    $$ |$$       |$$ |  $$ |  $$  $$/ $$ | $/  $$ |$$    $$ |$$ |  $$ |$$    $$ |$$    $$ |$$ | $$ | $$ |$$       |$$ |  $$ |  $$  $$/
        $$$$$$$/  $$$$$$/  $$$$$$/         $$$$$$/    $$$$/   $$$$$$/   $$$$$$$/  $$$$$$$/ $$/   $$/    $$$$/  $$/      $$/  $$$$$$$/ $$/   $$/  $$$$$$$/  $$$$$$$ |$$/  $$/  $$/  $$$$$$$/ $$/   $$/    $$$$/
                                                                                                                                                          /  \__$$ |
                                                                                                                                                          $$    $$/
                                                                                                                                                           $$$$$$/
)";

    cout<< rang::fg::cyan<<"School Managemt system"<<endl;
    //menu_Display();
    principal();
}

