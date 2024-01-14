#include <iostream>
#include <fstream>

int main()
{
	/*std::cout << "Hello, World!" << std::endl;*/

	// Image

	int image_width = 256;
	int image_height = 256;

	std::ofstream out("image.ppm");


	// Render

	if(!out)
	{
		std::cerr << "Could not open the file for writing.\n";
		return 1;
	}

	out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int h = 0; h < image_height; ++h)
	{
		for (int w = 0; w < image_width; ++w)
		{
			auto r = double(w) / (image_width - 1);
			auto g = double(h) / (image_height - 1);
			auto b = 0;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			out << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}

	out.close();

	return 0;
}