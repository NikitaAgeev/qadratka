#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "../Inc/main.h"
#include "../Inc/Qmath.h"

#define BAD_VAR 1
#define GOOD_VAR 0

#define PRECISION_AFTER_DOT 3

u_int8_t d_var_cheaker(char* c_var);

int main (int argc, char** argv)
{   
    var_data vars = var_init (argc, argv);
    ans_data ans =  trinomial_solve(&vars);
    ans_printer(&vars, &ans);
}

var_data var_init (int argc, char** argv)
{
    
    var_data vars = {};

    //Проверка количества переменных 
    if ((argc > 4) || (argc == 1)) 
    {
        vars.eqation_tipe = vars.eqation_tipe | VAR_ERR;
        return vars;
    }

    //Проверка на переход в тестовый режим
    if (argc == 2)
    {
        if(strcmp(argv[1], "test") == 0)
        {
            vars.eqation_tipe = vars.eqation_tipe | TEST_MODE;
            return vars;
        }
        else
        {
            vars.eqation_tipe = vars.eqation_tipe | VAR_ERR;
            return vars;
        }
    }

    //Проверка данных на числа
    u_int8_t i = 1;
    for (i = 1; i < argc; i ++)
    {
        if (d_var_cheaker(argv[i]) == BAD_VAR)
        {
            vars.eqation_tipe = vars.eqation_tipe | VAR_ERR;
            return vars; 
        } 
    }

    //Всё ок с точки зрения ввода, записываем переменные

    if (argc == 4)
    {   
        vars.a = atof(argv[1]);
        vars.b = atof(argv[2]);
        vars.c = atof(argv[3]);
        vars.eqation_tipe = SQR_EQ;
    }
    else
    {   
        vars.b = atof(argv[1]);
        vars.c = atof(argv[2]);
        vars.eqation_tipe = LINE_EQ;
    } 

    return vars;

}

u_int8_t d_var_cheaker(char* c_var)
{
    u_int8_t i = 0;
    u_int8_t dot_flag = 0;
    for (i = 0; c_var[i] != '\0'; i++)
    {
        if ((((c_var[i] < '0') || (c_var[i] > '9')) && c_var != 0) \
            || ((c_var[i] == '.') && dot_flag))
        {
            return BAD_VAR;
        }
        if (((c_var[i] == '.') && !dot_flag))
        {
            dot_flag = 1;
        }
    }
    return GOOD_VAR;
}

void ans_printer (var_data* var, ans_data* ans)
{   
    switch (ans->stat & (ONE_ANS | TWO_ANS | INF_ANS | NO_ANS))
    {
    case ONE_ANS:
        printf("x = %.*f\n", PRECISION_AFTER_DOT, ans->x_1);
        break;
    
    case TWO_ANS:
        printf("x1 = %.*f, x2 = %.*f\n", PRECISION_AFTER_DOT, ans->x_1,
                                         PRECISION_AFTER_DOT, ans->x_2);
        break;

    case INF_ANS:
        printf("Inf num of ans\n");
        break;

    case NO_ANS:
        printf("No ans\n");
        break;

    default:
        printf("No code\n");
        break;
    }
}