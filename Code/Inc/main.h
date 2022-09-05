
#ifndef STRUCT
#define STRUCT
    typedef struct variable_data
    {
        u_int8_t eqation_tipe;
        double a;
        double b;
        double c;
    } var_data;

    typedef struct ans_data
    {
        u_int8_t stat;
        double x_1;
        double x_2;
    } ans_data;
#endif

#ifndef EQENS_VAR_STAT_E
    #define EQENS_VAR_STAT_E
    enum EQENS_VAR_STAT
    {
        SQR_EQ = 1,
        LINE_EQ = 1 << 1,
        VAR_ERR = 1 << 2,
        TEST_MODE = 1 << 3
    };
#endif

#ifndef ANS_KEY_E
    #define ANS_KEY_E
    enum ANS_KEY
    {
        TWO_ANS = 1,
        ONE_ANS = 1 << 1, 
        INF_ANS = 1 << 2,
        NO_ANS = 1 << 3,
        BAD_DISC = 1 << 4,
        BAD_LOG_CONST = 1 << 5
    };
#endif

var_data var_init (int argc, char** argv);

ans_data trinomial_solve (var_data* var);

void ans_printer (var_data* var, ans_data* ans);


