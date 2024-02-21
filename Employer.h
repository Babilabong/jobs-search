//
// Created by אלמוג בבילה on 02/02/2024.
//

#ifndef JOB_SEARCH_EMPLOYER_H
#define JOB_SEARCH_EMPLOYER_H
#include <iostream>
#include <string>
using namespace std;
#include "Jobs.h"
#include <list>


class Employer {
public:
    Employer(string name, string last_name, string id, string password, string email, int age):
    name(name), last_name(last_name), id(id), password(password), email(email), age(age){}
    Employer():name("null"), last_name("null"), id("null"), password("null"), email("null"), age(18){}

    Employer(const Employer& other);

    string getName() const{return name;}
    string getLastName() const{return last_name;}
    string getId() const{return id;}
    string getPassword() const{return password;}
    string getEmail() const{return email;}
    void setName(string name){this->name = name;}
    void setLastName(string lastName){last_name = lastName;}
    void setId(string id){this->id = id;}
    void setEmail(string email){this->email = email;}
    void setPassword(string password){this->password = password;}
    void printEmp();
    void enterNewJob();
    void printAllJobs();


private:
    string name;
    string last_name;
    string id;
    string password;
    string email;
    int age;
    list<Jobs> jobList;

};


#endif //JOB_SEARCH_EMPLOYER_H
