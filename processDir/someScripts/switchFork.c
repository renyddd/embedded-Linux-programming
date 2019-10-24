// P427
pid_t childPid;

switch (childPid = fork()) {
    case -1:
        /* Handle error */

    case 0:
        /* Perform actions specific to child */

    default:
        /* Perform actions specific to parent */

}
