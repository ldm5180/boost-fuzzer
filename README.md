# boost-fuzzer
LibFuzzer fuzzers (and some corpus) for Boost libs.

## Building
* Assuming that you have a modern clang compiler and the boost libs installed, get libfuzzer and build it.
```bash
svn co http://llvm.org/svn/llvm-project/llvm/trunk/lib/Fuzzer
clang -c -g -O2 -std=c++11 Fuzzer/*.cpp -IFuzzer
```
* Build the fuzzer you desire.
```bash
COV_FLAGS=" -fsanitize-coverage=edge,indirect-calls,8bit-counters"
FUZZER_NAME=<FUZZER_NAME>  # example: FUZZER_NAME=tokenizer
clang++ -std=c++11 -fsanitize=address $COV_FLAGS -o test_$FUZZER_NAME $FUZZER_NAME/fuzzer.cc Fuzzer*.o
```
* Run your fuzzer, and optionally include the existing corpus.
```bash
./test_$FUZZER_NAME $FUZZER_NAME/CORPUS
```

## Learning more...
Head over to http://llvm.org/docs/LibFuzzer.html