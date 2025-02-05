/*
** EPITECH PROJECT, 2024
** reverse.c
** File description:
** -r
*/
#include "my_ls.h"

void reverse_array(file_info_t *files, int count)
{
    int start = 0;
    int end = count - 1;
    file_info_t temp;

    while (start < end) {
        temp = files[start];
        files[start] = files[end];
        files[end] = temp;
        start++;
        end--;
    }
}

static int collect_files(const char *path, DIR *dir,
    file_info_t *files, ls_flags_t *flags)
{
    struct dirent *entry;
    int count = 0;

    entry = readdir(dir);
    while (entry != NULL && count < MAX_FILES) {
        if (flags->show_hidden || entry->d_name[0] != '.') {
            files[count].name = entry->d_name;
            count++;
        }
        entry = readdir(dir);
    }
    return count;
}

void display_reverse(const char *path, ls_flags_t *flags)
{
    DIR *dir = opendir(path);
    file_info_t files[MAX_FILES];
    int count;

    if (!dir) {
        perror("opendir");
        return;
    }
    count = collect_files(path, dir, files, flags);
    reverse_array(files, count);
    for (int i = 0; i < count; i++) {
        display_file(path, files[i].name, flags);
    }
    closedir(dir);
}
