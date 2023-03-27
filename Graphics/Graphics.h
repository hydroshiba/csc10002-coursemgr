#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

class Application {
public:
	Application(int width = 800, int height = 450, std::string title = "Course Management System");
	~Application() noexcept;

	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool AppShouldClose() const;
	void Tick();

private:
	void Display();
	void Update();
};

#endif