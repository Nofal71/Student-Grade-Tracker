#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
// class to store History 
class History {
public:
    time_t currentTime = time(NULL);
    string currentTimeStr = ctime(&currentTime);

    void SaveData(const string name, const double Percentage, const string grade) {
        ofstream myfile("file.txt" , ios::app);

        if (myfile.is_open() ) {
            
            myfile << "Name............." << name << endl;
            if(Percentage == 0.00){
                
            }else{
            myfile << "Percentage......." << Percentage << "%"<< endl;
            }
            myfile << "Grade............" << grade << endl;
            myfile << currentTimeStr<<endl;
            myfile << ".............................." << endl;

        } else {
            cout << "Error";
        }
    }
// function to clear history
   void Clear_history(){
    ofstream myfile("file.txt" , ios::trunc);
    if(myfile.is_open()){
        cout<<"\n\n\t\t HISTORY SUCCESSFULLY DLETED ";
        cout<<"\t\t...................................."<<endl;
        myfile.close();
    }else{
        cout<<"ERROR";
    }
   }
//  functions To Display History
    
    void View_History(){
    ifstream myfile("file.txt");
    string Read;
    system("CLS");
    cout<<"\n\n\n";
    cout<<"\t\t\t|+++++++++++++++++++|"<<endl;
    cout<<"\t\t\t|+++++ HISTORY  ++++|"<<endl;
    cout<<"\t\t\t|+++++++++++++++++++|"<<endl;
   	
    while(getline(myfile,Read)){
    cout<<"\n\t\t\t"<<Read<<endl;
    }
   }
};
// Get Input from user 
class Input_Data {
protected:
    double* obtained;
    double* total;
    int Subject_Count;
    char op;
    double Total_Marks, Obtained_Marks;

public:
    Input_Data() {
        Subject_Count = 0;
        Total_Marks = 0;
        Obtained_Marks = 0;
        obtained = new double[Subject_Count];
        total = new double[Subject_Count];
    }

    void Welcome() {
        cout << "\n\n\n";
        cout << "\t\t|*****************************************************|" << endl;
        cout << "\t\t|************  STUDENT GRADE TRACKER SYSTEM  *********|" << endl;
        cout << "\t\t|*****************************************************|" << endl;
        cout << "\n";
    }

    void select() {
        cout << "\t\t\t   |----------------------------------|" << endl;
        cout << "\t\t\t   | SELECT OPTIONS :                 |" << endl;
        cout << "\t\t\t   | 1- Calculate Grades              |" << endl;
        cout << "\t\t\t   | 2- Calculate Grade & Percentage  |" << endl;
        cout << "\t\t\t   | 3- View History                  |" << endl;
        cout << "\t\t\t   | 4- Delete History                |" << endl;
        cout << "\t\t\t   |----------------------------------|" << endl;
        cout << "\n\n\t\tEnter Choice (1-4) : ";
    }
//    Function to Store Marks
    void marks() {
        cout << "\n\t\tENTER SUBJECT COUNT :";
        cin >> Subject_Count;
        for (int i = 0; i < Subject_Count; i++) {
            cout << "\n\t\tEnter Subject_" << i + 1 << " Marks " << endl;
            cout << "\n\t\tEnter Obtained Marks : ";
            cin >> obtained[i];
            cout << "\t\tEnter Total Marks : ";
            cin >> total[i];
            if (total[i] < obtained[i]) {
                cout << "TRY AGAIN";
                i--;
            } else {
                Total_Marks += total[i];
                Obtained_Marks += obtained[i];
            }
        }
    }

    ~Input_Data() {
        delete[] obtained;
        delete[] total;
    }
};

class Calculation : public Input_Data {
public:
    History obj_history;
//     function to calculate Percentage

        double Percentage(double obtained, double total) {
        double percentage = (obtained / total) * 100;
        return percentage;
    }

//     function to calculate Grade

    string Grade(double percentage) {
        string A = "A", B = "B", C = "C", D = "D", F = "F";
        if (percentage >= 90.0) {
            return A;
        } else if (percentage >= 80.0) {
            return B;
        } else if (percentage >= 70.0) {
            return C;
        } else if (percentage >= 60.0) {
            return D;
        } else {
            return F;
        }
    }

    void Save_grade() {
        string name ;
        cout<<"\n\n\t\tPLEASE ENTER YOUR NAME : ";
        cin>>name;
        double Percentage = 0.00;
        string grade = Grade(this->Percentage(Obtained_Marks, Total_Marks));
        obj_history.SaveData(name, Percentage, grade );
    }

//     function to calculate Result

   void Result(){
     cout<<"\n\n\t\t Percentage is : "<<Percentage(Obtained_Marks,Total_Marks)<<"%";
     cout<<"\n\t\t Grade is : "<<Grade(Percentage(Obtained_Marks,Total_Marks));
   }

   void Save_Result(){
        string name ;
        cout<<"\n\n\t\tPLEASE ENTER YOUR NAME : ";
        cin>>name;
        double Percentage = this->Percentage(Obtained_Marks,Total_Marks);
        string grade = Grade(this->Percentage(Obtained_Marks,Total_Marks));
        obj_history.SaveData(name, Percentage, grade );
   }
   

};

class Functionality : public Calculation {
public:
    void Options() {
        cin >> op;
        switch (op) {
            case '1':
                marks();
                cout << "\n\t\tGRADE IS : " << Grade(Percentage(Obtained_Marks, Total_Marks));
                Save_grade();
                break;
            case '2':
                marks();
                Result();
                Save_Result();
                break;
            case '3':
                obj_history.View_History();
                break;
            case '4':
                obj_history.Clear_history();
                break;
            default:
              cout<<"Unexpected Error please run application again ";
              break;
        }
    }
};




int main() {

    char Choice;
    
    Input_Data Obj_input;
    Functionality obj_functionality;
    
    Obj_input.Welcome();
    Obj_input.select();
    obj_functionality.Options();

    while(true){
    cout<<"\n\n\t\t Calculate Again (y / n) : ";
    cin>>Choice;
    if(Choice == 'y'){
    system("CLS");
    Obj_input.Welcome();
    Obj_input.select();
    obj_functionality.Options();
    }else if(Choice == 'n') {
        break;
    }else{
        cout<<"Enter either y or n ";
        break;
    }
    }
    return 0;
}
