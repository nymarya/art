#ifndef _background_h_
#define _background_h_

#include "color.h"

namespace art{

    class Background
    {
        public:
            /**
             * @brief Constructs background with solid color.
             */
            Background(Color &c);

            /**
             * @brief Constructs background with solid color.
             */
            Background(Color &c1, Color &c2, Color &c3, Color &c4, size_t nx, size_t ny);

            ~Background() = default;

        private:
            /* data */
            std::unique_ptr<component[]> m_pixels;
    
    };
 
}

#endif