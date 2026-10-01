#include "log.h"
#include "sway/commands.h"
#include "sway/config.h"
#include "util.h"

struct cmd_results *cmd_ultrawide_mode (int argc, char **argv) {
    struct cmd_results *error = checkarg(argc, "ultrawide_mode", EXPECTED_AT_LEAST, 1);

    bool result = parse_boolean(argv[0], false);

    config->ultrawide_mode = result;

    return cmd_results_new(CMD_SUCCESS, NULL);
}