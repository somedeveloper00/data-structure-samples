#include "includes.cpp"

namespace Utilities
{
    void PrintIntro() {
        std::cout << PrintTexts::Intro << std::endl;
    }

    void OpenLink(const std::string url) {
        system(("start " + url).c_str());
    }

    void OpenSourceLink() {
        // open the source code link in the default browser
        OpenLink("https://github.com/somedeveloper00");
    }


    int* GetRandomValues(const int count, const int min, const int max, const int seed = 101) {
        std::mt19937 rand(seed);
        std::uniform_int_distribution<int> udist(0, 100);
        int* vals = new int[count];
        for (size_t i = 0; i < count; i++) {
            vals[i] = udist(rand);
        }
        return vals;
    }

    int* Sorted(ListType<int>* list) {
        auto count = list->count();
        int* vals = new int[count];
        for (size_t i = 0; i < count; i++) {
            vals[i] = list->get_at(i);
        }
        // bubble sort
        for (size_t i = 0; i < count; i++) {
            for (size_t j = i + 1; j < count; j++) {
                if (vals[j] > vals[i]) {
                    auto tmp = vals[i];
                    vals[i] = vals[j];
                    vals[j] = tmp;
                }
            }
        }
        return vals;
    }

    void ShowDesc_Array() {
        std::cout << PrintTexts::ArrayDescription << std::endl;
    }

    void ShowDesc_LinkedList() {
        std::cout << PrintTexts::LinkedList << std::endl;
    }
    void ShowDesc_QueueList() {
        std::cout << PrintTexts::Queue << std::endl;
    }
    void ShowDesc_StackList() {
        std::cout << PrintTexts::Stack << std::endl;
    }
} // namespace Utilities

