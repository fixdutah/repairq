//Function file for RepairQ project main.cpp file..

#include <Header.h>
#include "main.cpp"
#include "Repair.cpp"
#include "ascii.cpp"

using namespace std;


//Static Utility Functions
void clw();
string employeeLogin();
std::ostream& rfield(std::ostream& o, size_t size);
//UI functions
int mainMenuSelection();
void printMainTitle();
void loadBar(int waitTime, int waitInterval);
//Dynamic Functions
Repair repairEntry(string employee);
void formatRepair(Repair x);


//Definitions
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
                cout << std::setw(fieldSize[j]) << repairData[j] << std::center << "|";
        }
        cout << endl;
}


