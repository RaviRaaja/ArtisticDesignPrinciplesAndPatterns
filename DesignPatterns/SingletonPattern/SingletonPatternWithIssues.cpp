#include <iostream>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

/**
 * Singleton pattern without mutex protection
 * This will cause issues when accessed by multiple threads.
 */

class NetworkManager {
public:
  NetworkManager(const NetworkManager &) = delete; // Prevent copying
  NetworkManager &
  operator=(const NetworkManager &) = delete; // Prevent assignment
  ~NetworkManager() { std::cout << "Instance destroyed" << std::endl; }

  static NetworkManager *getInstance() {
    if (!s_instance) {
      s_instance.reset(new NetworkManager());
    }
    return s_instance.get();
  }

  void printInstanceID() const {
    std::cout << "Instance ID (Memory Address): " << this << std::endl;
  }

private:
  NetworkManager() { std::cout << "Network manager constructed" << std::endl; }

  static std::unique_ptr<NetworkManager> s_instance;
};

std::unique_ptr<NetworkManager> NetworkManager::s_instance = nullptr;

void threadFunction(int id) {
  NetworkManager *inst = NetworkManager::getInstance();
  std::cout << "Thread " << id << " - ";
  inst->printInstanceID();
}

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.push_back(std::thread(threadFunction, i));
  }

  for (auto &t : threads) {
    t.join();
  }

  return 0;
}
