#include "log.h"
#include "sway/commands.h"
#include "sway/config.h"
#include "util.h"

struct cmd_results *cmd_ultrawide_split_fraction (int argc, char **argv) {
    struct cmd_results *error = checkarg(argc, "ultrawide_split_fraction", EXPECTED_EQUAL_TO, 1);

    if (error) {
		return error;
	}

    float result = parse_float(argv[0]);

    // pr note #2
    if(result > 0 && result < 1) {
        config->ultrawide_split_fraction = result;
    } else {
        cmd_results_new(CMD_INVALID, "ultrawide_split_fraction value must be between 0 and 1");
    }

    arrange_root();
    
    return cmd_results_new(CMD_SUCCESS, NULL);
}

struct cmd_results *cmd_ultrawide_mode (int argc, char **argv) {
    struct cmd_results *error = checkarg(argc, "ultrawide_mode", EXPECTED_EQUAL_TO, 1);
	
    if (error) {
		return error;
	}
    
    bool result = parse_boolean(argv[0], false);

    config->ultrawide_mode = result;

    arrange_root();

    return cmd_results_new(CMD_SUCCESS, NULL);
}
