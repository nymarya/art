#ifndef _si_h_
#define _si_h_

#include "common.h"
#include "geometry/point3d.h"
#include "geometry/vector3.h"
#include "includes.h"

namespace art{
    class Primitive; // Forward declaration 

    typedef Vector3 Point3;
    
    class SurfaceInteraction {
        public:
            SurfaceInteraction(){}
            SurfaceInteraction(const Point3 &p,const Vector3&n, const Vector3&wo, float time,
                const Point3& uv, const Primitive *pri )
                :m_p{p}, m_n{n}, m_wo{wo}, m_time{time}, m_uv{uv}, m_primitive{pri}
                {}

            /**
             * @brief Get primitive
             * 
             * @return const Primitive* 
             */
            const Primitive * primitive() const
            {return m_primitive;}

            /**
             * @brief Set primitive
             * 
             * @param pri 
             */
            void primitive(const Primitive *pri)
            {m_primitive = pri;}

            /**
             * @brief Get contact point
             * 
             * @return Point3 
             */
            Point3 p() const {return m_p;}

            /**
             * @brief Set contact point
             * 
             * @param p 
             */
            void p(Point3 p) {m_p = p;}

            /**
             * @brief Get the surface normal
             * 
             * @return Vector3 
             */
            Vector3 n() const {return m_n; }

            /**
             * @brief Set the surface normal
             * 
             * @param n 
             */
            void n( Vector3 n) {m_n = n;}

            /**
             * @brief Get the outgoing direction of light
             * 
             * @return Vector3 
             */
            Vector3 wo() const {return m_wo; }

            /**
             * @brief Set outgoing direction of light
             * 
             * @param n 
             */
            void wo( Vector3 wo) {m_wo = wo;}

            /**
             * @brief Get the parametric coordinate (u,v) 
             * of the hit surface
             * 
             * @return Point3 
             */
            Point3 uv() const {return m_uv; }

            /**
             * @brief Set the parametric coordinate (u,v) 
             * of the hit surface
             * 
             * @param n 
             */
            void uv( Point3 uv) {m_uv = uv;}

            /**
             * @brief Get the time of contact
             * 
             * @return float 
             */
            float time() const {return m_time;}

            /**
             * @brief Set the time of contact
             * 
             * @param t 
             */
            void time( float t) {m_time = t;}

        private:
            Point3 m_p; // Contact point.
            Vector3 m_n; // The surface normal.
            Vector3 m_wo; // Outgoing direction of light, which is -ray.
            float m_time; // Time of contact.
            Point3 m_uv; // Parametric coordinate (u,v) of the hit surface.
            const Primitive *m_primitive=nullptr; // Pointer to the primitive.
        };
}

#endif