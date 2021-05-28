// searchInfoSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream> //using files  to store and retrieve


using namespace std;

//structure 
struct Student {
	string id;
	string name; 
	int age;

	//constructor
	Student(string d="100", string n="Bobby", int a=30) {
		id = d;
		name = n;
		age = a;
	}
};

//take input from the user
struct Student* input_details(struct Student* ptr) {
	int i;
	for (i = 0; i < 3; i++) {
		cout << "\nEnter the id of the student: ";
		cin >> ptr->id;
		cout << "\nEnter the name of the student: ";
		cin >> ptr->name;
		cout << "\nEnter the age of the student: ";
		cin >> ptr->age;
		ptr++;
	}

	return(ptr); //returns the pointer for the first element in the array
}

//output the details
void output_details(struct Student* ptr) {
	int i;
	for (i = 0; i < 3; i++) {
		cout << "\nId: " << ptr->id << endl;
		cout << "\nName: " << ptr->name << endl;
		cout << "\nAge: " << ptr->age << endl;
		ptr++;
	}

}


int main()
{
	struct Student s[3];//array of structure
	struct Student* p = s; //pointer for Student array of structure

	//reading the values of the constructor

	cout << "\nId: " << p->id;
	cout << "\nName: " << p->name;
	cout << "\nAge: " << p->age;

	//using a function with pointer for array of structure to take input from the user
	input_details(p);

	//using a function with pointer returned from input_details() function to output details
	output_details(p);

	//writing to the file
	fstream my_file;

	//open the file
	my_file.open("student.txt", ios::out);

	//write all the input data into the file
	int i;
	for (i = 0; i < 3; i++) {
		my_file << p->id << "\t";
		my_file << p->name << "\t";
		my_file << p->age << endl;
		p++;

	}
	cout << "\nStored details into the file" << endl <<endl;
	my_file.close();

	cout << "\nRetrieving data from the file" << endl;

	//opening file to retrieve data
	my_file.open("student.txt", ios::in);
	string store_detail, what_id;

	cout << "\nPlease enter the id of the student you want: ";
	cin >> what_id;
	int flag=0;
	while (getline(my_file, store_detail)) {
		string subs = store_detail.substr(0, 3);

		
		if (subs == what_id) {
			cout << "Line of data from the file: " << store_detail << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		cout << "\n Record found";
	}
	else {
		cout << "\nRecord not found";
	}
	
	return 0;
   
}
