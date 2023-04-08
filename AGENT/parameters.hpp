#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

class Parameters{ 

    public:
    //costruttore default
    Parameters();

    //funzioni set
    void set_Beta(float);
    void set_Gamma(float);
    void set_Mu(float);


    //funzioni get
    float get_Alfa();
    float get_Beta();
    float get_Gamma();
    float get_Mu();

    private:

    float Alfa_;
    float Beta_;
    float Gamma_;
    float Mu_;
};

#endif