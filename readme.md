To run the simulator, you can simply run **run.sh** and it will build and run the simulator
for you. By default, it is set to use **test.hex** as the input. Once your simulator has
already been compiled, the core binary file that’s built can also be used to run the
simulator. It takes in the machine code dump as the only argument.
When running the program, you’ll be faced with a prompt that says Request:. Here
you have couple of options:
1. **s** - to process a single instruction.
2. **m** - to process multiple instructions (you’ll be asked to input how many instructions should run).
3. **b** - to run the simulator until hitting a breakpoint (this will be given as the memory
address of the instruction). This may be useful when debugging.
4. **v** - to view a memory address.
5. **q** - to quit the simulator.
