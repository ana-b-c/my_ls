# my_ls

# The project:
You must recode the ls [-alRdrt] [FILE] command.
  -Options can be given in either order.
  -It must be possible to pass a list of files/folders as parameters.

# Authorized Functions
The only system calls allowed are the following ones:
  ✓ opendir, readdir, closedir, stat, lstat, write,
  ✓ getpwuid, getgrgid, time, ctime, readlink,
  ✓ va_start, va_arg, va_end,
  ✓ malloc, free, perror, strerror, exit
