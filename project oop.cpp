// project oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include <stdlib.h>
#include<iomanip>
using namespace std;
template <class T>
////formatted output function///////
void PrintMessage(T message, bool printTop = true, bool printBottom = true)
{
	if (printTop)
	{
		cout << "\t\t\t\t\t\t\t*----------------------------------------------------------*" << endl;
		cout << "\t\t\t\t\t\t\t|";
	}
	else
		cout << "\t\t\t\t\t\t\t|";
	bool front = true;
	for (int i = message.length(); i < 58; i++)
	{
		if (front)
			message = " " + message;
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message;
	if (printBottom)
	{
		cout << "|" << endl;
		cout << "\t\t\t\t\t\t\t*----------------------------------------------------------*" << endl;

	}
	else
		cout << "|" << endl;

}
///welcome///
void welcomeSign()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t\t" << "============================================"<<endl;
	cout << "\t\t\t\t\t\t\t\t" << "           BEARED BROS AUTOS                "<<endl;
	cout << "\t\t\t\t\t\t\t\t" << "============================================"<<endl;
}
/////file input ouput////
void writeinFile(string path, string var)
{
	ofstream fout(path.c_str(), ios::app);
	fout.is_open();
	fout << var << endl;
	fout.close();
}
void loadWord(string path,vector<string>& v)
{
	string word;
	ifstream fin(path.c_str(),ios::in);
	while (getline(fin, word))
	{
		v.push_back(word);
	}
	fin.close();
}
/////Purchase Detailses/////
void userData(string username, string email, string car, string color, string city, string payMeth, double Model, double price, double percentage, double year)
{
	cout << endl << endl;
	PrintMessage("BEARED BROS AUTOS");
	PrintMessage("USERNAME:        ", true, false);
	PrintMessage(username, false);
	PrintMessage("EMAIL:           ", false, false);
	PrintMessage(email, false);
	PrintMessage("CAR NAME:        ", false, false);
	PrintMessage(car, false);
	PrintMessage("COLOR:           ", false, false);
	PrintMessage(color, false);
	PrintMessage("MODEL:           ", false, false);
	PrintMessage(Model, false);
	PrintMessage("REGISTRATION CITY:  ", false, false);
	PrintMessage(city, false);
	PrintMessage("PRICE IN DOLLARS: ", false, false);
	PrintMessage(price, false);
	PrintMessage("PAYMENT METHOD:   ", false, false);
	PrintMessage(payMeth, false);
	PrintMessage("DOWN PAYMENT(%):  ", false, false);
	PrintMessage(percentage, false);
	PrintMessage("TIME IN YEARS:     ", false, false);
	PrintMessage(year, false);
	PrintMessage("YOUR ORDER WILL BE DELIVERED IN 30 DAYS");
}
/////storing user data///////
void saveUserData(string path,string username, string email, string car, string color, string city, string payMeth, double Model, double price, int percentage, int year)
{
	ofstream fout(path.c_str(), ios::app);
	fout.is_open();
	fout << username << "  " << email << "  " << car << "  " << color << " " << city << "  " << payMeth << "  " << Model << "  " << price << "  " << percentage << "  " << year << endl;
	fout.close();
}

///////starting AND FILING////
class startUp
{
	string username;
	string email;
	string password;
	vector<string>Usercheck;
	vector<string>emailCheck;
	vector<string>Passcheck;
	int choice;
  public:
	startUp()
	{
		username = "";
		email = "";
	}
	void welcomePage()
	{
		PrintMessage("Beared Brothers Autos");
		PrintMessage("welcome to beared bros Autos ", false, false);
		PrintMessage("We deliver High quality and most trustable", false, false);
		PrintMessage("vehicles in town !!!", false, false);
		PrintMessage("your partners in save and comfortable journey");
	}
	void userData()
	{
		system("pause"); system("cls");
		PrintMessage("Beared Bros Autos");
		PrintMessage("press 1.To sign Up", false, false);
		PrintMessage("Press 2.To Log in", false, false);
		PrintMessage("your partners in save and comfortable journey");
	}
	
