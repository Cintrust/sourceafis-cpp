//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_MINUTIAPAIR_H
#define SOURCEAFIS_CPP_MINUTIAPAIR_H

#include <string>

class MinutiaPair {
public:
    int probe;
    int candidate;
    int probeRef;
    int candidateRef;
    int distance;
    int supportingEdges;

    inline  std::string toString() {

        return (std::to_string(probe)+"<->"+std::to_string(candidate)+" @ "
        +std::to_string(probeRef)+"<->"+std::to_string(candidateRef)+" #"+std::to_string(supportingEdges));
    }
    inline explicit operator std::string (){
        return   toString();
    }
};


#endif //SOURCEAFIS_CPP_MINUTIAPAIR_H
