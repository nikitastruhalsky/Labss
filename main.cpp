#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>

class Model
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
};

class Bus
{
public:
    int number;
    std::string color;
    std::string size;

    Bus()
    {
        number = 0;
        color = "";
        size = "";
    }

    Bus(int _number, std::string _color, std::string _size)
    {
        number = _number;
        color = _color;
        size = _size;
    }
};

class BusModel : public Model
{
public:
    std::vector<Bus> buses;

    void AddBus(Bus& bus)
    {
        buses.push_back(bus);
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

class Street
{
public:
    std::string streetName;
    int streetNumber;

    Street(std::string& _name, int _streetNumber)
    {
        streetName = _name;
        streetNumber = _streetNumber;
    }
};

class StreetModel : public Model
{
public:
    std::vector<Street> streets;

    void AddStreet(Street& street)
    {
        streets.push_back(street);
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

class Route
{
public:
    Bus bus;
    std::vector<Street> routeStreets;

    Route(Bus& _bus, std::vector<Street>& _routeStreets)
    {
        bus = _bus;
        routeStreets = _routeStreets;
    }
};

class RouteModel : public Model
{
public:
    std::map<int, std::vector<Street>> routes;

    void AddRoute(Route& route)
    {
        routes[route.bus.number] = route.routeStreets;
        notify();
    }

    void RemoveRoute(Bus& bus)
    {
        routes.erase(bus.number);
        notify();
    }
};

class BusController
{
public:
    BusModel busModel;
    BusController(BusModel& _busModel): busModel(_busModel){};

    void AddBus(Bus bus)
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

    void AddStreet(Street street)
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

    void AddRoute(Route route)
    {
        routeModel.AddRoute(route);
    }

    void RemoveRoute(Bus bus)
    {
        routeModel.RemoveRoute(bus);
    }
};

class View
{
public:
    std::string modelAppearance;
    std::function<void(Model*)> updateView = [this](Model* busModel)
    {
        modelAppearance += "foo";
    };
};

class BusView : public View
{
private:
    std::vector<Bus> busModelAppearance;
    BusController& busController;
public:
    BusView(BusController &controller) : busController(controller)
    {
        controller.busModel.subscribe(&updateView);
        for(auto x : busController.busModel.buses)
        {
            busModelAppearance.push_back(x);
        }
    }

    void showData()
    {
        /*for (auto & i : busModelAppearance)
        {
            std::cout << i.number << ' ' << i.color << ' '<< i.size << std::endl;
        }*/
        std::cout << modelAppearance;
    }

    void AddBus(Bus& bus)
    {
        busController.AddBus(bus);
    }

    void RemoveBus(int busNumber)
    {
        busController.RemoveBus(busNumber);
    }
};

class StreetView
{
private:
    std::vector<Street> streetNameAppearance;
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

    void AddStreet(Street& street)
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
    std::map<int, std::vector<Street>> routeAppearance;
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
        routeAppearance = routeModel -> routes;
    };

    void AddRoute(Route& route)
    {
        routeController.AddRoute(route);
    }

    void RemoveRoute(Bus& bus)
    {
        routeController.RemoveRoute(bus);
    }

    RouteView(RouteController& _routeController): routeController(_routeController){};
};


int main()
{
    Bus bus = Bus(11, "a", "b");
    BusModel busModel;
    BusController busController(busModel);
    BusView busView(busController);

    busView.AddBus(bus);
    busView.AddBus(bus);
    busView.AddBus(bus);
    busView.AddBus(bus);

    busView.showData();
    return 0;
}