	void signUp()
	{
		welcomeSign();
		cout << "\n\n";
		cout << "\t\t\t\t\t\t\t\t" << "Enter Your Username: "; cin >> username;
		cout << "\t\t\t\t\t\t\t\t" << "Enter Your Email: "; cin >> email;
		cout << "\t\t\t\t\t\t\t\t" << "Enter Your Password: ";
		char ch=' ';
		while (ch != 13)////ascii of enter
		{
			ch = _getch();
			password += ch;
			cout << "x";
		}
	    	writeinFile("usernames.txt", username);
			writeinFile("emails.txt", email);
			writeinFile("passwords.txt", password);
			cout << "\n\t\t\t\t\t\t\t\t" << "Suceesfull Signup ";
				 
		
	}

	void login()
	{
		/////username check////
		bool flag = false;
		int x = 0, temp = 0, y;
		loadWord("usernames.txt", Usercheck);
	y:
		{
			temp = 0;
			welcomeSign();
			cout << "\n\n";
			cout << "\t\t\t\t\t\t\t\t" << "Enter Your Username: "; cin >> username;
		}
		for (int i = 0; i < Usercheck.size(); i++)
		{
			if (string(username) == string(Usercheck[i]))
			{
				temp=i;
				flag = true;
				break;
			}
		}


		if (!flag && x < Usercheck.size())
		{
			x++;
			system("cls");
			cout << "\t\t\t\t\t\t\t\t" << "Invalid Username";
			goto y;

		}
		else if (!flag)
		{
			cout << "\t\t\t\t\t\t\t\t" << "Access denied";
			cout << "\n\t\t\t\t\t\t\t\t" << "Press 1 to exit";
			cout << "\n\t\t\t\t\t\t\t\t" << "press 2 to sign up";
			cin >> choice;
			if (choice == 1)
				exit(0);
			else if (choice == 2)
				signUp();
		}
		/////////email check///////
		flag = false;
		x = 0; int z;
		loadWord("emails.txt", emailCheck);
		system("cls");
	z:
		{
			welcomeSign();
			cout << "\n\n";
			cout << "\t\t\t\t\t\t\t\t" << "Enter Your Username: "; cout << username << endl;
			cout << "\t\t\t\t\t\t\t\t" << "Enter Your Email: "; cin >> email;
		}
		for (int i = 0; i < emailCheck.size(); i++)
		{
			if (string(email) == string(emailCheck[temp]))
			{
				flag = true;
				break;
			}
		}


		if (!flag && x < emailCheck.size())
		{
			x++;
			system("cls");
			cout << "\t\t\t\t\t\t\t\t" << "Invalid Email";
			goto z;

		}
		else if (!flag)
		{
			cout << "\t\t\t\t\t\t\t\t" << "Access denied";
			cout << "\n\t\t\t\t\t\t\t\t" << "Press 1 to exit";
			cout << "\n\t\t\t\t\t\t\t\t" << "press 2 to sign up";
			cin >> choice;
			if (choice == 1)
				exit(0);
			else if (choice == 2)
				signUp();
		}
		/////password check///////
		flag = false;
		x = 0; int v;
		loadWord("passwords.txt",Passcheck);
		system("cls");
	v:
		{
			welcomeSign();
			cout << "\n\n";
			cout << "\t\t\t\t\t\t\t\t" << "Enter Your Username: "; cout << username << endl;
			cout << "\t\t\t\t\t\t\t\t" << "Enter Your Email: "; cout << email << endl;
			cout << "\t\t\t\t\t\t\t\t" << "Enter Your Password: ";
			char ch=' ';
			while (ch != 13)
			{
				ch = _getch();
				password += ch;
				cout << "x";
			}
			for (int i = 0; i < Passcheck.size(); i++)
			{
				if (string(password) == string(Passcheck[temp]))
				{
					flag = true;
					cout << "\n\t\t\t\t\t\t\t\t" << "Successfull Login ";
					
					break;
				}
			}


			if (!flag && x < Passcheck.size())
			{
				x++;
				system("cls");
				cout << "\t\t\t\t\t\t\t\t" << "Invalid Password";
				goto v;

			}
			else if (!flag)
			{
				cout << "\t\t\t\t\t\t\t\t" << "Access denied";
				cout << "\n\t\t\t\t\t\t\t\t" << "Press 1 to exit";
				cout << "\n\t\t\t\t\t\t\t\t" << "press 2 to sign up";
				cin >> choice;
				if (choice == 1)
					exit(0);
				else if (choice == 2)
					signUp();
			}
		}
	}
	string getEmail()
	{
		return email;
	}
	string getUserName()
	{
		return username;
	}
	friend void loadUserData(string path, startUp s, string& username, string& email, string& car, string& color, string& city, string& payMeth, double& Model, double& price, int& percentage, int& year);
	
};
void loadUserData(string path, startUp s, string& username, string& email, string& car, string& color, string& city, string& payMeth, double& Model, double& price, int& percentage, int& year)
{
	ifstream fin(path.c_str());
	fin.is_open();
	while (fin >> username >> email >> car >> color >> city >> payMeth >> Model >> price >> percentage >> year)
	{
		string e;
		e = s.getUserName();
		if (string(username) == string(e))
		{
			
			break;
		}
		
	}
}
class registrationDetails
{
	int modelYear;
	string regDetails;
public:
	registrationDetails(int m = 2000, string RC = "LHR")
	{
		modelYear = m;
		regDetails = RC;
	}
	void setModel(int m)
	{
		this->modelYear = m;
	}
	int getModel()
	{
		return modelYear;
	}
	void setCity(string c)
	{
		regDetails = c;
	}
	string getCity()
	{
		return regDetails;
	}
	void printregDetails()
	{
		cout << "\n Model Year: " << modelYear ;
		cout << "\nRegistration city: " << regDetails ;
	}
};
//////parent class///////
class Car
{
protected:
	
