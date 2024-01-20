#include <iostream>
#include <string>
using namespace std;
class Grade{
 protected:
double Total_Marks , Obtained_Marks , Percentage;
 public:
string Student_Name;
   Grade(){
    Total_Marks = 0;
    Obtained_Marks = 0;
    
   }

double calPercentage(double Obtained_Marks , double Total_Marks){
    Percentage = (Obtained_Marks/Total_Marks)*100;
    return Percentage;
}


string calGrade(double Percentage){
         if (Percentage >= 90 && Percentage <= 100) {
            return "A+";
        } else if (Percentage >= 85 && Percentage < 90) {
            return "A";
        } else if (Percentage >= 80 && Percentage < 85) {
            return "A-";
        } else if (Percentage >= 75 && Percentage < 80) {
            return "B+";
        } else if (Percentage >= 70 && Percentage < 75) {
            return "B";
        } else if (Percentage >= 65 && Percentage < 70) {
            return "B-";
        } else if (Percentage >= 60 && Percentage < 65) {
            return "C+";
        } else if (Percentage >= 55 && Percentage < 60) {
            return "C";
        } else if (Percentage >= 50 && Percentage < 55) {
            return "C-";
        } else if (Percentage >= 45 && Percentage < 50) {
            return "D";
        } else {
            return "Failure";
        }
}

 

};

class PerSubject : Grade {
public:

void Main(int subCount) {
    double Total[subCount], Obtained[subCount];
    int choice;

    for (int i = 0; i < subCount; i++) {
        cout << "\t\tSubject number " << i + 1 << endl;
        cout << "\t\t\tObtained Marks : ";
        cin >> Obtained[i];
        cout << "\t\t\tOut Of  :";
        cin >> Total[i];

        if (Obtained[i] > Total[i]) {
            cout << "Invalid Marks Entry. Try again." << endl;
            i--; 
        } else {
            Total_Marks += Total[i];
            Obtained_Marks += Obtained[i];
        }
    }

    cout << "\tChoose Options : " << endl;
    cout << "\t1- Total Grades " << endl;
    cout << "\t2- Grade per Subject " << endl;
    cout << "\t3- Both :" << endl;
    cin >> choice;

    if (choice == 2) {
        cout<<"Grade Per Subject For "<<Student_Name<<" is ";
        for (int i = 0; i < subCount; i++) {
            cout << "\t\tSubject " << i + 1 << "  Grade : " << calGrade(calPercentage(Obtained[i], Total[i])) << endl;
        }
    } else if (choice == 3) {
        cout<<"Grade Per Subject For "<<Student_Name<<" is ";
        for (int i = 0; i < subCount; i++) {
            cout << "\t\tSubject " << i + 1 << " Grade : " << calGrade(calPercentage(Obtained[i], Total[i])) << endl;
        }
        cout << "\t\tTotal Grade: " << calGrade(calPercentage(Obtained_Marks, Total_Marks)) << endl;
    } else if (choice == 1) {
        cout<<"Total Grade For "<<Student_Name<<" is ";
        cout << "\t\tTotal Grade: " << calGrade(calPercentage(Obtained_Marks, Total_Marks)) << endl;
    }
}


};


int main() {
    int count ;
    char choise;
    PerSubject object;
    Grade obj;
    cout<<"\n\n\n";
    cout << "\t\t\t\t\t++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\t\t\t\t\t|  WELCOME TO STUDENT GRADE TRACKER  | " << endl;
    cout << "\t\t\t\t\t++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\n\n\t\tEnter Student Name : ";
    cin>>obj.Student_Name;
    cout << "\n\n\t\tEnter Subject Counts You Want to calculate : ";
    cin >> count;


object.Main(count);

int y = 1;
while(y>0){


cout<<"Again Calculate (y/n) : ";
cin>>choise;
if(choise == 'y'){
    cout << "Enter Subject Counts You Want to calculate : ";
    cin >> count;
object.Main(count);

}else{
    break;
}
y++;
}

    return 0;
    
}
