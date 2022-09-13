enum UTEST_OUT
{
    UTEST_OK = 0,
    UTEST_BED = 1
};

enum STRUCT_CMP_OUT
{
    STRUCT_IS_EQ = 0,
    STRUCT_NOT_EQ = 1
};

u_int8_t Unitest_start (ans_data (*qadratka) (var_data*));