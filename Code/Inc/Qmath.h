
#ifndef COMP_CODE_E
    #define COMP_CODE_E
    enum COMP_CODE
    {
        AgrB = 1,
        BgrA = 1 << 1,
        AeqB = 1 << 2
    };
#endif

#define DELT 0.0001

ans_data square_solution (var_data* var);

u_int8_t d_comp (double A, double B);