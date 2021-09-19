#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>

/*class Model
{
public:
    std::vector<std::function<void(Model*)>*> subscribers;

    void subscribe(std::function<void(Model*)>* sub)
    {
        subscribers.push_back(sub);
    }

    void notify()
    {
        for (auto sub: subscribers)
        {
            sub -> operator()(this);
        }
    }
};*/

class BusModel
{
public:

    std::vector<std::function<void(BusModel*)>*> subscribers;

    void subscribe(std::function<void(BusModel*)>* sub)
    {
        subscribers.push_back(sub);
    }

    void notify()
    {
        for (auto sub: subscribers)
        {
            sub -> operator()(this);
        }
    }
    int number;
    std::string color;
    std::string size;
    std::vector<BusModel> buses;

    BusModel()
    {
        number = 0;
        color = "";
        size = "";
    }

    BusModel(int _number, std::string _color, std::string _size)
    {
        number = _number;
        color = _color;
        size = _size;
    }

    void AddBus(BusModel& busModel)
    {
        buses.push_back(busModel);
        notify();
    }

    void RemoveBus(int busNumber)
    {
        for (int i = 0; i < buses.size(); ++i)
        {
            if (buses[i].number == busNumber)
            {
                buses.erase(buses.begin() + i + 1);
            }
        }
        notify();
    }
};

class StreetModel
{
public:
    std::vector<std::function<void(StreetModel*)>*> subscribers;

    void subscribe(std::function<void(StreetModel*)>* sub)
    {
        subscribers.push_back(sub);
    }

    void notify()
    {
        for (auto sub: subscribers)
        {
            sub -> operator()(this);
        }
    }
    std::string streetName;
    int streetNumber;
    std::vector<StreetModel> streets;
    StreetModel(std::string& _name, int _streetNumber)
    {
        streetName = _name;
        streetNumber = _streetNumber;
    }

    void AddStreet(StreetModel& streetModel)
    {
        streets.push_back(streetModel);
        notify();
    }

    void RemoveStreet(std::string& name)
    {
        for (int i = 0; i < streets.size(); ++i)
        {
            if (streets[i].streetName == name)
            {
                streets.erase(streets.begin() + i + 1);
            }
        }
        notify();
    }
};

class RouteModel
{
public:
    std::vector<std::function<void(RouteModel*)>*> subscribers;

    void subscribe(std::function<void(RouteModel*)>* sub)
    {
        subscribers.push_back(sub);
    }

    void notify()
    {
        for (auto sub: subscribers)
        {
            sub -> operator()(this);
        }
    }
    BusModel bus;
    std::vector<StreetModel> routeStreets;
    std::map<int, std::vector<StreetModel>> routes;

    RouteModel(BusModel& _bus, std::vector<StreetModel>& _routeStreets)
    {
        bus = _bus;
        routeStreets = _routeStreets;
    }

    void AddRoute(RouteModel& routeModel)
    {
        routes[routeModel.bus.number] = routeModel.routeStreets;
        notify();
    }

    void RemoveRoute(BusModel& busModel)
    {
        routes.erase(busModel.number);
        notify();
    }
};

class BusController
{
public:
    BusModel busModel;
    BusController(BusModel& _busModel): busModel(_busModel){};

    void AddBus(BusModel bus)
    {
        busModel.AddBus(bus);
    }

    void RemoveBus(int busNumber)
    {
        busModel.RemoveBus(busNumber);
    }
};

class StreetController
{
public:
    StreetModel streetModel;
    StreetController(StreetModel& _streetModel): streetModel(_streetModel){};

    void AddStreet(StreetModel& street)
    {
        streetModel.AddStreet(street);
    }

    void RemoveStreet(std::string streetName)
    {
        streetModel.RemoveStreet(streetName);
    }
};

class RouteController
{
public:
    RouteModel routeModel;
    RouteController(RouteModel& _routeModel): routeModel(_routeModel){};

    void AddRoute(RouteModel route)
    {
        routeModel.AddRoute(route);
    }

    void RemoveRoute(BusModel bus)
    {
        routeModel.RemoveRoute(bus);
    }
};

class BusView
{
private:
    std::vector<BusModel> busModelAppearance;
    BusController& busController;
public:
    void showData()
    {
        for (auto & i : busModelAppearance)
        {
            std::cout << i.number << ' ' << i.color << ' '<< i.size << std::endl;
        }
    }

    std::function<void(BusModel*)> updateView = [this](BusModel* busModel)
    {
        busModelAppearance = busModel -> buses;
    };

    void AddBus(BusModel& bus)
    {
        busController.AddBus(bus);
    }

    void RemoveBus(int busNumber)
    {
        busController.RemoveBus(busNumber);
    }

    BusView(BusController& _busController): busController(_busController){};
};

class StreetView
{
private:
    std::vector<StreetModel> streetNameAppearance;
    StreetController& streetController;
public:
    void showData()
    {
        for (auto & i : streetNameAppearance)
        {
            std::cout << i.streetName << std::endl;
        }
    }

    std::function<void(StreetModel*)> updateView = [this](StreetModel* streetModel)
    {
        streetNameAppearance = streetModel -> streets;
    };

    void AddStreet(StreetModel& street)
    {
        streetController.AddStreet(street);
    }

    void RemoveStreet(std::string& streetName)
    {
        streetController.RemoveStreet(streetName);
    }

    StreetView(StreetController& _streetController): streetController(_streetController){};
};

class RouteView
{
private:
    std::map<int, std::vector<StreetModel>> routeAppearance;
    RouteController& routeController;
public:
    void showData()
    {
        auto it = routeAppearance.begin();
        for (int i = 0; it != routeAppearance.end(); ++it, ++i)
        {
            std::cout << it -> first << " number: " << std::endl;
            for (auto & j : it -> second)
            {
                std::cout << j.streetName << " - " << j.streetNumber << std::endl;
            }
        }
    }

    std::function<void(RouteModel*)> updateView = [this](RouteModel* routeModel)
    {
        routeAppearance = routeModel->routes;
    };

    void AddRoute(RouteModel& routeModel)
    {
        routeController.AddRoute(routeModel);
    }

    void RemoveRoute(BusModel& busNumber)
    {
        routeController.RemoveRoute(busNumber);
    }

    RouteView(RouteController& _routeController): routeController(_routeController){};
};


int main()
{
    BusModel busModel;
    BusController busController(busModel);
    BusView busView(busController);

    BusModel busModel1 = BusModel(11, "a", "b");
    busView.AddBus(busModel1);
    busModel.subscribe(&busView.updateView);

    busView.showData();
    return 0;
}
