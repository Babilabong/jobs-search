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
bool isItGoodName(string &name);
bool isItGoodAge(int age);
bool isItGoodStory(string story);
string getRandomPassword();
string enterStory();
void deleteJob(Employer& emp,list<Candidate>& canList);
bool checkAlreadyIn(string,Jobs& job);
bool checkCanIdAlreadyInList(string id,list<Candidate>& canList);
bool checkEmpIdAlreadyInList(string id,list<Employer>& empList);
bool checkSameDetails(const Employer& emp);
bool checkSameDetails(const Candidate& can);
void changePassword(Employer& emp);
void changePassword(Candidate& can);


void signMenu();
void canMenu(Candidate& user,list<Employer>& empList);
void empMenu(Employer& user,list<Candidate>& canList);
void updateDetails (Candidate &user);
void add_update_deleteJobsMenu(Employer& user,list<Candidate>& canList);
void canInJobs(Employer& user,list<Candidate>& canList);
void filteringJobs(Candidate &user,list<Employer>& empList);
void writeCanToFile(fstream& file,list<Candidate>& canList);
void writeEmpToFile(fstream& file,list<Employer>& empList);
void readCanFromFile(fstream& file,list<Candidate>& canList);
void readEmpFromFile(fstream& file,list<Employer>& empList);



int main() {

    signMenu();

    return 0;
}





