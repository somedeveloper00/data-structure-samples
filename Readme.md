# Data Structure Samples
by saeed barari

## What's this?!
A project that takes a look at implementation of different list types, arrays and linked list in particular, and executes benchmarks on them.

## Install
```console
g++ main.cpp -o main
```
The file `main.exe` (or without the `exe` if it's not on windows) will be the final executable file, which you can run. This is a CLI (command-line interface) so running it from console/terminal/commandline is advised.

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

You can also change the way benchmark works by modifying the source code "Benchmark.cpp". here for instance, take a look at this variable 

![benchmark script variable](/imgs/img1.png)
I'm changing that to 128 and doing another build, to do another (better) benchmark.  
`main.exe -b arr`
```console
adding 100000 items to list all at once.
---median total delay: 0.1823ms
adding 100000 items to list one by one.
---avg total delay: 4.8653ms
```
and here's `main.exe -b ll`
```console
adding 100000 items to list all at once.
---median total delay: 3.8754ms
adding 100000 items to list one by one.
---avg total delay: 4.0116ms```