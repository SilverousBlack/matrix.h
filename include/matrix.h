#pragma once
#ifndef ___INC_MATRIX_
namespace experimental {
    #include "matpack.h"
}
namespace legacy {
    #include "previous/dimensional.h"
    #include "previous/matrix.h"
    template<typename type>
    using legacy_matrix = s_mtx::matrix<type>;
    template<size_t z = 0, size_t y = 0, size_t x = 0>
    using legacy_dim_size = s_dim::dimensional_size<z, y, x>;
}
#endif