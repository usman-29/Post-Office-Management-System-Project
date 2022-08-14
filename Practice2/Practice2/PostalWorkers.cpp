#include "PostalWorkers.h"

//Postal Workers Class Functions
//Default constructor
PostalWorker::PostalWorker() {
	worker_Name = "";
	worker_ID = 0;
	worker_Position = "";
	worker_Salary = 0;
	worker_Designation = 0;
}

//Parameterised constructor
PostalWorker::PostalWorker(string wName, int wID, string pos, int sal, int des) : worker_Name(wName), worker_ID(wID), worker_Position(pos), worker_Salary(sal), worker_Designation(des) {

}

//Function to add postal worker
void PostalWorker::inputPostalWorker() {
	cout << "Name: ";
	getline(cin, worker_Name);
	cout << "Position: ";
	getline(cin, worker_Position);
	set_Worker_ID();
	cout << "Salary: ";
	cin >> worker_Salary;
	cout << "Designation: ";
	cin >> worker_Designation;
}

//SET & GET Functions
void PostalWorker::set_Worker_Name(string wName) {
	worker_Name = wName;
}
void PostalWorker::set_Worker_ID() {
	srand(time(NULL));
	worker_ID = (rand() % 900) + 100;
}
void PostalWorker::set_Worker_Position(int pos) {
	worker_Position = pos;
}
void PostalWorker::set_Worker_Salary(int sal) {
	worker_Salary = sal;
}
void PostalWorker::set_Worker_Designation(int des) {
	worker_Designation = des;
};
string PostalWorker::get_Worker_Name() {
	return worker_Name;
}
int PostalWorker::get_Worker_ID() {
	return worker_ID;
}
string PostalWorker::get_Worker_Position() {
	return worker_Position;
}
int PostalWorker::get_Worker_Salary() {
	return worker_Salary;
}
int PostalWorker::get_Worker_Designation() {
	return worker_Designation;
}



//Pure virtual Display function
 void PostalWorker::Display() {
	cout << "Name: " << worker_Name << endl;
	cout << "ID: " << worker_ID << endl;
	cout << "Position: " << worker_Position << endl;
	cout << "Salary: " << worker_Salary << endl;
	cout << "Designation: " << worker_Designation << endl;
}

//Derived classes Functions

//Account Officer Class Functions
 int AccountOfficer::getPassword() {
	 int pass = 1298;
	 return pass;
 }

//Default constructor
AccountOfficer::AccountOfficer() {}

//Parameterised constructor
AccountOfficer::AccountOfficer(string wName, int wID, string pos, int sal, int des) : PostalWorker(wName, wID, pos, sal, des) {
}

//Function to check password
bool AccountOfficer::checkPassword(int x) {
	if (getPassword() == x) {
		return true;
	}
	else {
		return false;
	}
}

//Function to read parcel record
void AccountOfficer::parcelRecord() {
	fstream myfile;
	myfile.open("Parcel.txt", ios::in | ios::binary);
	myfile.seekg(0, ios::end);
	int endPos = myfile.tellg();
	int numberOfRecords = endPos / sizeof(Invoice);
	cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
	int n;
	cout << "Enter the record number: ";
	cin >> n;
	int pos = (n - 1) * sizeof(Invoice);
	myfile.seekg(pos);
	myfile.read(reinterpret_cast<char*>(&invoice), sizeof(invoice));
	invoice.Display();
	myfile.close();
}

//Function to read mail record
void AccountOfficer::MailRecord() {
	fstream myfile;
	myfile.open("Mail.txt", ios::in | ios::binary);
	myfile.seekg(0, ios::end);
	int endPos = myfile.tellg();
	int numberOfRecords = endPos / sizeof(Mail);
	cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
	int n;
	cout << "Enter the record number: ";
	cin >> n;
	int pos = (n - 1) * sizeof(Mail);
	myfile.seekg(pos);
	myfile.read(reinterpret_cast<char*>(&mail), sizeof(mail));
	mail.Display();
	myfile.close();
}

//Display Function
void AccountOfficer::Display() {
	PostalWorker::Display();
}

//Postman Class Functions
//Default constructor
Postman::Postman() {}

