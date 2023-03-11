#include "includes.cpp"

class ArgvParser {
public:
    ArgvParser(int argc, char const *argv[]) {
        for (size_t i = 1; i < argc; i++) {
            std::string arg = lower(argv[i]);

            // analyse for commands
            if (arg == "--no-intro" || arg == "-ni") {
                showIntro = false;
            }
            else if(arg == "--source" || arg == "-s") {
                openSourceLink = true;
            }
            else if(arg == "--desc" || arg == "-d") {
                arg = lower(argv[++i]);
                int t = resolveType(arg);
                if (t == TYPE_ARRAY) arrayDesc = true;
                else if (t == TYPE_LINKEDLIST) linkDesc = true;
                else if (t == TYPE_QUEUE) queueDesc = true;
                else if (t == TYPE_STACK) stackDesc = true;
                else {
                    std::cout << "wrong arguments. check the usage in the intro." << std::endl;
                    error = true;
                    return;
                }

            }
            else if(arg == "--benchmark" || arg == "-b") {
                arg = lower(argv[++i]);
                int t = resolveType(arg);
                if (t == TYPE_ARRAY) arrayBench = true;
                else if (t == TYPE_LINKEDLIST) linkBench = true;
                else if (t == TYPE_QUEUE) queueBench = true;
                else if (t == TYPE_STACK) stackBench = true;
                else {
                    std::cout << "wrong arguments. check the usage in the intro." << std::endl;
                    error = true;
                    return;
                }
            }
            else {
                std::cout << "wrong arguments. check the usage in the intro. (" << arg << ")" << std::endl;
                error = true;
                return;
            }
        }
    }

    bool error = false;
    bool showIntro = true;
    bool openSourceLink = false;
    bool arrayDesc = false;
    bool linkDesc = false;
    bool queueDesc = false;
    bool stackDesc = false;
    bool arrayBench = false;
    bool linkBench = false;
    bool queueBench = false;
    bool stackBench = false;
    
    int benchmark_addcount = 100000;

private:
    const int TYPE_ARRAY = 1;
    const int TYPE_LINKEDLIST = 2;
    const int TYPE_QUEUE = 3;
    const int TYPE_STACK = 4;

    std::string lower(std::string str) const {
        for (size_t i = 0; i < str.length(); i++) {
            str[i] = std::tolower(str[i]);
        }
        return str;
    }
    int resolveType(std::string str) const {
        if (str == "array" || str == "arr") return TYPE_ARRAY;
        if (str == "linkedlist" || str == "ll") return TYPE_LINKEDLIST;
        if (str == "queue" || str == "q") return TYPE_QUEUE;
        if (str == "stack" || str == "s") return TYPE_STACK;
        return -1;
    }
};