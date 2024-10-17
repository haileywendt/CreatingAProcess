/* Exercise 1, Operating Systems. 
 * Author: Ziad Youssfi
 * 1 -- Correctly report the PID for the parent and child processes.
 * 2 -- Implement a loop in the child code to call the sleep 
 *      function 10 times, for 1 seconds each, i.e. a total of 
 *      10 seconds of sleep. Print each loop iteration number.
 * 3 -- Make the parent process wait for the child before exiting.
 *      Hint: use the wait system function call. 
 *      
 */
#include <iostream> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void report_and_exit (const char* msg) { 
	perror(msg);
	exit(-1); /* EXIT_FAILURE */
}

int main() {
	pid_t pid = fork ();
	if (pid < 0)
		report_and_exit ("Error creating a new child process");
		
	if (pid == 0) {	// child code
		cout << "I am the child process. My pid = " << pid << endl; 
	} else {	// parent code
		cout << "I am the parent process. My pid = " << pid << endl;
	}
	return 0;
}