//Parameterised constructor
Postman::Postman(string wName, int wID, string pos, int sal, int des) : PostalWorker(wName, wID, pos, sal, des) {}

//Mail recieved for delivery
void Postman::RecieveMail() {
	mail = gpo.getMail();
}

//Mail delivered
void Postman::delivered() {
	cout << endl << "Mail delivered successfully!" << endl;
}

//Display function
void Postman::Display() {
	cout << "Postman Details: " << endl;
	PostalWorker::Display();
	cout << "Mail Details: " << endl;
	mail.Display();
}

//Clerk Class Functions
//Default constructor
Clerk::Clerk() {
	stamp = 0;
}

//Parameterised constructor
Clerk::Clerk(string wName, int wID, string pos, int sal, int des, float s) : PostalWorker(wName, wID, pos, sal, des) {
	stamp = s;
}

//Function to buy stamp
float Clerk::buyStamp(float wKG) {
	if (wKG <= 1) {
		stamp = 5;
		return stamp;
	}
	else if (wKG <= 5) {
		stamp = 10;
		return stamp;
	}
	else if (wKG <= 20) {
		stamp = 20;
		return stamp;
	}
	else if (wKG <= 30) {
		stamp = 50;
		return stamp;
	}
	else {
		stamp = 100;
		return stamp;
	}
}

//Display function
void Clerk::Display() {
	PostalWorker::Display();
}

//HeadOfPostOffice Class Functions
int HeadOfPostOffice::getPassword() {
	int pass = 54321;
	return pass;
}

//Default constructor
HeadOfPostOffice::HeadOfPostOffice() {}

//Parameterised constructor
HeadOfPostOffice::HeadOfPostOffice(string wName, int wID, string pos, int sal, int des) : PostalWorker(wName, wID, pos, sal, des) {
}

//Function to check password
bool HeadOfPostOffice::checkPassword(int x) {
	if (getPassword() == x) {
		return true;
	}
	else {
		return false;
	}
}

//menu
void HeadOfPostOffice::workersMenu() {
	int num;
	cout << "1) Parcel Record" << endl;
	cout << "2) Mail Record" << endl;
	cout << "3) Add Postal worker" << endl;
	cout << "4) Postal workers information" << endl;
	cout << "Enter (number): ";
	cin >> num;
	cin.ignore();
	if (num == 1) {
		parcelRecord();
	}
	else if (num == 2) {
		MailRecord();
	}
	else if (num == 3) {
		AddPostalWorker();
	}
	else if (num == 4) {
		workerRecord();
	}
	else {
		cout << "Invalid option!" << endl;
	}
}

//Function to add postal workers
void HeadOfPostOffice::AddPostalWorker() {
	PostalWorker* pw[10];
	AccountOfficer ao;
	Clerk clerk;
	Postman postman;
	char again;
	int choose;
	do {
		cout << "1) Account Officer" << endl;
		cout << "2) Clerk" << endl;
		cout << "3) Postman" << endl;
		cin >> choose;
		cin.ignore();
		if (choose == 1) {
			pw[0] = new AccountOfficer;
			pw[0]->inputPostalWorker();
			system("CLS");
			ofstream myFile;
			myFile.open("PostalWorker.txt", ios::app | ios::binary);
			myFile.write(reinterpret_cast<char*>(this), sizeof(PostalWorker));
			myFile.close();
			pw[0]->Display();
		}
		else if (choose == 2) {
			pw[0] = new Clerk;
			pw[0]->inputPostalWorker();
			system("CLS");
			ofstream myFile;
			myFile.open("Parcel.txt", ios::app | ios::binary);
			myFile.write(reinterpret_cast<char*>(this), sizeof(PostalWorker));
			myFile.close();
			pw[0]->Display();
		}
		else if (choose == 3) {
			pw[0] = new Postman;
			pw[0]->inputPostalWorker();
			ofstream myFile;
			myFile.open("Parcel.txt", ios::app | ios::binary);
			myFile.write(reinterpret_cast<char*>(this), sizeof(PostalWorker));
			myFile.close();
			system("CLS");
			pw[0]->Display();
		}
		else {
			cout << "Invalid option!" << endl;
		}
		cout << endl << "Do you want to login again?" << endl;
		cout << "Press 'y' for yes otherwise press any key to exit." << endl;
		cin >> again;
	} while (again == 'y');
}

