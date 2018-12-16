//Employee Object Class



class Employee{
	private:
		string name;
		int pass;
	public:
		Employee(string n, int p) : name(n), pass(p){}

		string getName(){
			return name;
		}
		int getPass(){
			return pass;
		}



};
