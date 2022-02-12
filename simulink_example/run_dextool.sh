rm -rf /workspaces/c_google_test/simulink_example/dextool_mutate.sqlite3
dextool mutate analyze --mutant all
dextool mutate test
dextool mutate report