//Main driver file for 'RepairQ' project

#include <Header.h>
#include "ascii.cpp"
#include "repair.cpp"
//#include "QueryU.cpp" DANGEROUS MESS OF A CLASS
#include <unistd.h>
//Operational Funtion declaration

	//clw, clears console
void clw();
	//field, manages formatting
std::ostream& rfield(std::ostream& o, size_t size);
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
//void printQueue(vector <Repair> list);

void formatRepair(Repair x);
//Global Variables/Methods


	//Menu Selection Strings
string menu1 = "-----RepairQ-----\nExit(0) List(1) Add(2) Remove(3) Help(4)";

int main(){
	//Local Initialization

	char confirmExit;
	string currentEmployeeName;
	int menuChoice;
	
	//Initial Splash Menu
	printMainTitle();
	cout << "Loading..." << endl;
	loadBar(10, 1);
	
	//Queue
	
	vector <Repair> queue;

	//Program
		//Initial clear console
		clw();
		
		//Initial Employee name definition
		currentEmployeeName = employeeLogin();
		clw();
	do{
		//Print Menu
		menuChoice = mainMenuSelection();
		cin.ignore();
		clw();

		char quit;
		
		//Switch for user selection
		switch(menuChoice){
			//NO default case needed, input handling already managed in mainMenuSelection function
			case 2:
				queue.push_back(repairEntry(currentEmployeeName));
				cout << "Repair Added.." << endl;
				cin.ignore();
				clw();
				break;
			case 3:
					queue.pop_back();
					cout << "Last repair removed..." << endl;
				cin.ignore();
				clw();
				break;
			case 1:
				cout << "Queue" << endl;
				for(unsigned int i = 0; i < queue.size(); i++){
					formatRepair(queue[i]);
				}
				cin.ignore();
				clw();
				break;
			case 0:
				break;
			case 4:
				cout << "Help will be added later....good luck" << endl;
				cin.ignore();
				clw();
				break;
			case 5:
				currentEmployeeName = employeeLogin();
				clw();
				break;
		}	


	}while(menuChoice != 0);
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
	string a,b,c,d,e = employee,f,g; double h; int i;
	char correct;
	do{
		cout << "Device: ";
		getline(cin, a);
		
		cout << "\nRepair: ";
		getline(cin, b);

		cout << "\nCustomer's First Name: ";
		getline(cin, c);

		cout << "\nCustomer's Last Initial: ";
		getline(cin, d);

		cout << "\nDue Date (mm/dd): ";
		getline(cin, f);

		cout << "\nDue Time (00:00-24:59): ";
		getline(cin, g);

		cout << "\nQuote: ";
		cin >> h;

		cout << "\nPriority (Highest=1, Lowest=3, Normal=0): ";
		cin >> i;
		cout << endl;

		cout << "Is this information correct? (y/n): ";
		cin >> correct;
		
	}while(correct == 'n');
	
	Repair ret = Repair(a,b,c,d,e,f,g,h,i);
	return ret;

}

void printMainTitle(){
	textArt a;
	a.printTitle();
}

void loadBar(int waitTime, int waitInterval){
	unsigned int usecs = waitInterval * 1000000;
	cout << "Loading [";
	for(int i = 0; i < waitTime; i++){
		usleep(usecs);
		cout << "#";
	}
	cout << "]\n Done in " << waitTime << " seconds." << endl;
	unsigned int pauseU = 2000000;
	usleep(pauseU);	
}

int mainMenuSelection(){
	string menua = "-----RepairQ-----\nExit(0) List(1) Add(2) Remove(3) Help(4) Change Employee(5)";
	int a;

	cout << menua << endl;
	cin >> a;
	if(a < 0 || a > 5){
		cout << "Invalid response" << endl;

		//OOOH! A FANCY RECURSION    (0.0)
		a = mainMenuSelection();

	} else{
	return a;
	}
} 

string employeeLogin(){
	string name;
	cout << "Employee Name: ";
	cin >> name;
	cout << endl;
	return name;
}
//string rfield(std::ostream& o, size_t size){
//	return o << std::setw(size) << std::right;
//}
void formatRepair(Repair x){
	int fieldSize[10]{20,20,15,2,7,5,5,7,7};
	
	string a = x.getDeviceName(); string b = x.getRepairName();
       	string c = x.getCustomerFirstName(); string d = x.getCustomerLastInitial();
	string e = x.getEmployeeName(); string f = x.getDueDate(); string g = x.getDueTime(); double m = x.getQuote();
	string i = x.getPriority();
	std::setprecision(2);
	string h = to_string(m);
	string repairData[10]{a,b,c,d,e,f,g,h,i};

	for(int j = 0; j < 9; j++){
		cout << std::setw(fieldSize[j]) << std::setprecision(2) << repairData[j] << std::right << "|";
	}	
	cout << endl;
}
//void queue(vector <Repair> list){



//}
