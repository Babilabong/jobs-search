//
// Created by אלמוג בבילה on 06/02/2024.
//

#ifndef JOB_SEARCH_CANDIDATE_H
#define JOB_SEARCH_CANDIDATE_H
#include <string>
#include <iostream>
using namespace std;
#include "Jobs.h"
#include <list>
#include <fstream>

class Candidate {
public:
    Candidate(string name, string last_name, string id, string password, string email, int age, string story):
            name(name), last_name(last_name), id(id), password(password), email(email), personalStory(story), age(age),resume("empty"){}
    Candidate(const Candidate& other);
    Candidate():name("null"), last_name("null"), id("null"), password("null"), email("null"), personalStory("null"), age(18),resume("empty"){}

    string getName() const{return name;}
    string getLastName() const{return last_name;}
    string getId() const{return id;}
    string getPassword() const{return password;}
    string getEmail() const{return email;}
    int getAge() const{return age;}
    void setResume(string resume){this->resume = resume;}
    void setName(string name){this->name = name;}
    void setLastName(string lastName){last_name = lastName;}
    void setId(string id){this->id = id;}
    void setEmail(string email){this->email = email;}
    void setPassword(string password){this->password = password;}
    void setAge(int age){this->age = age;}
    void setStory(string personalStory){this->personalStory = personalStory;}
    void printCan();
    void jobHistory();
    void deleteFromHistory(list<Jobs>::iterator job);
    void writeToFile(fstream& file);
    void readFromFile(fstream& file);

    list<Jobs> canJobs;

private:
    string name;
    string last_name;
    string id;
    string password;
    string email;
    string personalStory;
    int age;
    string resume;
};


#endif //JOB_SEARCH_CANDIDATE_H
