#include<iostream>
#include<cmath>

using namespace std;

class Vec{
	private:
		double *v;
		int len;
	
	public:
		Vec(int l, double *int_v){
			len = l;
			v = new double[len];
			for(int i = 0; i < len; i++){
				v[i] = int_v[i];
			}
		}

		Vec(int l){
			len = l;
			v = new double[len];
			for(int i = 0; i < len; i++){
				v[i] = 0;
			}
		}
                
		Vec(const Vec& other){
			len = other.len;
			v = new double[len];
			for(int i = 0; i < len; i++){
				v[i] = other.v[i];
			}
		}

                Vec& operator=(const Vec& a); 
		void set(double arg, int coord);
		double get(int coord) const;
		double euc_norm() const;
		double max_norm() const;
		void print() const;
		~Vec(){
			delete[] v;
		}
};      

Vec& Vec::operator=(const Vec& a)
{
	v = a.v;
	len = a.len;
	return *this;
}
	
void Vec::set(double arg, int coord)
{
	if(coord >= 0 && coord < len){
		v[coord] = arg;
	}
}

double Vec::get(int coord) const {
	if(coord >= 0 && coord < len){
		return v[coord];
	}
	return 0;
}

double Vec::euc_norm() const {
	double sum = 0;
	for(int i = 0; i < len; i++){
                sum += v[i]*v[i];
	}
	return sqrt(sum);
}

double Vec::max_norm() const {
	double max = 0;
	for(int i = 0;i < len; i++){
		double a = fabs(v[i]);
		if(a > max){
			max = a;
		}	
        }
	return max;
}

void Vec::print() const {
	cout << "(";
	for(int i = 0; i < len; i++){
		cout << v[i];
		if(i < len -1){
			cout << ",";
        	}
	}
	cout << ")" << endl;
}



/*
int main(void)
{
    double y1[3] = {1,2,3};
    double y2[5] = {2,1,0,5,7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;

    y.print();
    x.print();
    z.print();
    u.print();

    x.set(23, 2);  u.set(34, 1);  z.set(-3, 3);
    cout << "x[2] = " << x.get(2) << endl;
    cout << "u[1] = " << u.get(1) << endl;
    cout << "euc_norma y: " << y.euc_norm() << endl;
    cout << "max_norma z: " << z.max_norm() << endl;
    return 0;
}
*/