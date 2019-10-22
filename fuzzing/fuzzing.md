# Fuzzing notes

# Dependencies

**Docker CE**

Please install docker CE. The instructions can be found here: https://docs.docker.com/install/

#Run Fuzzers
There are two options, you install `afl` in your host or you use a docker container.

If you want to use the docker container. In the `fuzzing` directory:

- Use `make login` to get a bash session in a preinstalled container.
- Run `make build` to build an instrumented stub
- Run `make run` to start fuzzing

If you want to run multiple fuzzers:

- Get another session in the same container: `make login`
- run `make run_slaves` to start 4 more parallel fuzzers

You may want to configure docker to use more CPUs/cores
