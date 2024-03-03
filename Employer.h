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
#include <fstream>


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
    int getAge() const{return age;}
    void setName(string name){this->name = name;}
    void setLastName(string lastName){last_name = lastName;}
    void setId(string id){this->id = id;}
    void setEmail(string email){this->email = email;}
    void setPassword(string password){this->password = password;}
    void setAge(int age){ this->age=age;}
    void printEmp();
    void enterNewJob();
    void printAllJobs();
    void updateJob();
    void deleteJob();
    void writeToFile(fstream& file);
    void readFromFile(fstream& file);

    list<Jobs> jobList;


private:
    string name;
    string last_name;
    string id;
    string password;
    string email;
    int age;

};


#endif //JOB_SEARCH_EMPLOYER_H
