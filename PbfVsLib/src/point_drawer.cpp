//
//  point_drawer.cpp
//  PBF
//
//  Created by Ye Kuang on 3/30/17.
//  Copyright © 2017 Ye Kuang. All rights reserved.
//

#include "../include/point_drawer.h"

namespace pbf {
namespace {
    // One octahedron has 6 vertices and 8 faces. Each vertex stores
    // its (position, color), which requires 6 GLfloats.Therefore,
    // each vertex is associated with 6 * 6 = 36 GLfloats
    // and 8 * 3 = 24 GLuints.
    enum { VERTEX_DATA_PER_POINT = 36u, INDEX_DATA_PER_POINT = 24u };
    
    typedef glm::vec3 vec3;
    
    std::vector<vec3> GetVertexOffsets_(float size) {
        std::vector<vec3> result = {
            vec3{0.0f, size, 0.0f},     // 0 top
            vec3{-size, 0.0f, 0.0f},    // 1 left
            vec3{0.0f, 0.0f, size},     // 2 front
            vec3{size, 0.0f, 0.0f},     // 3 right
            vec3{0.0f, 0.0f, -size},    // 4 back
            vec3{0.0f, -size, 0.0f}     // 5 bottom
        };
        
        return result;
    }
} // namespace detail_
    
    void AddPointToDraw(const glm::vec3& pt, std::vector<GLfloat>* vertices, 
        std::vector<GLuint>* /*indices*/, const glm::vec3& color, float size) {
        vertices->push_back(pt[0]);
        vertices->push_back(pt[1]);
        vertices->push_back(pt[2]);

        vertices->push_back(color[0]);
        vertices->push_back(color[1]);
        vertices->push_back(color[2]);
    }
    
    
    void ChangePointToDraw(const glm::vec3& pt, size_t index,
		std::vector<GLfloat>* vertices, const glm::vec3& color, float /*size*/) {
        unsigned vidx = index * 6;
        (*vertices)[vidx] = pt[0];
        (*vertices)[vidx + 1] = pt[1];
        (*vertices)[vidx + 2] = pt[2];
        (*vertices)[vidx + 3] = color[0];
        (*vertices)[vidx + 4] = color[1];
        (*vertices)[vidx + 5] = color[2];
    }
} // namespace pbf
