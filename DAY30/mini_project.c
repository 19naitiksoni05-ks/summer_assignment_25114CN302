#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PI 3.14159265358979323846
#define E_CONST 2.71828182845904523536
#define MAX_EXPR 256
#define MAX_HIST 10
#define STACK_SIZE 64
#define ERROR_VALUE -9999.0

char history[MAX_HIST][MAX_EXPR];
int hist_count = 0;

int show_menu(void)
{
    int ch;

    printf("\n+======================================+\n");
    printf("|     SCIENTIFIC CALCULATOR (C)        |\n");
    printf("+======================================+\n");
    printf("|  1. Basic Arithmetic (BODMAS)        |\n");
    printf("|  2. Powers & Roots                   |\n");
    printf("|  3. Logarithms                       |\n");
    printf("|  4. Trigonometry                     |\n");
    printf("|  5. View History                     |\n");
    printf("|  6. Clear History                    |\n");
    printf("|  7. Exit                             |\n");
    printf("+======================================+\n");
    printf("  Choice: ");

    if (scanf("%d", &ch) != 1)
    {
        while (getchar() != '\n')
            ;
        return -1;
    }

    return ch;
}

int add_history(const char *entry)
{
    if (hist_count < MAX_HIST)
    {
        strncpy(history[hist_count], entry, MAX_EXPR - 1);
        history[hist_count][MAX_EXPR - 1] = '\0';
        hist_count++;
    }
    else
    {
        int i;

        for (i = 0; i < MAX_HIST - 1; i++)
            strcpy(history[i], history[i + 1]);

        strncpy(history[MAX_HIST - 1], entry, MAX_EXPR - 1);
        history[MAX_HIST - 1][MAX_EXPR - 1] = '\0';
    }

    return hist_count;
}

int print_history(void)
{
    int i;

    if (hist_count == 0)
    {
        printf("  [No history yet]\n");
        return 0;
    }

    printf("\n-- Calculation History --\n");
    for (i = 0; i < hist_count; i++)
        printf("  %2d. %s\n", i + 1, history[i]);

    return hist_count;
}

int clear_history(void)
{
    hist_count = 0;
    memset(history, 0, sizeof(history));
    printf("  History cleared.\n");
    return 0;
}

static int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

static int is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

static int right_associative(char op)
{
    return op == '^';
}

static double apply_op(double a, double b, char op, int *error)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0.0)
        {
            printf("  [Division by zero]\n");
            *error = 1;
            return 0.0;
        }
        return a / b;
    }
    if (op == '^')
        return pow(a, b);

    *error = 1;
    return 0.0;
}

static int reduce_once(double vals[], int *vi, char ops[], int *oi, int *error)
{
    double a, b;
    char op;

    if (*vi < 2 || *oi < 1)
    {
        *error = 1;
        return 0;
    }

    b = vals[--(*vi)];
    a = vals[--(*vi)];
    op = ops[--(*oi)];
    vals[(*vi)++] = apply_op(a, b, op, error);

    return !*error;
}

