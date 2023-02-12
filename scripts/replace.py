# Script that replaces all occurences `replace_from` to `replace_to`

import getopt
import sys


DEFAULT_ENCODING = "utf-8"


def usage():
    return """Usage: comment_processor.py -i input_file -o output_file
       [-e encoding] -r replace_from -t replace_to"""


def main():
    argv = sys.argv[1:]

    try:
        opts, args = getopt.getopt(argv, "i:o:e:r:t:")
    except getopt.GetoptError as err:
        print(usage())
        raise RuntimeError("Error while parsing command line arguments: ", err)

    if args:
        raise RuntimeError(usage())

    input_file, output_file, replace_from, replace_to = "", "", "", ""
    encoding = DEFAULT_ENCODING

    for opt, arg in opts:
        if opt == "-i":
            input_file = arg
        elif opt == "-o":
            output_file = arg
        elif opt == "-e":
            encoding = arg
        elif opt == "-r":
            replace_from = arg
        elif opt == "-t":
            replace_to = arg
        else:
            raise RuntimeError("Unrecognized option: " + opt + '\n' + usage())

    if not (input_file and output_file and replace_to and replace_from):
        raise RuntimeError(usage())

    try:
        input = open(input_file, mode='r', encoding=encoding, errors="strict")
        output = open(output_file, mode='w', encoding=encoding, errors="strict")
    except OSError:
        raise RuntimeError("Unable to open file: ", OSError)

    in_line = input.readline()
    while in_line:
        in_line = in_line.replace(replace_from, replace_to)
        output.write(in_line)
        in_line = input.readline()

    input.close()
    output.close()


try:
    if __name__ == "__main__":
        main()
except Exception as err:
    print(err)
    sys.exit(1)
