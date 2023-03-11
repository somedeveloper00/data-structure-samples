# Data Structure Samples
by saeed barari

## What's this?!
A project that takes a look at implementation of different list types, arrays and linked list in particular, and executes benchmarks on them.

## Install
```console
g++ main.cpp -o main
```
The file `main.exe` (or without the `exe` if it's not on windows) will be the final executable file, which you can run. This is a CLI (command-line interface) so running it from console/terminal/commandline is advised.  
> You can also use the pre-built binary for windows at the [release page](https://github.com/somedeveloper00/data-structure-samples/releases/tag/main).  
<button onclick="window.location.href='https://github.com/somedeveloper00/data-structure-samples/releases/download/main/main.exe';">Download v1.0.0</button>

> :Buttons
> > :Button label=GitHub, url=https://github.com
## Usage & Sample
here's a benchmark example of arrays in my device:  
`main.exe -b arr`
```console
adding 100000 items to list all at once.
---median total delay: 0.1826ms
adding 100000 items to list one by one.
---avg total delay: 4.9384ms
```
and here's `main.exe -b ll`
```console
adding 100000 items to list all at once.
---median total delay: 3.8506ms
adding 100000 items to list one by one.
---avg total delay: 4.0162ms
```
as you can see, array outperformed linked list in a all-at-once adding of items, but the linked list performed slightly better when adding items one by one.

> You can also change the way benchmark works by modifying the source code "Benchmark.cpp". here for instance, take a look at this variable  
> ![benchmark script variable](/imgs/img1.png)  
> I'm changing that to 128 and doing another build, to do another (better) benchmark.  
> `main.exe -b arr`
> ```console
> adding 100000 items to list all at once.
> ---median total delay: 0.1823ms
> adding 100000 items to list one by one.
> ---avg total delay: 4.8653ms
> ```
> and here's `main.exe -b ll` 
> ```console
> adding 100000 items to list all at once.
> ---median total delay: 3.8754ms
> adding 100000 items to list one by one.
> ---avg total delay: 4.0116ms
> ```

for more usage more, just run `main.exe` without any argument; it'll print a nicely formatted usage text!  
here's the usage:

```console

 =====================================================
|                                                     |
|        LIST DATA STRUCTURE SAMPLE & BENCHMARK       |
|                                                     |
|                   by Saeed Barari                   |
|             github.com/somedeveloper00              |
|                                                     |
|                   written in c++                    |
|                                                     |
|      (with help of Bing Chat & Github Copilot)      |
|                                                     |
 -----------------------------------------------------

# Description:
    This is a project to demonstrating the way different data
    types work, buy showing examples and benchmarks of the given
    data type. This particular project is aimed only at list
    types, it includes the following list types:

    * Array:  An array is a collection of items of same data
               type stored at contiguous memory locations.
    * Linked  List: an ordered set of data elements, each
               containing a link to its successor.
    * Queue:  a data structure that follows the FIFO (First In
               First Out) principle, meaning that the first
               element inserted is the first one to be removed.
    * Stack:  a data structure that follows the LIFO (Last In
               First Out) principle, meaning that the last element
               inserted is the first one to be removed.

    The project also demonstrates the way sorted lists are used and
    keep them in benchmark.

# Usage:
    --no-intro (-ni):     hides this intro on execution
    --source (-s):        opens a link to source code
    --desc (-d) [LTYPE]:  shows description and c++ code sample for
                          a list type.
    --benchmark (-b)
        [LTYPE]:          executes a benchmark on the specified list
                          type. (only supports array and linked list)

    * Parameters:
        LTYPE:            list type. possible options:
                            'array (arr)', 'linkedlist (ll)', 'queue (q)',
                            'stack (s)'
```