# matrix.h
A 3D vector-based class

Packaged with dimensional.h, a library for storing/handling sizes and locations/positions of objects in a three-dimensional space

//A 1.0 Features:
  > Internally a three-dimensional vector (std::vector) of typename "type" (vector<vector<vector<type> > >)
  > Compatible to contain a any number of members with default setting of 1x1x1 space (_breadth=0, _height=0, _width=0)
  > Compatible to contain any type structure/class
  > Size is internally managed by dimensional_size from dimensional.h
  
  > Functionalities
    > resize() - resizes the matrix space the same a vector does, but the size of each row (x), column (y) and flank (z) are uniform in nature; a matrix space does not have jagged rows/columns/flanks. Default resize is a 1x1x1 space.
    > assign() - assigns a value to a matrix member of (z, y, x) position. No default setting.
    > access() - accesses/returns the value of a matrix member of (z, y, x) position. Default is at (0, 0, 0).
    > move() - moves a matrix member from an old (z, y, x) position to a new (z, y, x) position. Overwrites the member in the new position if already occupied. Positions are noted in dimensional_pos<type>.
    > get_capacity() - returns the entire capacity of the matrix space.
    > copy() - copies row or row-column to a vector _dest. Also returns the selected vector space.
    > get_loc() - finds or gets the location/position of an object in the matrix, if it exists.
    > operator<< - inserts an object to the earliest blank space.
    > operator>> - extracts a member of the latest position (this also removes the member from the matrix space).
    > operator= - equates/assigns the matrix from a pre-defined matrix.
  
  > Known Bugs
    > operator<< and operator>> does not work with special user-defined data structures/classes without a definition of a boolean cast definition internally.
