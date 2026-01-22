#include<bits/stdc++.h>
#include<iomanip>
#include<stdlib.h>
#include<fstream>

using namespace std;

// Function Decleration
void project();
void addData();
void displayData();
void deleteData();
void getTrash();

class Student{
    private:
    int admission_number;
    char student_name[20];
    char student_gender;
    int standard;
    float student_marks;
    double student_percentage;

    public:
    void getData();
    void showData();

    int getAdmissionNumber(){
        return admission_number;
    }


}s; // Note : Creating Object of a class;


int main(){

    project();

    return 0;
}

// Project Decleration
void project(){
    int choice = -1;
    
    do{
        // Clear Terminal
        system("cls");
		cout << "**************STUDENT MANAGEMENT SYSTEM***************\n";

        cout<<"1. Write Student Record"<<endl;
        cout<<"2. Read Student Record"<<endl;
        cout<<"3. Delete Student Record"<<endl;
        cout<<"4. Get Deleted Record"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1: addData();
                    break;
            case 2: displayData();
                    break;
            case 3: deleteData();
                    break;
            case 4: getTrash();
                    break;
            case 0: break;

            default : cout<<"Unknown Choice"<<endl;
                    break;
        }

        if(choice == 0){
            break;
        }

        // This will ask for anykey and continue
        system("pause");

    }while(choice);
}

// Get input from console
void Student::getData(){
	cout << "\n\n*******Enter Student Data*******\n";
    
    cout<<"Admission Number : ";
    cin >> admission_number;

    cout<<"Full Name : ";
    cin.ignore();
    cin.getline(student_name, 20);

    cout<<"Gender (M/F) : ";
    cin>>student_gender;

    cout<<"Class : ";
    cin>>standard;
    
    cout<<"Total Marks : ";
    cin>>student_marks;

    cout<<endl;
    student_percentage = (student_marks / 500.0)*100;
}

void Student::showData(){
    cout << "\n\n*******Student Details*******\n";

    cout<<"Admission Number : "<<admission_number<<endl;
    cout<<"Name : "<<student_name<<endl;
    cout<<"Gender : "<<student_gender<<endl;
    cout<<"Class : "<<standard<<endl;
    cout<<"Total Marks : "<<student_marks<<endl;
    cout<<"Percentage : "<<student_percentage<<" %"<<endl;
}

void addData(){
    ofstream file;
    file.open("student_details.txt", ios::out | ios ::app | ios::binary);

    s.getData(); // Getting Data from the console inside the object

    file.write((char*)&s, sizeof(s)); // Writing entire student object in the file

    file.close();

	cout << "\n\n*******Data Successfully Saved to File*******\n";
}

void displayData(){
    ifstream file;

    file.open("student_details.txt", ios::in | ios::binary);

    while(file.read((char*)&s, sizeof(s))){
        s.showData();
    }

    file.close();
	cout << "\n\n******Data Reading from File Successfully Done*****\n";
}

void deleteData(){
    int number;
    int flag = 0;

    ifstream readFile;
    ofstream write_in_tempfile, write_in_trashFile;
    
    readFile.open("student_details.txt", ios::in | ios::binary);

    write_in_tempfile.open("temp.txt", ios::out | ios::app | ios::binary);
    write_in_trashFile.open("trash.txt", ios::out | ios::app | ios::binary);

    cout<<"Enter Admission Number : ";
    cin>>number;

    while(readFile.read((char*)&s, sizeof(s))){
        // Seraching Through the admission Number 
        if(number == s.getAdmissionNumber()){
            cout << "This Record " << number << " has been sent to Trash:\n";

            s.showData();

            write_in_trashFile.write((char*)&s, sizeof(s));
            flag++;
        }
        else{
            write_in_tempfile.write((char*)&s, sizeof(s));
        }
    }

    // close all files
    readFile.close();
    write_in_tempfile.close();
    write_in_trashFile.close();

    if(flag == 0){
        cout << "� �" << number << "No Record found*****\n\n";
    }

    remove("student_details.txt");
    rename("temp.txt", "student_details.txt");
}

void getTrash(){
    ifstream file;

    file.open("trash.txt", ios::in | ios::binary);

    while(file.read((char*)&s, sizeof(s))){
        s.showData();
    }
    file.close();

    cout << "\n\n*******Data Reading from Trash File Successfully Done*****\n";
}