#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Caesar cipher cli encoder/decoder.
 *
 * - Default shift is 3.
 *
 * ## Examples:
 *
 *        $ caesar encode "hello world" => "khoor zruog"
 *        $ caesar encode "hello world" -s 7 => "olssv dvysk"
 *
 *        $ caesar decode "khoor zruog" => "hello world"
 *        $ caesar decode "olssv dvysk" -s 7 => "hello world"
 */

/**
 * Print help message.
 */
int help(void)
{
  printf("\n"
         "To encode and decode a word in the Caesar cipher, "
         "you can follow the examples:\n"
         "\n"
         "  $ caesar encode \"hello world\"\n"
         "  $ caesar encode \"hello world\" 7\n"
         "  $ caesar decode \"khoor zruog\"\n"
         "  $ caesar decode \"olssv dvysk\" 7\n"
         "\n"
         "To set the shift, use a number <VALUE> after "
         "the phrase to be encoded/decoded.\n"
         "\n");

  return 0;
}

bool is_valid_option(char *option)
{
  return strcmp(option, "encode") == 0 || strcmp(option, "decode") == 0;
}
