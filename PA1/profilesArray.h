//
// Created by musa on 2/9/21.
//

#ifndef CPTS_223_PA1_PROFILESARRAY_H
#define CPTS_223_PA1_PROFILESARRAY_H
#include "header.h"

class profilesArray
{
private:
    string name;
    string points;
public:

    profilesArray()
    {
    }

    ~profilesArray()
    {

    }
    void setName(string s)
    {

        name = s;

    }

    void setPoints(string p)
    {
        points = p;
    }
    string getName()
    {
        return name;
    }

    string  getPoints()
    {
        return points;
    }
};
#endif //CPTS_223_PA1_PROFILESARRAY_H
