#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../Inc/main.h"
#include "../Inc/Qmath.h"

static ans_data square_solution (const var_data* var);

static ans_data line_solve (const var_data* var);



static ans_data square_solve (const var_data* var)
{
    double D = 0;
    ans_data ans = {};

    D = (var->b * var->b) - (4 * var->a * var->c);
    if (!isfinite(D))
    {
        ans.stat = ans.stat | BED_DISC;
        return ans;
    }
    else if (D < 0)
    {
        ans.stat = ans.stat | NO_ANS;
        return ans;
    }
    else if (d_comp(D, 0) == AeqB)
    {
        ans.stat = ans.stat | ONE_ANS;
        ans.x_1 = -var->b/(2 * var->a);
        if (!isfinite(ans.x_1))
        {
            ans.stat = ans.stat | BED_ANS;
        }
        return ans;
    }
    else
    {
        ans.stat = ans.stat | TWO_ANS;
        ans.x_1 = (-var->b + sqrtl(D))/(2 * var->a);
        ans.x_2 = (-var->b - sqrtl(D))/(2 * var->a);
        if (!isfinite(ans.x_1) || !isfinite(ans.x_2))
        {
            ans.stat = ans.stat | BED_ANS;
        }
        return ans;    
    }
}

static ans_data line_solve (const var_data* var)
{
    ans_data ans = {};
    ans.stat = ans.stat | ONE_ANS;
    ans.x_1 = var->c/var->b;
    return ans;
}

ans_data trinomial_solve (var_data* var)
{
    //Логическая проверка типа уравнения
    if ((var->eqation_tipe == SQR_EQ) && (d_comp(var->a, 0) == AeqB))
    {
        var->eqation_tipe = var->eqation_tipe & !SQR_EQ;
        var->eqation_tipe = var->eqation_tipe | LINE_EQ;
    }

    //Проверка наличия уравнения и определение решаемости
    if ((var->eqation_tipe == LINE_EQ) && (d_comp(var->b, 0) == AeqB))
    {   
        ans_data ans = {};
        if (d_comp(var->c, 0) == AeqB)
        {
            ans.stat = ans.stat | INF_ANS;
            return ans;    
        }
        else
        {
            ans_data ans = {};
            ans.stat = ans.stat | NO_ANS;
            return ans;
        }
    }

    //Распределение уравнений пофункциям решения
    
    switch (var->eqation_tipe)
    {
    case SQR_EQ:
        return square_solve(var);
        break;
    
    case LINE_EQ:
        return line_solve(var);
        break;

    default:
        return {};
        break;
    }
}

u_int8_t d_comp (double A, double B)
{
    if  (A > (B + DELT))
    {
        return AgrB;
    }
    else if (A < (B - DELT))
    {
        return BgrA;
    }
    else
    {
        return AeqB;
    }
}
