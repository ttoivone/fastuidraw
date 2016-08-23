/*!
 * \file shader_code.hpp
 * \brief file shader_code.hpp
 *
 * Copyright 2016 by Intel.
 *
 * Contact: kevin.rogovin@intel.com
 *
 * This Source Code Form is subject to the
 * terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with
 * this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 *
 * \author Kevin Rogovin <kevin.rogovin@intel.com>
 *
 */

#pragma once

#include <fastuidraw/glsl/shader_source.hpp>

namespace fastuidraw
{
  namespace glsl
  {
    namespace code
    {
      /*!
        Construct/returns a ShaderSource value that
        implements the two functions:
        \code
        float
        function_name(in int texel_value,
                      in vec2 texture_coordinate,
                      in int geometry_offset)
        \endcode

        which returns the signed pseudo-distance to the glyph boundary
        for a glyph of type \ref curve_pair_glyph (these glyphs are
        backed by data produced from a \ref GlyphRenderDataCurvePair).
        The value texel_value is value in the texel store from the
        position texture_coordinate (the bottom left for the glyph being
        at Glyph::atlas_location().location() and the top right
        being at that value + Glyph::layout().m_texel_size.
        The value geometry_offset is from Glyph::geometry_offset().

        \param alignment alignment of the backing geometry store,
                         GlyphAtlasGeometryBackingStoreBase::alignment().
        \param function_name name for the function
        \param geometry_store_fetch the macro function (that returns a vec4)
                                    to use in the produced GLSL code to fetch
                                    the geometry store data.
        \param derivative_function if true, give the GLSL function with the
                                   argument signature (in int, in vec2, in int, out vec2)
                                   where the last argument is the gradient of
                                   the function with repsect to texture_coordinate.
       */
      ShaderSource
      glsl_curvepair_compute_pseudo_distance(unsigned int alignment,
                                             const char *function_name,
                                             const char *geometry_store_fetch,
                                             bool derivative_function = false);
    }
  }
}
