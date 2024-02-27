//
// Created by אלמוג בבילה on 06/02/2024.
//

#include "Candidate.h"

Candidate::Candidate(const Candidate &other) {
    name = other.name;
    last_name = other.last_name;
    id = other.id;
    password = other.password;
    email = other.email;
    age = other.age;
    personalStory = other.personalStory;
    resume = other.resume;
    for(auto job=other.canJobs.begin();job!=other.canJobs.end();++job){
        canJobs.push_front(*job);
    }
}

void Candidate::printCan() {
    cout<<endl<<"name: "<<name <<" "<<last_name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"email: "<<email<<endl;
    cout<<"about me: "<<personalStory<<endl;
    cout<<"resume: "<<resume<<endl;

}

void Candidate::jobHistory() {
    int counter = 0;
    for(auto it=canJobs.begin();it!=canJobs.end();++it) {
        ++counter;
        cout<<endl<<"job "<<counter<<endl;
        it->printJob();
    }
}

void Candidate::writeToFile(fstream& file) {

    file<<name<<endl;
    file<<last_name<<endl;
    file<<id<<endl;
    file<<password<<endl;
    file<<email<<endl;
    file<<personalStory<<endl;
    file<<age<<endl;
    file<<resume<<endl;
    file<<canJobs.size()<<endl;
    for(auto job = canJobs.begin();job != canJobs.end();++job){
        job->writeToFile(file);
    }
}

void Candidate::readFromFile(fstream &file) {
    int jobSize=0;
    file>>name;
    file>>last_name;
    file>>id;
    file>>password;
    file>>email;
    file>>personalStory;
    file>>age;
    file>>resume;
    file>>jobSize;
    for(int i = 0;i<jobSize;++i){
        Jobs newJob;
        newJob.readFromFile(file);
        canJobs.push_front(newJob);
    }
    //return *this;
}

void Candidate::deleteFromHistory(list<Jobs>::iterator job) {
    for(auto it=canJobs.begin();it!=canJobs.end();++it){
        if(it->getArea() == job->getArea()&&
        it->getSaturday()==job->getSaturday()&&
        it->getEmpId()==job->getEmpId()&&
        it->getExperience()==job->getExperience()&&
        it->getJobType()==job->getJobType()&&
        it->getProfession()==job->getProfession()) {
            canJobs.erase(it);
            it=canJobs.end();
        }
    }
}