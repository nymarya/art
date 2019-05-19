#ifndef _ray_h_
#define _ray_h_

#include "geometry/vector3.h"

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

        /**
         * @brief Override operator () 
         */
        Point3 operator()(component_t t) const;

        /**
        friend std::ostream& operator<< (std::ostream &os, const Ray &t){
            os << "[o=" << t.m_o <<", d=" << t.m_d << "]";
            return os;
        }**/

        /**
         * @brief Get the x axis that generated the ray
         * 
         * @return component_t 
         */
        component_t x( void) const;

        /**
         * @brief Set the x axis that generated the ray
         * 
         * @return component_t 
         */
        void x(int x);

        /**
         * @brief Get the y axis that generated the ray
         * 
         * @return component_t 
         */
        component_t y(void) const;

        /**
         * @brief Set the y axis that generated the ray
         * 
         * @return component_t 
         */
        void y( int y );

    private:
        Point3 m_o; //!< origin
        Vector3 m_d; //!< direction

        int m_x, m_y;

    };

    
}

#endif