	string carName;
	registrationDetails RD;
	string bodyColor;
	int engineCapacity;
	string Transmission;
	double Mileage;
	double Price;
	double percentage;
public:
	Car() :carName(""), bodyColor(""), engineCapacity(0), Transmission(""), Mileage(0.0), Price(0)
	{

	}
	Car(string cn, registrationDetails rd, string bc, int ec, string t, double m, double p)
	{
		carName = cn;
		RD = rd;
		bodyColor = bc;
		engineCapacity = ec;
		Transmission = t;
		Mileage = m;
		Price = p;

	}
	/// <summary>
	/// getting memebers
	/// </summary>
	/// <returns></returns>
	int getCarModel()
	{
		return RD.getModel();
	}
	string getCarCity()
	{
		return RD.getCity();
	}
	string getBodyColor()
	{
		return bodyColor;
	}
	int getEngnCapacity()
	{
		return engineCapacity;
	}
	string getTransmission()
	{
		return Transmission;
	}
	double getPrice()
	{
		return Price;
	}
	double getMileage()
	{
		return Mileage;
	}
	string getCarname()
	{
		return carName;
	}
	/// ////setting up members ////////
	void setMileage(double m)
	{
		Mileage = m;
	}
	void setPrice(double p)
	{
		Price = p;
	}
	void setTransmission(string T)
	{
		Transmission = T;
	}
	void setEngnCapacity(int C)
	{
		engineCapacity = C;
	}
	void setModelYear(int my)
	{
		RD.setModel(my);
	}
	void setRegCity(string cy)
	{
		RD.setCity(cy);
	}
	void setBodyColor(string Bc)
	{
		bodyColor = Bc;
	}
	void setCarName(string n)
	{
		carName = n;
	}
	void PrintCarDetailes()
	{
		cout << "\n Name: " << carName;
		RD.printregDetails();
		cout << "\n Engine Capacity: " << engineCapacity;
		cout << "\n Body Color: " << bodyColor;
		cout << "\n Mileage: " << Mileage;
		cout << "\n Transmission: " << Transmission;
		cout << "\n Price: " << Price;

	}
	double InstallmentPlan()
	{
		percentage = 0;
		cout << "\n Selected Cars: " << carName;
		cout << "\n Model Year: " << RD.getModel();
		cout << "\n Price of The Cars: " << Price;
		cout << endl << endl;
		double years;
		
		cout << "\n Enter initial amount deposit percentage:(20,30,40,50) ";
		cin >> percentage ;
		cout << "\n You chosse " << percentage << '%';
		if (percentage == 20)
		{
			cout << "\n Initial Deposit: " << '$' << (Price * 20) / 100;
		}
		else if (percentage == 30)
		{
			cout << "\n Initial Deposit: " << '$' << (Price * 30) / 100;
		}
		else if (percentage == 40)
		{
			cout << "\n Initial Deposit: " << '$' << (Price * 40) / 100;
		}
		else if (percentage == 50)
		{
			cout << "\n Initial Deposit: " << '$' << (Price * 50) / 100;
		}
		else
		{
			cout << "\n No Package available for such percentage of initial pricce we are sorry for miss convenience!!";
		}
		cout << "\n\n Choose Tenure (1,2,3,4,5) years: "; cin >> years;
			if (years == 1)
			{
				double rate = Price - ((Price * percentage) / 100);
				rate = (rate / 12) * 1.20;
				cout << "\n Number of months: " << 12 << endl;
				cout << "\n Monthly Payment: " << '$' << rate;
			}
			else if (years == 2)
			{
				double rate = Price - ((Price * percentage) / 100);
				rate = (rate / 24) * 1.30;
				cout << "\n Number of months: " << 24 << endl;
				cout << "\n Monthly Payment: " << '$' << rate;

			}
			else if (years == 3)
			{
				double rate = Price - ((Price * percentage) / 100);
				rate = (rate / 36) * 1.35;
				cout << "\n Number of months: " << 36 << endl;
				cout << "\n Monthly Payment: " << '$' << rate;
			}
			else if (years == 4)
			{
				double rate = Price - ((Price * percentage) / 100);
				rate = (rate / 48) * 1.40;
				cout << "\n Number of months: " << 48 << endl;
				cout << "\n Monthly Payment: " << '$' << rate;
			}
			else if (years == 5)
			{
				double rate = Price - ((Price * percentage) / 100);
				rate = (rate / 60) * 1.45;
				cout << "\n Number of months: " << 60 << endl;
				cout << "\n Monthly Payment: " << '$' << rate;
			}
			else 
				cout << "\n No Package available for this tunure we are sorry for miss convenience!!";
			return years;
	}
	int getPerc()
	{
		return percentage;
	}
};
class japaneseCars :public Car
{
	int mileageInnCity;
	bool Ac;
	int fuelECO;
public:
	japaneseCars() :mileageInnCity(0), Ac(false), fuelECO(0)
	{

	}
	void setJapaneseCars(string cn, registrationDetails R, string b, int e, string t, double m, double p, bool A, int min, int fc)
	{
		///////set back to PrintDetails in Parent class/////
		carName = cn;
		RD = R;
		bodyColor = b;
		engineCapacity = e;
		Transmission = t;
		Mileage = m;
		Price = p;
		mileageInnCity = min;
		Ac = A;
		fuelECO = fc;
	}
	void getJapaneseValues(japaneseCars* J, const int size)
	{
		registrationDetails * R = new registrationDetails[size]; ///request to initialize memory and R points to this memory 
		int model = 2012;
		for (int index = 0;index < size; index++)
		{
			R[index].setCity("RWP");
			R[index].setModel(model);
			model += 2;
		}
		J[0].setJapaneseCars("Daihatsu-Mira", R[0], "Crimson-Black", 660, "Automatic", 18.75, 5700, true, 17.3, 33);
		J[1].setJapaneseCars("suzuki-Alto", R[1], "Light-Blue", 660, "Automatic", 17.55, 4700, false, 16.3, 30);
		J[2].setJapaneseCars("Honda-N-One", R[2], "Jet-Red", 660, "Automatic", 19.75, 6700.0, true, 18.3, 36);
		J[3].setJapaneseCars("Daihatsu-Move", R[3], "Dark-Grey", 660, "Automatic", 20.75, 5900, true, 19.3, 38);
	}
	void setMinCity(int m)
	{
		mileageInnCity = m;
	}
	int getMinCity()
	{
		return mileageInnCity;
	}
	void setAc(bool A)
	{
		Ac = A;
	}
	bool getAc()
	{
		return Ac;
	}
	void setFuel(int F)
	{
		fuelECO = F;
	}
	int getFuel()
	{
		return fuelECO;
	}
	void PrintJapDetails()
	{
		PrintCarDetailes();
		cout << "\n Ac: ";
			if (Ac)
			{
				cout << "Yes ";
			}
			else
			{
				cout << "No ";
			}
			cout << "\n Mileage In City: " << mileageInnCity << " Km/h";
			cout << "\n Fuel Economy: " << fuelECO << " mpg";
	}

};
class HatchBacks :public Car
{
	int bootSpace;
	int noOfDoors;
public:
	HatchBacks() :bootSpace(0), noOfDoors(0)
	{

	}
	void setHatchBacks(string cn, registrationDetails R, string b, int e, string t, double m, double p, int bs, int door)
	{
		carName = cn;
		RD = R;
		bodyColor = b;
		engineCapacity = e;
		Transmission = t;
		Mileage = m;
		Price = p;
		bootSpace = bs;
		noOfDoors = door;
	}
	void getHatchBacks(HatchBacks* H, const int size) ////array is pass as pointer ///
	{
		registrationDetails* R = new registrationDetails[size];
		int model = 2013;
		for (int i = 0; i < size;i++)
		{
			R[i].setCity("FSD");
			R[i].setModel(model);
			model++;
		}
		H[0].setHatchBacks("Toyota-Pruis", R[0], "Silver-Metallic", 1798, "Automatic", 26.24, 12000, 38, 4);
		H[1].setHatchBacks("Ford-Focus", R[1], "Tangerine-Scream", 1696, "Automatic", 19.33,13645,35, 4);
		H[2].setHatchBacks("Chevrolet-Spark", R[2], "Denim", 995, "Automatic", 22.25, 9000, 41, 4);
		H[2].setHatchBacks("Nissan-Juke", R[3], "Automic-Gold", 1598, "Automatic", 23.64, 14500, 48, 4);
	}
	int getDoors()
	{
		return noOfDoors;
	}
	void setSpace(int s)
	{
		bootSpace = s;
	}
	void PrintCarDetails()
	{
		Car::PrintCarDetailes(); //cars
		cout << "\n Cargo Space: " << bootSpace << "mitres";
		cout << "\n Total Doors: " << noOfDoors;

	}
};

