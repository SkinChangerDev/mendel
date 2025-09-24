# Mendel
Mendel is a hobby project of mine that attempts to introduce memory safety into C++ with a minimal feature set and learning curve, while remaining compatible with existing C++ code. It does this by providing safe, flexible abstractions over existing functionality.

## Disclamer
Mendel is a hobby project in a pre-alpha state that I made with moderate C++ experience. Mendel is currently proof-of-concept only, and is not production ready.

## Contributing
While I'm open to contributions, be aware that it may take me some time to handle your pull request.

## Q&A

### What makes Mendel different from projects like Rust or Go?
Mendel takes a different approach to memory safety. Instead of ensuring your program will not violate memory safety at compile time with borrow checking, or handling memory at runtime using garbage collection, Mendel checks for safety violations at runtime and throws an error(s) if it detects any.

This may seem like an unnecessarily complex approach with a lot of overhead, but it's actually quite simple. We start with a foundation of generational pointers, and build off from there.

### What's a generational pointer?
Whenever we create an object that we want to reference elsewhere, we give it a unique identifier called a generation. This generation gets overriden when the object is destroyed. Then, we can create a pointer to this object that has this generation attached, and check that the object's generation and the pointer's generation match when the pointer is dereferenced, throwing an error if they don't.

This ensures that we never access an object that has been deallocated. If you want a deeper look into generational pointers, I'd recomend [this](https://verdagon.dev/blog/generational-references) blog by verdagon.

### Why is it called Mendel?
Because Darwin was to obvious.