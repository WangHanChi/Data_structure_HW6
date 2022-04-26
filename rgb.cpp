

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int diff;

struct rgb {
    string color;
    vector<int> rgb_value;
};

struct input{
	vector<int> number;
};


struct count{
	int x;
	count(int a ) : x(a) {}
	bool operator()(const rgb& foo, const input& yu) const{
		diff = 0;
		for(int i = 0; i < foo.rgb_value.size(); ++i){
			diff = ( abs(foo.rgb_value[i] - yu.number[i]) );
		}
		
		if(diff >= x) {
			return false;
		}else if(diff < x){
			return true;			
		}
	}
};


template< typename T, typename F>
void print( T a, T b, F fn){
	for( T c = a ; c != b ; ++c){
		if( fn(*c) ){
			cout << *c << endl;		
		}
	}
}

istream& operator>> (istream& in, rgb& foo){
	while( foo.rgb_value.size()){
		foo.rgb_value.pop_back();
	}
	int Value;
	string word;

	getline(in, word);
	istringstream str(word);
	str >> foo.color;
	while(str >> Value){
		foo.rgb_value.push_back(Value);
	}

	return in;
}


ostream& operator<< (ostream& out, const rgb& foo){
	out << foo.color << "";
	int sum = 0;
	for(int i = 0; i < foo.rgb_value.size(); ++i){
		sum += foo.rgb_value[i];
		out << setw(4) << foo.rgb_value[i];
	}

	out << "";
}


int main()
{
    
    ifstream infile("rgb.txt");

    vector<rgb> foo;
    rgb name;

	while(infile >> name){
		foo.push_back( name ); 
	}


	int i ;
	
	cout << "this is origin : " << endl;
	
	for(i = 0; i < foo.size(); ++i){
		cout << foo[i] << endl;
	} 


    do {
		string line;
    	istringstream istr;
		vector<input> yu;
		input input_number;
		
        cout << "> ";
        getline(cin, line);
        istr.str(line);
		while(istr >> input_number){
			yu.push_back( input_number );
		}
		istr.clear();
		print(foo.begin(), foo.end(), count(20));
		


//		for(i = 0; i < yu.size(); ++i){
//			cout << yu[i] << " ";
//		}
//		cout << endl;
    } while (1);



	return 0;
}

