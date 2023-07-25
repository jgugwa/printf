#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags
 * passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flag
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct phandler - struct to choose the right function depending
 * on format pass
 * @c: format 
 * @f: pointer to aligned printing function
 */
typedef struct phandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* convert */
char *convert(unsigned long int num, int base, int lowercase);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);


/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_npc(va_list l, flags_t *f);

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif
