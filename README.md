# matrix.h
`matrix.h` and `dimensional.h` are C++ libraries. Where `matrix.h` contains the class `matrix`, a three-dimensional `std::vector`-based class and `dimensional.h` contains the class `dimensional_size`, a class for handling three-dimensional sizes and class `dimensional_pos`, a class for handling three-dimensional positions in a space.

***IMPORTANT***
Visit `code/releases` for the latest release as well all other releases.

## Latest Release

### 3.0 ***BETA*** Features
#### New I/O
* Added a file I/O system
    - Allows file generation `make_file`
    - Allows file reading `read_file`
* Added an initialization system
    - Still a huge prototype function
    - Places an integral value to all the members of the matrix space
* Added an enumeration `mtxio` for I/O mode control
    - Output modes
        * `std` - a mode for sole generation of an Matrix file (*.mtx)
        * `cpy` - a mode for combined generation of a Matrix file (*.mtx) and a readable file
        * `safe` - a mode for combined generation of a Matrix file in a binary mode and a readable file in normal mode
    - Input modes
        * `sta` (standard type allocation) - a mode for standard class initialization;
        * `cta` (convetional type allocation) - a mode for conventional class initialization;
        * `bbta` (boolean-based type allocation) - a mode for comparison-based class split initialization;
        * ++more
#### Beta Notes
* The new prototype functions are purely in testing phase there is no guarantee they would work.

### 2.1 Features
#### Type definitions
* Added type definitions for common data types
    - `mat_int` for `int`
    - `mat_chr` for `char`
    - `mat_bln` for `bool` or `boolean`
    - `mat_flt` for `float`
    - `mat_dbl` for `double`
    - `mat_wch` for `wchar_t`
    - `mat_str` for `std::string`
    - `mat_wsr` for `std::wstring`
#### Constants
* Made some functionalities a constant
#### ~BUG~
* Fixed issue with downloading a previous version in the `.zip` file

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
