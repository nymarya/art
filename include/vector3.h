#ifndef _vector3_h_
#define _vector_h_

#include "common.h"

typedef float component;

namespace art{

    /// Class representing a tridimensional vector
    class Vector3
    {
        public:
            Vector3(component component1, component component2, component component3);
            ~Vector3() = default;

            /////////////////
            /// Accessors ///
            /////////////////  

            /**
             * @brief Get x coordinate.
             */
            component x() const;
            /**
             * @brief Get y coordinate.
             */
            component y() const;
            /**
             * @brief Get z coordinate.
             */
            component z() const;
            /**
             * @brief Get red intensity.
             */
            component r() const;
            /**
             * @brief Get green intensity.
             */
            component g() const;
            /**
             * @brief Get blue intensity.
             */
            component b() const;    

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
             * @brief Override operator for multiplication with component.
             */
            Vector3& operator*=(const component t);

            /**
             * @brief Override operator for division by component.
             */
            Vector3& operator/=(const component t);

            /**
             * @brief Access element.
             */
            component operator[](int i) const;

            /**
             * @brief Access element and return reference to it.
             */
            component& operator[](int i);

        private:
            /// Content
            component m_components[3];
            
    };

}

#endif