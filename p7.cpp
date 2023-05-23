#include <iostream>
#include <string>
using namespace std;

class Producto {
    public:
    Producto(){ }
        Producto(string n, string d, double p){
            this->nombre = n;
            this->descripcion= d;
            this->precio=p;
        }
    string nombre;
    string descripcion;
    double precio;
};

class ProductoBase : virtual public Producto{
    public:
        ProductoBase(){ }
        ProductoBase(string n,string d, double p):Producto(n,d,p){
            this->nombre=n;
            this->descripcion=d;
            this->precio=p;
        }
};
class ProductoFisico: virtual public ProductoBase{
    public:
        double peso;
        double tamaño;
        ProductoFisico(){ }
        ProductoFisico(string n, string d,double p, double w, double _s): ProductoBase(n,d,p), peso(w),tamaño(_s) {};

};

class ProductoDigital : virtual public ProductoBase{
    public:
        string link;
        ProductoDigital(string n, string d, double p, string l)
        : ProductoBase(n,d,p), link(l) { };
    ProductoDigital(){ }

};

class proVenta : virtual public ProductoDigital, virtual public ProductoFisico{
    public:
        proVenta(){}
        proVenta(string n, string d, double p, string l, double w, double t)
        : ProductoDigital(n,d,p,l), ProductoFisico(n,d,p,w,t)
        {
            this->nombre=n;
            this->descripcion=d;
            this->precio=p;
            this->link=l;
            this->peso=w;
            this->tamaño=t;
        }
};

int main(){
    ProductoFisico libro("aaa","bbb",12.33,1.2,121.2);
    ProductoDigital cancion("jaaa","hahsa",0.99,"gaaaa");
    proVenta prod001("nas","frank",0.99,"asass",2.3,12.3);

    cout<<"producto fisico: "<< libro.nombre<<endl;
    cout<<"Descripcion: "<< libro.descripcion<<endl;
    cout<<"producto precio: "<< libro.precio<<endl;
    cout<<"producto peso: "<< libro.peso<<"kg"<<endl;
    cout<<"tamaño: "<< libro.tamaño<<"cm"<<endl;

    cout<<"producto digital: "<< cancion.nombre<<endl;
    cout<<"descripcion: "<< cancion.descripcion<<endl;
    cout<<"precio:"<< cancion.precio<<endl;
    cout<<"Link: "<< cancion.link<<endl;

    cout<<"DESCRIPCION DE VENTA: "<< prod001.descripcion<<endl;
    cout<<"precio: Proventa "<< prod001.precio<<endl;
    cout<<"Link de descarga: "<< prod001.link<<endl;
    cout<<"Peso: "<< prod001.peso<<"kg"<<endl;
    cout<<"Tamaño: "<< prod001.tamaño<<"cm"<<endl;

}
