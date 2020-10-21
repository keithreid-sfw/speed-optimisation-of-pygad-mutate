Speed Optimisation of Pygad Mutate

A grateful developer giving something back to the excellent pygad project.
A head to head comparison of four mutate methods for an ndarray and back again. 

 - base library
 - keith_mutate my bespoke C implementation in a ctypes callable shared library, batteries included, see the C module is here and a precompiled .so too
 - pygad's existing mutate function
 - aggressive vectorisation of the pygad function (my own previous approach in my own dev project)
 
 The four approaches do not separate at my use case, but increasing the computational demand shows small differences which could be important in large projects.
 Results are in the code.
 
 Guess what.  The base functions are pretty fast.
