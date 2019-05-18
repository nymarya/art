#ifndef _shape_h_
#define _shape_h_

namespace art
{

    class Shape
    {
        public:
            /**
             * @brief Construct a new Shape object
             */
            Shape( std::string name, Material * material );

            /**
             * @brief Destroy the Shape object
             */
            virtual ~Shape(){ }

            /**
             * @brief   check if a ray intersect a primitive
             * 
             * @param r        the ray
             * @param surface  the surface of primitive
             * @return true    if the ray intersect the sphere
             * @return false   if the ray not intersect the sphere
             */
            virtual bool intersect ( const Ray& r,
                                    SurfaceInteraction * surface)
                                    const = 0;
        
            /**
             * @brief  check if a ray intersect a primitive
             * 
             * @param r        the ray 
             * @return true    if the ray intersect the sphere 
             * @return false   if the ray not intersect the sphere
             */
            virtual bool intersect_p( const Ray& r ) const = 0;

            /**
             * @brief Set the name of the shape
             * @param name.
             */
            void set_name ( std::string name );

        protected:
            std::string m_name;
            Material * m_material;
        };
            
} // art

#endif