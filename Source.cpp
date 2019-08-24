/*
"Disofenix 117"
Diego Esteban Suarez C.		1201689
Universidad Militar Nueva Granada
2019
*/

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Math.h>
#include <stdlib.h> 
#define PI 3.14159265



using Eigen::Matrix4f;
using Eigen::Vector4f;


using namespace std;
using namespace Eigen;


int main(int argc, char ** argv)
{
	bool index = true;
	int opc1;
	float tx = 1, ty = 1, tz = 1, sx = 0, sy = 0, sz = 0, ang, alpha = 0, beta = 0, gamma = 0, Vm, a, b, c, d;
	float conversion = PI / 180;
	char eje;
	Matrix4f MTrans, MTransO,  MEscal, MRotX, MRotY, MRotZ,Mr;
	Vector4f V, U, Ux,Uy,Uz, vectorI, vectorF, puntoE, PuntoI, PuntoF;
	Ux << 1, 0, 0, 1;
	Uy << 0, 1, 0, 1;
	Uz << 1, 0, 1, 1;

	vectorI << 0, 0, 0, 1;
	vectorF << 0, 0, 0, 1;
	PuntoI << 0, 0, 0, 1;
	PuntoF << 0, 0, 0, 1;
	V << 0, 0, 0, 1;
	U << 0, 0, 0, 1;

	do
	{
		cout << "\t\t . . : : TRANSFORMACION DE UN VECTOR : : . ." << endl;
		cout << "1. Transladar Vector." << endl;
		cout << "2. Escalar Vector." << endl;
		cout << "3. Rotar Vector." << endl;
		cout << "4. Rotar Vector en ejes paralelos." << endl;
		cout << "5. Rotar Vector en eje arbitrario." << endl;
		cout << "0. Salir." << endl;
		cin >> opc1;
		system("cls");
		switch (opc1)
		{
		case 1://transladar vector
		{
			cout << "Ingrese el vector que quiere transladar: " << endl;
			cout << "X: "; cin >> vectorI[0];
			cout << "Y: "; cin >> vectorI[1];
			cout << "Z: "; cin >> vectorI[2];
			cout << "Ingrese el punto donde lo quiere transladar: " << endl;
			cout << "Coordenada en X: "; cin >> tx;
			cout << "Coordenada en Y: "; cin >> ty;
			cout << "Coordenada en Z: "; cin >> tz;
			MTrans << 1, 0, 0, tx,
				0, 1, 0, ty,
				0, 0, 1, tz,
				0, 0, 0, 1;
			vectorF = MTrans * vectorI;
			cout << "el vector final es:\n" << vectorF << endl;
			break;
		}
		case 2://escalar vector
		{
			cout << "Ingrese el vector que quiere escalar: " << endl;
			cout << "X: "; cin >> vectorI[0];
			cout << "Y: "; cin >> vectorI[1];
			cout << "Z: "; cin >> vectorI[2];
			cout << "Ingrese el vector de escalamiento: " << endl;
			cout << "Escala en X: "; cin >> sx;
			cout << "Escala en Y: "; cin >> sy;
			cout << "Escala en Z: "; cin >> sz;
			MEscal << sx, 0, 0, 0,
				0, sy, 0, 0,
				0, 0, sz, 0,
				0, 0, 0, 1;
			vectorF = MEscal * vectorI;
			cout << "el vector final es:\n" << vectorF << endl;
			break;
		}
		case 3://rotar vector
		{
			cout << "Ingrese el vector que quiere rotar:" << endl;
			cout << "X: "; cin >> vectorI[0];
			cout << "Y: "; cin >> vectorI[1];
			cout << "Z: "; cin >> vectorI[2];
			cout << "Ingrese el ángulo de rotacion:"; cin >> ang;
			cout << "Sobre que eje quiere rotar el vector?: ";
			cin >> eje;
			switch (eje)
			{
			case 'x':
			case 'X':
			{
				alpha = ang;
				MRotX << 1, 0, 0, 0,
					0, cosf(alpha*conversion), -sinf(alpha*conversion), 0,
					0, sinf(alpha*conversion), cosf(alpha*conversion), 0,
					0, 0, 0, 1;
				vectorF = MRotX * vectorI;
				cout << "el vector final es:\n" << vectorF << endl;
				break;
			}
			case 'y':
			case 'Y':
			{
				beta = ang;
				MRotY << cosf(beta*conversion), 0, sinf(beta*conversion), 0,
					0, 1, 0, 0,
					-sinf(beta*conversion), 0, cosf(beta*conversion), 0,
					0, 0, 0, 1;
				vectorF = MRotY * vectorI;
				cout << "el vector final es:\n" << vectorF << endl;
				break;
			}
			case 'z':
			case 'Z':
			{
				gamma = ang;
				MRotZ << cosf(gamma*conversion), -sinf(gamma*conversion), 0, 0,
					sinf(gamma*conversion), cosf(gamma*conversion), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1;
				vectorF = MRotZ * vectorI;
				cout << "el vector final es: \n" << vectorF << endl;
				break;
			}
			default:
			{
				cout << "esa opcion no existe!" << endl;
				break;
			}
			break;
			}
			break;
		}
		case 4://transladar vector en ejes paralelos
		{
			cout << "Ingrese el vector que quiere rotar:" << endl;
			cout << "X: "; cin >> vectorI[0];
			cout << "Y: "; cin >> vectorI[1];
			cout << "Z: "; cin >> vectorI[2];
			cout << "Ingrese el ángulo de rotacion:"; cin >> ang;
			cout << "Punto por donde pasa el eje paralelo:" << endl;
			cout << "X: "; cin >> puntoE[0];
			cout << "Y: "; cin >> puntoE[1];
			cout << "Z: "; cin >> puntoE[2];
			cout << "Sobre que eje paralelo quiere rotar el vector?: ";
			cin >> eje;
			switch (eje)
			{
			case 'x':
			case 'X':
			{
				alpha = ang;
				MTransO << 1, 0, 0, 0,
					0, 1, 0, -puntoE[1],
					0, 0, 1, -puntoE[2],
					0, 0, 0, 1;
				MRotX << 1, 0, 0, 0,
					0, cosf(alpha*conversion), -sinf(alpha*conversion), 0,
					0, sinf(alpha*conversion), cosf(alpha*conversion), 0,
					0, 0, 0, 1;
				
				vectorF = MTrans.inverse() * MRotX* MTransO* vectorI;
				cout << "el vector final es:\n" << vectorF << endl;
				break;
			}
			case 'y':
			case 'Y':
			{
				beta = ang;
				MTransO << 1, 0, 0, -puntoE[0],
					0, 1, 0, 0,
					0, 0, 1, -puntoE[2],
					0, 0, 0, 1;
				MRotY << cosf(beta*conversion), 0, sinf(beta*conversion), 0,
					0, 1, 0, 0,
					-sinf(beta*conversion), 0, cosf(beta*conversion), 0,
					0, 0, 0, 1;
				
				vectorF = MTrans.inverse() * MRotY* MTransO* vectorI;
				cout << "el vector final es:\n" << vectorF << endl;
				break;
			}
			case 'z':
			case 'Z':
			{
				gamma = ang;
				MTransO << 1, 0, 0, -puntoE[0],
					0, 1, 0, -puntoE[1],
					0, 0, 1, 0,
					0, 0, 0, 1;
				MRotZ << cosf(gamma*conversion), -sinf(gamma*conversion), 0, 0,
					sinf(gamma*conversion), cosf(gamma*conversion), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1;
				vectorF = MTrans.inverse() * MRotZ* MTransO* vectorI;

				cout << "el vector final es: \n" << vectorF << endl;
				break;
			}
			default:
			{
				cout << "esa opcion no existe!" << endl;
				break;
			}
			break;
			}
			break;
		}
		case 5://transladar vector en eje arbitrario(E,O,C)
		{

			cout << "1. Version estandar." << endl;
			cout << "2. Version optima." << endl;
			cout << "3. Version cuaterniones." << endl;
			cin >> opc1;
			system("cls");
			switch (opc1)
			{
			case 1:
			{
				cout << "Ingrese el Punto que quiere transladar:" << endl;
				cout << "X: "; cin >> vectorI[0];
				cout << "Y: "; cin >> vectorI[1];
				cout << "Z: "; cin >> vectorI[2];
				cout << "Ingrese los puntos por donde pasa el eje Arbitrario" << endl;
				cout << "Punto Inicial:" << endl;
				cout << "X: "; cin >> PuntoI[0];
				cout << "Y: "; cin >> PuntoI[1];
				cout << "Z: "; cin >> PuntoI[2];
				cout << "Punto Final:" << endl;
				cout << "X: "; cin >> PuntoF[0];
				cout << "Y: "; cin >> PuntoF[1];
				cout << "Z: "; cin >> PuntoF[2];

				cout << "Ingrese el ángulo de rotacion:"; cin >> ang;

				V = PuntoF - PuntoI;
				V[3] = 1;
				Vm = sqrt(pow(V(0), 2) + pow(V(1), 2) + pow(V(2), 2));
				U[0] = V[0] / Vm;
				U[1] = V[1] / Vm;
				U[2] = V[2] / Vm;


				a = U[0]; b = U[1]; c = U[2]; d = sqrt(pow(b, 2) + pow(c, 2));
				cout << "a " ;
				cout << a << endl;
				cout << "b " ;
				cout << b << endl;
				cout << "c " ;
				cout << c << endl;
				cout << "d " ;
				cout << d << endl;
				cout << "Vm " ;
				cout << Vm << endl;


				MTrans << 1, 0, 0, -PuntoI[0],
					0, 1, 0, -PuntoI[1],
					0, 0, 1, -PuntoI[2],
					0, 0, 0, 1;

				cout << "\nMatriz Translacion" << endl;
				cout << MTrans << endl;

				MRotX << 1, 0, 0, 0,
					0, c / d, -b / d, 0,
					0, b / d, c / d, 0,
					0, 0, 0, 1;

				cout << "\nMatriz Rotacion X" << endl;
				cout << MRotX << endl;

				MRotY << d, 0, -a, 0,
					0, 1, 0, 0,
					a, 0, d, 0,
					0, 0, 0, 1;

				cout << "\nMatriz Rotacion Y" << endl;
				cout << MRotY << endl;

				MRotZ << cosf(ang*conversion), -sinf(ang*conversion), 0, 0,
					sinf(ang*conversion), cosf(ang*conversion), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1;

				cout << "\nMatriz rotacion Z" << endl;
				cout << MRotZ << endl;

				cout << "\nMatriz rotacion Y Inversa" << endl;
				cout << MRotY.inverse() << endl;
				cout << "\nMatriz rotacion X Inversa" << endl;
				cout << MRotX.inverse() << endl;
				cout << "\nMatriz Translacion Inversa" << endl;
				cout << MTrans.inverse() << endl;

				vectorF = MTrans.inverse() * MRotX.inverse()*MRotY.inverse()*MRotZ*MRotY*MRotX*MTrans*vectorI;

				cout << "el vector final es:\n" << vectorF << endl;

				break;
			}
			case 2:
			{
				cout << "Ingrese el Punto que quiere transladar:" << endl;
				cout << "X: "; cin >> vectorI[0];
				cout << "Y: "; cin >> vectorI[1];
				cout << "Z: "; cin >> vectorI[2];
				cout << "Ingrese los puntos por donde pasa el eje Arbitrario" << endl;
				cout << "Punto Inicial:" << endl;
				cout << "X: "; cin >> PuntoI[0];
				cout << "Y: "; cin >> PuntoI[1];
				cout << "Z: "; cin >> PuntoI[2];
				cout << "Punto Final:" << endl;
				cout << "X: "; cin >> PuntoF[0];
				cout << "Y: "; cin >> PuntoF[1];
				cout << "Z: "; cin >> PuntoF[2];
				cout << "Ingrese el ángulo de rotacion:"; cin >> ang;

				V = PuntoF - PuntoI;
				V[3] = 1;
				Vm = sqrt(pow(V(0), 2) + pow(V(1), 2) + pow(V(2), 2));
				U[0] = V[0] / Vm;
				U[1] = V[1] / Vm;
				U[2] = V[2] / Vm;

				Matrix4f Rc,RcD;
				Vector4f UpZ, UpY, UpX;
				float Mu;
				UpX << 0, 0, 0, 1;
				UpZ << 0, 0, 0, 1;
				UpY << 0, 0, 0, 1;

				UpZ = U;
				UpY[0] = (U[1]*Ux[2])-(Ux[1]*U[2]);
				UpY[1] = -((U[0] * Ux[2]) - (Ux[0] * U[2]));
				UpY[2] = (U[0] * Ux[1]) - (Ux[0] * U[1]);

				Mu= sqrt(pow(UpY(0), 2) + pow(UpY(1), 2) + pow(UpY(2), 2));
				UpY[0] = UpY[0] / Mu;
				UpY[1] = UpY[1] / Mu;
				UpY[2] = UpY[2] / Mu;

				UpX[0] = (UpY[1] * UpZ[2]) - (UpZ[1] * UpY[2]);
				UpX[1] = -((UpY[0] * UpZ[2]) - (UpZ[0] * UpY[2]));
				UpX[2] = (UpY[0] * UpZ[1]) - (UpZ[0] * UpY[1]);
				cout << "U'X:" << endl;
				cout << UpX << endl;
				cout << "U'Y:" << endl;
				cout << UpY << endl;
				cout << "U'Z:" << endl;
				cout << UpZ << endl;

				MTrans << 1, 0, 0, -PuntoI[0],
					0, 1, 0, -PuntoI[1],
					0, 0, 1, -PuntoI[2],
					0, 0, 0, 1;
				Rc << UpX[0], UpX[1], UpX[2], 0,
					UpY[0], UpY[1], UpY[2], 0,
					UpZ[0], UpZ[1], UpZ[2], 0,
					0, 0, 0, 1;
				MRotZ << cosf(ang*conversion), -sinf(ang*conversion), 0, 0,
					sinf(ang*conversion), cosf(ang*conversion), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1;
				cout << "\nMatriz translacion" << endl;
				cout << MTrans << endl;
				cout << "\nMatriz rotacion de vectores" << endl;
				cout << Rc << endl;
				cout << "\nMatriz rotacion Z" << endl;
				cout << MRotZ << endl;
				cout << "\nMatriz rotacion de vectores inversa" << endl;
				cout << Rc.inverse() << endl;
				cout << "\nMatriz translacion inversa" << endl;
				cout << MTrans.inverse() << endl;


				vectorF = MTrans.inverse() * Rc.inverse() * MRotZ * Rc * MTrans * vectorI;
				cout << "el vector final es:\n" << vectorF << endl;


				break;
			}
			case 3:
			{
				cout << "Ingrese el Punto que quiere transladar:" << endl;
				cout << "X: "; cin >> vectorI[0];
				cout << "Y: "; cin >> vectorI[1];
				cout << "Z: "; cin >> vectorI[2];
				cout << "Ingrese los puntos por donde pasa el eje Arbitrario" << endl;
				cout << "Punto Inicial:" << endl;
				cout << "X: "; cin >> PuntoI[0];
				cout << "Y: "; cin >> PuntoI[1];
				cout << "Z: "; cin >> PuntoI[2];
				cout << "Punto Final:" << endl;
				cout << "X: "; cin >> PuntoF[0];
				cout << "Y: "; cin >> PuntoF[1];
				cout << "Z: "; cin >> PuntoF[2];

				cout << "Ingrese el ángulo de rotacion:"; cin >> ang;

				V = PuntoF - PuntoI;
				V[3] = 1;
				Vm = sqrt(pow(V(0), 2) + pow(V(1), 2) + pow(V(2), 2));
				U[0] = V[0] / Vm;
				U[1] = V[1] / Vm;
				U[2] = V[2] / Vm;
				a = U[0]; b = U[1]; c = U[2];


				MTrans << 1, 0, 0, -PuntoI[0],
					0, 1, 0, -PuntoI[1],
					0, 0, 1, -PuntoI[2],
					0, 0, 0, 1;

				Mr << pow(a, 2)*(1 - cosf(ang*conversion)) + cosf(ang*conversion), (a*b)*(1 - cosf(ang*conversion)) - (c*sinf(ang*conversion)), (a*c)*(1 - cosf(ang*conversion)) + (b*sinf(ang*conversion)), 0,
					(b*a)*(1 - cosf(ang*conversion)) + (c*sinf(ang*conversion)), pow(b, 2)*(1 - cosf(ang*conversion)) + cosf(ang*conversion), (b*c)*(1 - cosf(ang*conversion)) - (a*sinf(ang*conversion)), 0,
					(c*a)*(1 - cosf(ang*conversion)) - (b*sinf(ang*conversion)), (c*b)*(1 - cosf(ang*conversion)) + (a*sinf(ang*conversion)), pow(c, 2)*(1 - cosf(ang*conversion)) + cosf(ang*conversion), 0,
					0, 0, 0, 1;

				cout << "\nMatriz translacion" << endl;
				cout << MTrans << endl;
				cout << "\nMatriz rotacion de Cuaterniones" << endl;
				cout << Mr << endl;
				cout << "\nMatriz translacion inversa" << endl;
				cout << MTrans.inverse() << endl;

				vectorF = MTrans.inverse()*Mr*MTrans*vectorI;
				cout << "el vector final es:\n" << vectorF << endl;



				break;
			}
			default:
			{
				cout << "esa opcion no existe!" << endl;
				break;
			}
			}
			break;
		}
		case 0://Salir
		{
			index = false;
			break;
		}
		default:
		{
			cout << "esa opcion no existe!" << endl;
			break;
		}
		}

	} while (index == true);
	return 0;
}