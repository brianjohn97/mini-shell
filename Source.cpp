#include <iostream>
#include <vector>
#include <filesystem>
#include <sys/stat.h>

using namespace std;
vector <string> arr;
struct stat stats;

//takes the user input and takes only the proper input
//and seperates each input and puts them into a vector of strings

void inputString(string str){
    string delim = " ";
    int start = 0;
    int end = str.find(delim);
    while (end != -1) {
        string test = str.substr(start, end - start);
        start = end + delim.size();
        end = str.find(delim, start);

        if (test.empty()){
            continue;
        }
        arr.push_back(test);
    }
    arr.push_back(str.substr(start, end - start));
}

//will determine the type of a file given the filename
void determineType(string str){
    filesystem::file_status status = filesystem::status(str);
    filesystem::file_type type = status.type();

    switch(type){
        case filesystem::file_type::regular:
            cout << "This files type is regular.\n";
            break;
        case filesystem::file_type::none:
            cout << "There is no file type.\n";
            break;
        case filesystem::file_type::not_found:
            cout << "The file type was unfortunately not found.\n";
            break;
        case filesystem::file_type::block:
            cout << "The type of the file is block\n";
            break;
        case filesystem::file_type::directory:
            cout << "The file is of type directory.\n";
            break;
        case filesystem::file_type::symlink:
            cout << "The type of this file is symlink.\n";
            break;
        case filesystem::file_type::character:
            cout << "The type of this file is character.\n";
            break;
        case filesystem::file_type::fifo:
            cout << "This files type is fifo.\n";
            break;
        case filesystem::file_type::socket:
            cout << "This file has a socket type.\n";
            break;
        case filesystem::file_type::unknown:
            cout << "The file type of this file is unknown.\n";
            break;
    }
}

//prints out help for how to use the fileinfo command
void fileInfoHelp(){
    cout << "FILEINFO\n\n"
            "DESCRIPTION\n"
            "\tYou can use this command to print information about the files: such as \n"
            "\tthe inode number used for each linux file, the last time a file was modified\n"
            "\tor the type of a given a file.\n\n"
            "NAME\n"
            "\tfileinfo - this command is to find information about the files on the computer.\n\n"
            "OPTIONS\n"
            "\t-i[filename]\tThis will print the inode number of the given file.\n\n"
            "\t-t[filename]\tThis option will print the given files type.\n\n"
            "\t-m[filename]\tThis will print the last time the given file was modified.\n\n"
            "\tIf no switch is provided then all three pieces of information above will printed.\n\n";
}

//prints out help for how to use the prompt command
void promptHelp(){
    cout << "PROMPT\n\n"
            "DESCRIPTION\n"
            "\tYou can use this command to change the prompt, currently set to cwushell to anything\n"
            "\tof your choosing.\n"
            "NAME\n"
            "\tprompt - This is the name of the word that sits in front of every command.\n\n"
            "OPTIONS\n"
            "\t[new prompt name]\tAfter prompt type in what you want the new prompt to be.\n\n"
            "\tIf no new prompt is provided then the prompt is changed back to the orginal: cwushell.\n\n";
}

//prints out help for how to use the exit command
void exitHelp(){
    cout << "EXIT\n\n"
            "DESCRIPTION\n"
            "\tUse this command when you want to close out of this terminal. \n"
            "NAME\n"
            "\texit - Will exit the current shell.\n\n"
            "OPTIONS\n"
            "\tnone\n\n";
}

