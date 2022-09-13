#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "../Inc/main.h"
#include "../Inc/Qmath.h"
#include "../Inc/Unitest.h"

typedef struct Utest
{
    var_data i_var;
    var_data o_var;
    ans_data ans;
} Utest;


//====================||UTEST_TETSTS||========================================

#define NUM_OF_TEST 8

static const Utest test_mass [NUM_OF_TEST] =
    {
        {{SQR_EQ , 0, 0, 0}, {LINE_EQ, 0, 0, 0}, {INF_ANS, 0, 0}},         // вырожденное уравнение
        {{SQR_EQ , 0, 0, 1}, {LINE_EQ, 0, 0, 1}, {NO_ANS, 0, 0}},          // не валидное уравнение
        {{SQR_EQ , 0, 1, 1}, {LINE_EQ, 0, 1, 1}, {ONE_ANS, -1, 0}},        // проверка логического определения типа уравнения
        {{LINE_EQ , 0, 1, 1}, {LINE_EQ, 0, 1, 1}, {ONE_ANS, -1, 0}},       // допроверка на решение линейного уравнения
        {{SQR_EQ , 1, 1e200, 1}, {SQR_EQ, 1, 1e200, 1}, {BED_DISC, 0, 0}}, // невалидность дискриминанта
        {{SQR_EQ , 1, 1, 1}, {SQR_EQ, 1, 1, 1}, {NO_ANS, 0, 0}},           // проверка дискриминанта меньше 0
        {{SQR_EQ , 1, 2, 1}, {SQR_EQ, 1, 2, 1}, {ONE_ANS, -1, 0}},         // нулевой дискрминант
        {{SQR_EQ , 1, 4, 0}, {SQR_EQ, 1, 4, 0}, {TWO_ANS, 0, -4}}           // обычное квадратное уравнение
    };


//============================================================================

static u_int8_t Unitest_comp (Utest t_data, var_data o_var, ans_data ans);

static u_int8_t var_cmp (var_data a, var_data b);

static u_int8_t ans_cmp (ans_data a, ans_data b);

static void Unitest_report (Utest t_data, var_data o_var, ans_data ans, int num_of_test);


u_int8_t Unitest_start (ans_data (*qadratka) (var_data*))
{
    int i = 0;
    u_int8_t exit_status = UTEST_OK;
    for(i = 0; i < NUM_OF_TEST; i++)
    {
        var_data var_copy = test_mass[i].i_var;
        ans_data ans = (*qadratka)(&var_copy);

        if( Unitest_comp( test_mass[i], var_copy, ans) == UTEST_BED)
        {
            exit_status = UTEST_BED;
            Unitest_report (test_mass[i], var_copy, ans, i);
        }
    }

    return exit_status;
}

static void Unitest_report (Utest t_data, var_data o_var, ans_data ans, int num_of_test)
{
    printf("Test #%05d failed ------------------------------------------------------------\n", num_of_test);
    printf("Data, to input  : a = %.3f, b = %.3f, c = %.3f, var_status: %d\n", t_data.i_var.a, t_data.i_var.b, t_data.i_var.c, t_data.i_var.eqation_tipe);
    printf("Expected output : var_stat_out: %d, x_1 = %.3f, x_2 = %.3f, ans_status: %d\n", t_data.o_var.eqation_tipe,  t_data.ans.x_1, t_data.ans.x_2, t_data.ans.stat);
    printf("Real output     : var_stat_out: %d, x_1 = %.3f, x_2 = %.3f, ans_status: %d\n", o_var.eqation_tipe, ans.x_1, ans.x_2, ans.stat);
}

static u_int8_t Unitest_comp (Utest t_data, var_data o_var, ans_data ans)
{
    if ((var_cmp(t_data.o_var, o_var) == STRUCT_NOT_EQ) || (ans_cmp(t_data.ans, ans) == STRUCT_NOT_EQ))
    {
        return UTEST_BED;
    }
    else
    {
        return UTEST_OK;
    }    
}

static u_int8_t var_cmp (var_data a, var_data b)
{
    if ((d_comp(a.a, b.a) != AeqB) || (d_comp(a.b, b.b) != AeqB) || (d_comp(a.b, b.b) != AeqB) || (a.eqation_tipe != b.eqation_tipe))
    {
        return STRUCT_NOT_EQ;
    }
    else
    {
        return STRUCT_IS_EQ;
    }
    
}

static u_int8_t ans_cmp (ans_data a, ans_data b)
{
    if((a.stat != b.stat) || (d_comp(a.x_1, b.x_1) != AeqB) || (d_comp(a.x_2, b.x_2) != AeqB))
    {
        return STRUCT_NOT_EQ;
    }
    else
    {
        return STRUCT_IS_EQ;
    }
}
    