class superCars :public Car
{
	int horsePower;
	float topSpeed;
public:
	superCars()
	{
		horsePower = 0;
		topSpeed = 0;
	}
	superCars(string Cn, registrationDetails R, string b, int e, string t, double m, double P, int hp, float ts) :Car::Car(Cn, R, b, e, t, m, P)
	{
		horsePower = hp;
		topSpeed = ts;
	
	}
	void AssignElement(string Cn, registrationDetails R, string B, int e, string t, double m, double p, int hp, float ts)
	{
		carName = Cn;
		RD = R;
		bodyColor = B;
		engineCapacity = e;
		Transmission = t;
		Mileage = m;
		Price = p;
		horsePower = hp;
		topSpeed = ts;
	}
	void insertValues(superCars S[], const int size=4)/////same as introducing pointer as in previous /////
	{
		registrationDetails R[4];      ////same as above 
		int model = 2012;
		for (int i = 0; i < size; i++)
		{
			R[i].setCity("KHI");
			R[i].setModel(model);
			model += 3;
		}
		S[0].AssignElement("Mclaren-720-S", R[0], "Yellow", 3496, "Manual", 9, 28000,660, 412);
		S[1].AssignElement("Ferrari", R[1], "Carbon-Green", 3496, "Manual", 8, 32000, 670, 426);
		S[2].AssignElement("Mclaren-720-Z", R[3], "Black", 3496, "Manual", 9, 22000, 660, 402);
		S[3].AssignElement("Ford-GT", R[3], "Yellow", 3496, "Manual", 9, 25000, 580, 396);
	}
	void setTSPeed(float t)
	{
		topSpeed = t;
	}
	float getSpeed()
	{
		return topSpeed;
	}
	void setPower(int h)
	{
		horsePower = h;
	}
	int getPower()
	{
		return horsePower;
	}
	void printSuper()
	{
		PrintCarDetailes();
		cout << "\n Horse Power: " << horsePower;
		cout << "\n Top Speed: " << topSpeed;
	}
};
class sedan : public Car
{
	int NoOfAirBags;
	bool SunRoof;
public:
	sedan()
	{
		NoOfAirBags = 0;
		SunRoof = false;
	}
	void setSedan(string Cn, registrationDetails R, string b, int e, string t, double m, double P, int AirB, bool roof)
	{
		carName = Cn;
		RD = R;
		bodyColor = b;
		engineCapacity = e;
		Transmission = t;
		Mileage = m;
		Price = P;
		NoOfAirBags = AirB;
		SunRoof = roof;
	}
	void setAirBag(int b)
	{
		NoOfAirBags = b;
	}
	void setSunR(bool a)
	{
		SunRoof = a;
	}
	int getAir()
	{
		return NoOfAirBags;
	}
	bool getBag()
	{
		return SunRoof;
	}
	void printSedan()
	{
		PrintCarDetailes();
		cout << "\n Air Bags: " << NoOfAirBags;
		cout << "\n Sunroof: ";
		if (SunRoof)
		{
			cout << "Yes";
		}
		else
			cout << "No";
	}
};
int main()
{
	///GOTO
	int giyal, back;
	///for file///
	string car, city,payMeth,color;
	double model=0, price=0; int years=0, percentage=0;
	startUp s;
	s.welcomePage();
	s.userData();
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		s.signUp();
		system("pause"); system("cls");
	}
	else if (choice == 2)
	{
		system("cls");
		s.login();
		choice = 0;
		cout << endl ;
		cout << "\t\t\t\t\t\t\t\t" << "============================================" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "TO CHECK PREVIOUS PURCHASE...PRESS 1";
		cout << "\n\t\t\t\t\t\t\t\t" << "TO MAKE NEW PURCHASE.....PRESS 2"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			string UN, email;
			loadUserData("user data.txt", s, UN, email, car, color, city, payMeth, model, price, percentage, years);
			userData(UN, email, car, color, city, payMeth, model, price, percentage, years);
			cout << "\n press any key to direct to purchasing";
			system("pause"); system("cls");
			PrintMessage("BEARED BROS AUTOS ");
			PrintMessage("YOU HAVE MADE YOUR ", false, false);
			PrintMessage("FIRST PURCHASE. YOUR NEXT ", false, false);
			PrintMessage("PURCHASE WILL BE ALLOWED AFTER DELIVERY", false, false);
			PrintMessage("SORRY FOR INCONVENIENCE");
			exit(0);
		}
		else
		{
			
		giyal: {

			PrintMessage("BEARED BROS AUTOS ");
			PrintMessage("YOU HAVE MADE YOUR ", false, false);
			PrintMessage("FIRST PURCHASE. YOUR NEXT ", false, false);
			PrintMessage("PURCHASE WILL BE ALLOWED AFTER DELIVERY", false, false);
			PrintMessage("SORRY FOR INCONVENIENCE");
			exit(0);
			}
		}
	}
