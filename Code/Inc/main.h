
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
        BED_VAR = 1 << 2,
        COMAND_MODE = 1 << 3,
        NO_VARIABLE = 1 << 4
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
        BED_DISC = 1 << 4,
        BED_ANS = 1 << 5
    };
#endif

#ifndef COMAND_KEY_E
    #define COMAND_KEY_E
    enum COMAND_KEY
    {
        NO_COMAND = 1,
        BAD_COMAND = 1 << 1,
        TEST = 1 << 2,
        HELP = 1 << 3  
    };
#endif

var_data var_init (int argc, char** argv);

ans_data trinomial_solve (var_data* var);

void ans_printer (var_data* var, ans_data* ans);

u_int8_t var_err_cheacker (var_data* var);

u_int8_t d_var_cheaker(char* c_var);

u_int8_t comand_manager (var_data* var, char** argv);

u_int8_t ans_err_cheacker (ans_data* ans);

