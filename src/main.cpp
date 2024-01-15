#include "color.h"
#include "vec3.h"
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
		std::clog << "\rScanlines remaining: " << (image_height - h) << ' ' << std::flush;
		for (int w = 0; w < image_width; ++w)
		{
			auto pixel_color = color(double(w) / (image_width - 1), double(h) / (image_height - 1), 0);
			write_color(out, pixel_color);
		}
	}

	std::clog << "\rDone.					\n";

	out.close();

	return 0;
}