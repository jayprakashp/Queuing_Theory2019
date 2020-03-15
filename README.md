# Queuing_Theory2019
Implementing different queuing models in c


    				CONSOLE APPLICATION

HEADER FILES INCLUDED IN THE APPLICATION:

  	#include<bits/stdc++.h>


=====================================================================================================================================
USER DEFINED FUNCTION IMPLEMENTED IN THE APPLICATION:

FUNCTIONS USED IN MAIN FILE :

	double max_find(double ,double ) :----------------------------------------This utility function is used to find the maximum of two doubles.
	double poisson_distributed_random_variables(double) :---------------------This function is used to generate poisson distributed random varibles.
	double exponentially_distributed_random_variables(double) :---------------This function is used to generate exponentially distributed random varibles.
	void case_A(double ,double ,int ) :---------------------------------------This function is used to implement the case A of the problem.
	void case_B(double ,double ,int ) :---------------------------------------This function is used to implement the case B of the problem.
	void case_C(double ,double ,int ) :---------------------------------------This function is used to implement the case C of the problem.


----------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------

INPUT FORMAT OF THE APPLICATION:

	--> The application asks the user to choose among case A, B, C. The user can choose option E for EXIT.

	--> After choosing a case, it asks for arrival rate and service rate to generate the output for the case chosen. 

----------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------

OUTPUT FORMAT OF THE APPLICATION:

	--> For each case, it generates the following output;

		1.Average number of passengers getting inspected.

		2.Average response time for passengers in getting inspected.
		
		3.Average time for which a passenger has to wait until getting inspected.
		
		4.Average number of passengers waiting in queue before each officer (except the one getting inspected).

-----------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------

EXECUTION STEPS OF THE APPLICATION:
	 Step 1: Compile the project using g++ compiler.

	 Step 2: Run the project as;
	 		./a.out


	EXAMPLE :
	Compile : g++ problem2.cpp

	Run : 	  ./a.out


******************************************************************EOF******************************************************************************
