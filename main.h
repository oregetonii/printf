#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces an output according to a format
 * @format: char string to print
 *
 * Return: num of chars printed to stdio
 */

int _printf(const char *format, ...);

#endif
