#include <iostream>
#include <string>

/*Este es un ejemplo de Builder
Se hará un carrp con las siguientes partes:
- Llantas
- Motor
- Chasis

Y por último, se construirá uno, literlamente*/

class Llanta {
    public:
    int tamano;
};

class Motor{
    public:
    int caballosFuerza;
};

class Chasis{
    public:
    std::string forma;
};

class Carro{
    public:
    Llanta* llanta[4]; //tamano de llantas
    Motor* motor;
    Chasis* chasis;

    void caracteristicas(){
        std::cout << "Chasis: " << chasis->forma << std::endl;
        std::cout << "Poder del motor: " << motor->caballosFuerza << std::endl;
        std::cout << "tamano de llantas: " << llanta[0]->tamano << std::endl;
    }
};

class Builder {
    public:
    virtual Llanta* getLlanta() = 0;
    virtual Motor* getMotor() = 0;
    virtual Chasis* getChasis() = 0;
};

class Director{
    Builder* builder;

    public:
    void setBuilder(Builder* newBuilder){
        builder = newBuilder;
    }

    Carro* getCarro(){
        Carro* carro = new Carro();

        carro->chasis = builder->getChasis();
        carro->motor = builder->getMotor();
        
        carro->llanta[0] = builder->getLlanta();
        carro->llanta[1] = builder->getLlanta();
        carro->llanta[2] = builder->getLlanta();
        carro->llanta[3] = builder->getLlanta();

        return carro;
    }
};

class Carro1 : public Builder{
    public:
    Llanta* getLlanta(){
        Llanta* llanta = new Llanta();
        llanta->tamano = 10;
        return llanta;
    }

    Motor* getMotor(){
        Motor* motor = new Motor();
        motor->caballosFuerza = 100;
        return motor;
    }

    Chasis* getChasis(){
        Chasis* chasis = new Chasis();
        chasis->forma = "rectangulo";
    }
};

int main(){
    Carro* carro;
    Director director;
    Carro1 carro1;

    std::cout << "Construyendo..." << std::endl;
    director.setBuilder(&carro1);
    carro = director.getCarro();
    carro->caracteristicas();
    
    return 0;
}
