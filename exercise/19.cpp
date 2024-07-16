// concurrent programming

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

// void f(){
//     std::cout << "hooya from thread";
// }

// int main(){

// std::thread th(f);
// th.join();
// std::cout<<std::thread::hardware_concurrency();
// }

// mutex example

// void f(int &value, std::mutex &m)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         m.lock();
//         value++;
//         // other threads must wait
//         m.unlock();
//         std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     }
// }
// int main()
// {
//     std::mutex m;
//     int value = 0;
//     std::vector<std::thread> th_vect;
//     for (int i = 0; i < 100; i++)
//         th_vect.push_back(std::thread(f, std::ref(value), std::ref(m)));
//     for (auto &it : th_vect)
//         it.join();
//     std::cout << value;
// }

// atomic example -> lock free sync operations
// faster than mutex lock

// void f(std::atomic<int> &value)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         value++;
//         std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     }
// }
// int main()
// {
//     std::atomic<int> value(0);
//     std::vector<std::thread> th_vect;
//     for (int i = 0; i < 100; i++)
//         th_vect.push_back(std::thread(f, std::ref(value)));
//     for (auto &it : th_vect)
//         it.join();
//     std::cout << value;
//     // print 1000
// }

// task based parallelism

#include <future>
#include <numeric>

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
    auto len = end - beg;
    if (len < 1000)
        // base case
        return std::accumulate(beg, end, 0);
    RandomIt mid = beg + len / 2;
    auto handle = std::async(std::launch::async, // right side
                             parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg, mid);
    // left side
    return sum + handle.get();
    // left + right
}
int main()
{
    std::vector<int> v(10000, 1); // init all to 1
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end());
}
