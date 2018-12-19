//Main driver file for 'RepairQ' project

#include <Header.h>
#include "ascii.cpp"
#include "repair.cpp"
#include <unistd.h>
#include "methods.cpp"
#include "globalRes.cpp"



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





