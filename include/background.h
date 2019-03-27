#ifndef _background_h_
#define _background_h_

#include<memory> //unique_ptr
#include <stdlib.h> // srand, rand 
#include <cmath>
#include <vector> //vector

#include "vector3.h"
#include "common.h"
#include "color.h"

namespace art{

    class Background
    {
        public:
            /**
             * @brief Constructs background with solid color.
             */
            Background(Color &c, std::string type);

            /**
             * @brief Constructs background with solid color.
             */
            Background(Color &c1, Color &c2, Color &c3, Color &c4, std::string type);

            ~Background() = default;

            void pixel( size_t x, size_t y, Color &c);
            /**
             * @brief Get the pixel color from background.
             */
            Vector3 color(float x, float y);

            /**
             * @brief inter
             */
            Vector3 billinear( float t_x, float t_y);

        private:
            /* data */
            std::vector<Vector3> m_colors;
            std::string m_type;
    
    };
 
}

#endif