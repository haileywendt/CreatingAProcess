/* Homework 1: Creating a Process - ECCS 3661 Spring 2024 
 * Author: Hailey Wendt
 * File: newsourcecode.cpp
 * Last Updated: 3/6/2024
 * This program demonstrates parent/child process creation using fork(), 
 * reports the PID of both the parent process and the child process, 
 * implements sleep() 10 times for 1 second using a for loop, and then
 * the parent process waits for the child process to finish before 
 * exiting.
 */

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void report_and_exit(const char* msg) {
    perror(msg);
    exit(-1); // EXIT_FAILURE
}

int main() {
    pid_t pid = fork();
    if (pid < 0)
        report_and_exit("Error creating a new child process");
    
    if (pid == 0) { // child code
        cout << "I am the child process. My pid = " << getpid() << endl;
        for (int i = 1; i <= 10; ++i) {
            sleep(1);
            cout << "Loop #" << i << endl;
        }
    } 
    else { // parent code
        cout << "I am the parent process. My pid = " << getpid() << endl;
        // Make the parent wait for the child to finish
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            report_and_exit("Error waiting for child process");
        }

	cout << "Child process rejoined parent. Exiting" << endl;
    }
    return 0;
}
