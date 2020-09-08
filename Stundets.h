//
//  Stundets.h
//  C++Pro
//
//  Created by Tititof Irakoze on 9/5/20.
//  Copyright © 2020 Tititof Irakoze. All rights reserved.
//

#ifndef Students_h
#define Students_h
using namespace std;

class Date
{
public:
    int day,month,year;
    bool
    Valid()
    {
        return day > 0 && day <32 && month >0 && month < 13 && year > 1980 && year < 2021;
    }
    void print()
    {
        cout << "Current date is :" << year << " "  << " " << month << " " << day << endl;
    }

};
class Course
{
public:
    int credit;
    char Title[20];
    float Mark;    
};
class Student
{
public:
    string name,username,address;
    int regstNum;
    Date date_Birth;
    Course * courseMark = new Course();
    Student( int r, string n, string u, string a, Course *c, Date d)
    {
        regstNum = r;
        name = n;
        username = u;
        address = a;
        courseMark = c;
        date_Birth = d;
    }
};


#endif /* Students_h */

