#include "history.hpp"

History::History(){

}

void History::add(vector<string> commandVector){
	history.push_back(commandVector);
}

vector<string> History::get(int count){
		return history[count];
}

void History::print(){
	for(int i = 0; i < history.size(); i++){
		for( int j = 0; j < history[i].size(); j++){
				cout << history[i][j] << " ";
		}
		cout << endl;
	}
}