//Function to read Postal workers detail
void HeadOfPostOffice::workerRecord() {
	PostalWorker* pw[10];
	AccountOfficer ao;
	Clerk clerk;
	Postman postman;
	char again;
	int choose;
	do {
		cout << "1) Account Officer" << endl;
		cout << "2) Clerk" << endl;
		cout << "3) Postman" << endl;
		cin >> choose;
		cin.ignore();
		if (choose == 1) {
			pw[0] = new AccountOfficer;
			fstream myfile;
			myfile.open("PostalWorker.txt", ios::in | ios::binary);
			myfile.seekg(0, ios::end);
			int endPos = myfile.tellg();
			int numberOfRecords = endPos / sizeof(PostalWorker);
			cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
			int n;
			cout << "Enter the record number: ";
			cin >> n;
			int pos = (n - 1) * sizeof(PostalWorker);
			myfile.seekg(pos);
			myfile.read(reinterpret_cast<char*>(this), sizeof(PostalWorker));
			pw[0]->Display();
			myfile.close();
		}
		else if (choose == 2) {
			pw[0] = new Clerk;
			fstream myfile;
			myfile.open("PostalWorker.txt", ios::in | ios::binary);
			myfile.seekg(0, ios::end);
			int endPos = myfile.tellg();
			int numberOfRecords = endPos / sizeof(PostalWorker);
			cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
			int n;
			cout << "Enter the record number: ";
			cin >> n;
			int pos = (n - 1) * sizeof(PostalWorker);
			myfile.seekg(pos);
			myfile.read(reinterpret_cast<char*>(this), sizeof(PostalWorker));
			pw[0]->Display();
			myfile.close();
		}
		else if (choose == 3) {
			pw[0] = new Postman;
			fstream myfile;
			myfile.open("PostalWorker.txt", ios::in | ios::binary);
			myfile.seekg(0, ios::end);
			int endPos = myfile.tellg();
			int numberOfRecords = endPos / sizeof(PostalWorker);
			cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
			int n;
			cout << "Enter the record number: ";
			cin >> n;
			int pos = (n - 1) * sizeof(PostalWorker);
			myfile.seekg(pos);
			myfile.read(reinterpret_cast<char*>(this), sizeof(PostalWorker));
			pw[0]->Display();
			myfile.close();
		}
		else {
			cout << "Invalid option!" << endl;
		}
		cout << endl << "Do you want to login again?" << endl;
		cout << "Press 'y' for yes otherwise press any key to exit." << endl;
		cin >> again;
	} while (again == 'y');
}

//Function to read parcel record
void HeadOfPostOffice::parcelRecord() {
	fstream myfile;
	myfile.open("Parcel.txt", ios::in | ios::binary);
	myfile.seekg(0, ios::end);
	int endPos = myfile.tellg();
	int numberOfRecords = endPos / sizeof(Invoice);
	cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
	int n;
	cout << "Enter the record number: ";
	cin >> n;
	int pos = (n - 1) * sizeof(Invoice);
	myfile.seekg(pos);
	myfile.read(reinterpret_cast<char*>(&invoice), sizeof(invoice));
	//Display();
	myfile.close();
}

//Function to read mail record
void HeadOfPostOffice::MailRecord() {
	fstream myfile;
	myfile.open("Mail.txt", ios::in | ios::binary);
	myfile.seekg(0, ios::end);
	int endPos = myfile.tellg();
	int numberOfRecords = endPos / sizeof(Mail);
	cout << endl << "There are " << numberOfRecords << " records in the file." << endl;
	int n;
	cout << "Enter the record number: ";
	cin >> n;
	int pos = (n - 1) * sizeof(Mail);
	myfile.seekg(pos);
	myfile.read(reinterpret_cast<char*>(&mail), sizeof(mail));
	mail.Display();
	myfile.close();
}

//Display Function
void HeadOfPostOffice::Display() {
	PostalWorker::Display();
}
