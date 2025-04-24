#include <iostream>
#include <memory>

using namespace std;

/**
 * Singleton pattern
 * 1. Create class with 2 static vairables Instance* and mutex
 * 2. Dont forget to initialize them outside class
 * 3. Have getInstance to get the raw instance
 * 4. Use uniqueptr to hold reference of raw instance and user unique_ptr
 * inst.get() to access raw ptr
 * 5. Add guard in getinstance()
 * 6. do not allow copy construction - (const Instance &) in argument and
 * &operator= and Instace is function names
 * 7. Constructor should be in private
 */

class NetworkManager {
public:
  NetworkManager(const NetworkManager &) = delete;
  NetworkManager &operator=(const NetworkManager &) = delete;
  ~NetworkManager() { std::cout << "Instance destroyed" << endl; }
  static NetworkManager *getInstance() {
    std::lock_guard lock(s_mutex);
    if (!s_instance) {
      s_instance.reset(new NetworkManager());
    }
    return s_instance.get();
  }

  void printInstanceID() const {
    std::cout << "Instance ID (Memory Address): " << this << std::endl;
  }

private:
  NetworkManager() {
    std::cout << " Network manager constructed " << std::endl;
  }
  static std::unique_ptr<NetworkManager> s_instance;
  static std::mutex s_mutex;
};

std::unique_ptr<NetworkManager> NetworkManager::s_instance = nullptr;
std::mutex NetworkManager::s_mutex;

int main() {
  NetworkManager *inst1 = NetworkManager::getInstance();
  inst1->printInstanceID();

  NetworkManager *inst2 = NetworkManager::getInstance();
  inst2->printInstanceID();
}
