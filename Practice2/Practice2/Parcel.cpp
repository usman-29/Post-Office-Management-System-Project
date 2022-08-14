#include "Parcel.h"

//Address Class Functions
//Default constructor
Address::Address() {
	StreetNo = 0;
	HouseNo = 0;
	PostalCode = 0;
}

//Parameterised constructor
Address::Address(string city, string area, int street, int house, int postal) : City(city), Area(area), StreetNo(street), HouseNo(house), PostalCode(postal) {

}

//SET & GET Functions
void Address::setCity(string city) {
	City = city;
}
void Address::setArea(string area) {
	Area = area;
}
void Address::setStreet(int street) {
	StreetNo = street;
}
void Address::setHouse(int house) {
	HouseNo = house;
}
void Address::setPostal(int postal) {
	PostalCode = postal;
}
string Address::getCity() {
	return City;
}
string Address::getArea() {
	return Area;
}
int Address::getStreet() {
	return StreetNo;
}
int Address::getHouse() {
	return HouseNo;
}
int Address::getPostal() {
	return PostalCode;
}

//Input Address function
void Address::inputAddress() {
	cout << "City: ";
	getline(cin, City);
	cout << "Area: ";
	getline(cin, Area);
	cout << "Street no.: ";
	cin >> StreetNo;
	while (StreetNo < 1) {
		cout << "Invalid street number!. Must be greater than 0." << endl;
		cin >> StreetNo;
	}
	cout << "House no.: ";
	cin >> HouseNo;
	while (HouseNo < 1) {
		cout << "Invalid house number!. Must be greater than 0." << endl;
		cin >> HouseNo;
	}
	cout << "Postal code: ";
	cin >> PostalCode;
	while (PostalCode < 1) {
		cout << "Invalid postal code!. Must be greater than 0." << endl;
		cin >> PostalCode;
	}
}

//Display function
void Address::Display() {
	cout << "City: " << City << endl;
	cout << "Area: " << Area << endl;
	cout << "Street no.: " << StreetNo << endl;
	cout << "House no.: " << HouseNo << endl;
	cout << "Postal code: " << PostalCode << endl;
}

//Customer Class Functions
//Default constructor
Customer::Customer() {
	Name = "";
	PhoneNo = 0;
}

//Parameterised constructor
Customer::Customer(string name, Address add, long int phone) : Name(name), address(add), PhoneNo(phone) {

}

//SET & GET Functions
void Customer::setName(string name) {
	Name = name;
}
void Customer::setAddress(Address add) {
	address = add;
}
void Customer::setPhone(long long int phone) {
	PhoneNo = phone;
}
string Customer::getName() {
	return Name;
}
Address Customer::getAddress() {
	return address;
}
long long int Customer::getPhone() {
	return PhoneNo;
}

//Input Customer details function
void Customer::inputCustomer() {
	cout << "Name: ";
	getline(cin, Name);
	cout << "Address: " << endl;
	address.inputAddress();
	cout << "Phone no.: ";
	cin >> PhoneNo;
	while (PhoneNo < 1) {
		cout << "Invalid phone number!. Must be greater than 0." << endl;
		cin >> PhoneNo;
	}
	cin.ignore();
}

//Display function
void Customer::Display() {
	cout << "Name: " << Name << endl;
	cout << "Address: " << endl;
	address.Display();
	cout << "Phone number: " << PhoneNo << endl;
}

//Date Class Functions
//Default constructor
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

//Parameterised constructor
Date::Date(int d, int m, int y) :day(d), month(m), year(y) {

}

//SET & GET Functions
void Date::setDay(int d) {
	day = d;
}
void Date::setMonth(int m) {
	month = m;
}
void Date::setYear(int y) {
	year = y;
}
int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}

//Urgent delivery date function
void Date::Urgent_Date() {
	day += 1;
	if (day > 31) {
		day = 1;
		month += 1;
		if (month > 12) {
			month = 1;
			year += 1;
		}
	}
}

//Normal delivery date function
void Date::Normal_Date() {
	srand((unsigned int)time(NULL));
	day = day + (2 + rand() % 7);
	if (day > 31) {
		day = 1;
		month += 1;
		if (month > 12) {
			month = 1;
			year += 1;
		}
	}
}

//Input date function
void Date::inputDate() {
	cout << "Day: ";
	cin >> day;
	while (day < 1 || day > 31) {
		cout << "Invalid day!. Must be between 1 and 31." << endl;
		cin >> day;
	}
	cout << "Month: ";
	cin >> month;
	while (month < 1 || month > 12) {
		cout << "Invalid month!. Must be between 1 and 12." << endl;
		cin >> month;
	}
	cout << "Year: ";
	cin >> year;
	while (year < 2022) {
		cout << "Invalid year!." << endl;
		cin >> year;
	}
}

//Display function
void Date::Display() {
	cout << day << "/" << month << "/" << year << endl;
}


//Dimesnion Class Functions
//Default constructor
Dimension::Dimension() {
	length = 0;
	width = 0;
	height = 0;
}

//Parameterised constructor
Dimension::Dimension(float l, float w, float h) :length(l), width(w), height(h) {

}

