//
// Created by אלמוג בבילה on 02/02/2024.
//

#include "Employer.h"

Employer::Employer(const Employer &other) {
    name = other.name;
    last_name = other.last_name;
    id = other.id;
    password = other.password;
    email = other.email;
    age = other.age;
}

void Employer::printEmp() {
    cout<<endl<<"name: "<< this->name <<endl;
    cout<<"last name: "<<this->last_name<<endl;
    cout<<"email: "<<this->email<<endl;
    cout<<"age: "<< this->age<<endl;
    cout<<"ID: "<<this->id<<endl;
    cout<<"password: "<<this->password<<endl;

}

void Employer::enterNewJob() {
    char choice;
    int experience = 0;
    string area, jobType, profession;
    bool saturday,flag = false;

    //choosing area
    do {
        flag = false;
        cout << "please enter the job area:" << endl << "1 for north , 2 for Central , 3 for South: " << endl;
        cin>>choice;
        if(choice == '1')
            area = "north";
        else{
            if(choice == '2')
                area = "central";
            else {
                if (choice == '3')
                    area = "south";
                else{
                    cout<<"invalid input"<<endl;
                    flag = true;
                }
            }
        }
    } while (flag);

    //choosing job type
    do {
        flag = false;
        cout << "please enter the job time type:" << endl << "1 for full time job , 2 for half time job:" << endl;
        cin>>choice;
        if(choice == '1')
            jobType = "full";
        else{
            if(choice == '2')
                jobType = "half";
            else {
                cout<<"invalid input"<<endl;
                flag = true;
            }
        }
    } while (flag);

    //choosing experience
    do {
        flag = false;
        cout << "please enter the experience in years for the job:" << endl;
        cin>>experience;
        if(experience<0){
            cout<<"cant be a negative experience"<<endl;
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
                cout<<"please enter the job profession: "<<endl;
                getline(cin,profession);
                break;
            default:
                flag = true;
        }
    }while(flag);

    //available in sat?
    cout<<"please enter 0 if the job not include saturday or any key if the job include saturday"<<endl;
    cin>>saturday;

    jobList.push_front(Jobs(area,jobType,saturday,profession,experience));

}

void Employer::printAllJobs() {
    for(auto it = jobList.begin();it != jobList.end();++it){
        it->printJob();
    }
}
