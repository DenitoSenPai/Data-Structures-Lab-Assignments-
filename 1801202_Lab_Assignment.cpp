#include <iostream>
#include <string>

/*
    Dinito Thompson : 1801202
    Lab Assignment #1 
    Some of the questions were rather confusing with regards to implementation. 
*/
// Composition
using namespace std;

class Room
{
private:
    string name;
    int capacity;
public:
    // Constructors don't have a data type.
    Room()
    {
        name = "Test_Name";
        capacity = 0;
    }
    Room(string Name, int Capacity)
    {
        string name = Name;
        int capacity = Capacity;
    }
    Room(Room &p)
    {
        name = p.name;
        capacity = p.capacity;
    }
    void setRoomName(string Name)
    {
        name = Name; 
    }
    void setCapacity(int Capacity)
    {
        capacity = Capacity; 
    }
    string getName()
    {
        return name;
    }
    int getCapacity()
    {
        return capacity;
    }
    void RoomDisplay()
    {
        cout << "Room Detail" << endl;
        cout << "Room Name: " << name << endl;
        cout << "Room Capacity: " << capacity << endl;
    }
    //Destructor
    ~Room()
    {}
};

class SmokeDetector : public Room
{
private:
    Room room[5];
    float threshold;
    float smokeLevel;
    bool soundAlarm;
    int avaiableRoom;
public:
    SmokeDetector()
    {
        threshold = 50.0;
        smokeLevel = 0.0;
        soundAlarm = false;
        avaiableRoom = 5;
    }
    SmokeDetector(float Threshold, float SmokeLevel, bool SoundAlarm, int AvaiableRoom)
    {
        float threshold = Threshold;
        float smokeLevel = SmokeLevel;
        bool soundAlarm = SoundAlarm;
        int avaiableRoom = AvaiableRoom; 
    }
    SmokeDetector (SmokeDetector &p)
    {
        threshold = p.threshold;
        smokeLevel = p.smokeLevel;
        soundAlarm = p.soundAlarm;
        avaiableRoom = p.avaiableRoom; 
    }
    void RoomObject()
    {
    	//Isn't the default constructors called by default when initialized ? : Question 2
        /* 
		I taught this was viable
        room[0].Room("Lab C", 23);
		*/ 
		// Question 2 : A
        room[0].setRoomName("Lab C");
		room[0].setCapacity(23); 
		
        // Question 2 : B 
        //room[0].Room("Lab A", 25)

		room[0].RoomDisplay();   
    }
    int getRoomCount()
    {
        return avaiableRoom; 
    }
    bool addRoomToBeMonitored ()
    {
        int i = 0;
        int useropt;
        string roomName = ""; 
		int roomCapacity=0; 
        if (avaiableRoom == 0)
        {
            cout << "Room Capacity Maxed." << endl;
            return false;
        }
        else do
        {
            cout << "Room: " << i << "/5" << endl;
            cout << "Enter Room Information Below." << endl;
            
            cout << "Enter Room Name: " << endl; 
            cin >> roomName; 
            cout << "Enter Room Capacity: " << endl; 
            cin >> roomCapacity; 
            
            room[i].setRoomName(roomName);
            room[i].setCapacity(roomCapacity);
            room[i].RoomDisplay();
            i++;
            avaiableRoom --;
            cout << "Enter : 0 : Exit" << endl;
            cin >> useropt;
        } while (useropt != 0 || avaiableRoom == 0);
        return true;
    }
    void setThreshold (float thresh)
    {
        threshold = thresh;
        cout << "Current Threshold: " << getThreshold() << endl;
    }
    float getThreshold ()
    {
        return threshold;
    }
    void setSmokeLevel(float SmokeLevel)
    {
        smokeLevel = SmokeLevel; 
    }
    float getSmokeLevel()
    {
        return smokeLevel;
    }
    void resetAlarm()
    {
        soundAlarm = false;
        cout << "Alarm Reset." << endl;
        // Alarm sound would turn off here.
    }
    bool checkAlarm()
    {
        if (smokeLevel > getThreshold())
        {
            soundAlarm = true;
            cout << "Get Out Immediately !" << endl;
            // Alarm sound would turn on here.
            return soundAlarm; 
        }
        else
        {	soundAlarm = false;  
            cout << "Your Safe." << endl;
            return soundAlarm; 
    	}
	}
    void roomDetails()
    {
        int roomNum = 0; 
        cout << "Enter Room Number: " << endl; 
        cin >> roomNum; 
        if (roomNum > avaiableRoom || roomNum < avaiableRoom)
            cout << "Room #: " << roomNum << " : Doesnt Exist" << endl; 
        else
            room[roomNum].RoomDisplay(); 
    }
    void displayAllRooms()
    {
        int i; 
        cout << "'displayAllRooms()' Function. " << endl; 
        for (i = 0; i < avaiableRoom; i++)
        {
            cout << "\n" << "Room #: " << i+1 << endl; 
            room[i].RoomDisplay();             
        }
    }   
    void DetectorDetails()
    {
        cout << "Smoke Detector Details." << endl;
        cout << "Threshold: " << threshold << endl;
        cout << "Smoke Level: " << smokeLevel << endl;
        cout << "Sound Alarm: " << soundAlarm << endl;
    }
    void userOption()
    {
        cout << "Enter : 0 : To Exit Program." << endl;
        cout << "Enter : 1 : Add a New Room. (5 Max Rooms)" << endl;
        cout << "Enter : 2 : Set Threshold." << endl;
        cout << "Enter : 3 : Set Smoke Level." << endl;
        cout << "Enter : 4 : View Smoke Detector Details." << endl;
    }
    ~SmokeDetector()
    {}
};

int main ()
{
    SmokeDetector S;

    //Question 2
    S.RoomObject(); 

    //Question 2 : C
    cout << " \n Question 2 : C" << endl; 
    S.setThreshold(50.0); 
    S.getThreshold();
    
    //Question 3 : Isnt it only 1 smoke detector, monitoring multiple rooms ? 
    
    //Question 4
    cout << "\nQuestion 3" << endl; 
    S.setSmokeLevel(75.0); 
    S.checkAlarm(); 
    
    //Question 4 
    cout << "\nQuestion 4" << endl; 
    S.setSmokeLevel(33.0);
    S.checkAlarm(); 
    
    
    //S.displayAllRooms(); 
    
    return 0;
}
