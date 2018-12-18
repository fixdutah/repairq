#include <Header.h>

class textArt{
	private:
	       	string title_repairq[10] = {

  	  " ______                 _         _____",
 	  " | ___ \\               (_)       |  _  |",
  	  " | |_/ /___ _ __   __ _ _ _ __   | | | |",
	  " |    // _ \\ '_ \\ / _` | | '__|  | | | |",
	  " | |\\ \\  __/ |_) | (_| | | |     \\ \\/' /",
	  " \\_| \\_\\___| .__/ \\__,_|_|_|      \\_/\\_\\",
	  "           | |			   ",
	  "  Fixd LLC |_|   Ethan Hulse 2018       "
	};

	public: 
	void printTitle(){
		for(int i = 0; i < 10; i++){
			cout << title_repairq[i] << endl;
		}


	}
};









