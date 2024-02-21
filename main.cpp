#include <iostream>
#include <string>
#include "Employer.h"
#include "Candidate.h"
#include <list>
#include <regex>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isItGoodPassword(string password);
bool isItGoodEmail(string email);
bool isItGoodId(string id);
bool isItGoodName(string name);
bool isItGoodAge(int age);
bool isItGoodStory(string story);
string getRandomPassword();
string enterStory();


void signMenu();
void canMenu(Candidate& user);
void empMenu(Employer& user);



int main() {

    signMenu();

    return 0;
}





void signMenu(){
    list<Employer> empList;
    list<Candidate> canList;


    string name,last_name,id,email,password,randPassword;
    int age = 0;
    bool flag = true;
    int type = 0;
    char choice;
    do {
        cout << "welcome to job search:"<<endl
             <<"enter 1 if you Employer"<<endl
             <<"enter 2 if you Candidate"<<endl
             <<"enter 3 if you want close job search"<<endl;
        cin>>type;
        if(type != 1 && type != 2 && type != 3)
            type = 0;
        else
            if(type == 3)
                return;
    }while(!type);
    while(flag) {


        cout << "for Sign-up enter 1 and for Login 2 and 3 to Exit" << endl;
        cin >> choice;
        switch (choice) {
            case '1':
                do {
                    cout << "please enter your name: " << endl;
                    cin >> name;
                }while(!isItGoodName(name));

                do {
                    cout << "please enter your last name: " << endl;
                    cin >> last_name;
                }while(!isItGoodName(last_name));

                do {
                    cout << "please enter your id: " << endl;
                    cin >> id;
                }while(!isItGoodId(id));

                do{
                    cout<<"please enter your age: "<<endl;
                    cin>> age;
                } while (!isItGoodAge(age));

                do {
                    cout << "please enter your email: " << endl;
                    cin >> email;
                }while(!isItGoodEmail(email));

                do {
                    randPassword = getRandomPassword();
                    cout << "please enter your password or enter 1 if you want this random password: "<<randPassword<< endl;
                    cin >> password;
                    if(password == "1")
                        password = randPassword;
                }while(!isItGoodPassword(password));

                if(type == 1)
                    empList.push_front(Employer(name,last_name,id,password,email,age));
                else {
                    canList.push_front(Candidate(name, last_name, id, password, email, age,enterStory()));
                }
                break;

            case '2':
                do {
                    cout << "please enter your id: " << endl;
                    cin >> id;
                }while(!isItGoodId(id));

                do {
                    cout << "please enter your password: " << endl;
                    cin >> password;
                }while(!isItGoodPassword(password));

                if(type == 1) {
                    for (auto it = empList.begin(); it != empList.end();) {
                        if (it->getId() == id) {
                            if (it->getPassword() == password) {
                                cout << "welcome Employer" << endl;
                                empMenu(*it);
                            } else
                                cout << "wrong password" << endl;
                            it = empList.end();
                        } else {
                            ++it;
                            if (it == empList.end())
                                cout << "user didnt exist" << endl;
                        }
                    }
                }
                else{
                    for (auto it = canList.begin(); it != canList.end();) {
                        if (it->getId() == id) {
                            if (it->getPassword() == password) {
                                cout << "welcome Candidate" << endl;
                                canMenu(*it);
                            } else
                                cout << "wrong password" << endl;
                            it = canList.end();
                        } else {
                            ++it;
                            if (it == canList.end())
                                cout << "user didnt exist" << endl;
                        }
                    }
                }
                break;

            case '3':
                cout<<"bye bye"<<endl;
                flag = false;
                break;

            default:
                cout << "try again" << endl;
        }
    }
}


bool isItGoodPassword(string password){
    int i;
    if(password.size()<=10 && password.size()>=5) {
        for (i = 0; i < password.size();++i) {
            if ((password[i] < 'a' || password[i] > 'z') && (password[i] < 'A' || password[i] > 'Z') &&
                password[i] != '!' && password[i] != '@' && password[i] != '#' && password[i] != '$' &&
                password[i] != '*' && (password[i] < '0' || password[i] > '9')) {
                cout << "Invalid password" << endl;
                return false;
            }
        }
        return true;
    }

    else {
        cout<<"Invalid password"<<endl;
        return false;
    }
}

bool isItGoodEmail(string email){
    const regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    if (!regex_match(email, pattern)) {
        cout << "Invalid email" << endl;
        return false;
    }
    return true;
}

bool isItGoodId(string id){
    if(id.size()==9){
        for(int i=0; i <id.size(); ++i){
            if(id[i] < '0' || id[i] > '9') {
                cout<<"invalid ID"<<endl;
                return false;
            }
        }
        return true;
    }
    else {
        cout<<"invalid ID"<<endl;
        return false;
    }
}

bool isItGoodName(string name){
    if(name[0]>='a'&&name[0]<='z')
        name[0]-=('a'-'A');
    if(name[0]<'A'||name[0]>'Z') {
        cout<<"invalid name/last name"<<endl;
        return false;
    }
    for(int i = 1 ; i<name.size(); ++i){
        if(name[i]>='A' && name[i]<='Z'){
            name[i]+=('a'-'A');
        }
        if(name[i]<'a'||name[i]>'z') {
            cout<<"invalid name/last name"<<endl;
            return false;
        }
    }
    return true;
}

bool isItGoodAge(int age){
    if(age>=18)
        return true;
    return false;
}

bool isItGoodStory(string story){
    if(story.size()>1000) {
        cout<<"the text is to long(>1000)"<<endl;
        return false;
    }
    return true;
}

string getRandomPassword(){
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$*";
    const int length = 10;
    std::string randomString;

    srand(time(nullptr));

    for (int i = 0; i < length; ++i) {
        char randomChar = characters[rand() % characters.length()];
        randomString += randomChar;
    }

    return randomString;
}

string enterStory(){
    string story;
    do {
        cin.ignore();
        cout << "tell about yourself her and press enter when you done:" << endl;
        getline(cin,story);
    }while(!isItGoodStory(story));
    return story;

}



void canMenu(Candidate& user){
    char choice;
    string resume;
    bool flag = true;
    while(flag) {

        cin.ignore();//clear buffer
        cout << "welcome to candidate menu " << user.getName()<<" chose:" << endl
        <<"1 for change your personal information"<<endl
        <<"2 for tell about yourself"<<endl
        <<"3 for logout"<<endl;
        cin>>choice;

        switch (choice) {

            case '1':
                user.printCan();
                break;

            case '2':
                cin.ignore();
                cout<<"start tell about yourself and press enter when you done"<<endl;
                getline(cin,resume);
                break;

            case '3':
                flag = false;
                break;

            default:
                cout<<"invalid choice try again"<<endl;

        }
    }
}


void empMenu(Employer& user){
    user.enterNewJob();
    user.enterNewJob();
    user.printAllJobs();
}