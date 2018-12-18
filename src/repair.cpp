#include <Header.h>



class Repair {


private:
	string device_name, repair_name, customer_first_name, customer_last_initial, employee_name, due_date, due_time;
	double quote;
	int priority;
public:
	//Param constr
	Repair(string dn,string rn,string cfn,string cli,string en,string dd,string dt, double qu, int pri) : 
		device_name(dn), repair_name(rn), customer_first_name(cfn), customer_last_initial(cli), employee_name(en), due_date(dd), due_time(dt), quote(qu), priority(pri) {}
	//Default constr
	Repair(){}

	//Getters
	string getDeviceName(){
		return device_name;
	}
	string getRepairName(){
		return repair_name;
	}
	string getCustomerFirstName(){
		return customer_first_name;
	}
	string getCustomerLastInitial(){
		return customer_last_initial;
	}
	string getEmployeeName(){
		return employee_name;
	}
	string getDueDate(){
		return due_date;
	}
	string getDueTime(){
		return due_time;
	}
	double getQuote(){
		std::setprecision(2);
		return quote;
	}
	int getPriorityIndex(){
		return priority;
	}
	string getPriority(){
		switch(priority){
		case 1:
			return "Urgent";
			break;
		case 2:
			return "High";
			break;
		case 0: 
			return "Normal";
			break;
		case 3:
			return "Low";
			break;
		default:
			return "Normal";
				break;
		}
	}
	//ResetAll
	/*
	reRepair(string dn,string rn,string cfn,string cli,string en,string dd,string dt, double qu, int pri) :
                device_name(dn), repair_name(rn), customer_first_name(cfn), customer_last_initial(cli), employee_name(en), due_date(dd), due_time(dt), quote(qu), priority(pri) {}

		*/
};