back: {
	welcomeSign();
	cout << "\n\n";
	cout << setw(80) << "Welcome " << s.getUserName() << " To Beared Bros Autos * *\n\n";
	cout << "Looking For Your Dream Car ? You're At Right Place " << endl;
	cout << "For Luxury Cars, Press 1" << endl;
	cout << "For Sports Cars, Press 2" << endl;
	cout << "For Japanese Cars, Press 3" << endl;
	cout << "For Hatchbacks, Press 4" << endl;
	}
	int dec = 5;
	cout << "What Would You Like To do?:  ";
	cin >> dec;
	while (dec > 4 || dec < 0)
	{
		cout << "Wrong Decision! "<<endl;
		cout << "What Would You Like To do?:  ";
		cin >> dec;
	}
	if (dec == 1)
	{
		system("pause"); system("cls");
		sedan Cars[4];
		registrationDetails SedCars[4];
		int model = 2008;
		for (int i = 0; i < 4; i++)
		{
			SedCars[i].setModel(model);
			SedCars[i].setCity("PES");
			model += 3;
		}
		Cars[0].setSedan("Corolla-Gli", SedCars[0], "Titanium-Grey", 1300, "Automatic", 12, 5000, 7, true);
		Cars[1].setSedan("Honda-Civic", SedCars[1], "Metalic-Blue", 1300, "Manual", 14, 6500, 5, true);
		Cars[2].setSedan("Honda-Civiv Turbo", SedCars[2], "Red", 1900, "Automatic", 13, 7500, 5 ,true);
		Cars[3].setSedan("Nissan-Maxima", SedCars[3], "Jet-Grey", 1700, "Automatic", 17,6800, 3, false);
		char dec = 'n';
		int i = 0;
		while (dec == 'n' || dec == 'N')
		{
			system("cls");
			welcomeSign();
			cout << "*********************" << endl;
			Cars[i].printSedan();
			cout << "\n*********************" << endl;
			cout << "Press Y to proceed or Press N to look Another car Or Press B to go back: "; cin >> dec;
			if (dec == 'y' || dec == 'Y')
			{
				car = Cars[i].getCarname();
				model = Cars[i].getCarModel();
				color = Cars[i].getBodyColor();
				city = Cars[i].getCarCity();
				break;
			}
			else if(dec=='B'||dec=='b')
			{
				goto back;
			}
			if (i == 3)
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
		cout << endl;
		char ch;
		cout << "Do yo want to pay Lump SUm Or Installments(L/I)";
		cin >> ch;
		if (ch == 'I' || ch == 'i')
		{
			payMeth = "Installments";
			years=Cars[i].InstallmentPlan(); cout << endl;
			percentage = Cars[i].getPerc();
			price = Cars[i].getPrice();
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail()<<" soon"<<endl;
		}
		else
		{
			payMeth = "Lump Sump";
			price = Cars[i].getPrice();
			cout << "Car Choosen:" << Cars[i].getCarname() << endl << "Model Number "
				<< Cars[i].getCarModel() << endl
				<<"price: " <<Cars[i].getPrice()<<endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;

		}
	}
	if (dec == 2)
	{
		superCars sc[4];
		const int size = 4;
		sc->insertValues(sc, size);
		
		char dec = 'n';
		int i = 0;
		while (dec == 'N' || dec == 'n')
		{
			 system("cls");
			welcomeSign();
			cout << "*********************" << endl;
			sc[i].printSuper();
			cout << "\n*********************" << endl;
			cout << endl << endl;
			cout << "Pres Y to proceed or Press N to Look ANother Car Or Press B to go back: "; cin >> dec;
			if(dec=='Y'||dec=='y')
			{
				car = sc[i].getCarname();
				color = sc[i].getBodyColor();
				model = sc[i].getCarModel();
				city = sc[i].getCarCity();
				break;
			}
			else if (dec=='B'||dec=='b')
			{
				goto back;
			}
			if (i == 3)
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
		char ch; cout << endl;
		cout << "Do you Want to pay On Installments Or Pay Lump sum (I/L): "; cin >> ch;
		cout << endl << endl;
		if (ch == 'I' || ch == 'i')
		{
			payMeth = "Installments";
			years=sc[i].InstallmentPlan();
			percentage = sc[i].getPerc();
			price = sc[i].getPrice();
			cout << endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;
		}
		else
		{
			payMeth = "Lump Sump";
			price = sc[i].getPrice();
			cout << "Car Choosen:" << sc[i].getCarname() << endl << "Model Number "
				<< sc[i].getCarModel() << endl
				<< "price: " << sc[i].getPrice() << endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;

		}
	}
	if (dec == 3)
	{
		const int size = 4;
		japaneseCars* jap = new japaneseCars[size]; /////initializing array as pointers
		jap->getJapaneseValues(jap, size);
		system("pause"); system("cls");
		char dec = 'n';
		int i = 0;
		while (dec == 'N' || dec == 'n')
		{
			system("cls");
			welcomeSign();
			cout << "*********************" << endl;
			jap[i].PrintJapDetails();
			cout << "\n*********************" << endl;
			cout << endl << endl;
			cout << "Press Y to Proceed or Press n to look another car or Press B to go back: "; cin >> dec;
			if (dec == 'y' || dec == 'Y')
			{
				car = jap[i].getCarname();
				color = jap[i].getBodyColor();
				model = jap[i].getCarModel();
				city = jap[i].getCarCity();
				break;
			}
			else if (dec == 'B' || dec == 'b')
				goto back;
			if (i == 3)
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
		char ch;
		cout << endl;
		cout << "Do you Want to Pay On Installments or Pay Lump Sum (I/L): "; cin >> ch;
		cout << endl << endl;
		if (ch == 'I' || ch == 'i')
		{
			payMeth = "Installments";
			price = jap[i].getPrice();
			percentage = jap[i].getPerc();
			years=jap[i].InstallmentPlan();
			cout << endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;

		}
		else
		{
			price = jap[i].getPrice();
			payMeth = "Lump sum";
			cout << "Car Choosen:" << jap[i].getCarname() << endl << "Model Number "
				<< jap[i].getCarModel() << endl
				<<"price"<< jap[i].getPrice()<<endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;

		}

	}
	if (dec == 4)
	{
		const int  size = 4;
		HatchBacks* H = new HatchBacks[size];
		
		H->getHatchBacks(H, size);
		char dec = 'n';
		int i = 0;
		while (dec == 'N' || dec == 'n')
		{
			system("pause"); system("cls");
			welcomeSign();
			cout << "*********************" << endl;
			H[i].PrintCarDetails();
			cout << "\n*********************" << endl;
			cout << endl << endl;
			cout << "Press Y to Proceed or Press n to look another car or Press B to go back: "; cin >> dec;
			if (dec == 'y' || dec == 'Y')
			{
				car = H[i].getCarname();
				model = H[i].getCarModel();
				color = H[i].getBodyColor();
				city = H[i].getCarCity();
				break;
			}
			else if (dec == 'B' || dec == 'b')
				goto back;
			if (i == 3)
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
		char ch;
		cout << endl;
		cout << "Do you Want to Pay On Installments or Pay Lump Sum (I/L): "; cin >> ch;
		cout << endl << endl;
		if (ch == 'I' || ch == 'i')
		{
			payMeth = "Installments";
			price = H[i].getPrice();
			percentage = H[i].getPerc();
			years=H[i].InstallmentPlan();
			cout << endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;
		}
		else
		{
			price = H[i].getPrice();
			payMeth = "Lump Sum";
			cout << "Car Choosen:" << H[i].getCarname() << endl << "Model Number "
				<< H[i].getCarModel() << endl
				<< "Price: " << H[i].getPrice() << endl;
			cout << "Please Visit Beared Bros autus to finalise details and taka the car for test drive .\nfurther details would be co-ordinated to your email " << s.getEmail() << " soon" << endl;

		}
    }
	cout << "\n\t\t\t\t\t\t\t\t PURCHASE SUCCESSFULL. FOLLOWING IS THE PURCHASE INFORMATION......";
	system("pause");
	system("cls");
	userData(s.getUserName(), s.getEmail(), car, color, city, payMeth, model, price, percentage, years);
	saveUserData("user data.txt", s.getUserName(), s.getEmail(), car, color, city, payMeth, model, price, percentage, years); system("pause"); system("cls");
	PrintMessage("BEARED BROS AUTOS");
	PrintMessage("TO MAKE ANOTHER PURCHASE....PRESS 1", false, false);
	PrintMessage("TO EXIT THE SYSTEM...... PRESS 2", false, false);
	PrintMessage("PURCHASE SUCCESSFUL"); choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		goto giyal;
	}
	else
	{
		exit(0);
	}

		_getch();
	return 0;
}
