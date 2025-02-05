/*
** EPITECH PROJECT, 2024
** ls.h
** File description:
** ls
*/
#ifndef MY_LS_H
    #define MY_LS_H
    #define MAX_FILES 1024

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <errno.h>
    #include "my_lib.h"

typedef struct {
    const char *name;
    time_t mtime;
} file_info_t;

typedef struct {
    int show_hidden;
    int long_format;
    int recursive;
    int reverse;
    int sort_time;
    int path_start;
} ls_flags_t;

typedef void (*display_func_t)(const char *path, ls_flags_t *flags);

typedef struct {
    int flag_condition;
    display_func_t display_func;
} flag_action_t;

typedef struct {
    char option;
    void (*set_func)(ls_flags_t *);
} flag_map_t;

void parse_arguments(int argc, char *argv[], ls_flags_t *flags);
void list_directory(const char *path, ls_flags_t *flags);
void handle_error(const char *message);

void set_flag(char option, ls_flags_t *flags);
void (*find_flag_function(char option))(ls_flags_t *);

void display_long_format(const char *path, const char *filename);
void display_hidden_files(const char *path, ls_flags_t *flags);
void display_recursive(const char *path, ls_flags_t *flags);
void display_reverse(const char *path, ls_flags_t *flags);
void display_time_sort(const char *path, ls_flags_t *flags);

#endif /* MY_LS_H */