double eval_expression(const char *expr, int *error)
{
    double vals[STACK_SIZE];
    char ops[STACK_SIZE];
    int vi = 0, oi = 0;
    int i = 0;
    int n = (int)strlen(expr);
    int expect_value = 1;

    *error = 0;

    while (i < n)
    {
        if (isspace((unsigned char)expr[i]))
        {
            i++;
            continue;
        }

        if (isdigit((unsigned char)expr[i]) || expr[i] == '.' ||
            (expr[i] == '-' && expect_value))
        {
            char *endptr;
            double val = strtod(&expr[i], &endptr);

            if (endptr == &expr[i] || vi >= STACK_SIZE)
            {
                *error = 1;
                return 0.0;
            }

            vals[vi++] = val;
            i = (int)(endptr - expr);
            expect_value = 0;
            continue;
        }

        if (expr[i] == '(')
        {
            if (oi >= STACK_SIZE)
            {
                *error = 1;
                return 0.0;
            }
            ops[oi++] = expr[i++];
            expect_value = 1;
            continue;
        }

        if (expr[i] == ')')
        {
            while (oi > 0 && ops[oi - 1] != '(')
            {
                if (!reduce_once(vals, &vi, ops, &oi, error))
                    return 0.0;
            }

            if (oi == 0)
            {
                *error = 1;
                return 0.0;
            }

            oi--;
            i++;
            expect_value = 0;
            continue;
        }

        if (is_operator(expr[i]))
        {
            char current = expr[i];

            if (expect_value)
            {
                *error = 1;
                return 0.0;
            }

            while (oi > 0 && ops[oi - 1] != '(' &&
                   (precedence(ops[oi - 1]) > precedence(current) ||
                    (precedence(ops[oi - 1]) == precedence(current) &&
                     !right_associative(current))))
            {
                if (!reduce_once(vals, &vi, ops, &oi, error))
                    return 0.0;
            }

            if (oi >= STACK_SIZE)
            {
                *error = 1;
                return 0.0;
            }

            ops[oi++] = current;
            i++;
            expect_value = 1;
            continue;
        }

        printf("  [Unknown char '%c']\n", expr[i]);
        *error = 1;
        return 0.0;
    }

    if (expect_value)
    {
        *error = 1;
        return 0.0;
    }

    while (oi > 0)
    {
        if (ops[oi - 1] == '(')
        {
            *error = 1;
            return 0.0;
        }

        if (!reduce_once(vals, &vi, ops, &oi, error))
            return 0.0;
    }

    if (vi != 1)
    {
        *error = 1;
        return 0.0;
    }

    return vals[0];
}

int menu_bodmas(void)
{
    char expr[MAX_EXPR], record[MAX_EXPR + 32];
    int err;
    double result;

    printf("\n-- BODMAS Expression Evaluator --\n");
    printf("  Operators: + - * / ^ ( )\n");
    printf("  Example: (3+5)*2^2-4/2\n");
    printf("  Enter expression: ");
    scanf(" %255[^\n]", expr);

    result = eval_expression(expr, &err);
    if (!err)
    {
        printf("  Result: %s = %.6g\n", expr, result);
        snprintf(record, sizeof(record), "BODMAS | %s = %.6g", expr, result);
        add_history(record);
    }
    else
    {
        printf("  Invalid expression.\n");
    }

    return 1;
}

double nth_root(double x, double n)
{
    double rounded;

    if (n == 0.0)
        return ERROR_VALUE;

    rounded = round(n);
    if (x < 0.0 && fabs(n - rounded) > 1e-10)
        return ERROR_VALUE;
    if (x < 0.0 && ((long long)rounded % 2 == 0))
        return ERROR_VALUE;
    if (x < 0.0)
        return -pow(fabs(x), 1.0 / rounded);

    return pow(x, 1.0 / n);
}

int menu_roots(void)
{
    char record[MAX_EXPR];
    double a, b, result;
    int ch;

    printf("\n-- Powers & Roots --\n");
    printf("  1. a ^ b   (power)\n");
    printf("  2. sqrt(a) (square root)\n");
    printf("  3. cbrt(a) (cube root)\n");
    printf("  4. n-th root of a\n");
    printf("  Choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("  Enter base a: ");
        scanf("%lf", &a);
        printf("  Enter exponent b: ");
        scanf("%lf", &b);
        result = pow(a, b);
        printf("  %.6g ^ %.6g = %.6g\n", a, b, result);
        snprintf(record, sizeof(record), "POW   | %.6g ^ %.6g = %.6g", a, b, result);
        break;
    case 2:
        printf("  Enter a: ");
        scanf("%lf", &a);
        if (a < 0)
        {
            printf("  Error: sqrt of negative\n");
            return 1;
        }
        result = sqrt(a);
        printf("  sqrt(%.6g) = %.6g\n", a, result);
        snprintf(record, sizeof(record), "SQRT  | sqrt(%.6g) = %.6g", a, result);
        break;
    case 3:
        printf("  Enter a: ");
        scanf("%lf", &a);
        result = cbrt(a);
        printf("  cbrt(%.6g) = %.6g\n", a, result);
        snprintf(record, sizeof(record), "CBRT  | cbrt(%.6g) = %.6g", a, result);
        break;
    case 4:
        printf("  Enter a: ");
        scanf("%lf", &a);
        printf("  Enter n: ");
        scanf("%lf", &b);
        result = nth_root(a, b);
        if (result == ERROR_VALUE)
        {
            printf("  Error: invalid root\n");
            return 1;
        }
        printf("  %g-th root of %.6g = %.6g\n", b, a, result);
        snprintf(record, sizeof(record), "ROOT  | %g-root(%.6g) = %.6g", b, a, result);
        break;
    default:
        printf("  Invalid choice.\n");
        return 1;
    }

    add_history(record);
    return 1;
}

