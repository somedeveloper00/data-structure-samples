#include "includes.cpp"
#include "ListTypes.cpp"
#include <chrono>
#include <iostream>

#define now() std::chrono::high_resolution_clock::now()

namespace Benchmark
{
    // how many times tests happen. the more the better 
    int test_sample_count = 64;
    bool verbose = false;

    void do_list_benchmark_add_remove(ListType<int>* list, int count) {
        // add all at once
        std::cout << "adding " << count << " items to list all at once." << std::endl;
         std::chrono::duration<double, std::milli> ellapseds[test_sample_count];
        auto adding_vals = Utilities::GetRandomValues(count, 0, 100);
        for (size_t s = 0; s < test_sample_count; s++) {
            auto start = now();
            list->add(count, adding_vals);
            auto stop = now();
            ellapseds[s] = stop - start;
            if (verbose)
                std::cout << "sample " << s << " finished. ellapsed: " << ellapseds[s].count() << "ms" << std::endl;
            list->clear();
        }
        
        std::sort(ellapseds, ellapseds + test_sample_count);
        std::cout << "---median total delay: " << ellapseds[(int)std::ceil(test_sample_count/2.)].count() << "ms" << std::endl;
        
        // add one by one
        std::cout << "adding " << count << " items to list one by one." << std::endl;
        for (size_t s = 0; s < test_sample_count; s++) {
            auto start = now();
            for (size_t i = 0; i < count; i++) {
                list->add(adding_vals[i]);
            }
            auto stop = now();
            ellapseds[s] = stop - start;
            if (verbose)
                std::cout << "sample " << s << " finished. ellapsed: " << ellapseds[s].count() << "ms" << std::endl;
            list->clear();
        }
        std::sort(ellapseds, ellapseds + test_sample_count);
        std::cout << "---avg total delay: " << ellapseds[(int)std::ceil(test_sample_count/2.)].count() << "ms" << std::endl;
    }
} // namespace Benchmark