void signMenu(){
    list<Employer> empList;
    list<Candidate> canList;

    //canList.push_front(Candidate("alm","bab","123123123","Aa123","cbwjbjcw@scjkhw.com",25,"my story"));
    //empList.push_front(Employer("alm","bab","123123123","Aa123","cbwjbjcw@scjkhw.com",25));


    fstream empFile("empData.txt",  ios::in);

    if (!empFile.is_open()) {
        cout << "Unable to open emp file!" << endl;
        return ;
    }

    fstream canFile("canData.txt",  ios::in);

    if (!canFile.is_open()) {
        cout << "Unable to open can file!" << endl;
        return ;
    }

    readCanFromFile(canFile,canList);
    readEmpFromFile(empFile,empList);
    empFile.close();
    canFile.close();


    string name,last_name,id,email,password,randPassword;
    int age = 0;
    bool flag = true,idFlag=true;
    int type;
    char choice;
    bool sysFlag = true;
    while(sysFlag) {
        cout << "welcome to job search (enter only integer number(1,2,3)):" << endl
             << "enter 1 if you Employer" << endl
             << "enter 2 if you Candidate" << endl
             << "enter 3 if you want close job search" << endl;
        cin >> type;
        while ((getchar()) != '\n');

        if (type == 1 || type == 2){
            flag = true;
            while (flag) {

                if(type == 1)
                    cout<<"welcome Employer"<<endl;
                else
                    cout<<"welcome Candidate"<<endl;

                cout << "enter 1 for Sign-up"<<endl
                <<"enter 2 for Login"<<endl
                <<"enter 3 if you forgot your password"<<endl
                <<"enter 4 for Exit" << endl;
                cin >> choice;
                while ((getchar()) != '\n');
                switch (choice) {
                    case '1':
                        do {
                            cout << "please enter your name(first letter capital): " << endl;
                            cin >> name;
                            while ((getchar()) != '\n');
                        } while (!isItGoodName(name));

                        do {
                            cout << "please enter your last name(first letter capital): " << endl;
                            cin >> last_name;
                            while ((getchar()) != '\n');
                        } while (!isItGoodName(last_name));

                        do {
                            cout << "please enter your id(9 numbers): " << endl;
                            cin >> id;
                            while ((getchar()) != '\n');
                            if(checkCanIdAlreadyInList(id,canList)||checkEmpIdAlreadyInList(id,empList)){
                                cout<<"this id already have account"<<endl;
                                id = "0";
                            }
                        } while (!isItGoodId(id));

                        do {
                            cout << "please enter your age(in integer numbers): " << endl;
                            cin >> age;
                            while ((getchar()) != '\n');
                        } while (!isItGoodAge(age));

                        do {
                            cout << "please enter your email: " << endl;
                            cin >> email;
                            while ((getchar()) != '\n');
                        } while (!isItGoodEmail(email));

                        do {
                            randPassword = getRandomPassword();
                            cout << "please enter your password or enter 1 if you want this random password: "
                                 << randPassword
                                 << endl;
                            cin >> password;
                            while ((getchar()) != '\n');
                            if (password == "1")
                                password = randPassword;
                        } while (!isItGoodPassword(password));

                        if (type == 1)
                            empList.push_front(Employer(name, last_name, id, password, email, age));
                        else {
                            canList.push_front(Candidate(name, last_name, id, password, email, age, enterStory()));
                        }
                        break;

                    case '2':
                        do {
                            cout << "please enter your id(9 numbers): " << endl;
                            cin >> id;
                            while ((getchar()) != '\n');
                        } while (!isItGoodId(id));

                        do {
                            cout << "please enter your password: " << endl;
                            cin >> password;
                            while ((getchar()) != '\n');
                        } while (!isItGoodPassword(password));

                        if (type == 1) {
                            for (auto it = empList.begin(); it != empList.end();) {
                                if (it->getId() == id) {
                                    if (it->getPassword() == password) {
                                        //cout << "welcome Employer" << endl;
                                        empMenu(*it,canList);
                                    } else
                                        cout << "wrong password" << endl;
                                    it = empList.end();
                                } else {
                                    ++it;
                                    if (it == empList.end())
                                        cout << "user didnt exist" << endl;
                                }
                            }
                        } else {
                            for (auto it = canList.begin(); it != canList.end();) {
                                if (it->getId() == id) {
                                    if (it->getPassword() == password) {
                                        canMenu(*it,empList);
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
                        idFlag=true;
                        cout<<"please enter your id(9 numbers):"<<endl;
                        cin>>id;
                        while(getchar()!='\n');
                        if(type==1){
                            for(auto emp=empList.begin();emp!=empList.end();++emp){
                                if(emp->getId()==id){
                                    idFlag=false;
                                    if(checkSameDetails(*emp)) {
                                        changePassword(*emp);
                                        cout<<"great,you change your password"<<endl;
                                    }
                                    else
                                        cout<<"the details are wrong"<<endl;
                                }
                            }
                        }
                        else{
                            for(auto can=canList.begin();can!=canList.end();++can){
                                if(can->getId()==id){
                                    idFlag=false;
                                    if(checkSameDetails(*can)) {
                                        changePassword(*can);
                                        cout<<"great,you change your password"<<endl;
                                    }
                                    else
                                        cout<<"the details are wrong"<<endl;
                                }
                            }
                        }
                        if(idFlag)
                            cout<<"id didnt exist in the system"<<endl;
                        break;


                    case '4':
                        flag = false;
                        break;

                    default:
                        cout << "try again" << endl;
                }
            }
        }

        else{
            if (type == 3)
                sysFlag = false;
            else
                cout<<"invalid input"<<endl;
        }
    }


    fstream empFileOut("empData.txt",  ios::out);

    if (!empFileOut.is_open()) {
        cout << "Unable to open emp file!" << endl;
        return ;
    }

    fstream canFileOut("canData.txt",  ios::out);

    if (!canFileOut.is_open()) {
        cout << "Unable to open can file!" << endl;
        return ;
    }
    canFileOut<<canList.size()<<endl;
    empFileOut<<empList.size()<<endl;
    writeCanToFile(canFileOut,canList);
    writeEmpToFile(empFileOut,empList);
    canFileOut.close();
    empFileOut.close();

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

bool isItGoodName(string &name){
    if(name[0]>='a' && name[0]<='z') {
        cout<<"first letter must be capital"<<endl;
        return false;
    }
    if(name[0]<'A' || name[0]>'Z') {
        cout<<"invalid name/last name"<<endl;
        return false;
    }
    for(int i = 1 ; i<name.size(); ++i){
        if(name[i]>='A' && name[i]<='Z'){
            cout<<"Except for the first letter, the rest of the letters should be lowercase"<<endl;
            return false;
        }
        if(name[i]<'a' || name[i]>'z') {
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



void canMenu(Candidate& user,list<Employer>& empList){
    char choice;
    string resume;
    bool flag = true;
    while(flag) {

        cout << "welcome to candidate menu " << user.getName()<<" please enter:" << endl
        <<"1 for change your personal information"<<endl
        <<"2 for enter your resume"<<endl
        <<"3 for see jobs and send request"<<endl
        <<"4 for see all jobs request history"<<endl
        <<"5 for logout"<<endl;
        cin>>choice;
        while ((getchar()) != '\n'); //clear buffer

        switch (choice) {

            case '1':
                updateDetails(user);
                break;

            case '2':
                cout<<"start write your resume and press enter when you done"<<endl;
                getline(cin,resume);
                user.setResume(resume);
                break;

            case '3':
                filteringJobs(user,empList);
                break;

            case '4':
                user.jobHistory();
                break;

            case '5':
                flag = false;
                break;

            default:
                cout<<"invalid choice try again"<<endl;

        }
    }
}


void empMenu(Employer& user,list<Candidate>& canList){

    char choice;
    bool flag = true;
    while(flag) {

        cout << "welcome to Employer menu " << user.getName()<<" please enter:" << endl
             <<"1 for add new job/update job/delete job"<<endl
             <<"2 for see all jobs you publish"<<endl
             <<"3 for see all the profile candidate that request one of your job"<<endl
             <<"4 for logout"<<endl;
        cin>>choice;
        while ((getchar()) != '\n'); //clear buffer

        switch (choice) {

            case '1':
                add_update_deleteJobsMenu(user,canList);
                break;

            case '2':
                user.printAllJobs();
                break;

            case '3':
                canInJobs(user,canList);
                break;

            case '4':
                flag = false;
                break;

            default:
                cout<<"invalid choice try again"<<endl;

        }
    }


}



void updateDetails (Candidate &user) {
    char choice;
    string name;
    string last_name;
    string id;
    string password;
    string email;
    string personalStory;
    int age;
    string resume;
    bool flag = true;
    while(flag) {

        cout<<endl<<"your details is:";
        user.printCan();

        cout << "Enter 1 for change your name" << endl
             << "Enter 2 for change your last name" << endl
             << "Enter 3 for change your age" << endl
             << "Enter 4 for change your email" << endl
             << "Enter 5 for change your personal story" << endl
             << "Enter 6 for change your resume" << endl
             << "Enter 7 for don't change nothing" << endl;

        cin >> choice;
        while ((getchar()) != '\n');
        switch (choice) {
            case '1':
                cout << "Enter your new name:" << endl;
                cin >> name;
                while ((getchar()) != '\n');
                if (isItGoodName(name)) {
                    user.setName(name);
                    cout << "your name is update!" << endl;
                } else
                    cout << "Please enter correct name." << endl;
                break;


            case '2':
                cout << "Enter your new last name:" << endl;
                cin >> last_name;
                while ((getchar()) != '\n');
                if (isItGoodName(last_name)) {
                    user.setLastName(last_name);
                    cout << "your last name is update!" << endl;
                }
                else
                    cout << "Please enter correct last name:" << endl;
                break;



            case '3':
                cout << "Enter your new age:" << endl;
                cin >> age;
                while ((getchar()) != '\n');
                if (isItGoodAge(age)) {
                    user.setAge(age);
                    cout << "your age is update!" << endl;
                }
                else
                    cout << "Please enter correct age" << endl;
                break;


            case '4':
                cout << "Enter your new email:" << endl;
                cin >> email;
                while ((getchar()) != '\n');
                if (isItGoodEmail(email)) {
                    user.setEmail(email);
                    cout << "your email is update!" << endl;
                }
                else
                    cout << "Please enter correct email" << endl;
                break;


            case '5':
                cout << "Enter your new personal story:" << endl;
                getline(cin, personalStory);
                if (isItGoodStory(personalStory)) {
                    user.setStory(personalStory);
                    cout << "your personal story is update!" << endl;
                }
                else
                    cout << "Please enter correct story" << endl;
                break;


            case '6':
                cout << "Enter your new resume:" << endl;
                cin >> resume;
                while ((getchar()) != '\n');
                user.setResume(resume);
                cout << "your resume is update!" << endl;
                break;


            case '7': {
                flag = false;
                break;
            }
            default:
                cout << "invalid choice try again" << endl;
        }
    }
}



void filteringJobs(Candidate &user,list<Employer>& empList){
    char choice;
    int experience = 0,counter = 0;
    string area, jobType, profession;
    bool saturday,flag = false;

    //choosing area
    cout << "please enter the job area:" << endl << "1 for north , 2 for Central , 3 for South , or any character for all: " << endl;
    cin>>choice;
    while ((getchar()) != '\n');
    if(choice == '1')
        area = "north";
    else{
        if(choice == '2')
            area = "central";
        else {
            if (choice == '3')
                area = "south";
            else{
                area = "any";
            }
        }
    }

    //choosing job type
    cout << "please enter the job time type:" << endl << "1 for full time job , 2 for half time job, or any character for all:" << endl;
    cin>>choice;
    while ((getchar()) != '\n');
    if(choice == '1')
            jobType = "full";
        else{
            if(choice == '2')
                jobType = "half";
            else {
                jobType = "any";
            }
        }

    //choosing experience
    do {
        cout<<"please enter experience level:"<<endl<<"1 for 0-2 years, 2 for 3-5 years, 3 for 6-9 years, 4 for 10+ years"<<endl;
        cin>>choice;
        while ((getchar()) != '\n');
        flag = false;
        switch (choice) {
            case '1':
                experience = 2;
                break;
            case '2':
                experience = 5;
                break;
            case '3':
                experience = 9;
                break;
            case '4':
                experience = 10;
                break;
            default:
                cout<<"invalid data try again"<<endl;
                flag = true;

        }
    } while (flag);

    //choosing profession
    do{
        flag = false;
        cout<<"please enter profession:"<<endl
            <<"1 for hi-tech"<<endl
            <<"2 for maintenance"<<endl
            <<"3 for civil servant"<<endl
            <<"4 for teaching"<<endl
            <<"5 for other"<<endl;
        cin>>choice;
        while ((getchar()) != '\n'); //clear buffer

        switch (choice) {
            case '1':
                profession = "hi-tech";
                break;
            case '2':
                profession = "maintenance";
                break;
            case '3':
                profession = "civil servant";
                break;
            case '4':
                profession = "teaching";
                break;
            case '5':
                profession = "other";
                break;
            default:
                flag = true;
        }
    }while(flag);

    //available in sat?
    cout<<"please enter 0 if you want job which does not include saturday or any key if the job include saturday"<<endl;
    cin>>saturday;


    for(auto it = empList.begin(); it != empList.end();++it){
        for(auto job = it->jobList.begin(); job != it->jobList.end();++job){
            if(job->inCri(area,jobType,saturday,profession,experience)) {
                ++counter;
                cout << "job number " << counter << endl;
                job->printJob();
                flag = true;
                while(flag) {
                    cout << endl << "apply to this job?(enter 1 if yes or 0 if no)" << endl;
                    cin >> choice;
                    while ((getchar()) != '\n');
                    if(choice == '1'){
                        if(!checkAlreadyIn(user.getId(),*job)) {
                            job->canIdInJob.push_front(user.getId());
                            user.canJobs.push_front(*job);
                        }
                        else
                            cout<<"you are already request this job"<<endl<<endl;
                        flag = false;
                    }
                    else {
                        if (choice == '0')
                            flag = false;
                        else
                            cout << "invalid key" << endl;
                    }
                }
            }
        }
    }
}


void writeEmpToFile(fstream& file,list<Employer>& empList){
    for(auto emp = empList.begin();emp!=empList.end();++emp){
        emp->writeToFile(file);
    }
}

void writeCanToFile(fstream& file,list<Candidate>& canList){
    for(auto can = canList.begin();can!=canList.end();++can){
        can->writeToFile(file);
    }
}

void readCanFromFile(fstream& file,list<Candidate>& canList){
    int size=0;
    file>>size;
    for(int i = 0;i<size;++i){
        Candidate newCan;
        newCan.readFromFile(file);
        canList.push_front(newCan);
    }

}
void readEmpFromFile(fstream& file,list<Employer>& empList){
    int size=0;
    file>>size;
    for(int i = 0;i<size;++i){
        Employer newEmp;
        newEmp.readFromFile(file);
        empList.push_front(newEmp);
    }

}


void deleteJob(Employer& emp,list<Candidate>& canList) {
    int job_choice = 0, counter = 0;
    if (emp.jobList.empty()){
        cout << "jobs list empty" << endl;
        return;
    }

    for (auto it = emp.jobList.begin(); it != emp.jobList.end(); ++it) {
        counter += 1;
        cout << "job number " << counter << endl;
        it->printJob();
    }
    do {
        cout << "please enter the job number you want to delete: " << endl;
        cin >> job_choice;
        while ((getchar()) != '\n');
    } while (job_choice > counter || job_choice < 1);
    for (auto it = emp.jobList.begin(); it != emp.jobList.end();) {
        while (job_choice - 1) {
            ++it;
            --job_choice;
        }
        for(auto id=it->canIdInJob.begin();id!=it->canIdInJob.end();++id){
            for(auto can=canList.begin();can!=canList.end();++can){
                if(can->getId()==*id){
                    can->deleteFromHistory(it);
                    //can->canJobs.erase(it);
                }
            }
        }
        emp.jobList.erase(it);
        it = emp.jobList.end();
    }
}


void add_update_deleteJobsMenu(Employer& user,list<Candidate>& canList){
    char choice;
    bool flag = true;
    while(flag) {
        cout << "enter 1 for adding job" << endl
             << "enter 2 for update job" << endl
             << "enter 3 for delete job" << endl
             << "enter 4 for back" << endl;
        cin >> choice;
        while (getchar() != '\n');
        switch (choice) {
            case '1':
                user.enterNewJob();
                break;
            case '2':
                user.updateJob();
                break;
            case '3':
                deleteJob(user, canList);
                break;
            case '4':
                flag = false;
                break;
            default:
                cout << "invalid input" << endl;

        }
    }
}


void canInJobs(Employer& emp,list<Candidate>& canList) {

    int counter = 0,job_choice;
    if (emp.jobList.empty()) {
        cout << "jobs list empty" << endl;
        return;
    }

    for (auto it = emp.jobList.begin(); it != emp.jobList.end(); ++it) {
        counter += 1;
        cout << "job number " << counter << endl;
        it->printJob();
    }
    do {
        cout << "please enter the job number you want to see all is candidate: " << endl;
        cin >> job_choice;
        while ((getchar()) != '\n');
    } while (job_choice > counter || job_choice < 1);
    for (auto job = emp.jobList.begin(); job != emp.jobList.end();) {
        while (job_choice - 1) {
            ++job;
            --job_choice;
        }
        if(job->canIdInJob.empty()){
            cout<<"there is no candidate in the request list for this job"<<endl;
            return;
        }
        for(auto id=job->canIdInJob.begin();id!=job->canIdInJob.end();++id){
            for(auto can=canList.begin();can!=canList.end();++can){
                if(can->getId()==*id){
                    can->printCan();
                }
            }
        }
        job = emp.jobList.end();
    }
}


bool checkAlreadyIn(string id,Jobs& job){
    for(auto it=job.canIdInJob.begin();it!=job.canIdInJob.end();++it){
        if(id == *it)
            return true;
    }
    return false;
}


bool checkEmpIdAlreadyInList(string id,list<Employer>& empList){
    for(auto it=empList.begin();it!=empList.end();++it){
        if(id==it->getId())
            return true;
    }
    return false;
}


bool checkCanIdAlreadyInList(string id,list<Candidate>& canList){
    for(auto it=canList.begin();it!=canList.end();++it){
        if(id==it->getId())
            return true;
    }
    return false;
}


bool checkSameDetails(const Employer& emp){
    string name,last_name,email;
    int age;
    cout<<"enter your name(first letter capital)"<<endl;
    cin>>name;
    while ((getchar()) != '\n');
    cout<<"enter your last name(first letter capital)"<<endl;
    cin>>last_name;
    while ((getchar()) != '\n');
    cout<<"enter your email"<<endl;
    cin>>email;
    while ((getchar()) != '\n');
    cout<<"enter your age(in numbers)"<<endl;
    cin>>age;
    while ((getchar()) != '\n');
    if(name==emp.getName()&&last_name==emp.getLastName()&&email==emp.getEmail()&&age==emp.getAge())
        return true;
    return false;
}


bool checkSameDetails(const Candidate& can){
    string name,last_name,email;
    int age;
    cout<<"enter your name(first letter capital)"<<endl;
    cin>>name;
    while ((getchar()) != '\n');
    cout<<"enter your last name(first letter capital)"<<endl;
    cin>>last_name;
    while ((getchar()) != '\n');
    cout<<"enter your email"<<endl;
    cin>>email;
    while ((getchar()) != '\n');
    cout<<"enter your age(in numbers)"<<endl;
    cin>>age;
    while ((getchar()) != '\n');
    if(name==can.getName()&&last_name==can.getLastName()&&email==can.getEmail()&&age==can.getAge())
        return true;
    return false;
}


void changePassword(Employer& emp){
    string randPassword,password;
    do {
        randPassword = getRandomPassword();
        cout << "please enter your password or enter 1 if you want this random password: "
             << randPassword
             << endl;
        cin >> password;
        while ((getchar()) != '\n');
        if (password == "1")
            password = randPassword;
    } while (!isItGoodPassword(password));
    emp.setPassword(password);
}


void changePassword(Candidate& can){
    string randPassword,password;
    do {
        randPassword = getRandomPassword();
        cout << "please enter your password or enter 1 if you want this random password: "
             << randPassword
             << endl;
        cin >> password;
        while ((getchar()) != '\n');
        if (password == "1")
            password = randPassword;
    } while (!isItGoodPassword(password));
    can.setPassword(password);
}