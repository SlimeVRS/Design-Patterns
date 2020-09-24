#include <iostream>
#include <string>

typedef int Cable;

class EnchufeEuropeo{
    public:
    virtual int voltage() = 0;
    virtual Cable activo() = 0;
    virtual Cable neutral() = 0;
    virtual Cable tierra() = 0;
};

class EnchufeUSA{
    public:
    virtual int voltage() = 0;
    virtual Cable activo() = 0;
    virtual Cable neutral() = 0;
};

class Enchufe : public EnchufeEuropeo {
    public:
    int voltage(){
        return 200;
    }

    Cable activo(){
        return 1;
    }

    Cable neutral(){
        return -1;
    }

    Cable tierra(){
        return 0;
    }
};

class Adapter : public EnchufeUSA{
    EnchufeEuropeo* enchufe;
    public:
    void conectado(EnchufeEuropeo* outlet){
        enchufe = outlet;
    }

    int voltage(){
        return 110;
    }

    Cable activo(){
        return enchufe->activo();
    }

    Cable neutral(){
        return enchufe->neutral();
    }
};

class PanelElectrico{
    EnchufeUSA* potencia;
    public:
    void conectado(EnchufeUSA* supply){
        potencia = supply;
    }

    void calentamiento(){
        if(potencia->voltage() > 100){
            std::cout << "El panel se quema!" << std::endl;
            return;
        }

        if(potencia->activo() == 1 && potencia->neutral() == -1){
            std::cout << "Todo bien!" << std::endl;
        }
    }
};

int main() {
    Enchufe* enchufe = new Enchufe;
    Adapter* adapter = new Adapter;
    PanelElectrico* panel = new PanelElectrico;

    adapter->conectado(enchufe);
    panel->conectado(adapter);

    panel->calentamiento();

    return 0;
}