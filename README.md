# Philosophers
This project is a simulation of dining philosophers. In the simulation, there are a number of philosophers sitting at a round table. There is a bowl of spaghetti in the middle of the table, and each philosopher needs two forks to eat. The philosophers can only eat when they have both forks. However, there are only as many forks as there are philosophers, so there is always the possibility that a philosopher will not be able to get both forks and will starve.
The goal of the simulation is to find a way to ensure that all of the philosophers can eat without starving. There are a number of different ways to do this, and the challenge is to find the most efficient and elegant solution.
## How to run the project
To run the project, you will need to have a C compiler installed. Once you have a compiler, you can compile the project by running the following command:
```bash
make
```
This will create an executable file called `philo`. To run the simulation, simply type the following command:
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] (optional)[number_of_times_each_philosopher_must_eat]
```
The number_of_philosophers argument specifies the number of philosophers in the simulation. The time_to_die argument specifies the number of milliseconds that a philosopher can go without eating before they starve. The time_to_eat argument specifies the number of milliseconds that a philosopher spends eating. The time_to_sleep argument specifies the number of milliseconds that a philosopher spends sleeping.
## Usage
The simulation will run until all of the philosophers have eaten enough to satisfy their hunger. You can stop the simulation by pressing Ctrl+C.
The simulation will print out a log of the events that occur. This log will include the following information:
* The time at which an event occurred
* The id of the philosopher who is involved in the event
* The type of event that occurred
## Example output
Here is an example of the output that the simulation might produce:
```bash
echo
```
## Challenges
There are a number of challenges that you will need to overcome in order to successfully complete this project. These challenges include:
* Deadlock: It is possible for the philosophers to deadlock. This can happen if two philosophers try to grab the same fork at the same time.
* Starvation: It is possible for a philosopher to starve. This can happen if the philosopher is unable to get both forks.
* Efficiency: You will need to find a way to ensure that the simulation is efficient. This means that the simulation should use as little resources as possible.
* Elegance: You will need to find a way to solve the problem in an elegant way. This means that the solution should be simple and easy to understand.
## Conclusion
This project is a challenging but rewarding project. It is a great opportunity to learn about threading and synchronization. I hope you enjoy it!
