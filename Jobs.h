//
// Created by אלמוג בבילה on 09/02/2024.
//

#ifndef JOB_SEARCH_JOBS_H
#define JOB_SEARCH_JOBS_H
#include <list>
#include <iostream>
using namespace std;
#include<string>
#include <fstream>

class Jobs {
public:
    Jobs();

    Jobs(string area, string jobType, bool saturday, string profession, int experience, string empId):
    area(area),jobType(jobType),saturday(saturday),profession(profession),experience(experience),empId(empId){}

    Jobs(const Jobs& other);

    void printJob()const;
    bool inCri(string area, string jobType, bool saturday, string profession, int experience);
    void setArea(string area){ this->area=area;}
    void setJobType(string jobType){ this->jobType=jobType;}
    void setProfession(string profession){ this->profession=profession;}
    void setExperience(int exp){experience=exp;}
    void setSaturday(bool sat){saturday=sat;}
    string getArea(){return area;}
    string getJobType(){return jobType;}
    string getProfession(){return profession;}
    string getEmpId(){return empId;}
    int getExperience(){return experience;}
    bool getSaturday(){return saturday;}
    void writeToFile(fstream& file);
    void readFromFile(fstream& file);

    list<string> canIdInJob;

private:
    string area;
    string jobType;
    bool saturday;
    string profession;
    int experience;
    string empId;

};


#endif //JOB_SEARCH_JOBS_H
