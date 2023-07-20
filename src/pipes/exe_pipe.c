/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

int exe_pipe_familly(Mysh *mysh, char *command, int i, int fd[2])
{
    char *path;
    int ret = 0;

    if (i < mysh->num_cmd - 2) {
        dup2(fd[1], STDOUT_FILENO);
    }
    ret = search_other(mysh, mysh->pipes[i].args, command);
    if (ret == 1) {
        exit(1);
    }
    if (ret == 2)
        exit(0);
    if (all_builtins(mysh->pipes[i].args, mysh) != 2) {
        path = find_command_path(mysh, mysh->pipes[i].args);
        ret = check_child_command(command, mysh->pipes[i].args, path, mysh);
    }
    mysh->retur = ret;
    exit(ret);
}

pid_t exe_pipe_fork(pid_t pid)
{
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return pid;
}

void exe_pipe_wait(int fd_in, pid_t pid, int fd[2], int *ret)
{
    if (fd_in != STDIN_FILENO) {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            *ret = WEXITSTATUS(status);
        }
    }
    close(fd[1]);
}

int exe_pipe_cmd(Mysh *mysh, char *command)
{
    int fd[2];
    int fd_in = STDIN_FILENO;
    pid_t pid;
    int ret = 0;
    for (int i = 0; i < mysh->num_cmd - 1; i++) {
        pipe(fd);
        pid = exe_pipe_fork(pid);
        if (pid == 0) {
            dup2(fd_in, STDIN_FILENO);
            close(fd[0]);
            exe_pipe_familly(mysh, command, i, fd);
        } else {
            exe_pipe_wait(fd_in, pid, fd, &ret);
            fd_in = fd[0];
        }
    }
    dup2(dup(STDOUT_FILENO), STDOUT_FILENO);
    dup2(dup(STDIN_FILENO), STDIN_FILENO);
    mysh->retur = ret;
    return ret;
}

int exe_pipe(Mysh *mysh, char *command)
{
    if (fill_args(mysh, command) == 1)
        return 1;
    exe_pipe_cmd(mysh, command);
    return 0;
}
