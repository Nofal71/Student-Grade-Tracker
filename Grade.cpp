#include <iostream>
#include <string>

using namespace std;

class Grade {
protected:
    double Total_Marks, Obtained_Marks, Percentage;

public:
    Grade() {
        Total_Marks = 0;
        Obtained_Marks = 0;
    }

    double calPercentage(double Obtained_Marks, double Total_Marks) {
        Percentage = (Obtained_Marks / Total_Marks) * 100;
        return Percentage;
    }

    string calGrade(double Percentage) {
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

class PerSubject : public Grade {
public:
    string student;

    void Main(int subCount) {
        Total_Marks = 0;
        Obtained_Marks = 0;
        double Total[subCount], Obtained[subCount];
        int choice;

        for (int i = 0; i < subCount; i++) {
            cout << "\n\t\t\tSubject number " << i + 1 << endl;
            cout << "\t\t\t\tObtained Marks : ";
            cin >> Obtained[i];
            cout << "\t\t\t\tOut Of  :";
            cin >> Total[i];

            if (Obtained[i] > Total[i]) {
                cout << "Invalid Marks Entry. Try again." << endl;
                i--;
            } else {
                Total_Marks += Total[i];
                Obtained_Marks += Obtained[i];
            }
        }

        system("CLS");

        cout << "\n\n\n";
        cout << "\tChoose Options : " << endl;
        cout << "\t1- Total Grades " << endl;
        cout << "\t2- Grade per Subject " << endl;
        cout << "\t3- Marks  " << endl;
        cout << "\t4- Result ";
        cin >> choice;

        if (choice == 1) {
            cout << "Total Grade For " << student << " is " << endl;
            cout << "\t\tTotal Grade: " << calGrade(calPercentage(Obtained_Marks, Total_Marks)) << endl;
        } else if (choice == 2) {
            cout << "Grade Per Subject For " << student << " is " << endl;
            for (int i = 0; i < subCount; i++) {
                cout << "\t\tSubject " << i + 1 << "  Grade : " << calGrade(calPercentage(Obtained[i], Total[i])) << endl;
            }
        } else if (choice == 3) {
            cout << "\n\t\tMarks Obtained by " << student << " is " << Obtained_Marks << "/" << Total_Marks << endl;
        } else if (choice == 4) {
            cout << "\n\t\tMarks Obtained by " << student << " is " << Obtained_Marks << "/" << Total_Marks;
            cout << "\n\t\tGrade Per Subject For " << student << " is " << endl;
            for (int i = 0; i < subCount; i++) {
                cout << "\t\tSubject " << i + 1 << "  Grade : " << calGrade(calPercentage(Obtained[i], Total[i])) << endl;
            }
            cout << "\t\tTotal Grade For " << student << " is " << endl;
            cout << "\t\tTotal Grade: " << calGrade(calPercentage(Obtained_Marks, Total_Marks)) << endl;
        }
    }
};

int main() {
    int count;
    char choice;

    PerSubject object;
    Grade obj;

    cout << "\n\n\n";
    cout << "\t\t++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\t\t|  WELCOME TO STUDENT GRADE TRACKER  | " << endl;
    cout << "\t\t++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\n\n\t\tEnter Student Name : ";
    cin >> object.student;
    cout << "\n\tEnter Subject Counts You Want to calculate : ";
    cin >> count;

    object.Main(count);

    int y = 1;
    while (y > 0) {
        
        cout << "Again Calculate (y/n) : ";
        cin >> choice;
        
        if (choice == 'y') {
        	system("CLS");
            cout << "Enter Subject Counts You Want to calculate : ";
            cin >> count;
            object.Main(count);
        } else {
            break;
        }

        y++;
    }

    return 0;
}
