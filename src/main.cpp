//Main driver file for 'RepairQ' project

#include <Header.h>
#include "ascii.cpp"
#include "repair.cpp"
#include "QueryU.cpp"



//Operational Funtion declaration


	//clw, clears console
void clw();

	//repairEntry, asks user for repair info, returns new repair object
Repair repairEntry(string employee);

	//Prints Main Title
void printMainTitle();

	//Sleep loop
void loadBar(int waitTime, int waitInterval);

	//Menu UI
int mainMenuSelection();

	//Employee 'login'
string employeeLogin();

	//Repair Queue 
void printQueue(vector <Repair> list);


//Global Variables/Methods


	//Menu Selection Strings
string menu1 = "-----RepairQ-----\nExit(0) List(1) Add(2) Remove(3) Help(4)

int main(){
	//Local Initialization
	using namespace std;

	char confirmExit;
	string currentEmployeeName;
	int menuChoice;

	//Initial Splash Menu
	printMainTitle();
	loadBar(10, 1);
	
	//Program
	do{
		//Initial clear console
		clw();
		
		//Initial Employee name definition
		currentEmployeeName = employeeLogin();
		clw();

		//Print Menu
		choice = mainMenuSelection();
		





		//Exit main program	
		cout << "Are you sure you want to quit? y/n " << endl;
		cin >> confirmExit;
	}while(confirmExit != 'y' && confirmExit == 'n');

	do{
       		cout << "Press enter to continue.." << endl;
	} while(cin.get() != '\n');
	return 0;
}



//Function definition


void clw(){
	system("clear");
}

Repair repairEntry(string employee){
	string a,b,c,d,e = employee,f,g,h,i;
	char correct;
	do{
		cout << "Device: ";
		cin >> a;
		
		cout << "\nRepair: ";
		cin >> b;

		cout << "\nCustomer's First Name: ";
		cin >> c;

		cout << "\nCustomer's Last Initial: ";
		cin >> d;

		cout << "\nDue Date (mm/dd): ";
		cin >> f;

		cout << "\nDue Time (00:00-24:59): ";
		cin >> g;

		cout << "\nQuote: ";
		cin >> h;

		cout << "\nPriority (Highest=1, Lowest=3, Normal=0)";
		cin >> i;
		cout << endl;

		cout << "Is this information correct? y/n";
		cin >> correct;
	}while(correct == 'n');
	
	Repair ret(a,b,c,d,e,f,g,h,i);
	return ret;
}

void printMainTitle(){
	textArt a;
	cout << a.printTitle();
}

void loadBar(int waitTime, int waitInterval){
	using namespace std;
	cout << "Loading [";
	for(int i = 0; i < waitTime; i++){
		usleep(waitInterval);
		cout << "#";
	}
	cout << "]\n Done in " << waitTime << " seconds." << endl;
	usleep(2);	
}

int mainMenuSelection(){
	
} 

string employeeLogin(){
	using namespace std;
	string name;
	cout << "Employee Name: ";
	cin >> name;
	cout << endl;
	return name;
}

void queue(vector <Repair> list){



}
