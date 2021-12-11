#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define CITIES_COUNT 9

class Sight
{
    private:

        bool m_checked = false;
        int m_weight;
        std::string m_name;

    public:

        Sight(int weight, std::string name) : m_weight(weight), m_name(name)
        {}

        void setChecked()
        {
            m_checked = true;
        }

        bool isChecked() const
        {
            return m_checked;
        }

        int getWeight() const
        {
            return m_weight;
        }

        const std::string& getName() const 
        {
            return m_name;
        }

        friend std::ostream& operator<<(std::ostream& output, const Sight& sight)
        {
            output << sight.m_name;
            return output;
        }
};

void findOptimalPath
                    (
                        std::vector<Sight>& sights,
                        const std::pair<int, int> adjacencyMatrix[CITIES_COUNT][CITIES_COUNT],
                        int source,
                        int& currTime,
                        int& currMoney,
                        const int time,
                        const int money,
                        std::vector<Sight>& optimalPath
                    )
{

    if (sights[source].isChecked()) // recursion condition
    {
       return;
    }

    optimalPath.push_back(sights[source]); // current sight already checked

    std::vector<std::pair<int, int>> adjacentSights; // adjacent sights indexes sorted by weight
    
    for (int j = 0; j < CITIES_COUNT; ++j) // iterate through sights, for finding adjacent sights
    {
        bool timeExist = 0 != adjacencyMatrix[source][j].first;
        bool moneyExist = 0 != adjacencyMatrix[source][j].second;

        if ( timeExist && moneyExist )
        {
            if (!sights[j].isChecked())
            {
                adjacentSights.push_back({sights[j].getWeight(), j});
            }
        }
    }

    std::sort(adjacentSights.begin(), adjacentSights.end()); // sort by weight (first)

    bool isFound = false;
    int adjSight;

    int i = adjacentSights.size() - 1;
    for (; i >= 0; --i)
    {
        adjSight = adjacentSights[i].second;

        int neededTime = adjacencyMatrix[source][adjSight].first;
        int neededMoney = adjacencyMatrix[source][adjSight].second;

        bool isTimeEnough = currTime + neededTime <= time;
        bool isMonyEnough = currMoney + neededMoney <= money;
        
        if ( isTimeEnough && isMonyEnough )
        {
            currTime += neededTime;
            currMoney += neededMoney;

            sights[source].setChecked();
            isFound = true;

            break;
        }
    }

    if (isFound)
    {
        findOptimalPath
                        (     
                            sights,  
                            adjacencyMatrix,
                            adjSight,
                            currTime,
                            currMoney,
                            time,
                            money,
                            optimalPath
                        );
    }
    else
    {
        std::cout << "You are visited " << optimalPath.size() << " sights! Great work!" << std::endl;
        std::cout << "Now you have " << money - currMoney << " USD money and " << time - currTime << " minutes time." << std::endl;
        std::cout << "You spent " << currMoney << " USD money and " << currTime << " minutes time." << std::endl;
    }
}

void advicePath(const int time, const int money, std::vector<Sight>& optimalPath)
{
    std::vector<Sight> sights = 
                                {
                                    Sight( 100, "Garni" ),
                                    Sight( 100, "Gexard" ),
                                    Sight( 100, "Ajdahak" ),
                                    Sight( 40,  "Jot Verq" ),
                                    Sight( 20,  "Surb Nshan" ),
                                    Sight( 25,  "Kecharis" ),
                                    Sight( 15,  "Grigor Lusavorich" ),
                                    Sight( 90,  "Lijq" ),
                                    Sight( 95,  "Tatev" )
                                };

    const std::pair<int, int> adjacencyMatrix[CITIES_COUNT][CITIES_COUNT] = 
    {
        { {0,    0},  {25,  10},  {0,    0},  {180, 40},  {0,     0},  {0,    0},  {0,    0},  {0,    0},  {0,    0} },
        { {25,  10},  {0,    0},  {120, 20},  {0,    0},  {30,   90},  {0,    0},  {0,    0},  {0,    0},  {0,    0} },
        { {0,    0},  {120, 20},  {0,    0},  {0,    0},  {0,     0},  {70,  15},  {0,    0},  {0,    0},  {0,    0} },
        { {180, 40},  {0,    0},  {0,    0},  {0,    0},  {120,  30},  {0,    0},  {120, 20},  {0,    0},  {0,    0} },
        { {0,    0},  {30,  90},  {0,    0},  {120, 30},  {0,     0},  {180, 60},  {0,    0},  {100, 15},  {0,    0} },
        { {0,    0},  {0,    0},  {70,  15},  {0,    0},  {180,  60},  {0,    0},  {0,    0},  {0,    0},  {240, 50} },
        { {0,    0},  {0,    0},  {0,    0},  {120, 20},  {0,     0},  {0,    0},  {0,    0},  {180, 40},  {0,    0} },
        { {0,    0},  {0,    0},  {0,    0},  {0,    0},  {100,  15},  {0,    0},  {180, 40},  {0,    0},  {90,  25} },
        { {0,    0},  {0,    0},  {0,    0},  {0,    0},  {0,     0},  {240, 50},  {0,    0},  {90,  25},  {0,    0} }
    };

    std::cout << "Please enter inital sight name." << std::endl;
    std::string sightName;

    std::cin >> sightName;

    int source = -1;

    for (int i = 0; i < sights.size(); ++i )
    {
        if ( sightName == sights[i].getName()) // try to find entered sight
        {
            source = i;
            break;
        }
    }
    
    if ( -1 != source )
    {
        int currTime = 0;
        int currMoney = 0 ;

        findOptimalPath
                        (       
                            sights,  
                            adjacencyMatrix,
                            source,
                            currTime,
                            currMoney,
                            time,
                            money,
                            optimalPath
                        );
    }
    else 
    {
        std::cout << "You have entered unknown sight name." << std::endl;
    }

}

int main() 
{
    std::cout << "__________Trip adviser!___________" << std::endl;
    std::cout << std::endl;

    std::cout << "Please enter days count that you have." << std::endl;
    std::cout << "Days : ";

    int time;
    std::cin >> time;
    time = time * 24 * 60; // convert days to minutes
 
    std::cout << "Please enter amount of money that you have." << std::endl;
    std::cout << "Money : ";

    int money;
    std::cin >> money;

    std::vector<Sight> optimalPath;

    advicePath(time, money, optimalPath);

    std::cout << "_____________________________________________" << std::endl;

    for (int i = 0; i < optimalPath.size(); ++i)
    {
        std::cout << optimalPath[i];

        if ( optimalPath.size() - 1 != i)
        {
            std::cout << "->";
        } 
    }
    
    std::cout << "_____________________________________________" << std::endl;

    std::cout << std::endl;

    return 0;
} 