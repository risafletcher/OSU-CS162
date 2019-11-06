# Chapter 15: Polymorphism and Virtual Functions

### 15.1 Type Compatibility in Inheritance Hierarchies

Objects of a derived class can be used wherever objects of a base class object are expected.

- **A derived class pointer can always be assigned to a base class pointer**. This means that base class pointers can point to derived class objects.
- **A type cast is required to perform the opposite assignment of a base class pointer to a derived class pointer.** An error may result at run time if the base class pointer does not actually point to a derived class object.