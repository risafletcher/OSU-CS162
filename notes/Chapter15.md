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

```c++
class Base
{
public:
    int i;
    Base(int k) { i = k; }
};

class Derived : public Base
{
public:
    double d;
    Derived(int k, double g) : Base(k) { d = g; }
};

// Raw pointers
Base  *raw_pb = new Base(5);
Derived *raw_pd = new Derived(6, 10.5);

// Smart pointers
shared_ptr<Base> pb = make_shared<Base>(5);
shared_ptr<Derived> pd = make_shared<Derived>(6, 10.5);

// Rule #1: A derived class pointer can always be assigned to a base class pointer.

// Raw pointers
Base *raw_bp1 = raw_pd;
Base *raw_bp2 = new Derived(7, 11.5);

// Smart pointers
shared_ptr<Base> pb1 = pd;
shared_ptr<Base> pb2 = make_shared<Derived>(7, 11.5);

// Rule #2: A type cast is required to perform the opposite assignment of a base class pointer to a derived class pointer.

Derived *raw_pd1 = static_cast<Derived *>(raw_pb1);
shared_ptr<Derived> pd1 = static_pointer_cast<Derived>(pb1);	// smart pointer

```

These compatibility rules hold true even for deep inheritance hierarchies, such as `Person` -> `Faculty` -> `TFaculty`. 

```c++
TFaculty *tF = new TFaculty(name, disc);
Person *p;
p - tF;

// An assignment in the reverse direction, however, requires a type cast:
tF = static_cast<TFaculty *>(p);
```

