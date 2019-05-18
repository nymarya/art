#ifndef _material_h_
#define _material_h_

namespace art{
    class Material
    {
        public:
            Material(std::string name)
            :m_name(name){}

            ~Material();

            /**
             * @brief 
             * 
             * @return std::string 
             */
            std::string name(){ return m_name; }

        private:
            std::string m_name;
    };
    
}

#endif