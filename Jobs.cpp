//
// Created by אלמוג בבילה on 09/02/2024.
//

#include "Jobs.h"

void Jobs::printJob()const {
    cout<<"profession: "<<profession<<endl;
    cout<<"area: "<<area<<endl;
    cout<<"job type: "<<jobType<<endl;
    if(saturday)
        cout<<"include saturday"<<endl;
    cout<<"experience: "<<experience<<endl<<endl;

}
