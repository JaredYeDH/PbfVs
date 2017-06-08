#version 330 core

in vec3 vertex_color;
out vec4 color;

void main()
{
    // compute normal
    vec4 normal;
    normal.xy = gl_PointCoord * 2 - 1.0;
    float r_sqr = dot(normal.xy, normal.xy);
    if (r_sqr > 1.0 - 1e-6) discard;
    normal.z = sqrt(1.0 - r_sqr);
    color = vec4(vertex_color, 1.0f);
}
