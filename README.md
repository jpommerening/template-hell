# template-hell
Welcome C++ template hell. Template meta programming at its worst

You probably should not use this.

## Example

The following example creates a variable "distance" that stores
its value as a `double` and has the unit "meters". It is initialized
to equal the length of one mile.

```c++
#include <iostream>
#include "units/si_units.h"
#include "units/imperial_units.h"
#include "units/value.h"

int main( void ) {
  Value<double, SIUnits::m> distance = Value<double, ImperialUnits::mile>( 1. );
  std::cout << distance << std::endl;
  return 0;
}
```

There are some physical constants such as the speed of light (`c0`) that
have a complex unit associated with them, in this case meters per second.
Using C++11's `auto` type we can let the compiler's template system figure
out the type of out calculations.

```c++
#include <iostream>
#include "units/si_units.h"
#include "units/physical_constants.h"
#include "units/value.h"

int main( void ) {
  /* so, how far did light go again, in a second? */
  auto result = PhysicalConstants<double>::c0 * Value<double, SIUnits::s>( 1. );
  std::cout << result << std::endl;
  return 0;
}
```

