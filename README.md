# Caesar CLI program.

Encode and decode sentences in the Caesar cipher with this CLI.

## Install (Linux)

### Clone the repository:
`user@pc:~/Downloads$ git pull https://github.com/pedrohaveloso/caesar-cli.git`

`user@pc:~/Downloads$ cd ./caesar-cli`

### Compile:
`user@pc:~/Downloads/caesar-cli$ gcc -o caesar ./caesar.c`

### Move:
`user@pc:~/Downloads/caesar-cli$ sudo mv ./caesar /usr/bin`


## Using

Default shift is 3. Examples:

    $ caesar encode "hello world" => "khoor zruog"
    $ caesar encode "hello world" 7 => "olssv dvysk"

    $ caesar decode "khoor zruog" => "hello world"
    $ caesar decode "olssv dvysk" 7 => "hello world"