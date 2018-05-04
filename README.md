# Philosophers
Rice-eating philosophers

N philosophers are around one table (N is defined on the command line).
Each philosopher has one rice bowl in front of him.  

There is a chopstick to the left of each bowl.
A philosopher can only use a chopstick if it is to the left or right of his bowls.  

A philosopher goes through three steps:  
	• eat : with two chopsticks. One left and one right.
	• rest : does not use either chopstick, even if one is available.
	• think : uses one and only one chopstick.  

There are a few more rules to guarantee better digestion.
It is really important for them to be healthy and to assimilate the rice’s nutrients
but you have to keep it a secret !  

	• A philosopher who thinks must eat before resting.
	• After resting, a philosopher can either eat or think.
	• The think and eat states must have a time limit.
	• A chopstick cannot be used by two philosophers at the same time.

./philo -p nbr_p -e nbr_e
--------------------------


| Parameters    | Description                                                        |
| ------------: | -------------------------------------------------------------------|
| **-p nbr_p**  | number of philosophers                                             |
| **-e nbr_e**  | maximum number times a philosopher eats before exiting the program |


libriceferee.so
---------------

Add the path location to the library in your LD_LIBRARY_PATH environment variable.