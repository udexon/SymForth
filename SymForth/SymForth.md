Updated code:

https://github.com/udexon/SymForth/blob/master/benchmarks/sm_expand.cpp

`std::stack<std::string> mystack;` has been renamed to:
```
std::stack<std::string> sm_S;
```

The most significant innovation in this project is the RCP stack, which allows SymEngine objects (RCP=Reference Counted Pointers) to be stored on stack and subsequently manipulated:
```
std::stack<SymEngine::RCP<const Basic>> RCP_S;
```

From Forth perspective, this leads to "multitype stacks" where the input tokens and string output tokens are stored on a string stack, while the code manages "one stack per type", a hopefully elegant solution for integrating Forth with modern type oriented programming languages:
```
std::stack<std::string> sm_S;
```
