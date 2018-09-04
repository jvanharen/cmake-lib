/**
 *   @file add.c
 *   @brief This source contains the adding function.
 *
 *   @author Julien Vanharen
 *   @date 04/09/2018
 */

#include "add/add.h"
#include "version.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * This method will be used for getting the version.
 * @author Julien Vanharen
 * @date 04/09/2018
 */
char *add_get_version() {
  char *version;
  version = (char *)malloc(6 * sizeof(char));
  sprintf(version, "%s.%s.%s", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
  return version;
}

/**
 * This method will be used for getting the git branch.
 * @author Julien Vanharen
 * @date 04/09/2018
 */
char *add_get_branch() { return GIT_BRANCH; }

/**
 * This method will be used for getting the git commit.
 * @author Julien Vanharen
 * @date 04/09/2018
 */
char *add_get_commit() { return GIT_COMMIT_HASH; }

/**
 * This method will be used for adding two integers.
 * Return \f$ a + b \f$.
 * @author Julien Vanharen
 * @param a The first integer
 * @param b The second integer
 * @date 04/09/2018
 */
int add_integer(int a, int b) { return a + b; }
