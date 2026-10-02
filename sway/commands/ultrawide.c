#include "log.h"
#include "sway/commands.h"
#include "sway/config.h"
#include "util.h"

struct cmd_results *cmd_ultrawide_split_percent (int argc, char **argv) {
    struct cmd_results *error = checkarg(argc, "ultrawide_split_percent", EXPECTED_AT_LEAST, 1);
	
    if (error) {
		return error;
	}

    float result = parse_float(argv[0]);

    if (result > 0) {
        config->ultrawide_split_percent = result;
    } else {
        config->ultrawide_split_percent = 1.0;
    }

    return cmd_results_new(CMD_SUCCESS, NULL);
}

struct cmd_results *cmd_ultrawide_mode (int argc, char **argv) {
    struct cmd_results *error = checkarg(argc, "ultrawide_mode", EXPECTED_AT_LEAST, 1);
	
    if (error) {
		return error;
	}
    
    bool result = parse_boolean(argv[0], false);

    config->ultrawide_mode = result;

    return cmd_results_new(CMD_SUCCESS, NULL);
}