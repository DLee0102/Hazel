#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// 这种写法可以不用引入hazel的所有头文件，能够加快编译速度
extern Hazel::Application* Hazel::CreateApplication();

int main(int args, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! Var={0}", a);
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif