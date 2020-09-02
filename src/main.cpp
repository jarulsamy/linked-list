#include "list.hpp"
#include "loader.hpp"

#include <iostream>
#include <deque>

#include <argp.h>

const char doc[] = "A simple example of a linked list";
const char args_doc[] = "PATH_TO_INPUT_TXT";

static struct argp_option options[] = {
    {"output", 'o', "FILE", 0, "Output to FILE instead of stdout"},
    {"reverse", 'r', 0, 0, "Reverse output"},
    {0},
};

typedef struct args
{
    char *args[1];
    std::string output_file;
    int reversed;
} arguments;

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    arguments *my_args = (arguments *)state->input;

    switch (key)
    {
    case 'o':
        my_args->output_file = arg;
        break;

    case 'r':
        my_args->reversed = 1;
        break;

    case ARGP_KEY_ARG:
        if (state->arg_num > 1)
            /* Too many args */
            /* Ignore unnecessary */
            argp_usage(state);
        my_args->args[state->arg_num] = arg;
        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1)
            /* Not enough args */
            /* Fail and quit */
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv)
{
    FILE *fp;

    arguments my_args;
    // Default arguments
    my_args.output_file = "";
    my_args.reversed = 0;

    argp_parse(&argp, argc, argv, 0, 0, &my_args);

    // Setup output
    if (my_args.output_file.empty())
        fp = stdout;
    else
        fp = fopen(my_args.output_file.c_str(), "w");

    // Load into linked list
    LinkedList<int> list = load(my_args.args[0]);
    std::deque<int> output;

    if (my_args.reversed)
    {
        list.dump_reverse(output);
    }
    else
    {
        list.dump(output);
    }

    for (int i : output)
    {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);

    return 0;
}
