#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool add(){

    int num;

    cout << "---------------------------------------" << endl;

    cout << "How many to add?: ";
    cin >> num;

    cout << "---------------------------------------" << endl;

    cin.ignore();

    vector<string> list;
    string item;

    for(int i=0; i<num; i++){

        cout << "Enter " << i+1 << " item: ";

        getline(cin, item);

        list.push_back(item);

        cout << "---------------------------------------" << endl;

    }

    ofstream file("lists.txt", ios::app);

    for (const string &item : list){

        file << item << endl;

    }

    file.close();

    return true;

}
void view(){

    ifstream file("lists.txt");

    string list;
    int index = 1;

    cout << "---------------------------------------" << endl;

    cout << "To Do list:\n\n";

    while (getline(file, list)){

        cout << index++ << ": " << list << endl;

    }

    cout << "---------------------------------------" << endl;

    file.close();

}
void remove(int num){

    ifstream file("lists.txt");

    vector<string> list;
    string line;
    int index = 1;

    while (getline(file, line)){

        if(index != num){

            list.push_back(line);

        }
        index++;
    }

    file.close();

    if (list.empty()) {
        cout << "File is now empty after removing the line." << endl;
        ofstream clearFile("lists.txt", ios::trunc); // Clears file if all lines are removed
        clearFile.close();
        return;
    }

    ofstream rewrite("lists.txt", ios::trunc);

    for (const string &l : list) {

        rewrite << l << endl;

    }
    rewrite.close();

    cout << num << " Removed!" << endl;

}
int main(){

    int choice;

    cout << "Welcome to ToDoList!\n" << endl;
    
    cout << "1: Add\n2: View\n3: Remove\n4: Exit\n" << endl;
    cout << "What do you want to do?: ";
    cin >> choice;

    if(choice == 1){

        bool status = add();
    
        if(!status){

            cout << "Failed to add, Try again!";
            system("pause");

        }else{

            cout << "Added!" << endl;
            system("pause");
            cout << "---------------------------------------" << endl;
            main();

        }

    }else if(choice == 2){

        view();
        system("pause");
        cout << "---------------------------------------" << endl;
        main();

    }else if(choice == 3){

        int num;

        view();

        cout << "which number to remove?: ";
        cin >> num;

        remove(num);

        cout << "---------------------------------------" << endl;
        system("pause");
        cout << "---------------------------------------" << endl;
        main();

    }else if(choice == 4){

        cout << "---------------------------------------" << endl;
        cout << "Exiting . . ." << endl;
        system("pause");

    }else{

        cout << "---------------------------------------" << endl;
        cout << "Invalid entry" << endl;
        system("pause");

    }

}