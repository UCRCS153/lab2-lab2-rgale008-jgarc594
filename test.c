#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_CHILDREN 3

int child_workload(int iterations, int priority) {
  int i, j;
  for (i = 0; i < iterations; i++) {
    for (j = 0; j < 1000000; j++) {} // Simulate some workload
    setpriority(priority); // Change priority after each iteration
  }
  return 0;
}

int main(void) {
  int i;
  int iterations = 100000;

  printf(1, "Parent process PID: %d\n", getpid());

  for (i = 0; i < NUM_CHILDREN; i++) {
    int pid = fork();
    if (pid < 0) {
      printf(1, "fork failed\n");
      exit();
    } 
    else if (pid == 0) {
      // Child process
      int priority = 25 - i * 8; // Create child processes with priorities 25, 17, 9
      setpriority(priority);
      child_workload(iterations, priority);
      exit();
    }
  }

  for (i = 0; i < NUM_CHILDREN; i++) {
    wait();
  }

  exit();
}
