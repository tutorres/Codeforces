#include <iostream>
#include <queue>

int main() {
  long long input;
  std::cin >> input;

  
  std::queue<long long> queue;
  queue.push(1);

  int countNumbersWith0and1 = 0;

  
  while (!queue.empty()) {
    long long current = queue.front();
    queue.pop();

    if (current > input) {
      continue;
    }

    countNumbersWith0and1++;

    // Generate the next numbers by appending 0 and 1
    queue.push(current * 10);
    queue.push(current * 10 + 1);
  }

  std::cout << countNumbersWith0and1 << std::endl;

  return 0;
}