//prints out help for how to use the osinfo  commmand
void osInfoHelp(){
    cout << "OSINFO\n\n"
            "DESCRIPTION\n"
            "\tYou can use this command to print information about the OS of the computer. It will show\n"
            "\tyou information about regarding the type of the file system, the total number of blocks and\n"
            "\tthe max amount of characters that you can use to name a file.\n\n"
            "NAME\n"
            "\tosinfo - this command is to find information the computer.\n\n"
            "OPTIONS\n"
            "\t-T\tThis will print the type of filesystem the computer is using.\n\n"
            "\t-b\tThis option will print the total number of blocks in the file system.\n\n"
            "\t-s\tThis will print the max amount of characters that can be used in a filename\n\n";
}
int main() {

    //sets up the prompt and basic pathway
    string prompt = "cwushell> ";
    string temp = prompt;
    string path = "/";
    while (true) {
        //clear out the vector for every new command
        arr.clear();
        string input;
        cout << temp;

        //get the input from the user and convert the commands
        //to the vector arr
        getline(cin, input);
        inputString(input);

        //the prompt command
        if (arr[0] == "prompt") {
            //changes the prompt to one specified by user
            if (arr.size() < 2) {
                temp = prompt;
                continue;
            }
            if(arr[1] == ""){
                cout << "Did not specify new prompt. Please type the new prompt after the command 'prompt.\n"
                        "For more help try prompt -h or prompt -help for more help.\n";
                continue;
            }

            if(arr[1] == "-h" || arr[1] == "-help"){promptHelp();continue;}
            temp = arr[1] + "> ";

        //the fileinfo command
        }else if(arr[0] == "fileinfo"){

            //if no specifer or filename was provided then print all 3 specifiers:
            //the inode number of file, the file type, and the last modified date.
            if(arr.size() < 2){
                stat("/", &stats);

                cout << "The Inode number of the basic file: " << stats.st_ino << endl;
                determineType("/");
                cout << "The last modification date of the basic folder file was: " <<ctime(&stats.st_mtime);
                continue;
            }

            //prints the inode number
            if (arr[1] == "-i") {
                if (arr.size() < 3){
                    cout << "No file was given to check file type. Please try again with a file name.\n"
                            "Use fileinfo -h or fileinfo -help for more help\n";
                    continue;
                }

                const char* inodeNum = arr[2].c_str();
                stat(inodeNum, &stats);
                cout << "The Inode number of the given file: " << stats.st_ino << endl;

            //prints the file type of given file
            }else if (arr[1] == "-t") {
                if (arr.size() < 3){
                    cout << "No file was given to check file type. Please try again with a file name.\n"
                            "Use fileinfo -h or fileinfo -help for more help\n";
                    continue;
                }
                determineType(arr[2]);

            //prints the date the file was last modified
            } else if (arr[1] == "-m") {
                if (arr.size() < 3){
                    cout << "No file was given to check file type. Please try again with a file name.\n"
                            "Use fileinfo -h or fileinfo -help for more help\n";
                    continue;
                }

                const char* modDate = arr[2].c_str();
                stat(modDate, &stats);
                cout << "The last modification date of the basic folder file was: " <<ctime(&stats.st_mtime);

            } else if (arr[1] == "-help" || arr[1] == "-h") {
                fileInfoHelp();
                continue;
            }

        //exit comman
        }else if(arr[0] == "exit"){
            if(arr[1] == "-h" || arr[1] == "-help"){exitHelp();}
            exit(0);

        //manual command that prints out all the help from the other commands
        }else if (arr[0] == "manual" || arr[0] == "manual" && arr.size() > 1) {
            cout << "\t\t\t\tMANUAL\n\n";
            promptHelp();
            fileInfoHelp();
            osInfoHelp();
            exitHelp();
            continue;

        //the osinfo command
        }else if(arr[0] == "osinfo"){

            //prints out warning if no specifier was given
            if(arr.size() < 2){
                cout << "No specifier was given.\n"
                        "Please try again with a specifier.\n"
                        "You can use osinfo -h or osinfo -help for help.\n";
                continue;
            }

            //prints out the file system of the computer
            if(arr[1] == "-T"){

            //prints out the total amount of blocks in the file system
            }else if(arr[1] == "-b"){
                stat("/", &stats);
                filesystem::space_info fileCap = filesystem::space("/");
                //cout << "Total number of blocks: " << fileCap.capacity /stats.st_blksize << endl;

            //prints out the max amount of charaters that can be used to create a filename
            }else if(arr[1] == "-s"){
                cout << "The max amount of characters that can be used for a filename is: " << FILENAME_MAX << endl;
            }else if(arr[1] == "-h" || arr[1] == "-help"){osInfoHelp();continue;}


        //changes the current pathway to one specified by the user
        }else if (arr[0] == "cd"){
            if(arr.size() < 2){cout << "Did not add filepath to change path to. please try again"; continue;}
            path = arr[1];

        //prints the current directories pathway
        }else if (arr[0] == "pwd"){
            system("pwd");

        //lets the user type in any linux commands
        }else {system(input.c_str());}
    }
}