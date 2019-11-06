# Zoo Tycoon

### Classes

#### Animal

- ##### public:

  - **age**
    - Adult: >= 3 days
    - Baby: < 3
  - **incrementAge()**
  - **isAdult()**
  - **cost**
  - **numberOfBabies**
  - **foodCost**
    - user-defined or const value (per day)
  - **payOffRate**
    - per day

#### Zoo

event enums: { SICKNESS, ATTENDANCE_BOOM, BIRTH }

Animal enums: { TIGER, PENGUIN, TURTLE }

- ##### private:

  - **const ANIMAL_CAPACITY**: 10 (at start)
  - **bank**
  - **tigers[numAnimals]** (dynamic array of Tigers)
  - **penguins[numAnimals]** (dynamic array of Penguins)
  - **turtles[numAnimals]** (dynamic array of Turtles)
  
- ##### public:

  - **addToBank(int)**
  - **subtractFromBank(int)**
  - **buyAnimal()**
  - **addTiger(int age)**
  - **killTiger()**
  - **addPenguin(int age)**
  - **killPenguin()**
  - **addTurtle(int age)**
  - **killTurtle()**

#### Game

- ##### private:

  - **day**

- ##### public:

  - **playAgain**
  - **start()**
  - **startMenu()**
  - **gameOver()**
  - **validateInput()**



### Derived Classes

#### Tiger : Animal

- ##### public:

  - **cost**: $10,000
  - **numBabies**: 1
  - **foodCost**: 5 * Animal::foodCost
  - **payOffRate**: 0.2 * cost

#### Penguin : Animal

- ##### public:

  - **cost**: $1,000
  - **numBabies**: 5
  - **foodCost**: Animal::foodCost
  - **payOffRate**: 0.1 * cost

#### Turtle : Animal

- ##### public:

  - **cost**: $100
  - **numBabies**: 10
  - **foodCost**: 0.5 * Animal::foodCost
  - **payOffRate**: 0.05 * cost



