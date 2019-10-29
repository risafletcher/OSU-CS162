# Zoo Tycoon

### Classes

#### Animal

- ##### public:

  - **age**
    - Adult: >= 3 days
    - Baby: < 3
  - **cost**
  - **numBabies**
  - **foodCost**
    - user-defined or const value (per day)
  - **payOffRate**
    - per day



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

