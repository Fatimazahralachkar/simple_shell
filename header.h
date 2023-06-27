#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

	/*string manipulation functions */

char *custom_strcpy(char *dest, const char *src);
int custom_strcmp(const char *s1, const char *s2);
char *custom_strdup(const char *str);
char *custom_strcat(char *dest, const char *src);
char *custom_strdup_ebb(char *str, int exclude_bytes);
char *c_ignore(char *str);
int custom_numlen(int n);
char *custom_int_to_string(int num);
int custom_atoi(char *str);
char *custom_ignore_first_c_strcat(char *dest, const char *src);
int my_setenv(list_t **env, const char *name, const char *dir);
char *custom_ignore_first_c_strcat(char *dest, const char *src);

	/* linked lists functions */

list_t *add_node_at_end(list_t **head, char *str);
size_t print_linked_list(list_t *head);
int delete_node_at_index(list_t **head, int index);
void free_linked_list(list_t *list);
list_t *env_linked_list(char **env);




	/* env */

int print_env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
int find_env(list_t *env, const char *str);
int custom_setenv(list_t **env, char **str);
int custom_unsetenv(list_t **env, char **str);
int custom_atoi(char *str);

    /* shell prompt function */

int shell_prompt(char **en);

    /*memory managing functions*/

void deallocate_strings(char **str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


    /* reading command */

size_t read_command(char **buffer);
void handle_piped_cmd(list_t *env);

    /* exiting*/

int exit_program(char **exit_cmd, list_t *env, int cmd_num, char **cmd);

    /* cd functions */

void cd_home(list_t *env_list, char *current_dir);
int cd_execute(list_t *env_list, char *dir, char *dirpath, char *a, int nline);
int cd_cmd(char **str, list_t *env, int num);


    /* user cmd*/

void free_cmd(char **str, list_t *env);
int exec_cmd(char **s, list_t *env, int num);
char *cmd_path(char *str, list_t *env);

    /* handling built in*/

void ignore_ctrl_C(int n);
void exit_if_ctrl_D(int i, char *command, list_t *env);
char *ignore_space(char *str);
int handling_built_in(char **token, list_t *env, int num, char **command);

    /* delimiters*/

int get_token_length(char *str, int pos, char delim);
int count_delimiters(char *str, char delim);
char *ignore_delm(char *str, char delm);
char **str_tokenize(char *str, char *delim);
int count_tokens(char *str, char delim);
char **custom_str_tokenize(char *str, char *delim);

    /*errors*/

void print_not_found_error(char *command, int command_number, list_t *env);
void print_cd_error(char *directory, int command_number, list_t *env);
void print_illegal_number_error(char *number, int command_number, list_t *env);



#endif


