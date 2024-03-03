//
// Created by אלמוג בבילה on 09/02/2024.
//

#include "Jobs.h"

Jobs::Jobs():area("none"),jobType("none"),saturday(false),profession("none"),experience(0),empId("none"){
    canIdInJob.clear();
}


void Jobs::printJob()const {
    cout<<"profession: "<<profession<<endl;
    cout<<"area: "<<area<<endl;
    cout<<"job type: "<<jobType<<endl;
    if(saturday)
        cout<<"include saturday"<<endl;
    cout<<"experience: "<<experience<<endl<<endl;

}

bool Jobs::inCri(string area, string jobType, bool saturday, string profession, int experience) {

    if(area != this->area && area != "any")
        return false;
    if(jobType != this->jobType && jobType != "any")
        return false;
    if(saturday != this->saturday)
        return false;
    if(profession != this->profession && profession != "other")
        return false;
    if(experience==2 && this->experience>2)
        return false;
    if(experience==5 && (this->experience<3|| this->experience>5))
        return false;
    if(experience==9 && (this->experience<6|| this->experience>9))
        return false;
    if(experience==10 && this->experience<10)
        return false;

    return true;
}

void Jobs::writeToFile(fstream &file) {

    file<<area<<endl;
    file<<jobType<<endl;
    file<<saturday<<endl;
    file<<profession<<endl;
    file<<experience<<endl;
    file<<empId<<endl;
    file<<canIdInJob.size()<<endl;
    for(auto id = canIdInJob.begin();id!=canIdInJob.end();++id){
        file<<*id<<endl;
    }
}

void Jobs::readFromFile(fstream &file) {
    int idSize=0;
    file>>area;
    file>>jobType;
    file>>saturday;
    file>>profession;
    file>>experience;
    file>>empId;
    file>>idSize;
    for(int i=0;i<idSize;++i){
        string newId;
        file>>newId;
        canIdInJob.push_front(newId);
    }
}

Jobs::Jobs(const Jobs& other) {
    area = other.area;
    jobType = other.jobType;
    saturday = other.saturday;
    profession = other.profession;
    experience = other.experience;
    empId = other.empId;
    canIdInJob.clear();
    for(auto it=other.canIdInJob.begin();it!=other.canIdInJob.end();++it){
        canIdInJob.push_front(*it);
    }
}
