#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
        string employee_Name;
        int employee_ID;
        string employee_Department;
        string employee_Position;
    public:
        //contructors with arguments or parameterized constructors
        Employee(string name, int id, string dept, string pos) {
            employee_Name = name;
            employee_ID = id;
            employee_Department = dept; 
            employee_Position = pos;           
        }
        Employee(char name[], int id) {
            employee_Name = name;
            employee_ID = id;
            employee_Department = ""; 
            employee_Position = "";            
        }
        //default constructor
        Employee() {
            employee_Name = "";
            employee_ID = 0;
            employee_Department = ""; 
            employee_Position = "";
        }
        // copy constructor
        Employee(const Employee &obj) {
            employee_Name = obj.employee_Name;
            employee_ID = obj.employee_ID;
            employee_Department = obj.employee_Department;
            employee_Position = obj.employee_Position; 
        }
        // Destructor
        ~Employee() {
            cout <<"\nDestructor executed... ";
        }

        // setter
        void setEmployee_name(string name) {
            employee_Name = name;
        }
        void setEmployee_ID(int id) {
            employee_ID = id;
        }
        void setEmployee_dept(string dept) {
            employee_Department = dept;
        }
        void setEmployee_pos(string pos) {
            employee_Position = pos;
        }

        // getter
        string getEmployee_name() {
            return employee_Name;
        }
        int getEmployee_ID() {
            return employee_ID;
        }
        string getEmployee_dept() {
            return employee_Department;
        }
        string getEmployee_pos() {
            return employee_Position;
        }
        void setInfo(string name, int id, string dept, string pos) {
            employee_Name = name;
            employee_ID = id;
            employee_Department = dept; 
            employee_Position = pos;
        }
        //for taking input from user
        void getInfo() {
            cout <<"\n\nenter the employee Name : ";
            getline(cin, this->employee_Name);

            cout <<"enter the employee Id : ";
            cin >> this->employee_ID;
            // for clearing input stream
            cin.ignore();

            cout <<"enter the employee department : ";
            getline(cin, this->employee_Department);

            cout <<"enter the employee position : ";
            getline(cin, this->employee_Position);
        }
        //for display data
        void putInfo() {
           cout <<employee_Name<<"\t"<<employee_ID<<"\t\t"<<employee_Department<<"\t"<<employee_Position<<endl;     
        }
};

int main() {
	//Employee obj1("Naveed Ali", 1230, "Computer Science", "Assistant Professor"), obj2("Noman Abdullah", 1231, "Software Enginner", "Lecturer"), obj3("Naeem Ahmad", 1240, "Computer Science ", "Lecturer"), obj4("Nadia Afghan", 1242, "Information Technology", "Assistant Professor");
	Employee obj1, obj2, obj3, obj4;
    obj1.getInfo();
    obj2.getInfo();
    obj3.getInfo();
    obj4.getInfo();
    cout << "Name" << "\t" << "\t"<<"Id Number" << "\t" << "Department " << "\t"<<"\t" << "Position" << endl;
    cout <<endl;
    obj1.putInfo();
    obj2.putInfo();
    obj3.putInfo();
    obj4.putInfo();
    return 0;
}