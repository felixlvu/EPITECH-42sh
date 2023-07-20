/*
** EPITECH PROJECT, 2022
** my.r
** File description:
** my.r
*/

#ifndef MYM_H
    #define MYM_H

typedef struct {
    int num_args;
    char **args;
} Pipe;

typedef struct {
    char **new_env;
    char **args;
    char *home;
    char *pwd;
    char *hold;
    char *oldpwd;
    char *path;
    int retur;
    int num_cmd;
    int index;
    int num_pipes;
    int find_env;
    int len_env;
    int find_pwd;
    int find_oldpwd;
    int exit;
    Pipe *pipes;
} Mysh;

    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <string.h>

    int main(int arc, char *arv[], char **env);
    int check_child_command(char *command, char **args, char *path, Mysh *mysh);
    char* my_strnncat(char* dest, const char* src, size_t n, size_t m);
    char* my_strnncat(char* dest, const char* src, size_t n, size_t m);
    int search_other(Mysh *mysh, char **args, char *arg_dup);
    int all_builtins(char **args, Mysh *mysh);
    char **copy_array_remove(char **array, int remove_line);
    int check_type_child_next(char *command, char **args,
    char *path, Mysh *mysh);
    char **str_to_word_array(char *str, char separator);
    char **copy_array_add(char **array, int add_line);
    char* find_command_path(Mysh *mysh, char **args);
    char **event_unsetenv(Mysh *mysh, char **args);
    int search_env_var(Mysh *mysh, char *command);
    int exe_separator(Mysh *mysh, char *command);
    int exe_logic_and(Mysh *mysh, char *command);
    int exe_logic_or(Mysh *mysh, char *command);
    int find_command(char *command, Mysh *mysh);
    void create_new_env(char **env, Mysh *mysh);
    void find_elements(char **env, Mysh *mysh);
    void event_setenv(Mysh *mysh, char **args);
    int exe_redirec(Mysh *mysh, char *command);
    int fill_args(Mysh *mysh, char *command);
    void change_oldpwd(Mysh *mysh, char *cwd);
    void execute_cd(Mysh *mysh, char **args);
    void event_echo(Mysh *mysh, char **args);
    int exe_pipe(Mysh *mysh, char *command);
    int main_loop(char **env, Mysh *mysh);
    int execute_command(char *command);
    int search_separator(char **args);
    int search_logic_and(char **args);
    int search_logic_or(char **args);
    int search_redirec(char **args);
    char **copy_array(char **array);
    char* strdup(const char* str);
    int search_pipe(char **args);
    void change_pwd(Mysh *mysh);
    void print_env(Mysh *mysh);
    void init_path(Mysh *mysh);
    void trim(char *str);
    int exe_redirec_left(Mysh *mysh, char *command);
    int backslash_simple(char *line, Mysh *mysh);
    char *str_clean(char *str);
    char **str_to_array(char const *str, char delim);
    int check_alias_exists(void);
    void alias(char *args[]);
    void unalias(char *args[]);
    int break_searching(char *buffer, char *args[], int i);
    void search_line_editing(char *args[], int fd);
    void unalias_editing_rc(int i, int fd, char *buffer);
    int search_redirec_left(char **args);
    void simple_alias(void);
    char *fill_output_str(char *output, const char *input);
    void exe_alias(char **args);
    char *strcleantok(char *str);

#endif
