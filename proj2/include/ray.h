#ifndef _ray_h_
#define _ray_h_

#include "vector3.h"

namespace art{

    typedef Vector3 Point3;

    /**
     * @brief Class representing a single ray, consisting of a origin point
     * and a direction
     */
    class Ray
    {
    
    public:
        Ray(const Point3& o, const Vector3& d );
        ~Ray() = default;

    private:
        Point3 m_o; //!< origin
        Vector3 m_d; //!< direction

    };

    
}

#endif