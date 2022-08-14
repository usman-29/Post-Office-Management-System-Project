#include "PostOffice.h"
//Post Office Class Functions
//Default constructor
PostOffice::PostOffice() {}

//Parameterised constructor
PostOffice::PostOffice(Invoice p, Mail m) :parcel(p), mail(m) {
	parcel = p;
	mail = m;
}

//SET & GET Functions
void PostOffice::setParcel(Invoice p) {
	parcel = p;
}
void PostOffice::setMail(Mail m) {
	mail = m;
}
Invoice PostOffice::getParcel() {
	return parcel;
}
Mail PostOffice::getMail() {
	return mail;
}

//Returned mail
void PostOffice::returnedMail(ReturnedMail m) {
	r = m;
}

//Bounced mail
void PostOffice::bouncedMail(BouncedMail m) {
	b = m;
}

//Function to save parcel record in file
void PostOffice::ParcelFile() {
	ofstream myFile;
	myFile.open("Parcel.txt", ios::app | ios::binary);
	myFile.write(reinterpret_cast<char*>(&parcel), sizeof(parcel));
	myFile.close();
}

//Function to read Parcel from file
void PostOffice::trackParcel() {
	int track;
	int count = 0;
	cout << "Enter parcel ID to track: ";
	cin >> track;
	ifstream myFile;
	myFile.open("Parcel.txt", ios::in);
	myFile.seekg(0, ios::end);
	int endPos = myFile.tellg();
	myFile.seekg(0);
	int numberOfRecords = endPos / sizeof(Invoice);
	system("CLS");
	for (int i = 0; i < numberOfRecords; i++) {
		myFile.read(reinterpret_cast<char*>(&parcel), sizeof(parcel));
		if (parcel.getID() == track) {
			parcel.Display();
			count++;
		}
	}
	myFile.close();
	if (count == 0) {
		cout << "No parcel found with this track ID: " << track << endl;
	}
}

//Function to save Mail in file
void PostOffice::MailFile() {
	ofstream myFile;
	myFile.open("Mail.txt", ios::app | ios::binary);
	myFile.write(reinterpret_cast<char*>(&mail), sizeof(mail));
	myFile.close();
}

//Function to read mail from file
void PostOffice::trackMail() {
	int track;
	int count = 0;
	cout << "Enter Mail ID to track: ";
	cin >> track;
	ifstream myFile;
	myFile.open("Mail.txt", ios::in | ios::binary);
	myFile.seekg(0, ios::end);
	int endPos = myFile.tellg();
	myFile.seekg(0);
	int numberOfRecords = endPos / sizeof(Invoice);
	system("CLS");
	for (int i = 0; i < numberOfRecords; i++) {
		myFile.read(reinterpret_cast<char*>(&mail), sizeof(mail));
		if (parcel.getID() == track) {
			parcel.Display();
			break;
		}
		else {
			cout << "No Mail found!" << endl;
		}
	}
	if (count == 0) {
		cout << "No mail found with this track ID: " << track << endl;
	}
	myFile.close();
}

//Shipment Class Functions
//Function to recieve parcel from post office
void Shipment::setParcel() {
	p = post.getParcel();
}

//Function to deliver the parcel
void Shipment::shipped() {
	if (p.getParcel().getID() != NULL) {
		cout << "Parcel shipped successfully!" << endl;
	}
	else {
		cout << "Parcel not shipped!";
	}
}


//GPO Class Functions 

//Function to get mail from post office
void GPO::setMail() {
	m = post.getMail();
}

//Function to send mail to postman
Mail GPO::getMail() {
	return post.getMail();
}



