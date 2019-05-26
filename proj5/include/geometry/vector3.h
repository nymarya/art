#ifndef _vector3_h_
#define _vector3_h_

#include "../common.h"

#include <math.h>

using component_t = float;

namespace art{

    /// Class representing a tridimensional vector
    class Vector3
    {
        public:
            Vector3():m_components( {0,0,0} ){}
            Vector3(component_t component_t1, component_t component_t2, component_t component_t3);
            ~Vector3() = default;
            
            /////////////////
            /// Accessors ///
            /////////////////  

            /**
             * @brief Get x coordinate.
             */
            component_t x() const;
            /**
             * @brief Get y coordinate.
             */
            component_t y() const;
            /**
             * @brief Get z coordinate.
             */
            component_t z() const;
            /**
             * @brief Get red intensity.
             */
            component_t r() const;
            /**
             * @brief Get green intensity.
             */
            component_t g() const;
            /**
             * @brief Get blue intensity.
             */
            component_t b() const;    

            /////////////////
            /// Operators ///
            /////////////////
            
            /**
             * @brief Override operator for unitary plus.
             */
            const Vector3& operator+() const;

            /**
             * @brief Override operator for unary minus.
             */
            Vector3 operator-() const;

            /**
             * @brief Override operator for sum with another
             * vector.
             */
            Vector3& operator+=(const Vector3 &v2);

            /**
             * @brief Override operator for subtraction with another
             * vector.
             */
            Vector3& operator-=(const Vector3 &v2);

            /**
             * @brief Override operator for multiplication with another
             * vector.
             */
            Vector3& operator*=(const Vector3 &v2);

            /**
             * @brief Override operator for division by another
             * vector.
             */
            Vector3& operator/=(const Vector3 &v2);

            /**
             * @brief Override operator for multiplication with component_t.
             */
            Vector3& operator*=(const component_t t);

            /**
             * @brief Override operator for division by component_t.
             */
            Vector3& operator/=(const component_t t);

            /**
             * @brief Override operator for sum between vectors.
             */
            Vector3 operator+(const art::Vector3 &v2) const;

            /**
             * @brief Override operator for difference between vectors.
             */
            Vector3 operator-(const art::Vector3 &v2);

            /**
             * @brief Override operator for multiplication between vector and scalar.
             */
            Vector3 operator*( const component_t t) const;

            /**
             * @brief Override operator for division between vector and scalar.
             */
            Vector3 operator/( component_t t);

            /**
             * @brief Override operator for division between vector and scalar.
             */
            component_t operator*( const Vector3 &v2);

            /**
             * @brief Access element.
             */
            component_t operator[](int i) const;

            /**
             * @brief Access element and return reference to it.
             */
            component_t& operator[](int i);

            /**
             * @brief Override operator for product between vectors.
             */
            Vector3 cross(const art::Vector3 &v2);

            /**
             * @brief Make unit vector
             */
            Vector3 normalize();

            friend std::ostream& operator<< (std::ostream &os, const Vector3 &t){
                // std::string d1 = static_cast<component_t>(t.m_components[0]);
                // std::string d2 = static_cast<component_t>(t.m_components[1]);
                // std::string d3 = static_cast<component_t>(t.m_components[2]);
                os << "("<< t.m_components[0] << ", " << t.m_components[1] << ", " 
                        << t.m_components[2] << ")";
                return os;
            }

        private:
            /// Content
            component_t m_components[3];
            
    };

}

#endif