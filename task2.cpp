#include <iostream>

using namespace std;

class Student {
    private:
        int reg_no;
        string first_name;
        string last_name;
        string program;
        float cgpa;
    public:
        //mutators
        void set_regno(const int regno) {
            reg_no = regno;
        }
        void set_first_name(const string name) {
            first_name = name;
        }
        void set_last_name(const string name) {
            last_name = name;
        }
        void set_program(const string prog)  {
            program = prog;
        }
        void set_cgpa(const float gpa) {
            cgpa = gpa;
        }

        //accessors
        int get_regno() const { 
            return reg_no;
        }
        string get_first_name() const {
            return first_name;
        }
        string get_last_name() const {
            return last_name;
        }
        string get_program() const {
            return program;
        }
        float get_cgpa() const {
            return cgpa;
        }

        //constructor
        Student(int regno, string first_name, string last_name, string prog) {
            if (regno >= 501 && regno <= 565) {
                set_regno(regno);  
            } 
            else {
                this->reg_no = 0;  
            }
            this->first_name = first_name;
            this->last_name = last_name;
            this->cgpa = -1;
        }

        Student(int regno, string first_name, string prog) {
            this->reg_no = regno;
            this->first_name = first_name;
            this->last_name = "";
            this->cgpa = -1;
        }

        Student(int regno, string first_name, string last_name, string prog, float gpa ) {
            this->reg_no = regno;
            this->first_name = first_name;
            this->last_name = last_name;
            this->program = prog;
            if (gpa >= 0 && gpa <= 4) {
                set_cgpa(gpa);
            }
            else {
                cgpa = -1;
            }
        }
        //copy constructor 
        Student(Student &obj) {
            reg_no = obj.reg_no;
            first_name = obj.first_name;
            last_name = obj.last_name;
            cgpa = obj.cgpa;
        }
        //destructor
        ~Student() {
            cout << "\nDestructor executed..."<< endl;
        }

        //member 
        void set_data(int regno, string first_name, string last_name, string prog, float gpa) {
            if (regno >= 501 && regno <= 565) {
                set_regno(regno);  
            } 
            else {
                this->reg_no = 0;  
            }
            this->first_name = first_name;
            this->last_name = last_name;
            if (gpa >= 0 && gpa <= 4) {
                set_cgpa(gpa);
            }
            else {
                cgpa = -1;
            }
        }

        void read_data() {
            cout << "enter your registration no : ";
            cin >> reg_no;

            if (reg_no < 501 || reg_no > 565) {
                this->reg_no = 0;  
            }

            cout << "enter your first name : ";
            cin >> first_name;

            cout << "enter your last name : ";
            cin >> last_name;

            cout << "enter your program : ";
            cin >> program;

            cout << "enter your cgpa : ";
            cin >> cgpa;

            if (cgpa < 0 || cgpa > 4) {
                this->cgpa = -1;
            }
        }

        void write_data() {
            cout << "Student Registration no : " << reg_no <<endl;
            cout << "Student first name      : " << first_name <<endl;
            cout << "Student last name       : " << last_name <<endl;
            cout << "Student Program         : " << program <<endl;
            cout << "Student CGPA            : " << cgpa << endl;
        }

        bool is_semester_first() {
            if (this->cgpa == -1) {
                return true;
            }
            return false;
        }
        
        float get_Percentage() {
            if (cgpa >= 0 && cgpa <= 4) {
                return ((cgpa/4)*100);
            }
            return -1;
        }

        bool is_promoted() {
            if (cgpa >= 2) {
                return true;
            }
            return false;
        }

};

int main() {
    Student obj(534, "ahmed", "rasheed", "IT", 3.5); 
    obj.write_data();
    if (obj.is_semester_first()) {
        cout << "\nfirst semester" <<endl;
    } else {
        cout <<"\nnot first semester "<<endl;
    }
    cout <<"\npercentage : "<<obj.get_Percentage();
    
    if (obj.is_promoted()) {
        cout << "\npromoted" <<endl;
    } else {
        cout <<"\nnot promoted "<<endl;
    }
    // cout << " vlaue " << obj.get_first_name() <<endl;
    obj.set_cgpa(3);
    obj.write_data();

    // Student obj1 = obj; 
    // cout <<endl;
    // obj1.write_data();
    return 0;
} 