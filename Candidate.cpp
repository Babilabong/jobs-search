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
}

void Candidate::printCan() {
    cout<<endl<<"name: "<<name <<" "<<last_name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"email: "<<email<<endl;
    cout<<"about me: "<<personalStory<<endl;
    cout<<"resume: "<<resume<<endl;

}


