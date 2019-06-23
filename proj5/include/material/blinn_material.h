#ifndef _blinn_material_h_
#define _blinn_metrial_h_

#include "../common.h"
#include "material.h"
#include "../geometry/vector3.h"

namespace art{
    class BlinnMaterial : public Material
    {
        public:
            BlinnMaterial(Vector3 ka, Vector3 kd, Vector3 s, real_t g, std::string name)
            :Material(name), m_ka(ka), m_kd(kd), m_s(s), m_g(g){}

            ~BlinnMaterial() = default;

            /**
             * @brief Get the ambient coefficient
             * 
             * @return Vector3 
             */
            Vector3 ka();

            /**
             * @brief Set the ambient coefficient.
             * 
             * @param ka 
             */
            void ka(Vector3 ka);

            /**
             * @brief Get the diffuse coefficient
             * 
             * @return Vector3 
             */
            Vector3 kd();

            /**
             * @brief Set the diffuse coefficient.
             * 
             * @param kd 
             */
            void kd(Vector3 kd);

            /**
             * @brief Get the specular coefficient.
             * 
             * @return Vector3 
             */
            Vector3 s();

            /**
             * @brief Set the specular coefficient.
             * 
             * @param s 
             */
            void s(Vector3 s);

            /**
             * @brief Get glossiness exponent.
             * 
             * @return real_t 
             */
            real_t g();

            /**
             * @brief Set glossiness exponent
             * 
             */
            void g( real_t g );

        private:
            Vector3 m_ka; // ambient coefficient
            Vector3 m_kd; // diffuse coefficient
            Vector3 m_s;  // specular coefficient
            real_t m_g;   // glossiness exponent
    };

    
}

#endif