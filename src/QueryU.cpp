//'QueryU' class file
//Class for querying users and recieving correctly parsed responses more elegantly than with plain cin and cout operators.
//Written by Ethan Hulse, December of 2018. 
//Open source, feel free to use, credit is appreciated.

#include <Header.h>

class QueryU {


	private:
		string datType, askString, answer;

		string responseString;
		int responseInt;
		double responseDouble;
		float responseFloat;
		char responseChar;

	public:
		//Parameterized constructor
		QueryU(string d, string q, string a) : datType(d), askString(q){}
		//Default constructor
		QueryU(){}
		//Setters
		void setResponse(string _datType, string _question){

			switch(datType){
				case "int":
					cout << _question;
					try{
						cin >> answer;
						responseInt = static_cast<int>(answer);
					}catch (exception exce){
						cout << exce.what();
					}
					break;
				case "string":
					cout << _question;
						getline(cin, answer);
						responseString = answer;
					break;
				case "float":
					cout << _question;
					try{
						cin >> answer;
						responseFloat = static_cast<float>(answer);
					} catch(exception e){
						cout << e.what();
					}
					break;
				case "char":
					cout << _question;
					try{
						cin >> answer;
						responseChar = static_cast<char>(answer);
					} catch (exception ex){
						cout << ex.what()
					}
					break;
				case "double":
					cout << _question;
					try{
						cin >> answer;
						responseDouble = static_cast<double>(answer);
					}catch (exception exc){
						cout << exc.what();
					}
					break;
				default:
					cout << "Invalid data type. Use one of the following types:\nint, char, string, float, double" << endl;
					break;

			}

		}
		//Getters
		string getResponseString(){return responseString}
		char getResponseChar(){return responseChar}
		double getResponseDouble(){return responseDouble}
		float getResponseFloat(){return responseFloat}
		int getResponseInt(){return responseInt}



};
