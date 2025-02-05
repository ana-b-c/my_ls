/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "my_ls.h"

void process_single_path(ls_flags_t *flags)
{
    list_directory(".", flags);
}

void process_multiple_paths(int argc, char *argv[], ls_flags_t *flags)
{
    for (int i = flags->path_start; i < argc; i++) {
        list_directory(argv[i], flags);
        if (i < argc - 1) {
            my_putchar('\n');
        }
    }
}

int main(int argc, char *argv[])
{
    ls_flags_t flags = {0};

    parse_arguments(argc, argv, &flags);
    if (flags.path_start == 0) {
        process_single_path(&flags);
    } else {
        process_multiple_paths(argc, argv, &flags);
    }
    return 0;
}
