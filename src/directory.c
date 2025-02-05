/*
** EPITECH PROJECT, 2024
** directory
** File description:
** directory
*/
#include "my_ls.h"

void execute_directory_action(const char *path, ls_flags_t *flags,
    flag_action_t *actions, int action_count)
{
    for (int i = 0; i < action_count; i++) {
        if (actions[i].flag_condition) {
            actions[i].display_func(path, flags);
            return;
        }
    }
    display_hidden_files(path, flags);
}

void list_directory(const char *path, ls_flags_t *flags)
{
    DIR *dir;
    flag_action_t actions[] = {
        { flags->sort_time, display_time_sort },
        { flags->reverse, display_reverse },
        { flags->recursive, display_recursive },
        { flags->show_hidden, display_hidden_files },
        { flags->long_format, display_hidden_files }
    };
    int action_count = sizeof(actions) / sizeof(actions[0]);

    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }
    execute_directory_action(path, flags, actions, action_count);
    closedir(dir);
}
