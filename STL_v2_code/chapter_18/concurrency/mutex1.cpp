#include <chrono>
#include <future>
#include <mutex>
#include <thread>
#include <iostream>
#include <string>

#define USE_MUTEX true 

std::mutex printMutex;

void print(const std::string& s){
#ifdef USE_MUTEX 
  std::lock_guard<std::mutex> l(printMutex);
#endif
  for (const char& c: s){
    std::cout.put(c);
  }
  std::cout << '\n';
}

int main() {
  auto f1 = std::async(std::launch::async, print, "Hello from the first thread!;");
  auto f2 = std::async(std::launch::async, print, "Hello from the second thread!;");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  print("hello from the main thread!");
}
