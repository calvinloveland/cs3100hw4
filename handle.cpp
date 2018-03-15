#include "handle.hpp"
#include "history.hpp"

Handler::Handler(){
	history = History();
}
string Handler::vstos(vector<string> vs){
	string returnString = "";
	for(int i = 0; i < vs.size(); i++){
		returnString += vs[i];
	}
	return returnString;
}

int Handler::handle(vector<string> args){
	if(args.size() > 0){
		auto start = chrono::system_clock::now();
		string command = args[0];
		//cout << command;
		if(command == "^"){
			handle(history.get(stoi(args[1])));
		}
		else if(command == "ptime"){
			cout << "Time spent executing child processes: " << ptime << " milliseconds" << endl;
		}
		else if(command == "history"){
			history.print();
		}
		else if(command == "cd"){
			char* directory = (char*)args[1].c_str();
			chdir(directory);
		}
		else{
			if(!fork()){
				char **execArgs = new char*[2];
				execArgs[0] = (char*)vstos(args).c_str();
				execArgs[1] = (char*)NULL;

				execvp(execArgs[0],execArgs);
				cout <<args[0] << " Command not found" << endl;
				_exit(1);
			}
			else{
				wait();
				cout << endl;
			}
		}
		history.add(args);
		auto end = chrono::system_clock::now();
		ptime = chrono::duration<double,milli>((end-start)).count();
	}
	return 0;
}
