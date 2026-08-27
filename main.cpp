#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
#include <iomanip>

using namespace std;


const int MAX = 120;


// ================= STUDENT DATA =================

string name[MAX];
string indexNumber[MAX];
string programme[MAX];
int level[MAX];

bool present[MAX]={false};

int studentCount = 0;


// ================= COURSE DATA =================

string courseName[MAX];
string courseCode[MAX];
int courseLevel[MAX];

int courseCount = 0;



// ================= FUNCTION DECLARATIONS =================


void registerStudent();

void viewStudents();

void addCourse();

void viewCourses();

void markAttendance();

void viewAttendance();

void searchStudent();

void deleteStudent();

void attendanceStatistics();

void editStudent();

void loadStudents();

void loadCourses();

void loadAttendance();



// ================= LOGIN =================


bool login()
{

string username;
string password;


cout<<"\n=================================\n";
cout<<"        LECTURER LOGIN\n";
cout<<"=================================\n";


cout<<"Username: ";
cin>>username;


cout<<"Password: ";
cin>>password;



if(username=="admin" && password=="gctu123")
{

cout<<"\nLogin Successful!\n";

return true;

}


cout<<"\nInvalid Login Details!\n";

return false;


}




// ================= MAIN PROGRAM =================


int main()
{


int choice;



if(!login())
{
    return 0;
}



// LOAD FILE DATA

loadStudents();

loadCourses();

loadAttendance();



cout<<"\n=================================\n";
cout<<" GCTU QR ATTENDANCE SYSTEM\n";
cout<<"=================================\n";


cout<<"Students Loaded: "
    <<studentCount<<endl;


cout<<"Courses Loaded: "
    <<courseCount<<endl;




do
{


cout<<"\n=================================\n";
cout<<"1. Register Student\n";
cout<<"2. View Students\n";
cout<<"3. Add Course\n";
cout<<"4. View Courses\n";
cout<<"5. Mark Attendance\n";
cout<<"6. View Attendance\n";
cout<<"7. Search Student\n";
cout<<"8. Delete Student\n";
cout<<"9. Attendance Statistics\n";
cout<<"10. Edit Student\n";
cout<<"11. Exit\n";
cout<<"=================================\n";


cout<<"Enter Choice: ";



while(!(cin>>choice))
{

cin.clear();

cin.ignore(numeric_limits<streamsize>::max(),'\n');


cout<<"Enter number: ";

}



switch(choice)
{


case 1:

registerStudent();

break;



case 2:

viewStudents();

break;



case 3:

addCourse();

break;



case 4:

viewCourses();

break;



case 5:

markAttendance();

break;



case 6:

viewAttendance();

break;



case 7:

searchStudent();

break;



case 8:

deleteStudent();

break;



case 9:

attendanceStatistics();

break;



case 10:

editStudent();

break;



case 11:

cout<<"\nThank you for using GCTU QR Attendance System\n";

break;



default:

cout<<"Invalid Choice!\n";


}



}
while(choice!=11);



return 0;


}
// ================= LOAD STUDENTS =================

void loadStudents()
{

ifstream file("students.txt");


if(!file.is_open())
{
    return;
}



while(studentCount < MAX)
{

getline(file,name[studentCount],',');


if(file.fail())
{
    break;
}



getline(file,indexNumber[studentCount],',');


getline(file,programme[studentCount],',');



file >> level[studentCount];


file.ignore(1000,'\n');



studentCount++;


}


file.close();


}
// ================= REGISTER STUDENT =================


void registerStudent()
{


if(studentCount >= MAX)
{

cout<<"Maximum students reached!\n";

return;

}



cin.ignore(numeric_limits<streamsize>::max(),'\n');



cout<<"\n========== REGISTER STUDENT ==========\n";



cout<<"Student Name: ";

getline(cin,name[studentCount]);



cout<<"Index Number: ";

getline(cin,indexNumber[studentCount]);




// CHECK DUPLICATE INDEX


for(int i=0;i<studentCount;i++)
{


if(indexNumber[i]==indexNumber[studentCount])
{

cout<<"Index Number already exists!\n";

return;

}


}




cout<<"Programme: ";

getline(cin,programme[studentCount]);



cout<<"Level: ";

while(!(cin>>level[studentCount]))
{

cin.clear();

cin.ignore(numeric_limits<streamsize>::max(),'\n');


cout<<"Enter valid level: ";

}




ofstream file("students.txt",ios::app);



if(file.is_open())
{


file<<name[studentCount]<<","
    <<indexNumber[studentCount]<<","
    <<programme[studentCount]<<","
    <<level[studentCount]
    <<endl;



file.close();



studentCount++;



cout<<"\nStudent Registered Successfully!\n";


}

else
{

cout<<"Error saving student!\n";

}


}
// ================= VIEW STUDENTS =================


void viewStudents()
{


cout<<"\n========== STUDENT LIST ==========\n";



if(studentCount==0)
{

cout<<"No students registered.\n";

return;

}



for(int i=0;i<studentCount;i++)
{


cout<<"\nStudent "<<i+1<<endl;

cout<<"----------------------\n";


cout<<"Name      : "<<name[i]<<endl;

cout<<"Index     : "<<indexNumber[i]<<endl;

cout<<"Programme : "<<programme[i]<<endl;

cout<<"Level     : "<<level[i]<<endl;


}



}