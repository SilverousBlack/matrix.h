# USES GUIDE
> for version A2.1

## Dimensional Size
Class `dimensional_size` is used to to monitor the size of a three-dimensional space. It's basically a way to store into memory the size of an space.
### Initialization
    * An object under this data structure can be initialized by template or by constuction.
    * By template it requires to have `<>` after the type name, e.g. `dimensional_size<> obj;`, `dimensional_size<const, const, const> obj;` and `dimensional_size<var, var, var> obj;`.
        - By default the sizes in its template are `0` thus can be `<>`.
        - The size declaration are in the template can be a constant `const` (e.g. `100`, `2` etc.) or a variable `var` (e.g. `i` etc.).
        - Note that the size declaration is a `std::size_t` type or `unsigned long long int`, it can be a mistake if the variable `var` has a non-integer type (e.g. `char` etc.).
    * After declaration, a `dimensional_size` can be initialize with `obj();`, `obj(const, const, const);` and `obj(var, var, var);`.
        - By default the sizes in its constructor are `0` thus can be `()`.
        - The size declaration are in the constructor can be a constant `const` (e.g. `100`, `2` etc.) or a variable `var` (e.g. `i` etc.).
        - Note that the size declaration is a `std::size_t` type or `unsigned long long int`, it can be a mistake if the variable `var` has a non-integer type (e.g. `char` etc.).
### Functionalities Usage
#### `get` Functions - to access the values.
    * Capacity `get_capacity() const` - returns the capacity of the declared space, a constant `size_t` value. Used as `obj.get_capacity()`.
    * Breadth `get_breadth() const` - returns the breadth of the declared space, a constant `size_t` value. Used as `obj.get_capacity()`.
    * Height `get_height() const` - returns the height of the declared space, a constant `size_t` value. Used as `obj.get_height()`.
    * Width `get_width() const` - returns the width of the declared space, a constant `size_t` value. Used as `obj.get_width()`.
#### `up` Functions - to update the values.
    * Update size `up_size` - a void functions that allows to update the internal values with variable/constant `size_t` value. Used as `obj.up_size(breath, height, width)`.
    
## Dimensional Position
Class `dimensional_pos` is used to monitor/control the position of a variable object in a three-dimesional space.
### Functionalities Usage
#### Initialization
    * An object can only be initialized by the use of the constructor.
    * By default the constructor takes in `0` values for its members.
    * Note that position declaration is a `s_dim::pos` type or `unsigned long long int`, it can be a mistake if the variable `var` has a non-integer type (e.g. `char` etc.).
#### `get` Functions
    * Position `get_pos()` -  returns the position of a variable `var` of a type `type` in a `std::vector` space. Returns the values as `dimensional_pos`.
        - 1D vector - used as `get_pos(std::vector<type>, var)`.
        - 2D vector - used as `get_pos(std::vector<std::vector<type> >, var)`.
        - 3D vector - used as `get_pos(std::vector<std::vector<std::vector<type> > >, var)`.
    * z `get_z() const` - returns the z position as declared/saved. Used as `obj.get_z()`.
    * y `get_y() const` - returns the y position as declared/saved. Used as `obj.get_y()`.
    * x `get_x() const` - returns the x position as declared/saved. Used as `obj.get_x()`.
    
## Matrix
Class `matrix` is a three-dimensional container for any type (though it is preferable that the type has boolean cast definiton).
### Functionalities Usage
#### Initialization
    * An object under this class can be initialized by template or by constuction.
    * By template it requires to have `<type>` after the type name, e.g. `matrix<type> obj;`, `matrix<type, const, const, const> obj;` `matrix<type, var, var, var> obj;`
        - By default the sizes in its template are `0` thus can be `<type>`.
        - The size declaration are in the template can be a constant `const` (e.g. `100`, `2` etc.) or a variable `var` (e.g. `i` etc.).
        - Note that the size declaration is a `std::size_t` type or `unsigned long long int`, it can be a mistake if the variable `var` has a non-integer type (e.g. `char` etc.).
    * After declaration, a `dimensional_size` can be initialize with `obj();`, `obj(const, const, const);` and `obj(var, var, var);`.
        - By default the sizes in its constructor are `0` thus can be `()`.
        - The size declaration are in the constructor can be a constant `const` (e.g. `100`, `2` etc.) or a variable `var` (e.g. `i` etc.).
        - Note that the size declaration is a `std::size_t` type or `unsigned long long int`, it can be a mistake if the variable `var` has a non-integer type (e.g. `char` etc.).
#### Utility Functions
    * `resize()` - resizes to the matrix space. Used as `obj.resize(width, height, length)`.
    * `assign()` - assigns a value to a member. Used as `obj.assign(val, z, y, x)`. Recommended to be used when assigning variables.
    * `access()` - returns the value of a member. Used as `obj.access(z, y, x)`. Recommended to be used when accessing variables.
    * `move()` - moves the value of a member to another position. Used as `obj.access(dimensional_pos old, dimensional_pos new)`.
    * `isfull()` - detects if the matrix is full or not. Used as `obj.isfull()`.
    * `fill()` - fills the matrix with a value of the type, does not overwrite. Used as `obj.fill(val)`.
    * `remove_instance()` - removes all instances of a value in the matrix. Used as `obj.remove_instance(value)`.
#### `get` Functions
    * Capacity `get_capacity() const` - returns the capacity of the matrix space, a constant `size_t` value. Used as `obj.get_capacity()`.
    * Location `get_loc()` - returns the first appearance dimensional position of variable of the type. Used as `obj.get_loc(var)`;
#### Operators
    * `operator<<` - inserts a value in the matrix to the earliest free space. Used as `obj << var;`.
    * `operator>>` - extracts a value in the matrix of the latest instance, removes the value from the member and assigns the value to the variable. Used as `obj >> var;`.
    * `operator=` - equates two matrices and returns the later. Used as `matrix<type> ant = obj;`.
