#include "includes.cpp"
#include "ArgvParser.cpp"
#include "Benchmark.cpp"

void do_test_on_list(ListType<int>* list) {
    std::cout << "adding random values" << std::endl;
    list->add(5, Utilities::GetRandomValues(7, 0, 100));
    list->print(ToString::int2str());
    std::cout << "inserting values" << std::endl;
    list->insert(0, 3, new int[]{1, 1, 1});
    list->print(ToString::int2str());
    std::cout << "inserting another values" << std::endl;
    list->insert(1, 2, new int[]{2, 2});
    list->print(ToString::int2str());
    std::cout << "Removing at 0" << std::endl;
    list->remove_at(0);
    list->print(ToString::int2str());
    std::cout << "Removing at last" << std::endl;
    list->remove_at(list->count()-1);
    list->print(ToString::int2str());
    std::cout << "clearing" << std::endl;
    list->clear();
    list->print(ToString::int2str());
}

int main(int argc, char const *argv[])
{
    ArgvParser* parser = new ArgvParser(argc, argv);
    if (parser->error) {
        return 1;
    }
    if (parser->openSourceLink) {
        Utilities::OpenSourceLink();
        return 0;
    } 

    if (parser->arrayDesc) {
        Utilities::ShowDesc_Array();
        return 0;
    }
    if (parser->linkDesc) {
        Utilities::ShowDesc_LinkedList();
        return 0;
    }
    if (parser->queueDesc) {
        Utilities::ShowDesc_QueueList();
        return 0;
    }
    if (parser->stackDesc) {
        Utilities::ShowDesc_StackList();
        return 0;
    }

    if (parser->arrayBench) {
        Array<int> list;
        Benchmark::do_list_benchmark_add_remove(&list, parser->benchmark_addcount);
        return 0;
    }
    if (parser->linkBench) {
        LinkedList<int> list;
        Benchmark::do_list_benchmark_add_remove(&list, parser->benchmark_addcount);
        return 0;
    }

    if (parser->showIntro) {
        Utilities::PrintIntro();
        return 0;
    }

    return 0;
    std::cout << "\nArray\n-------------" << std::endl;
    Array<int> arr;
    do_test_on_list(&arr);

    std::cout << "\nLinked List\n-------------" << std::endl;
    LinkedList<int> ll;
    do_test_on_list(&ll);

    std::cout << "\nCpp vector\n-------------" << std::endl;
    CppVector<int> cppv;
    do_test_on_list(&cppv);

    std::cout << "\nQueue\n-------------" << std::endl;
    Queue<int> queue;
    do_test_on_list(&queue);
    std::cout << "popping" << std::endl;
    queue.pop();
    queue.pop();
    queue.print(ToString::int2str());

    std::cout << "\nStack\n-------------" << std::endl;
    Stack<int> stack;
    do_test_on_list(&stack);
    std::cout << "popping" << std::endl;
    stack.pop();
    stack.pop();
    stack.print(ToString::int2str());

    return 0;
}
