/*
** EPITECH PROJECT, 2024
** flags.c
** File description:
** flags
*/
#include "my_ls.h"

static void set_show_hidden(ls_flags_t *flags)
{
    flags->show_hidden = 1;
}

static void set_long_format(ls_flags_t *flags)
{
    flags->long_format = 1;
}

static void set_recursive(ls_flags_t *flags)
{
    flags->recursive = 1;
}

static void set_reverse(ls_flags_t *flags)
{
    flags->reverse = 1;
}

static void set_sort_time(ls_flags_t *flags)
{
    flags->sort_time = 1;
}

void (*find_flag_function(char option))(ls_flags_t *)
{
    static flag_map_t flag_map[] = {
        { 'a', set_show_hidden },
        { 'l', set_long_format },
        { 'R', set_recursive },
        { 'r', set_reverse },
        { 't', set_sort_time },
    };

    for (size_t i = 0; i < sizeof(flag_map) / sizeof(flag_map[0]); i++) {
        if (flag_map[i].option == option) {
            return flag_map[i].set_func;
        }
    }
    return NULL;
}

void set_flag(char option, ls_flags_t *flags)
{
    void (*set_func)(ls_flags_t *) = find_flag_function(option);

    if (set_func) {
        set_func(flags);
    } else {
        my_putstr("Invalid option: -");
        my_putchar(option);
        my_putchar('\n');
        exit(84);
    }
}

void parse_option_string(const char *option_str, ls_flags_t *flags)
{
    for (int j = 1; option_str[j] != '\0'; j++) {
        set_flag(option_str[j], flags);
    }
}

void parse_arguments(int argc, char *argv[], ls_flags_t *flags)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            parse_option_string(argv[i], flags);
        } else {
            flags->path_start = i;
            break;
        }
    }
}
