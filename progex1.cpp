#include <iostream>

/**
 * Struct containing data for a 3D vector
 */
struct Vector3
{
public:
	/**
	 * X component
	 */
	float x;
	
	/**
	 * Y component
	 */
	float y;
	
	/**
	 * Z component
	 */
	float z;
	
	/**
	 * Constructor
	 * @param newX - New x component
	 * @param newY - New y component
	 * @param newZ - New z component
	 */
	Vector3(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
	
	/**
	 * Constructor
	 */
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
	         ret.x = -x;
		 ret.y = -y;
		 ret.z = -z;	 
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
	
	/**
	 * Task 4: normalized() member function
	 */
	 
	/**
	 * Task 5: add() static member function
	 */
	static Vector3 add(Vector3 a, Vector3 b)
	{
		Vector3 ret;
		return ret;
	}
	
	/**
	 * Task 6: subtract() static member function
	 */
	 
	/**
	 * Task 7: multiply() static member function
	 */
	
	/**
	 * Task 8: dot() static member function
	 */
	
	/**
	 * Task 9: cross() static member function
	 */
	
	/**
	 * Task 10: project() static member function
	 */
	
	/**
	 * Task 11: reflect() static member function
	 */
};

int main()
{
	/**
	 * This line is to test whether you can compile and run this cpp file.
	 * Remove this line when submitting.
	 */
	std::cout << "Hello World!" << std::endl;
	
	/**
	 * Task 12: Read input from standard input, and output
	 * to standard output based on the sample output.
	 */
        Vector3 original (1.0f, -20.0f, 3.0f);
	std::cout << original.x << std::endl;
	std::cout << original.y << std::endl;
	std::cout << original.z << std::endl;
	Vector3 negated = original.negative();
	std::cout << negated.x << std::endl;
	std::cout << negated.y << std::endl;
	std::cout << negated.z << std::endl;
	std::cout << original.magnitude() << std::endl;
	return 0;
}

