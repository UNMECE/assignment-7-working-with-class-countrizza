#include <iostream>
#include <cmath>
using namespace std;

class Electric_Field {
private:
    double *E; // [0]=x, [1]=y, [2]=z
public:
    Electric_Field() {
        E = new double[3];
        E[0] = 0; E[1] = 0; E[2] = 0;
    }

    Electric_Field(double Ex, double Ey, double Ez) {
        E = new double[3];
        E[0] = Ex; E[1] = Ey; E[2] = Ez;
    }

    ~Electric_Field() {
        delete[] E;
    }

    // getters / setters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }
    void setX(double v) { E[0] = v; }
    void setY(double v) { E[1] = v; }
    void setZ(double v) { E[2] = v; }
    void set(double Ex, double Ey, double Ez) { E[0]=Ex; E[1]=Ey; E[2]=Ez; }

    // |E|
    double calculateMagnitude() const {
        return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
    }

    // E · E
    double innerProduct() const {
        return E[0]*E[0] + E[1]*E[1] + E[2]*E[2];
    }
};

class Magnetic_Field {
private:
    double *B; // [0]=x, [1]=y, [2]=z
public:
    Magnetic_Field() {
        B = new double[3];
        B[0] = 0; B[1] = 0; B[2] = 0;
    }

    Magnetic_Field(double Bx, double By, double Bz) {
        B = new double[3];
        B[0] = Bx; B[1] = By; B[2] = Bz;
    }

    ~Magnetic_Field() {
        delete[] B;
    }

    // basic setters (getters optional here)
    void set(double Bx, double By, double Bz) { B[0]=Bx; B[1]=By; B[2]=Bz; }

    double calculateMagnitude() const {
        return sqrt(B[0]*B[0] + B[1]*B[1] + B[2]*B[2]);
    }

    // prints unit vector (Bx,By,Bz)/|B|
    void printUnitVector() const {
        double m = calculateMagnitude();
        double ux = (m==0)?0:B[0]/m;
        double uy = (m==0)?0:B[1]/m;
        double uz = (m==0)?0:B[2]/m;
        cout << "(" << ux << ", " << uy << ", " << uz << ")";
    }
};

int main() {
    // Electric fields
    Electric_Field E_default;                     // default ctor
    Electric_Field E_components(1e5, 10.9, 1.7e2);// 3-component ctor
    Electric_Field E_set;                         // use setters
    E_set.set(3.0, -4.0, 12.0);

    cout << "Electric magnitudes:\n";
    cout << "|E_default| = " << E_default.calculateMagnitude() << "\n";
    cout << "|E_components| = " << E_components.calculateMagnitude() << "\n";
    cout << "|E_set| = " << E_set.calculateMagnitude() << "\n";

    cout << "\nElectric inner products (E·E):\n";
    cout << "E_default: " << E_default.innerProduct() << "\n";
    cout << "E_components: " << E_components.innerProduct() << "\n";
    cout << "E_set: " << E_set.innerProduct() << "\n";

    // Magnetic fields
    Magnetic_Field B_default;
    Magnetic_Field B_components(0.01, -0.02, 0.03);
    Magnetic_Field B_set;
    B_set.set(5.0, 0.0, -12.0);

    cout << "\nMagnetic magnitudes:\n";
    cout << "|B_default| = " << B_default.calculateMagnitude() << "\n";
    cout << "|B_components| = " << B_components.calculateMagnitude() << "\n";
    cout << "|B_set| = " << B_set.calculateMagnitude() << "\n";

    cout << "\nMagnetic unit vectors:\n";
    cout << "B_default: "; B_default.printUnitVector(); cout << "\n";
    cout << "B_components: "; B_components.printUnitVector(); cout << "\n";
    cout << "B_set: "; B_set.printUnitVector(); cout << "\n";

    return 0;
}

