#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
#include<sstream>
using namespace std;
class Student
{
	int rollno;
	string name,depart;
	float cgpa;
	public:
		void setroll(int r)
		{
			rollno = r;
		}
		void setname(string n)
		{
			name = n;
		}
		void setdepart(string d)
		{
			depart = d;
		}
		void setcgpa(float c)
		{
			cgpa = c;
		}
		int getroll()
		{
			return rollno;
		}
		string getname()
		{
			return name;
		}
		string getdepart()
		{
			return depart;
		}
		float getcgpa()
		{
			return cgpa;
		}
};
class Management 
{
	vector<Student>students;
	Student s;
	public:
		void input()
		{
			int roll;
			string name,depart;
			float cgpa;
			cout << "Enter the Rollno of the Student : ";
			cin >> roll;
			cin.ignore();
			cout << "Enter the Name of the Student : ";
			getline(cin, name);
			cout << "Enter the Department of the Student : ";
			getline(cin, depart);
			cout << "Enter the CGPA of the Student : ";
			cin >> cgpa;
			s.setroll(roll);
			s.setname(name);
			s.setdepart(depart);
			s.setcgpa(cgpa);
			students.push_back(s);
			cout << "Student added successfully!" << endl;
		}
		void display()
		{
			if(students.empty())
			{
				cout << "No students record available." << endl;
			}
			else
			{
				cout << left <<
				setw(10) << "Rollno" << 
				setw(20) << "Name" << 
				setw(25) << "Department" << 
				setw(5) << "CGPA" << 
				endl;
				for(int i=0; i<students.size(); i++)
				{
					cout << left <<
					setw(10) << students[i].getroll() << 
					setw(20) << students[i].getname() << 
					setw(25) << students[i].getdepart() << 
					setw(5) << students[i].getcgpa() << 
					endl;
				}
			}	
		}
		void search()
		{
			if(students.empty())
			{
				cout << "No records to search. " << endl;
			}
			else
			{
				string key;
				cout << "Enter the Name or Rollno of Student : ";
				cin.ignore();
				getline(cin, key);
				if(isdigit(key[0]))
				{
					for(int i=0; i<students.size(); i++)
					{
						if(atoi(key.c_str())==students[i].getroll())
						{
							cout << "!--------STUDENT iNFORMATION--------!" << endl;
							cout << "ROllno : " << students[i].getroll() << endl;
							cout << "Name : " << students[i].getname() << endl;
							cout << "Department : " << students[i].getdepart() << endl;
							cout << "CGPA : " << students[i].getcgpa() << endl;
						}
					}
				}
				else
				{
					for(int j=0; j<students.size(); j++)
					{
						if(key==students[j].getname())
						{
							cout << "!--------STUDENT iNFORMATION--------!" << endl;
							cout << "ROllno : " << students[j].getroll() << endl;
							cout << "Name : " << students[j].getname() << endl;
							cout << "Department : " << students[j].getdepart() << endl;
							cout << "CGPA : " << students[j].getcgpa() << endl;
							return;
						}
					}
					cout << "!--------Result not found--------!" << endl;
				}
			}
		}
		void remove()
		{
			if(students.empty())
			{
				cout << "No students record available." << endl;
			}
			else
			{
				int ro;
				cout << "Enter the rollno of the student : ";
				cin >> ro;
				for(int i=0; i<students.size(); i++)
				{
					if(ro == students[i].getroll())
					{
						students.erase(students.begin()+i);
						ofstream file("Student.txt",ios::trunc);
						file.close();
						cout << "!====Data deleted successfull====!" << endl;
						return;
					}
				}
				cout << "!--------Rollno not found--------!" << endl;
			}
		
		}	
		void addfile()
		{
			ofstream file("Student.txt");
			file << "Rollno " << "	" << "Name " << "	" 
			<< "Department " << "	" << "CGPA " << "	"
			<< endl;
			for(int k=0; k<students.size(); k++)
			{
				file << students[k].getroll() << "	" << students[k].getname() << "	" 
			<< students[k].getdepart() << "	" << students[k].getcgpa() << "	"
			<< endl;
			}
			file.close();
			cout << "Data saved in file successfully." << endl;
		}
		void readfile()
		{
			ifstream file("Student.txt");
			string rol,nam,dep,head,cgp;
			getline(file, head);
			while(getline(file, head))
			{
				stringstream ss(head);
				getline(ss, rol, '	');
				getline(ss, nam, '	');
				getline(ss, dep, '	');
				getline(ss, cgp, '	');
				s.setroll(atoi(rol.c_str()));
				s.setname(nam);
				s.setdepart(dep);
				s.setcgpa(atof(cgp.c_str()));
				students.push_back(s);
			}
			file.close();
			cout << "Data loaded from the file successfully." << endl;
		}
		void update()
		{
			int roll;
			string field,temp;
			cout << "Rollno of student for updation : ";
			cin >> roll;
			cin.ignore();
			cout << "Field you want to update : ";
			getline(cin, field);
			if(field=="Rollno" || field=="rollno" || field=="ROLLNO")
			{
			 cout << "Field cannot be changed-----!" << endl;
			}
			else if(field=="Name" || field=="name" || field=="NAME")
			{
				cout << "Field cannot be changed-----!" << endl;
			}
			else if(field=="Department" || field=="department" || field=="DEPARTMENT")
			{
				cout << "Enter department : ";
				getline(cin, temp);
				for(int i=0; i<students.size(); i++)
				{
					if(roll==students[i].getroll())
					{
						students[i].setdepart(temp);
						cout << "Department updated successfully----!" << endl;
						return;
					}
				}
			}
			else if(field=="Cgpa" || field=="cgpa" || field=="CGPA")
			{
				cout << "Enter current CGPA : ";
				getline(cin, temp);
				for(int j=0; j<students.size(); j++)
				{
					if(roll==students[j].getroll())
					{
						students[j].setcgpa(atof(temp.c_str()));
						cout << "CGPA updated successfully----!" << endl;
						return;
					}
				}
			}
			else
			{
				cout << "Syntax Error----------!" << endl;
			}
		}
};
int main()
{
	Management m;
	int choice;
	do
	{
		cout << "1: Add Student " << endl;
		cout << "2: Search Student " << endl;
		cout << "3: Display Students " << endl;
		cout << "4: Delete Student " << endl;
		cout << "5: Update Fields " << endl;
		cout << "6: Save in file " << endl;
		cout << "7: load from file " << endl;
		cout << "8: Exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		system("cls");
		switch(choice)
		{
			case 1:
			{
				m.input();
				getch();
				system("cls");
				break;
			}
			case 2:
			{
				m.search();
				getch();
				system("cls");
				break;
			}	
			case 3:
			{
				m.display();
				getch();
				system("cls");
				break;
			}
			case 4:
			{
				m.remove();
				getch();
				system("cls");
				break;
			}
			case 5:
			{
				m.update();
				getch();
				system("cls");
				break;
			}
			case 6:
			{
				m.addfile();
				getch();
				system("cls");
				break;
			}
			case 7:
			{
				m.readfile();
				getch();
				system("cls");
				break;
			}
			case 8:
			{
				cout << "Exit......................!" << endl;
				break;
			}
		}	
	}while(choice!=8);
	return 0;
}