double log_base(double x, double base)
{
    if (x <= 0 || base <= 0 || base == 1)
        return ERROR_VALUE;
    return log(x) / log(base);
}

int menu_log(void)
{
    char record[MAX_EXPR];
    double a, base, result;
    int ch;

    printf("\n-- Logarithms --\n");
    printf("  1. log10(a)       (common log)\n");
    printf("  2. ln(a)          (natural log)\n");
    printf("  3. log2(a)\n");
    printf("  4. log_b(a)       (any base)\n");
    printf("  5. antilog10(a)   (10^a)\n");
    printf("  Choice: ");
    scanf("%d", &ch);

    printf("  Enter a: ");
    scanf("%lf", &a);

    switch (ch)
    {
    case 1:
        if (a <= 0)
        {
            printf("  Error: log of non-positive\n");
            return 1;
        }
        result = log10(a);
        printf("  log10(%.6g) = %.6g\n", a, result);
        snprintf(record, sizeof(record), "LOG10 | log10(%.6g) = %.6g", a, result);
        break;
    case 2:
        if (a <= 0)
        {
            printf("  Error: ln of non-positive\n");
            return 1;
        }
        result = log(a);
        printf("  ln(%.6g) = %.6g\n", a, result);
        snprintf(record, sizeof(record), "LN    | ln(%.6g) = %.6g", a, result);
        break;
    case 3:
        if (a <= 0)
        {
            printf("  Error: log2 of non-positive\n");
            return 1;
        }
        result = log2(a);
        printf("  log2(%.6g) = %.6g\n", a, result);
        snprintf(record, sizeof(record), "LOG2  | log2(%.6g) = %.6g", a, result);
        break;
    case 4:
        if (a <= 0)
        {
            printf("  Error: log of non-positive\n");
            return 1;
        }
        printf("  Enter base b: ");
        scanf("%lf", &base);
        result = log_base(a, base);
        if (result == ERROR_VALUE)
        {
            printf("  Error: invalid base\n");
            return 1;
        }
        printf("  log_%.6g(%.6g) = %.6g\n", base, a, result);
        snprintf(record, sizeof(record), "LOGB  | log_%g(%.6g) = %.6g", base, a, result);
        break;
    case 5:
        result = pow(10.0, a);
        printf("  10^%.6g = %.6g\n", a, result);
        snprintf(record, sizeof(record), "ALOG  | 10^%.6g = %.6g", a, result);
        break;
    default:
        printf("  Invalid choice.\n");
        return 1;
    }

    add_history(record);
    return 1;
}

double deg_to_rad(double deg)
{
    return deg * PI / 180.0;
}

double rad_to_deg(double rad)
{
    return rad * 180.0 / PI;
}

static const char *trig_names[] = {
    "sin", "cos", "tan",
    "cot", "sec", "csc",
    "asin", "acos", "atan",
    "sinh", "cosh", "tanh"};

#define TRIG_COUNT 12

double compute_trig(int idx, double val, int *err)
{
    double r = deg_to_rad(val);

    *err = 0;

    switch (idx)
    {
    case 0:
        return sin(r);
    case 1:
        return cos(r);
    case 2:
        if (fabs(cos(r)) < 1e-10)
        {
            *err = 1;
            return 0.0;
        }
        return tan(r);
    case 3:
        if (fabs(sin(r)) < 1e-10)
        {
            *err = 1;
            return 0.0;
        }
        return 1.0 / tan(r);
    case 4:
        if (fabs(cos(r)) < 1e-10)
        {
            *err = 1;
            return 0.0;
        }
        return 1.0 / cos(r);
    case 5:
        if (fabs(sin(r)) < 1e-10)
        {
            *err = 1;
            return 0.0;
        }
        return 1.0 / sin(r);
    case 9:
        return sinh(val);
    case 10:
        return cosh(val);
    case 11:
        return tanh(val);
    default:
        *err = 1;
        return 0.0;
    }
}

