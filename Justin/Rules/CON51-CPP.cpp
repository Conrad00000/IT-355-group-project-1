#include <mutex>

int main()
{
    std::mutex myMutex;
    /*lock guard ensures mutex wil be unlocked*/
    std::lock_guard<std::mutex> mutexGuard(myMutex);
    return 0;
}