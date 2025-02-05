/*
** EPITECH PROJECT, 2024
** long_format.c
** File description:
** long_format
*/
#include "my_ls.h"

void display_permissions(mode_t mode)
{
    my_putchar((S_ISDIR(mode)) ? 'd' : '-');
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    my_putchar((mode & S_IXOTH) ? 'x' : '-');
}

int get_file_stat(const char *path, const char *filename,
    struct stat *file_stat)
{
    char full_path[1024];

    my_strcpy(full_path, path);
    my_strcat(full_path, "/");
    my_strcat(full_path, filename);
    if (stat(full_path, file_stat) == -1) {
        perror("stat");
        return -1;
    }
    return 0;
}

void display_owner_and_group(uid_t uid, gid_t gid)
{
    struct passwd *pwd = getpwuid(uid);
    struct group *grp = getgrgid(gid);

    if (pwd)
        my_putstr(pwd->pw_name);
    my_putchar(' ');
    if (grp)
        my_putstr(grp->gr_name);
    my_putchar(' ');
}

static void display_size(off_t size)
{
    my_put_nbr(size);
    my_putchar(' ');
}

void display_modification_time(time_t mtime)
{
    char *mtime_str = ctime(&mtime);

    for (int i = 4; i < 16; i++)
        my_putchar(mtime_str[i]);
    my_putchar(' ');
}

void display_long_format(const char *path, const char *filename)
{
    struct stat file_stat;

    if (get_file_stat(path, filename, &file_stat) == -1)
        return;
    display_permissions(file_stat.st_mode);
    my_putchar(' ');
    my_put_nbr(file_stat.st_nlink);
    my_putchar(' ');
    display_owner_and_group(file_stat.st_uid, file_stat.st_gid);
    display_size(file_stat.st_size);
    display_modification_time(file_stat.st_mtime);
    my_putstr(filename);
    my_putchar('\n');
}