//SET & GET Functions
void Dimension::setLength(float l) {
	length = l;
}
void Dimension::setWidth(float w) {
	width = w;
}
void Dimension::setHeight(float h) {
	height = h;
}
float Dimension::getLength() {
	return length;
}
float Dimension::getWidth() {
	return width;
}
float Dimension::getHeight() {
	return height;
}

//Input dimension function
void Dimension::inputDimension() {
	cout << "Length: ";
	cin >> length;
	while (length < 1) {
		cout << "Invalid length!. Must be greater than 0." << endl;
		cin >> length;
	}
	cout << "Width: ";
	cin >> width;
	while (width < 1) {
		cout << "Invalid width!. Must be greater than 0." << endl;
		cin >> width;
	}
	cout << "Height: ";
	cin >> height;
	while (height < 1) {
		cout << "Invalid height!. Must be greater than 0." << endl;
		cin >> height;
	}
}

//Display function
void Dimension::Display() {
	cout << length << "\" x " << width << "\" x " << height << endl;
}

//Parcel Class Functions
//Default constructor
Parcel::Parcel() {
	parcel_ID = 0;
	parcel_Weight = 0;
}

//Parameterised constructor
Parcel::Parcel(int id, float w, Dimension d) :parcel_ID(id), parcel_Weight(w), parcel_Dimension(d) {

}

//SET & GET Functions
void Parcel::setID() {
	srand(time(0));
	int stack[100];
	for (int i = 0; i < 100; i++) {
		stack[i] = ((rand() * rand()) % 5000) + 100;
		if (stack[i] < 0) {
			stack[i] *= (-1);
		}
	}
	int x = rand() % 100;
	parcel_ID = stack[x];
}
void Parcel::setWeight(float w) {
	parcel_Weight = w;
}
void Parcel::setDimension(Dimension d) {
	parcel_Dimension = d;
}
int Parcel::getID() {
	return parcel_ID;
}
float Parcel::getWeight() {
	return parcel_Weight;
}
Dimension Parcel::getDimension() {
	return parcel_Dimension;
}

//Input Parcel details
void Parcel::inputParcel() {
	setID();
	parcel_ID = getID();
	cout << "Weight: ";
	cin >> parcel_Weight;
	while (parcel_Weight < 0.1) {
		cout << "Invalid weight!. Must be greater than 0." << endl;
		cin >> parcel_Weight;
	}
	parcel_Dimension.inputDimension();
}

//Display function
void Parcel::Display() {
	cout << "ID: " << parcel_ID << endl;
	cout << "Weight: " << parcel_Weight << endl;
	cout << "Dimension; " << endl;
	parcel_Dimension.Display();
}

//Charges Class Functions
//Default constructor
Charges::Charges() {
	s = 0;
	charges = 0;
}

//Function to calculate charges
void Charges::calculate_charges(float w) {
	//Charges depending upon mail weight (kg)
	if (w <= 1) {
		charges = 100;
	}
	else if (w <= 3) {
		charges = 175;
	}
	else if (w <= 5) {
		charges = 250;
	}
	else if (w <= 10) {
		charges = 375;
	}
	else if (w <= 15) {
		charges = 500;
	}
	else if (w <= 20) {
		charges = 625;
	}
	else if (w <= 25) {
		charges = 750;
	}
	else if (w <= 30) {
		charges = 870;
	}
	else {
		charges = w * 35;
	}
	charges += 75; //+75 for registration fee
}

//Function to get stamp charges
void Charges::stampCharges(float _stamp) {
	s = _stamp; //to get stamp charges
	charges += s;
}

//Urgent service charges
void Charges::Urgent_Parcel_Charges() {
	float extra;
	extra = charges * 20 / 100;
	charges += extra;
}

//Get function
float Charges::getCharges() {
	return charges;
}

//Display function
void Charges::Display() {
	cout << "Registration fee: RS.75" << endl;
	cout << "Stamp charges: Rs." << s << endl;
	cout << "Total charges: RS." << charges << endl;
}

//Invoice Class Functions
//Default constructor
Invoice::Invoice() {}

//Parameterised constructor
Invoice::Invoice(Customer s, Customer r, Date d, Parcel p, Charges c) :Sender(s), Reciever(r), date(d), parcel(p), charges(c) {

}

//SET & GET Functions
void Invoice::setSender(Customer s) {
	Sender = s;
}
void Invoice::setReciever(Customer r) {
	Reciever = r;
}
void Invoice::setDate(Date d) {
	date = d;
}
void Invoice::setParcel(Parcel p) {
	parcel = p;
}
Customer Invoice::getSender() {
	return Sender;
}
Customer Invoice::getReciever() {
	return Reciever;
}
Parcel Invoice::getParcel() {
	return parcel;
}
int Invoice::getID() {
	return parcel.getID();
}

//Display function
void Invoice::Display() {
	cout << "Sender information: " << endl;
	Sender.Display();
	cout << endl;
	cout << "Reciever information: " << endl;
	Reciever.Display();
	cout << endl;
	cout << "Date: ";
	date.Display();
	cout << endl;
	cout << "Parcel information: " << endl;
	parcel.Display();
	charges.Display();
}
