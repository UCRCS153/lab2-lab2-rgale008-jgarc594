#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  // Print the original priority
  printf(1, "Original priority: %d\n", getpriority());

  // Change priority to a new value (e.g., 10)
  changepriority(10);
  printf(1, "Priority changed to: %d\n", getpriority());

  // Change priority to another value (e.g., 15)
  changepriority(15);
  printf(1, "Priority changed to: %d\n", getpriority());

  // Change priority to an invalid value
  changepriority(30); // Should return -1 (error)
  printf(1, "Priority changed to: %d\n", getpriority());

  exit();
}
