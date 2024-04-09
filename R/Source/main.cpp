#include <iostream>
#include <string>
#include <fstream>
#include "glm/glm.hpp"
#include "ImageWriter.h"
#include "Ray.h"

glm::vec3 ray_color(const Ray& r) {
    glm::vec3 unitDirection = glm::normalize(r.Direction());
    float a = 0.5f * (unitDirection.y + 1.0);
    return (1.0f - a) * glm::vec3 (1.0f, 1.0f, 1.0f) + a * glm::vec3(0.5f, 0.7f, 1.0f);
}

int main() 
{
	 
	// image

	int ImageWidth = 1280;
	int imageHeight = 720;
	float aspectRatio = static_cast<float>(ImageWidth) / imageHeight;


	// Viewport widths less than one are ok since they are real valued.
	float viewportHeight = 2.f;
	float viewportWidth = viewportHeight * aspectRatio;

	glm::vec3 cameraOrigin(0.f, 0.f, 0.f);
	glm::vec3 cameraDirection(0.f, 0.0f, 1.f );

	float focalLength = 1.f;

	glm::vec3 viewportDirectionX(viewportWidth, 0, 0);
	glm::vec3 viewportDirectionY(0, -viewportHeight, 0);

	glm::vec3 deltaX = viewportDirectionX / static_cast<float>(ImageWidth);
	glm::vec3 deltaY = viewportDirectionY / static_cast<float>(imageHeight);

	glm::vec3 viewportTopLeftPixelCenter = cameraOrigin + (cameraDirection * focalLength) - (viewportDirectionY / 2.f) - (viewportDirectionX / 2.f) + (deltaX / 2.f) + (deltaY / 2.f);

	


	ImageWriter image("output/render.ppm", ImageWidth, imageHeight);

	
	std::cout.precision(3);

	for (int j = 0; j < imageHeight; ++j) {
	    std::cout << "progress: " << static_cast<float>(1 + j) / imageHeight * 100.f << "%\n";
	    for (int i = 0; i < ImageWidth; ++i) {
			auto pixelCenter = viewportTopLeftPixelCenter + (static_cast<float>(i) * deltaX) + (static_cast<float>(j) * deltaY);
			auto rayDirection = pixelCenter - cameraOrigin ;
			Ray ray(cameraOrigin, rayDirection);
			
			glm::vec3 iColor = ray_color(ray);
			glm::uvec3 color = {static_cast<int>(255.999) * iColor.x, static_cast<int>(255.999) * iColor.y, static_cast<int>(255.999) * iColor.z};

			image.Push(color);
		}

	    
	}
	std::cout << "done!\n";



}