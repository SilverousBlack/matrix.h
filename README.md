# matrix.h
`matrix.h` and `dimensional.h` are C++ libraries. Where `matrix.h` contains the class `matrix`, a three-dimensional `std::vector`-based class and `dimensional.h` contains the class `dimensional_size`, a class for handling three-dimensional sizes and class `dimensional_pos`, a class for handling three-dimensional positions in a space.

***IMPORTANT***
Visit `code/releases` for the latest release as well all other releases.

## Latest Release

### 2.0 Features
#### ***BIG CHANGES***
* Placed `dimensional_pos` and `dimensional_size` under `namespace` `s_dim`
    - This would allow you to create your own simplified vesion of the library's classes and use both simultaneously
* Placed `matrix` under namespace `s_matrix`
    - This would allow you to create your own simplified vesion of the library's class and use both simultaneously
* Seperated function declarations and definitions
*Added `*.lib` and `*.obj` files
     - `matrix.h` and `dimensional.h` are now static libraries
     - visit https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=vs-2019 for more information
     - for other IDEs, `matrix.h` and `dimensional.h` can be included by respective standard means (e.g. adding them to the linker list)

#### Additional Functionalities/Functionality Changes
* `matrix::isfull()`
  - detects if the entire matrix space is full. Boolean value, returns true if full, false if not.
* `matrix::fill()` 
  - fills all  blank spaces in the matrix with a certain value.
* `matrix::remove_instance()` 
  - clears all instances of a certain value in the matrix space.
* `matrix::operator bool() const` 
  - a cast to `bool` operator.
  - similar to `matrix::isfull()`.
* `matrix::operator size_t() const`
  - a cast to `size_t` operator.
  - randomly returns the breadth (`dimensional_size::get_breadth()`), height (`dimensional_size::get_height()`), width (`dimensional_size::get_width()`) or capacity (`matrix::get_capacity()`)

### 1.0 Features

- Internally a three-dimensional vector `(std::vector)` of typename `"type"` `(vector<vector<vector<type>>>)`.
- Compatible to contain an any number of members with default setting of `1x1x1` space `(_breadth=0, _height=0, _width=0)`.
- Compatible to contain any type structure/class.
- Size is internally managed by `dimensional_size` from `dimensional.h`.
  
#### Functionalities

  `resize()` - resizes the matrix space the same a vector does, but the size of each row `(x)`, column `(y)` and flank `(z)` are uniform in nature; a matrix space does not have jagged rows/columns/flanks. Default resize is a `1x1x1` space.
  
   `assign()` - assigns a value to a matrix member of `(z, y, x)` position. No default setting.
  
   `access()` - accesses/returns the value of a matrix member of `(z, y, x)` position. Default is at `(0, 0, 0)`.
  
   `move()` - moves a matrix member from an old `(z, y, x)` position to a new `(z, y, x)` position. Overwrites the member in the new position if already occupied. Positions are noted in `dimensional_pos<type>.`
  
   `get_capacity()` - returns the entire capacity of the matrix space.
  
   `copy()` - copies row or row-column to a vector `_dest`. Also returns the selected vector space.
  
   `get_loc()` - finds or gets the location/position of an object in the matrix, if it exists.
  
   `operator<<` - inserts an object to the earliest blank space.
  
   `operator>>` - extracts a member of the latest position, this also removes the member from the matrix space.
  
   `operator=` - equates/assigns the matrix from a pre-defined matrix.
  
#### Known Bugs

  `operator<<` and `operator>>` does not work with special user-defined data structures/classes without a definition of a boolean cast definition internally.
