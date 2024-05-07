#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

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

int encode(char *w, int shift)
{
  for (size_t i = 0; w[i]; i++)
  {
    int letter_i = strchr(ALPHABET, tolower(w[i])) - ALPHABET;

    if (letter_i < 0 || letter_i > 25 || &letter_i == NULL)
    {
      continue;
    }

    letter_i = letter_i + shift;

    if (letter_i > 25)
    {
      letter_i = letter_i - 26;
    }

    w[i] = ALPHABET[letter_i];
  }

  printf("%s\n", w);

  return 0;
}

int decode(char *w, int shift)
{
  return 0;
}

bool is_valid_option(char *o)
{
  return strcmp(o, "encode") == 0 || strcmp(o, "decode") == 0;
}

int main(int argc, char **argv)
{
  if (argc <= 1 || !is_valid_option(argv[1]) || argv[2] == NULL)
  {
    return help();
  }

  int shift = 3;

  if (argv[3] != NULL)
  {
    sscanf(argv[3], "%d", &shift);
  }

  if (strcmp(argv[1], "encode") == 0)
  {
    return encode(argv[2], shift);
  }

  if (strcmp(argv[1], "decode") == 0)
  {
    return decode(argv[2], shift);
  }
}