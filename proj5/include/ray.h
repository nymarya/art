#ifndef _ray_h_
#define _ray_h_

#include "geometry/vector3.h"

#include <limits>
#include <tuple>

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
        Point3 at(component_t t) const;

        
        friend std::ostream& operator<< (std::ostream &os, const Ray &t){
            os << "[o=" << t.m_o <<", d=" << t.m_d << "]";
            return os;
        }

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

        Point3 o() const 
        { return m_o;} 

        Vector3 d() const {return m_d;}

        /**
         * @brief Get tMin
         * 
         * @return float 
         */
        float tMin() const {return m_tMin;}

        /**
         * @brief Get tMax
         * 
         * @return float 
         */
        float tMax() const {return m_tMax;}

        /**
         * @brief Get x and y of the ray.
         * 
         * @param u 
         * @param v 
         */
        std::tuple<float, float> uv() const;

    private:
        Point3 m_o; //!< origin
        Vector3 m_d; //!< direction

        int m_x, m_y;

        // Parameters used for surface equation
        float m_tMin {0.0};
        float m_tMax {std::numeric_limits<float>::max()};

    };

    
}

#endif