#ifndef _background_h_
#define _background_h_

#include<memory> //unique_ptr

#include "common.h"
#include "color.h"

namespace art{

    class Background
    {
        public:
            /**
             * @brief Constructs background with solid color.
             */
            Background(Color &c, size_t, size_t);

            /**
             * @brief Constructs background with solid color.
             */
            Background(Color &c1, Color &c2, Color &c3, Color &c4, size_t nx, size_t ny);

            ~Background() = default;

            component* pixels() const;

            size_t width() const;

            size_t height() const;

            void pixel( size_t x, size_t y, Color &c);

        private:
            /* data */
            std::unique_ptr<component[]> m_pixels;

            size_t m_width, m_height;
    
    };
 
}

#endif