#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector <string> arr;
void help() {
    cout << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << endl;

}
void printVector(){
    for (int i = 0; i < arr.size(); ++i) {
        cout << "input"<<i << ": " << arr[i] << endl;
    }
}
void inputString(string str){
    string delimiter = " ";
    int start = 0;
    int end = str.find(delimiter);
    while (end != -1) {
        string test = str.substr(start, end - start);

        start = end + delimiter.size();
        end = str.find(delimiter, start);
        if (test.empty()){
            continue;
        }
        arr.push_back(test);
    }
    arr.push_back(str.substr(start, end - start));
}

int main() {

    string prompt = "cwushell> ";
    string temp = prompt;
    string input = "";



    while (true) {

        arr.clear();
        cout << temp;
        getline(cin, input);

        inputString(input);
        printVector();
        //inputString();


        if (arr[0] == "prompt") {
            if (arr.size() < 2) {
                cout << "did not enter the new prompt" << endl;
                continue;
            }
            temp = arr[1] + "> ";
        }

        if (input == "exit") {
            exit(0);
        }
        else if (input == "-help") {
            help();
            continue;
        }
        cout << endl;

    }

    /*
    int start = 0;
    int end = word.find(input);
    while (end != -1) {
        string test = word.substr(start, end - start);
        if (test == ""){
            start = end + input.size();
            end = word.find(input, start);
            continue;
        }
        cout << test  << endl;
        start = end + input.size();
        end = word.find(input, start);
    }
    cout << word.substr(start, end - start);


    while (true) {

        arr.clear();
        
        cout << temp;
        getline(cin, input);

        stringstream ss(input);
        while (getline(ss, temp, ' ')) {
            arr.push_back(temp);
        }
        

        if (arr[0] == "prompt") {
            if (arr.size() < 2) {
                cout << "did not enter the new prompt" << endl;
                continue;
            }
        }

        if (input == "exit") {
            exit(0);
        }
        else if (input == "-help") {
            help();
            continue;
        }
        cout << endl;

    }*/
}