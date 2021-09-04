#include <iostream>
#include <cstdio>
#include <cmath>
/**
 * Struct containing data for a 3D vector
 */
struct Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}

	Vector3()
		: Vector3(0.0f, 0.0f, 0.0f)
	{
	}
	
	/**
	 * Task 1: negative() member function
	 */
	 Vector3 negative()
	 {
		 Vector3 ret;
		 ret.x = x != 0 ? -x : x;
		 ret.y = y != 0 ? -y : y;
		 ret.z = z != 0 ? -z : z;
		 return ret;
	 }
	
	/**
	 * Task 2: magnitude() member function
	 */
	float magnitude() {
		float inside = pow(x, 2) + pow(y, 2) + pow(z, 2); 
		return sqrt(inside);

	}
	 
	/**
	 * Task 3: squaredMagnitude() member function
	 */
	float squaredMagnitude() {
		return pow(magnitude(), 2);
	}
	
	/**
	 * Task 4: normalized() member function
	 */
	Vector3 normalized() 
	{
		float mag = magnitude();
		Vector3 normalizedVec; 
		if (mag > 0) {
			normalizedVec.x = x / mag;
			normalizedVec.y = y / mag;
			normalizedVec.z = z / mag;
		}
		return normalizedVec;
	}

	 
	/**
	 * Task 5: add() static member function
	 */
	static Vector3 add(Vector3 a, Vector3 b)
	{
		Vector3 ret;
		ret.x = a.x + b.x;
		ret.y = a.y + b.y;
		ret.z = a.z + b.z;
		return ret;
	}
	
	/**
	 * Task 6: subtract() static member function
	 */
	 static Vector3 subtract(Vector3 a, Vector3 b) 
     {

		 Vector3 ret;
		 Vector3 negatedb = b.negative();
		 ret.x = a.x + negatedb.x;
		 ret.y = a.y + negatedb.y;
		 ret.z = a.z + negatedb.z;
		 return ret;
	 }
	/**
	 * Task 7: multiply() static member function
	 */
	 static Vector3 multiply(Vector3 vec, float scalar) 
	 {

		 Vector3 ret;
		 ret.x = vec.x * scalar;
		 ret.y = vec.y * scalar;
		 ret.z = vec.z * scalar;
		 return ret;
	 }
	/**
	 * Task 8: dot() static member function
	 */
	
	 static float dot(Vector3 a, Vector3 b) 
	 {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	 }
	/**
	 * Task 9: cross() static member function
	 */
	 static Vector3 cross(Vector3 a, Vector3 b)
	 {
		Vector3 ret;
		float cx = (a.y * b.z) - (a.z * b.y);
		float cy = (a.z * b.x) - (a.x * b.z);
		float cz = (a.x * b.y) - (a.y * b.x);
		ret.x = cx;
		ret.y = cy;
		ret.z = cz;
		return ret;
	 }
	
	/**
	 * Task 10: project() static member function
	 */
	 // proj_b a 
	 static Vector3 project(Vector3 a, Vector3 b) {
		float dotProduct = Vector3::dot(a, b);
		float squaredMagnitudeOfB = b.squaredMagnitude();
		float quotient = dotProduct / squaredMagnitudeOfB;
		return Vector3::multiply(b, quotient);
	 }
	
	/**
	 * Task 11: reflect() static member function
	 */
	 // R = i - 2 * (proj of i onto n)
	 // b = normal 
	 // a = incidence vector
	 static Vector3 reflect(Vector3 a, Vector3 b)
	 {
		 Vector3 projectionOfAOntoB = Vector3::project(a, b);
		 Vector3 projectedVectorTimes2 = Vector3::multiply(projectionOfAOntoB, 2);
		 return Vector3::subtract(a, projectedVectorTimes2);
	 }
};

int main()
{
	
	/**
	 * Task 12: Read input from standard input, and output
	 * to standard output based on the sample output.
	 */
	float scalar_v;
	Vector3 a;
	Vector3 b;
    scanf("%f %f %f %f %f %f %f", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z, &scalar_v);
	printf("A = (%.f, %.f, %.f)\n", a.x, a.y, a.z);
	printf("B = (%.f, %.f, %.f)\n", b.x, b.y, b.z);
	printf("S = %.f\n", scalar_v);

	Vector3 negatedA = a.negative();
	Vector3 negatedB = b.negative();
	printf("-A = (%.f, %.f, %.f)\n", negatedA.x, negatedA.y, negatedA.z);
	printf("-B = (%.f, %.f, %.f)\n", negatedB.x, negatedB.y, negatedB.z);

	printf("Squared magnitude of A = %.f\n", a.squaredMagnitude());
	printf("Magnitude of A = %.5f\n", a.magnitude());
	printf("Squared magnitude of B = %.f\n", b.squaredMagnitude());
	printf("Magnitude of B = %.5f\n", b.magnitude());

	Vector3 normalizedA = a.normalized();
	Vector3 normalizedB = b.normalized();

	printf("A normalized = (%.6f, %.6f, %.6f)\n", normalizedA.x, normalizedA.y, normalizedA.z);
	printf("B normalized = (%.6f, %.6f, %.6f)\n", normalizedB.x, normalizedB.y, normalizedB.z);

	Vector3 sum = Vector3::add(a, b);
	printf("A + B = (%.f, %.f, %.f)\n", sum.x, sum.y, sum.z);

	Vector3 difference = Vector3::subtract(a, b);
	printf("A + B = (%.f, %.f, %.f)\n", difference.x, difference.y, difference.z);

	Vector3 product = Vector3::multiply(a, scalar_v);
	printf("A * S = (%.f, %.f, %.f)\n", product.x, product.y, product.z);

	float dotProduct = Vector3::dot(a, b);
	printf("A dot B = %.f\n", dotProduct);

	Vector3 crossProduct = Vector3::cross(a, b);
	printf("A cross B = (%.f, %.f, %.f)\n", crossProduct.x, crossProduct.y, crossProduct.z);

	Vector3 projectionOfAOntoB = Vector3::project(a, b);
	printf("Projection of A onto B = (%.5f, %.5f, %.5f)\n", projectionOfAOntoB.x, projectionOfAOntoB.y, projectionOfAOntoB.z);

	Vector3 reflectionOfAAlongB = Vector3::reflect(a, b);
	printf("Reflection of A along B = (%.5f, %.5f, %.5f)\n", reflectionOfAAlongB.x, reflectionOfAAlongB.y, reflectionOfAAlongB.z);

	return 0;

}

