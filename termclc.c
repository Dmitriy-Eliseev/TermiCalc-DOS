/*******************************************************************************
 *  TERMCLC.C
 *  created:  2023-05-10
 *  modified: 2025-07-10
 *       _______                  _  _____      _      
 *      |__   __|                (_)/ ____|    | |     
 *         | | ___ _ __ _ __ ___  _| |     __ _| | ___ 
 *         | |/ _ \ '__| '_ ` _ \| | |    / _` | |/ __|
 *         | |  __/ |  | | | | | | | |___| (_| | | (__ 
 *         |_|\___|_|  |_| |_| |_|_|\_____\__,_|_|\___|
 *  
 *  TermiCalc  --  simple console calculator with trigonometric functions
 *  Copyright (C) 2023, 2025 Dmitriy Eliseev
 *  <code.eliseev2003.dmitriy@yandex.com>
 * 
 *  TermiCalc is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  TermiCalc is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TermiCalc.  If not, see <http://www.gnu.org/licenses/>.
 *
 * DOS version.
 * Ported to DOS 2025-07-10
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tinyexpr.h"

void print_help(void) {
    puts("\nTermiCalc v1.3 [DOS]\n"
         "Copyright (C) 2023, 2025 Dmitriy Eliseev\n"
         "Based on TinyExpr: https://github.com/codeplea/tinyexpr\n\n"
         "This program comes with ABSOLUTELY NO WARRANTY\n"
         "This is free software, and you are welcome to redistribute it\n"
         "under certain conditions.\n\n"
         "This is a simple console calculator that allows you "
         "to calculate arithmetic\n"
         "and trigonometric expressions.\n\n"
         "Usage:\n"
         "$ tcalc [expression ...]\n"
         "$ tcalc [expression1] [expression2] [expression ...]\n"
         "$ tcalc\n\n"
         "Examples:\n"
         "$ tcalc 2+2\n"
         "2+2 = 4\n"
         "$ tcalc\n"
         "> sin(pi/2)\n"
         "= 1\n");
}

void to_lower(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++)
        str[i] = tolower((unsigned char)str[i]);
}

int main(int argc, char *argv[]) {
    char input[256];
    double result;
    int error;
    int i;

    if (argc > 1) {
        if (!strcmp(argv[1], "help") || !strcmp(argv[1], "--help") ||
            !strcmp(argv[1], "h") || !strcmp(argv[1], "?")) {
            print_help();
            return 0;
        }

        for (i = 1; i < argc; i++) {
            to_lower(argv[i]);
            result = te_interp(argv[i], &error);
            if (argc > 2) printf("%s = ", argv[i]);
            if (error) puts("Error");
            else printf("%g\n", result);
        }
        return 0;
    }

    puts("TermiCalc v1.3 [DOS]\n"
         "Copyright (C) 2023, 2025 Dmitriy Eliseev\n"
         "Enter expression or 'q' to quit");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (!input[0] || input[0] == '\n') continue;
        to_lower(input);
        if (input[0] == 'q') break;
        if (input[0] == 'h' || input[0] == '?' || !strcmp(input, "help\n")) {
            print_help();
        } else {
            result = te_interp(input, &error);
            if (error) puts("Error");
            else printf("= %g\n", result);
        }
    }
    return 0;
}
