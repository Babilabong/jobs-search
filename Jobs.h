//
// Created by אלמוג בבילה on 09/02/2024.
//

#ifndef JOB_SEARCH_JOBS_H
#define JOB_SEARCH_JOBS_H
#include "Candidate.h"
#include <list>
#include <iostream>
using namespace std;
#include<string>

class Jobs {
public:
    Jobs(string area, string jobType, bool saturday, string profession, int experience):
    area(area),jobType(jobType),saturday(saturday),profession(profession),experience(experience){}

    void printJob()const;

private:
    //list<Candidate> canInJob;
    string area;
    string jobType;
    bool saturday;
    string profession;
    int experience;

};


#endif //JOB_SEARCH_JOBS_H
