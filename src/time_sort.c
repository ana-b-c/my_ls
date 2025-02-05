/*
** EPITECH PROJECT, 2024
** time
** File description:
** -t
*/
#include "my_ls.h"

static int get_file_mtime(const char *path, const char *filename,
    time_t *mtime)
{
    struct stat file_stat;
    char full_path[1024];

    my_strcpy(full_path, path);
    my_strcat(full_path, "/");
    my_strcat(full_path, filename);
    if (stat(full_path, &file_stat) == -1) {
        perror("stat");
        return -1;
    }
    *mtime = file_stat.st_mtime;
    return 0;
}

static int should_include_file(const struct dirent *entry, ls_flags_t *flags)
{
    return (flags->show_hidden || entry->d_name[0] != '.');
}

static int add_file_info(const char *path, const struct dirent *entry,
    file_info_t *file)
{
    file->name = entry->d_name;
    return get_file_mtime(path, entry->d_name, &file->mtime);
}

static int collect_files(const char *path, DIR *dir,
    file_info_t *files, ls_flags_t *flags)
{
    struct dirent *entry;
    int count = 0;

    entry = readdir(dir);
    while (entry != NULL) {
        if (!should_include_file(entry, flags)) {
            entry = readdir(dir);
            continue;
        }
        if (add_file_info(path, entry, &files[count]) == 0) {
            count++;
        }
        entry = readdir(dir);
    }
    return count;
}

void bubble_sort(file_info_t *files, int count)
{
    int swapped = 1;
    file_info_t temp;

    for (int i = 0; i < count - 1 && swapped; i++) {
        swapped = 0;
        for (int j = 0; j < count - i - 1; j++) {
            temp = files[j];
            files[j] = files[j + 1];
            files[j + 1] = temp;
            swapped = 1;
        }
    }
}

void display_time_sort(const char *path, ls_flags_t *flags)
{
    DIR *dir = opendir(path);
    file_info_t files[1024];
    int count;

    if (!dir) {
        perror("opendir");
        return;
    }
    count = collect_files(path, dir, files, flags);
    closedir(dir);
    bubble_sort(files, count);
    for (int i = 0; i < count; i++) {
        display_file(path, files[i].name, flags);
    }
}
