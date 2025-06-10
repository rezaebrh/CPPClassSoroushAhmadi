#include<string> 
#include<iostream>
#include<vector>
#include<sstream> 
using namespace std;

bool locky_number(vector<int> input){
    int counter =0;
    int tempvalue = input[0];
    for(int i = 1; i < input.size() ; i++){
        if (input[i] > tempvalue){
            tempvalue = input[i];
            counter++;
        }
        if (counter >=2){
            cout << "You are locky" << endl;
            return true;
        }
    }
    cout << "Its not your locky day today, try another day"<< endl;
    return false;
}


vector<int> string_to_vector(string input){
vector<int> input_number;

istringstream iss(input);
int num;
while(iss >> num){
    input_number.push_back(num);

}
return input_number;

}

int main(){
string input;
cout << "Please insert the input string :" << endl;
getline(cin ,input);
vector<int> input_number = string_to_vector(input);
cout << locky_number(input_number) << endl;
 return 0;
}