double compute_inv_trig(int idx, double val, int *err)
{
    *err = 0;

    switch (idx)
    {
    case 0:
        if (val < -1 || val > 1)
        {
            *err = 1;
            return 0.0;
        }
        return rad_to_deg(asin(val));
    case 1:
        if (val < -1 || val > 1)
        {
            *err = 1;
            return 0.0;
        }
        return rad_to_deg(acos(val));
    case 2:
        return rad_to_deg(atan(val));
    default:
        *err = 1;
        return 0.0;
    }
}

int menu_trig(void)
{
    char record[MAX_EXPR];
    double val, result;
    int i, ch, err;

    printf("\n-- Trigonometry --\n");
    printf("  -- Standard (input: degrees) --\n");
    for (i = 0; i < 6; i++)
        printf("  %2d. %-5s\n", i + 1, trig_names[i]);
    printf("  -- Inverse (input: ratio) --\n");
    for (i = 6; i < 9; i++)
        printf("  %2d. %-5s\n", i + 1, trig_names[i]);
    printf("  -- Hyperbolic (input: value) --\n");
    for (i = 9; i < TRIG_COUNT; i++)
        printf("  %2d. %-5s\n", i + 1, trig_names[i]);
    printf("  Choice: ");
    scanf("%d", &ch);
    ch--;

    if (ch < 0 || ch >= TRIG_COUNT)
    {
        printf("  Invalid choice.\n");
        return 1;
    }

    if (ch >= 6 && ch <= 8)
    {
        printf("  Enter ratio value: ");
        scanf("%lf", &val);
        result = compute_inv_trig(ch - 6, val, &err);
        if (err)
        {
            printf("  Error: value out of domain.\n");
            return 1;
        }
        printf("  %s(%.6g) = %.6g deg\n", trig_names[ch], val, result);
        snprintf(record, sizeof(record), "TRIG  | %s(%.6g) = %.6g deg",
                 trig_names[ch], val, result);
    }
    else if (ch >= 9)
    {
        printf("  Enter value: ");
        scanf("%lf", &val);
        result = compute_trig(ch, val, &err);
        if (err)
        {
            printf("  Error: undefined.\n");
            return 1;
        }
        printf("  %s(%.6g) = %.6g\n", trig_names[ch], val, result);
        snprintf(record, sizeof(record), "TRIG  | %s(%.6g) = %.6g",
                 trig_names[ch], val, result);
    }
    else
    {
        printf("  Enter angle (degrees): ");
        scanf("%lf", &val);
        result = compute_trig(ch, val, &err);
        if (err)
        {
            printf("  Error: undefined at this angle.\n");
            return 1;
        }
        printf("  %s(%.6g deg) = %.6g\n", trig_names[ch], val, result);
        snprintf(record, sizeof(record), "TRIG  | %s(%.6g deg) = %.6g",
                 trig_names[ch], val, result);
    }

    add_history(record);
    return 1;
}

int main(void)
{
    int running = 1;

    printf("\n  Welcome to the Scientific Calculator\n");
    printf("  Constants available: PI = %.5f, e = %.5f\n", PI, E_CONST);

    while (running)
    {
        int choice = show_menu();

        switch (choice)
        {
        case 1:
            menu_bodmas();
            break;
        case 2:
            menu_roots();
            break;
        case 3:
            menu_log();
            break;
        case 4:
            menu_trig();
            break;
        case 5:
            print_history();
            break;
        case 6:
            clear_history();
            break;
        case 7:
            printf("\n  Goodbye!\n");
            running = 0;
            break;
        default:
            printf("  Invalid option. Try again.\n");
        }
    }

    return 0;
}
