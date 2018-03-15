#include<iostream>
#include<sstream>
#include<string>
#include<vector>

#include "handle.hpp"

using namespace std;

vector<string> split(string split){
	istringstream splitStream(split);
	string temp;

	vector<string> returnVector;
	while(std::getline(splitStream, temp, ' ')) {
			returnVector.push_back(temp);
	}
	return returnVector;
}

int main(int argc, char *argv[]){
		Handler handler;
		bool exit = false;
		while(!exit){
			cout << "[cmd]:";
			string command;
			if(getline(cin,command)){
				if (command != "exit"){
					vector<string> commandVector = split(command);
					handler.handle(commandVector);
				}
				else{
						exit = true;
				}
			}
		}
}



