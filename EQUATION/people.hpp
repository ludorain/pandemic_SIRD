#ifndef PEOPLE_HPP
#define PEOPLE_HPP


class People{
friend class Pandemic;
public:
//Default constructor 

People();
//Setter functions
//Setter with control
bool set_S(int);
bool set_I(int);
void control_SI();
bool set_R(int);
bool set_D(int);
//Setter without control
void set_People(int,int,int,int);

//Getter functions
int get_Total();
int get_Susceptible();
int get_Infected();
int get_Recovered();
int get_Deads();

protected:

    int S_;
    int I_;
    int R_;
    int D_;
    };

#endif