

namespace targets 
{
// TODO: Insert the code for the alien class here
    class Alien
    {
        private:
        int health {3};
    
        public:
        int x_coordinate {0};
        int y_coordinate {0};
        bool shield {false};
        bool bomb {false};
    
        int get_health()
        {
            return health;
        }

        bool is_alive()
        {
            if(health > 0)
            {
                return true;
            }   
            else
            {
                return false;
            }
        }
    
        bool hit()
        {
            if((is_alive()) & (!shield))
            {
                health = health - 1;
                return true;
            }
            else
            {
                return false;
            }  
        }

        bool teleport(int x_new, int y_new)
        {
            if (!bomb)
            {
                x_coordinate = x_new;
                y_coordinate = y_new;
                return true;
            }
            else
            {
                return false;
            }  
        }

        bool collision_detection(Alien alien)
        {
            if((x_coordinate == alien.x_coordinate) &
                (y_coordinate == alien.y_coordinate))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        Alien(int x, int y)
        {
            x_coordinate = x;
            y_coordinate = y;
        }
    };

}  // namespace targets