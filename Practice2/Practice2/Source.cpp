//Post Office Management System Project
#include<iostream>
#include<Windows.h>
#include"PostOffice.h"
#include"PostalWorkers.h"
#include"Parcel.h"
#include"Payment.h"
#include"Mail.h"
using namespace std;
//Function prototypes
void Login();
void sendParcel();
void sendMail();
bool _Payment();

int main()
{
	char again;
	do {
		system("CLS");
		cout << "\tPakistan Post Office" << endl;
		Login();
		cout << endl << "Do you want to login again?" << endl;
		cout << "Press 'y' for yes otherwise press any key to exit." << endl;
		cin >> again;
	} while (again == 'y');
	system("pause");
	return 0;
}

//Function to login
void Login() {
	int login;
	int courier;
	cout << "1) Send Mail/Parcel" << endl;
	cout << "2) Track Mail/Parcel" << endl;
	cout << "3) Account Officer" << endl;
	cout << "4) Head of Post Office" << endl;
	cout << "Enter (number): ";
	cin >> login;
	cin.ignore();
	system("CLS");
	cout << "Welcome!" << endl;
	switch (login) {
	case 1: {
		cout << "What do you want to send? " << endl;
		cout << "1) Parcel" << endl;
		cout << "2) Mail" << endl;
		cout << "Enter (number): ";
		cin >> courier;
		cin.ignore();
		if (courier == 1) {
			sendParcel();
		}
		else if (courier == 2) {
			sendMail();
		}
		else {
			cout << "Invalid option!" << endl;
		}
		break;
	}
	case 2: {
		int choose;
		cout << "What do you want to track?" << endl;
		cout << "1) Parcel" << endl;
		cout << "2) Mail" << endl;
		cout << "Enter (number): ";
		cin >> choose;
		cin.ignore();
		PostOffice post;
		if (choose == 1) {
			post.trackParcel();
			break;
		}
		else if (choose == 2) {
			post.trackMail();
			break;
		}
		else {
			cout << "Invalid option!" << endl;
			break;
		}
	}
	case 3: {
		system("CLS");
		int pass;
		cout << "Enter password: ";
		cin >> pass;
		AccountOfficer ao;
		if (ao.checkPassword(pass) == true) {
			int num;
			cout << "1) Parcel Record" << endl;
			cout << "2) Mail Record" << endl;
			cout << "Enter (number): ";
			cin >> num;
			if (num == 1) {
				ao.parcelRecord();
				break;
			}
			else if (num == 2) {
				ao.MailRecord();
				break;
			}
			else {
				cout << "Invalid option!" << endl;
			}
		}
		else {
			cout << "Wrong password!" << endl;
		}
	}
	case 4: {
		system("CLS");
		int pass;
		cout << "Enter password: ";
		cin >> pass;
		HeadOfPostOffice h;
		if (h.checkPassword(pass) == true) {
			h.workersMenu();
		}
		else {
			cout << "Wrong password!" << endl;
		}
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		break;
	}
	}
}

//Function to send parcel
void sendParcel() {
	system("CLS");
	cout << "Enter Sender's Information: " << endl;
	Customer sender;
	sender.inputCustomer();
	system("CLS");
	Customer reciever;
	cout << "Enter Reciever's Information: " << endl;
	reciever.inputCustomer();
	system("CLS");
	cout << "Enter Parcel Information: " << endl;
	Parcel parcel;
	parcel.inputParcel();
	Date date;
	cout << "Enter date: " << endl;
	date.inputDate();
	Charges ch;
	ch.calculate_charges(parcel.getWeight());
	Clerk clerk;
	float _stamp;
	_stamp = clerk.buyStamp(parcel.getWeight());
	ch.stampCharges(_stamp);
	int _urgent;
	do {
		cout << "1) Urgent" << endl;
		cout << "2) Normal" << endl;
		cout << "Delivery mode: ";
		cin >> _urgent;
	} while (_urgent != 1 && _urgent != 2);
	if (_urgent == 1) {
		ch.Urgent_Parcel_Charges();
		date.Urgent_Date();
	}
	else {
		date.Normal_Date();
	}
	system("CLS");
	PostOffice pOffice;
	Shipment ship;
	if (_Payment() == true) {
		Invoice invoice(sender, reciever, date, parcel, ch);
		pOffice.setParcel(invoice);
		pOffice.ParcelFile();
		ship.setParcel();
		ship.shipped();
		system("CLS");
		invoice.Display();
	}
}

//Function to send mail
void sendMail() {
	system("CLS");
	cout << "Enter Sender's Information: " << endl;
	Customer sender;
	sender.inputCustomer();
	system("CLS");
	cout << "Enter Reciever's Information: " << endl;
	Customer reciever;
	reciever.inputCustomer();
	system("CLS");
	cout << "Enter Mail Information: " << endl;
	int choose;
	do {
		cout << "1) Urgent Mail Service" << endl;
		cout << "2) Regular Mail service" << endl;
		cout << "Delivery mode: ";
		cin >> choose;
	} while (choose != 1 && choose != 2);
	Urgent urgent;
	Regular regular;
	float _weight;
	Clerk clerk;
	float _stamp;
	Payment pay;
	PostOffice pOffice;
	Postman pMan;
	GPO gpo;
	if (choose == 1) {
		cout << "Enter weight: ";
		cin >> _weight;
		while (_weight < 0.1) {
			cout << "Invalid weight!. Must be greater than 0." << endl;
			cin >> _weight;
		}
		urgent._setWeight(_weight);
		urgent.Calculate_Charges(_weight);
		_stamp = clerk.buyStamp(_weight);
		urgent.stampCharges(_stamp);
		urgent.SetDays();
		Mail mail(urgent, sender, reciever);
		mail.setID();
		system("CLS");
		if (_Payment() == true) {
			pOffice.setMail(mail);
			pOffice.MailFile();
			gpo.setMail();
			gpo.getMail();
			pMan.RecieveMail();
			pMan.delivered();
			Sleep(2000);
			system("CLS");
			mail.Display();
		}
	}
	else {
		cout << "Enter weight: ";
		cin >> _weight;
		while (_weight < 0.1) {
			cout << "Invalid weight!. Must be greater than 0." << endl;
			cin >> _weight;
		}
		regular.set_Weight(_weight);
		regular.Calculate_Charges(_weight);
		_stamp = clerk.buyStamp(_weight);
		regular.stampCharges(_stamp);
		regular.SetDays();
		Mail mail(regular, sender, reciever);
		mail.setID();
		system("CLS");
		if (_Payment() == true) {
			pOffice.setMail(mail);
			pOffice.MailFile();
			gpo.setMail();
			gpo.getMail();
			pMan.RecieveMail();
			pMan.delivered();
			Sleep(2000);
			system("CLS");
			mail.Display();
		}
	}
}

//Function to do payment
bool _Payment() {
	Payment pay;
	cout << "Card information: " << endl;
	pay.Input_Card_Details();
	if (pay.isPayment_Done() == true) {
		cout << endl << "Payment Done Successfully!" << endl;
		cout << "Wait...";
		Sleep(4000);
		return true;
	}
	else {
		cout << "Payment not found";
		return false;
	}
}


