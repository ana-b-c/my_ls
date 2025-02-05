/*
** EPITECH PROJECT, 2024
** hidden_files.c
** File description:
** flag_a
*/
#include "my_ls.h"

int should_display_file(const ls_flags_t *flags, const char *filename)
{
    return (flags->show_hidden || filename[0] != '.');
}

void display_file(const char *path, const char *filename,
    const ls_flags_t *flags)
{
    if (flags->long_format) {
        display_long_format(path, filename);
    } else {
        my_putstr(filename);
        my_putchar('\n');
    }
}

void display_hidden_files(const char *path, ls_flags_t *flags)
{
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return;
    }
    entry = readdir(dir);
    while (entry) {
        if (should_display_file(flags, entry->d_name)) {
            display_file(path, entry->d_name, flags);
        }
        entry = readdir(dir);
    }
    closedir(dir);
}
