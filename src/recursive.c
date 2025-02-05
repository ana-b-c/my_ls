/*
** EPITECH PROJECT, 2024
** recursive.c
** File description:
** -R
*/
#include "my_ls.h"

void display_entry(const char *path, const struct dirent *entry,
    ls_flags_t *flags)
{
    if (flags->show_hidden || entry->d_name[0] != '.') {
        if (flags->long_format) {
            display_long_format(path, entry->d_name);
        } else {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
    }
}

int is_valid_directory(const struct dirent *entry)
{
    return entry->d_type == DT_DIR &&
        my_strcmp(entry->d_name, ".") != 0 &&
        my_strcmp(entry->d_name, "..") != 0;
}

void process_directory_entries(const char *path, ls_flags_t *flags, DIR *dir)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry) {
        display_entry(path, entry, flags);
        entry = readdir(dir);
    }
}

void process_subdirectories(const char *path, ls_flags_t *flags, DIR *dir)
{
    struct dirent *entry;
    char next_path[1024];

    entry = readdir(dir);
    while (entry) {
        if (is_valid_directory(entry)) {
            my_strcpy(next_path, path);
            my_strcat(next_path, "/");
            my_strcat(next_path, entry->d_name);
            display_recursive(next_path, flags);
        }
        entry = readdir(dir);
    }
}

void display_recursive(const char *path, ls_flags_t *flags)
{
    DIR *dir = opendir(path);

    if (!dir) {
        perror("opendir");
        return;
    }
    my_putstr(path);
    my_putstr(":\n");
    process_directory_entries(path, flags, dir);
    closedir(dir);
    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }
    process_subdirectories(path, flags, dir);
    closedir(dir);
}
