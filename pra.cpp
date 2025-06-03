#include <iostream>
#include <string> 
#include <numeric>
#include <vector>
#include <random>
#include <algorithm>
#include <thread>
using namespace std;
string duplicate(string text){
    const int ascii_ind = 128;
    bool char_detect[ascii_ind] = {false};
    char char_collect[text.size() + 1];
    int char_col = 0;
    for(int i = 0 ; i < text.size(); i++){
            if(char_detect[text[i]]== false){
                char_collect[char_col] = text[i];
                char_col++;
                char_detect[text[i]] = true;
            }
        
    }
    char_collect[-1] = 0;
return char_collect;
}

int generate_random_number(void){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1000);
    
    return dist(gen) ;
}

int missed_number(int input){
    vector<int> arr(1000);
    iota(arr.begin() , arr.end() , 0);
    //cout << arr[0] <<  endl;
    mt19937 g(42);
    shuffle(arr.begin(), arr.end() , g);
    arr.erase(remove(arr.begin() , arr.end() , input));
    //cout << arr[0] << endl;







    bool missed_number_ind[1000] = {false};
    for(int i = 0 ; i < arr.size() ; i++){
        
            missed_number_ind[arr[i]] = true;
        
    

    }
    auto it = find(missed_number_ind, missed_number_ind + 1000, false);
    int missing_index = distance(missed_number_ind, it);
    cout << missing_index << endl;



    return 0;
}






int main(){

//cout << duplicate("examtest") << endl;

//missed_number(100);
int x = generate_random_number();
cout << x << endl;
this_thread::sleep_for(chrono::seconds(3)); 
missed_number(x);


    return 0;
}