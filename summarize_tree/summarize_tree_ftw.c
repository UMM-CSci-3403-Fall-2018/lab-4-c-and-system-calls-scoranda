#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>


static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    //https://github.com/skuhl/sys-prog-examples/blob/master/simple-examples/ftw.c
    // checks to see if object at fpath is a file or directory
    if (typeflag == FTW_F) {
      num_regular++;
      return 0;
    } else if (typeflag == FTW_D) {
      num_dirs++;
      return 0;
    }

    return 1;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {

    // check correct args (from summarize_tree.c)
    if (argc != 2) {
      printf ("Usage: %s <path>\n", argv[0]);
      printf ("       where <path> is the file or root of the tree you want to summarize.\n");
      return 1;
    }

    num_dirs = 0;
    num_regular = 0;

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results
    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_regular);

    return 0;


}
