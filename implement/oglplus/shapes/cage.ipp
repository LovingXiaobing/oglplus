/**
 *  @file oglplus/shapes/cage.ipp
 *  @brief Implementation of shapes::Cage
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2019 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace oglplus {
namespace shapes {

OGLPLUS_LIB_FUNC
const Matrix<double, 3, 3>& Cage::_face_mat(GLuint face) {
    assert(face < 6);
    using M = Matrix<double, 3, 3>;
    static M m[6] = {
      // clang-format off
		M( 0, 0, 1,  0,-1, 0,  1, 0, 0),//[0]+x
		M( 0, 0,-1,  0,-1, 0, -1, 0, 0),//[1]-x
		M(-1, 0, 0,  0, 0, 1,  0, 1, 0),//[2]+y
		M(-1, 0, 0,  0, 0,-1,  0,-1, 0),//[3]-y
		M( 1, 0, 0,  0, 1, 0,  0, 0, 1),//[4]+z
		M(-1, 0, 0,  0, 1, 0,  0, 0,-1) //[5]-z
      // clang-format on
    };
    return m[face];
}

OGLPLUS_LIB_FUNC
GLuint Cage::_vert_count() const {
    return GLuint(
      6 * 8 + (_divs.z() - 1) * 2 * 4 * 2 + (_divs.x() - 1) * 4 * 4 * 2 +

      (_divs.y() - 1) * _divs.z() * 2 * 4 * 2 +
      (_divs.z() - 1) * _divs.x() * 2 * 4 * 2 +
      (_divs.y() - 1) * _divs.x() * 2 * 4 * 2 +

      (_divs.x() * _divs.y()) * 32 + (_divs.x() * _divs.z()) * 32 +
      (_divs.y() * _divs.z()) * 32);
}

OGLPLUS_LIB_FUNC
GLuint Cage::_index_count() const {
#ifdef GL_PRIMITIVE_RESTART
    return GLuint(
      6 * 11 + (_divs.z() - 1) * 2 * 5 * 2 + (_divs.x() - 1) * 4 * 5 * 2 +

      (_divs.y() - 1) * _divs.z() * 2 * 5 * 2 +
      (_divs.z() - 1) * _divs.x() * 2 * 5 * 2 +
      (_divs.y() - 1) * _divs.x() * 2 * 5 * 2 +

      (_divs.x() * _divs.y()) * 40 + (_divs.x() * _divs.z()) * 40 +
      (_divs.y() * _divs.z()) * 40);
#else
    return GLuint(
      6 * 12 + (_divs.z() - 1) * 2 * 6 * 2 + (_divs.x() - 1) * 4 * 6 * 2 +

      (_divs.y() - 1) * _divs.z() * 2 * 6 * 2 +
      (_divs.z() - 1) * _divs.x() * 2 * 6 * 2 +
      (_divs.y() - 1) * _divs.x() * 2 * 6 * 2 +

      (_divs.x() * _divs.y()) * 48 + (_divs.x() * _divs.z()) * 48 +
      (_divs.y() * _divs.z()) * 48);
#endif
}

OGLPLUS_LIB_FUNC
std::vector<GLfloat> Cage::_positions() const {
    std::vector<GLfloat> dest(_vert_count() * 3);
    auto p = dest.begin();

    using V = Vector<double, 3>;

    // for each face
    for(GLuint f = 0; f != 6; ++f) {
        double sx = _face_size(f, 0);
        double sy = _face_size(f, 1);
        double sz = _face_size(f, 2);

        double bx = _face_barw(f, 0);
        double by = _face_barw(f, 1);
        double bz = _face_barw(f, 1);

        p = _write(p, _face_vec(f, V(+bx - sx, +by - sy, sz)));
        p = _write(p, _face_vec(f, V(-sx, -sy, sz)));
        p = _write(p, _face_vec(f, V(+bx - sx, -by + sy, sz)));
        p = _write(p, _face_vec(f, V(-sx, +sy, sz)));
        p = _write(p, _face_vec(f, V(-bx + sx, -by + sy, sz)));
        p = _write(p, _face_vec(f, V(+sx, +sy, sz)));
        p = _write(p, _face_vec(f, V(-bx + sx, +by - sy, sz)));
        p = _write(p, _face_vec(f, V(+sx, -sy, sz)));

        GLuint dx = _face_divs(f, 0);
        GLuint dy = _face_divs(f, 1);

        double hx = (2 * sx - bx * (dx + 1)) / dx;
        double hy = (2 * sy - by * (dy + 1)) / dy;

        double xo = -sx + bx;
        for(GLuint x = 1; x != dx; ++x) {
            xo += hx;
            p = _write(p, _face_vec(f, V(+bx + xo, +by - sy, sz)));
            p = _write(p, _face_vec(f, V(+xo, +by - sy, sz)));
            p = _write(p, _face_vec(f, V(+bx + xo, -by + sy, sz)));
            p = _write(p, _face_vec(f, V(+xo, -by + sy, sz)));
            xo += bx;
        }

        xo = -sx + bx;
        for(GLuint x = 1; x != dx; ++x) {
            xo += hx;
            p = _write(p, _face_vec(f, V(+xo, +by - sy, sz - bz)));
            p = _write(p, _face_vec(f, V(+bx + xo, +by - sy, sz - bz)));
            p = _write(p, _face_vec(f, V(+xo, -by + sy, sz - bz)));
            p = _write(p, _face_vec(f, V(+bx + xo, -by + sy, sz - bz)));
            xo += bx;
        }

        double yo = -sy + by;
        for(GLuint y = 1; y != dy; ++y) {
            yo += hy;
            xo = -sx;
            for(GLuint x = 0; x != dx; ++x) {
                xo += bx;
                p = _write(p, _face_vec(f, V(+xo, +yo, sz)));
                p = _write(p, _face_vec(f, V(+xo, +by + yo, sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +by + yo, sz)));
                xo += hx;
            }
            yo += by;
        }

        yo = -sy + by;
        for(GLuint y = 1; y != dy; ++y) {
            yo += hy;
            xo = -sx;
            for(GLuint x = 0; x != dx; ++x) {
                xo += bx;
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, sz - bz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +by + yo, sz - bz)));
                p = _write(p, _face_vec(f, V(+xo, +yo, sz - bz)));
                p = _write(p, _face_vec(f, V(+xo, +by + yo, sz - bz)));
                xo += hx;
            }
            yo += by;
        }

        yo = -sy + by;
        for(GLuint y = 0; y != dy; ++y) {
            xo = -sx + bx;
            for(GLuint x = 0; x != dx; ++x) {
                p = _write(p, _face_vec(f, V(+xo, +yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+xo, +yo, +sz)));
                p = _write(p, _face_vec(f, V(+xo, +hy + yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+xo, +hy + yo, +sz)));

                p = _write(p, _face_vec(f, V(+xo, +hy + yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+xo, +hy + yo, +sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, +sz)));

                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, +sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, +sz)));

                p = _write(p, _face_vec(f, V(+hx + xo, +yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, +sz)));
                p = _write(p, _face_vec(f, V(+xo, +yo, -bz + sz)));
                p = _write(p, _face_vec(f, V(+xo, +yo, +sz)));
                xo += hx + bx;
            }
            yo += hy + by;
        }
    }
    assert(p == dest.end());
    return dest;
}

OGLPLUS_LIB_FUNC
std::vector<GLfloat> Cage::_normals() const {
    std::vector<GLfloat> dest(_vert_count() * 3);
    auto p = dest.begin();

    using V = Vector<double, 3>;

    // for each face
    for(GLuint f = 0; f != 6; ++f) {
        V t = _face_mat(f).Row(0);
        V b = _face_mat(f).Row(1);
        V n = _face_mat(f).Row(2);

        for(GLuint v = 0; v != 8; ++v)
            p = _write(p, n);

        GLuint dx = _face_divs(f, 0);
        for(GLuint s = 0; s != 2; ++s) {
            double sig = s ? -1 : 1;
            for(GLuint x = 1; x != dx; ++x) {
                for(GLuint v = 0; v != 4; ++v)
                    p = _write(p, n * sig);
            }
        }

        GLuint dy = _face_divs(f, 1);
        for(GLuint s = 0; s != 2; ++s) {
            double sig = s ? -1 : 1;
            for(GLuint y = 1; y != dy; ++y) {
                for(GLuint x = 0; x != dx; ++x) {
                    for(GLuint v = 0; v != 4; ++v)
                        p = _write(p, n * sig);
                }
            }
        }

        for(GLuint y = 0; y != dy; ++y) {
            for(GLuint x = 0; x != dx; ++x) {
                for(GLuint s = 0; s != 4; ++s)
                    p = _write(p, t);
                for(GLuint s = 0; s != 4; ++s)
                    p = _write(p, -b);
                for(GLuint s = 0; s != 4; ++s)
                    p = _write(p, -t);
                for(GLuint s = 0; s != 4; ++s)
                    p = _write(p, b);
            }
        }
    }
    assert(p == dest.end());
    return dest;
}

OGLPLUS_LIB_FUNC
std::vector<GLfloat> Cage::_tangents() const {
    std::vector<GLfloat> dest(_vert_count() * 3);
    auto p = dest.begin();

    using V = Vector<double, 3>;

    // for each face
    for(GLuint f = 0; f != 6; ++f) {
        V t = -_face_mat(f).Row(0);
        V n = -_face_mat(f).Row(2);

        for(GLuint v = 0; v != 8; ++v)
            p = _write(p, t);

        GLuint dx = _face_divs(f, 0);
        for(GLuint s = 0; s != 2; ++s) {
            double sig = s ? -1 : 1;
            for(GLuint x = 1; x != dx; ++x) {
                for(GLuint v = 0; v != 4; ++v)
                    p = _write(p, t * sig);
            }
        }

        GLuint dy = _face_divs(f, 1);
        for(GLuint s = 0; s != 2; ++s) {
            double sig = s ? -1 : 1;
            for(GLuint y = 1; y != dy; ++y) {
                for(GLuint x = 0; x != dx; ++x) {
                    for(GLuint v = 0; v != 4; ++v)
                        p = _write(p, t * sig);
                }
            }
        }

        for(GLuint y = 0; y != dy; ++y) {
            for(GLuint x = 0; x != dx; ++x) {
                for(GLuint s = 0; s != 16; ++s)
                    p = _write(p, -n);
            }
        }
    }
    assert(p == dest.end());
    return dest;
}

OGLPLUS_LIB_FUNC
std::vector<GLfloat> Cage::_tex_coords() const {
    std::vector<GLfloat> dest(_vert_count() * 3);
    auto p = dest.begin();

    using V = Vector<double, 3>;

    // for each face
    for(GLuint f = 0; f != 6; ++f) {
        double z = 0.0;
        double o = 1.0;

        double bx = 0.5 * _face_barw(f, 0) / _face_size(f, 0);
        double by = 0.5 * _face_barw(f, 1) / _face_size(f, 1);

        p = _write(p, _face_vec(f, V(+bx + z, +by + z, f)));
        p = _write(p, _face_vec(f, V(+z, +z, f)));
        p = _write(p, _face_vec(f, V(+bx + z, -by + o, f)));
        p = _write(p, _face_vec(f, V(+z, +o, f)));
        p = _write(p, _face_vec(f, V(-bx + o, -by + o, f)));
        p = _write(p, _face_vec(f, V(+o, +o, f)));
        p = _write(p, _face_vec(f, V(-bx + o, +by + z, f)));
        p = _write(p, _face_vec(f, V(+o, +z, f)));

        GLuint dx = _face_divs(f, 0);
        GLuint dy = _face_divs(f, 1);

        double hx = (1.0 - bx * (dx + 1)) / dx;
        double hy = (1.0 - by * (dy + 1)) / dy;

        double xo = bx;
        for(GLuint x = 1; x != dx; ++x) {
            xo += hx;
            p = _write(p, _face_vec(f, V(+bx + xo, +by + z, f)));
            p = _write(p, _face_vec(f, V(+xo, +by + z, f)));
            p = _write(p, _face_vec(f, V(+bx + xo, -by + o, f)));
            p = _write(p, _face_vec(f, V(+xo, -by + o, f)));
            xo += bx;
        }

        xo = bx;
        for(GLuint x = 1; x != dx; ++x) {
            xo += hx;
            p = _write(p, _face_vec(f, V(+xo, +by + z, f)));
            p = _write(p, _face_vec(f, V(+bx + xo, +by + z, f)));
            p = _write(p, _face_vec(f, V(+xo, -by + o, f)));
            p = _write(p, _face_vec(f, V(+bx + xo, -by + o, f)));
            xo += bx;
        }

        double yo = by;
        for(GLuint y = 1; y != dy; ++y) {
            yo += hy;
            xo = z;
            for(GLuint x = 0; x != dx; ++x) {
                xo += bx;
                p = _write(p, _face_vec(f, V(+xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +by + yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +by + yo, f)));
                xo += hx;
            }
            yo += by;
        }

        yo = by;
        for(GLuint y = 1; y != dy; ++y) {
            yo += hy;
            xo = z;
            for(GLuint x = 0; x != dx; ++x) {
                xo += bx;
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +by + yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +by + yo, f)));
                xo += hx;
            }
            yo += by;
        }

        yo = by;
        for(GLuint y = 0; y != dy; ++y) {
            xo = bx;
            for(GLuint x = 0; x != dx; ++x) {
                p = _write(p, _face_vec(f, V(+xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +hy + yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +hy + yo, f)));

                p = _write(p, _face_vec(f, V(+xo, +hy + yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +hy + yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, f)));

                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +hy + yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, f)));

                p = _write(p, _face_vec(f, V(+hx + xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+hx + xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +yo, f)));
                p = _write(p, _face_vec(f, V(+xo, +yo, f)));
                xo += hx + bx;
            }
            yo += hy + by;
        }
    }
    assert(p == dest.end());
    return dest;
}

OGLPLUS_LIB_FUNC
Cage::IndexArray Cage::Indices(Cage::Default) const {
    IndexArray indices(_index_count(), _pri());
    auto i = indices.begin();

    GLuint offs = 0;

    for(GLuint f = 0; f != 6; ++f) {
        for(GLuint v = 0; v != 10; ++v) {
            *i++ = offs + v % 8;
        }

        offs += 8;
        // end of strip
#ifdef GL_PRIMITIVE_RESTART
        ++i;
#else
        *i++ = offs - 1;
        *i++ = offs;
#endif

        GLuint dx = _face_divs(f, 0);
        for(GLuint s = 0; s != 2; ++s) {
            for(GLuint x = 1; x != dx; ++x) {
                for(GLuint v = 0; v != 4; ++v)
                    *i++ = offs + v;
                offs += 4;
                // end of strip
#ifdef GL_PRIMITIVE_RESTART
                ++i;
#else
                *i++ = offs - 1;
                *i++ = offs;
#endif
            }
        }

        GLuint dy = _face_divs(f, 1);
        for(GLuint s = 0; s != 2; ++s) {
            for(GLuint y = 1; y != dy; ++y) {
                for(GLuint x = 0; x != dx; ++x) {
                    for(GLuint v = 0; v != 4; ++v)
                        *i++ = offs + v;
                    offs += 4;
                    // end of strip
#ifdef GL_PRIMITIVE_RESTART
                    ++i;
#else
                    *i++ = offs - 1;
                    *i++ = offs;
#endif
                }
            }
        }

        for(GLuint y = 0; y != dy; ++y) {
            for(GLuint x = 0; x != dx; ++x) {
                for(GLuint s = 0; s != 4; ++s) {
                    for(GLuint w = 0; w != 4; ++w)
                        *i++ = offs + w;
                    offs += 4;
                    // end of strip
#ifdef GL_PRIMITIVE_RESTART
                    ++i;
#else
                    *i++ = offs - 1;
                    *i++ = offs;
#endif
                }
            }
        }
    }
    assert(i == indices.end());
    return indices;
}

OGLPLUS_LIB_FUNC
DrawingInstructions Cage::Instructions(Cage::Default) const {
    DrawOperation operation;
    operation.method = DrawOperation::Method::DrawElements;
    operation.mode = PrimitiveType::TriangleStrip;
    operation.first = 0;
    operation.count = _index_count();
#ifdef GL_PRIMITIVE_RESTART
    operation.restart_index = _pri();
#else
    operation.restart_index = DrawOperation::NoRestartIndex();
#endif
    operation.phase = 0;

    return this->MakeInstructions(operation);
}

} // namespace shapes
} // namespace oglplus
