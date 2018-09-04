/**
 *   @file prg_add.c
 *   @brief This source contains the adding program.
 *
 *   @author Julien Vanharen
 *   @date 04/09/2018
 */

#include "add/add.h"
#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

const char *argp_program_version = "1.0";
const char *argp_program_bug_address = "<julien.vanharen@inria.fr>";
static char doc[] = "ADD -- Add program.";
static char args_doc[] = "";
static struct argp_option options[] = {
    {"integer_a", 'a', "a", 0, "First integer to add"},
    {"integer_b", 'b', "b", 0, "Second integer to add"},
    {0}};

struct arguments {
  int a;
  int b;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
  struct arguments *arguments = state->input;
  switch (key) {
  case 'a':
    arguments->a = atoi(arg);
    break;
  case 'b':
    arguments->b = atoi(arg);
    break;
  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv) {
  int res;
  struct arguments arguments;

  arguments.a = 0;
  arguments.b = 0;
  argp_parse(&argp, argc, argv, 0, 0, &arguments);
  res = add_integer(arguments.a, arguments.b);
  printf("%d\n", res);

  return 0;
}
