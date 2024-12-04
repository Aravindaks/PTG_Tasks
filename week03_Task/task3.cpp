#include <iostream> 

#include <queue> 
#include <ctime>
#include <string> 

using namespace std; 

  

enum EventType  

{ 

    TAP, 

    SWIPE 

}; 

  

class Events  

{ 

public: 

    EventType eventType; 

    int x, y;        

    time_t timestamp;   

  

    Events(EventType type, int xCoord, int yCoord, time_t time) 

        : eventType(type), x(xCoord), y(yCoord), timestamp(time) {} 

}; 

  

void processEvent(const Events& event)  

{ 

    cout << "Timestamp: " << _wctime(&event.timestamp) 

        << "Event Type: "; 

  

    if (event.eventType == TAP)  

    { 

        cout << "Tap at position (" << event.x << ", " << event.y << ") " <<endl; 

    } else if (event.eventType == SWIPE) 

    { 

        cout << "Swipe from position (" << event.x << ", " << event.y << ") "; 

        if (event.x > 0) 

        { 

            cout << "right"<<endl; 

        } else if (event.x < 0) { 

            cout << "left"<<endl; 

        } else if (event.y > 0) { 

            cout << "down"<<endl; 

        } else { 

            cout << "up"<<endl; 

        } 

    } 

} 

  

  

void simulateEvents(queue<Events>& eventQueue) 

{ 

    const int numEvents = 5; 

  

    for (int i = 0; i < numEvents; ++i)  

    { 

        EventType eventType = (rand() % 2 == 0) ? TAP : SWIPE; 

        int x = rand() % 200 - 100;   

        int y = rand() % 200 - 100;   

        time_t timestamp = time(nullptr);

  

        

        eventQueue.push(Events(eventType, x, y, timestamp)); 

    } 

} 

  

int main()  

{ 

    queue<Events> eventQueue; 

    simulateEvents(eventQueue); 

    while (!eventQueue.empty())  

    { 

        Events event = eventQueue.front(); 

        eventQueue.pop();   

         processEvent(event);   

    } 

  

    return 0; 

} 