# Chapter 15: Polymorphism and Virtual Functions

### 15.1 Type Compatibility in Inheritance Hierarchies

Objects of a derived class can be used wherever objects of a base class object are expected.

- **A derived class pointer can always be assigned to a base class pointer**. This means that base class pointers can point to derived class objects.
- **A type cast is required to perform the opposite assignment of a base class pointer to a derived class pointer.** An error may result at run time if the base class pointer does not actually point to a derived class object.

Review:

- Shared pointers handle `new` and `delete` (dynamic memory allocation) for you and should be used when you want to share pointers between objects.
- Unique pointers should be used when you only need an instance of that pointer within scope because it will only exist within the scope where it is defined. Once the scope is exited, the pointer is destroyed.

```c++
#include <memory>
// shared pointer
//			template parameter		  equivalent to calling 'new'
std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

// unique pointer
std::unique_ptr<Entity> entity = std::make_unique<Entity>();
```

