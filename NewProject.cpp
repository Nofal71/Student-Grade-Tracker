#include <iostream>
using namespace std;

class calculations {
protected:
    double Total, Obtained;
    int subCount;
    double* Total_Marks;
    double* Obtained_Marks;
public:
	string Student_Name;
    calculations() {
        Total_Marks = NULL;
        Obtained_Marks = NULL;
        cout<<"Enter Your Name : ";
        cin>>Student_Name;
	}

    void Store_Marks() {
        subCount = 0;
        Total = 0;
        Obtained = 0;
        cout << "\t\tEnter Subject count : ";
        cin >> subCount;

        Total_Marks = new double[subCount];
        Obtained_Marks = new double[subCount];

        cout << "Enter Your Marks : "<<endl;
        for (int i = 0; i < subCount; i++) {
            cout << "\tSubject " << i + 1 << " Marks : " << endl;
            cout << "\tObtained Marks : ";
            cin >> Obtained_Marks[i];
            cout << "\tOut of         : ";
            cin >> Total_Marks[i];

            Total += Total_Marks[i];
            Obtained += Obtained_Marks[i];
        }
    }

    double Percentage() {
        double percentage = (Obtained / Total) * 100;
        return percentage;
    }

    void gradePerSub() {
    cout <<"\t\t"<< Student_Name << " Grades per subject :" << endl;
    for (int i = 0; i < subCount; i++) {
        double subjectPercentage = (Obtained_Marks[i] / Total_Marks[i]) * 100;
        cout << "\tGrade for subject " << i + 1 << " is " << grade(subjectPercentage) << endl;
    }
}


    string grade(double Percentage) {
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

    ~calculations() {
        delete[] Total_Marks;
        delete[] Obtained_Marks;
        Student_Name = " ";
    }
};

class Functionality : public calculations {
public:
    void ChooseOption() {
        int Option;
        cout << "\t\t1- Calculate Percentage " << endl;
        cout << "\t\t2- Calculate Grade " << endl;
        cout << "\t\t3- Calculate Grade Per Subject " << endl;
        cout << "\t\t4- Calculate Full Result " << endl;
        cout << "\t\t5- View History "<<endl;
        cout << "\t\t6- Clear History ";

        cin >> Option;

        switch (Option) {
        case 1:
            Store_Marks();
            cout << "\n\t\tPercentage  of "<< Student_Name <<" is : " << Percentage() << "%";
            break;

        case 2:
            Store_Marks();
            cout << "\n\t\tGrade of " << Student_Name<<" is : " << grade(Percentage()) << endl;
            break;

        case 3:
            Store_Marks();
            gradePerSub();
            break;

        case 4:
            Store_Marks();
            cout << "\n\t\tStudent GET " << Obtained << " Marks out of " << Total << endl;
            cout << "\n\t\tPercentage is " << Percentage() << "%" << endl;
            gradePerSub();
            cout << "\n\t\tGrade of student is : " << grade(Percentage()) << endl;
            break;
        }
    }
};

int main() {
    Functionality obj;
    char op;
    cout<<"\n\n\n";
    cout<<"\t\t\t++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t|Student GRADE calculator|"<< endl;
    cout<<"\t\t\t++++++++++++++++++++++++++"<<endl;
    cout <<"\n\t\tChoose Option : " << endl;
    obj.ChooseOption();

   while (true) {
    cout << "\n Again Calculate (y/n) : ";
    cin >> op;
    if (op == 'y') {
        system("CLS");
    cout<<"\n\n\n";
    cout<<"\t\t\t++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t|Student GRADE calculator|"<< endl;
    cout<<"\t\t\t++++++++++++++++++++++++++"<<endl;
    cout <<"\n\t\tChoose Option : " << endl;
    obj.ChooseOption();

    } else if (op == 'n') {
        break; 
    } else {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        break;
    }
}

    return 0;
}
