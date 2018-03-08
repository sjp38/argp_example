#include <stdio.h>
#include <argp.h>

const char *argp_program_version = "the_version";
const char *argp_program_bug_address = "the bug address";

error_t parse_option(int key, char *arg, struct argp_state *state)
{
	printf("%s called with key ", __func__);
	switch (key) {
	case ARGP_KEY_ARG:
		printf("ARG");
		break;
	case ARGP_KEY_ARGS:
		printf("ARGS");
		break;
	case ARGP_KEY_END:
		printf("END");
		break;
	case ARGP_KEY_NO_ARGS:
		printf("NO_ARGS");
		break;
	case ARGP_KEY_INIT:
		printf("INIT");
		break;
	case ARGP_KEY_SUCCESS:
		printf("SUCCESS");
		break;
	case ARGP_KEY_ERROR:
		printf("ERROR");
		break;
	case ARGP_KEY_FINI:
		printf("FINI");
		break;

	default:
		printf("%c(%d)", key, key);
		return ARGP_ERR_UNKNOWN;
	}
	printf(", arg %s, state->next: %d, state->arg_num: %d\n",
			arg, state->next, state->arg_num);
	return 0;
}

static  struct argp_option options[] = {
	{
		.name = "foo",
		.key = 'f',
		.arg = "foo_arg",
		.flags = 0,
		.doc = "just foo option",
		.group = 0,
	},
	{
		.name = "optionalarg",
		.key = 'o',
		.arg = "optional",
		.flags = OPTION_ARG_OPTIONAL,
		.doc = "option with optional argument",
		.group = 0,
	},
	{
		.name = "justflag",
		.key = 'j',
		.arg = 0,
		.flags = 0,
		.doc = "option without argument",
		.group = 0,
	},
	{}
};

struct opts {
	int abc;
	int def;
};

int main(int argc, char *argv[])
{
	struct opts opts;
	struct argp argp = {
		.options = options,
		.parser = parse_option,
		.args_doc = "<arg1> <arg2> ...",
		.doc = "example for argp usage\v"
			"This is a program to be used as an example for argp.",
	};
	argp_parse(&argp, argc, argv, ARGP_IN_ORDER, NULL, &opts);
	printf("hello world\n");
	return 0;
}
