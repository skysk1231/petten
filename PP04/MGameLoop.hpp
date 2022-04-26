#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;
		Enemy e;
		bool b = false;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{

				Input();
				Update();
				Render();

			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			if (b == true)
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{
					b = false;     
					e.x = 50;
				}
			}
			else if (b == false)
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{
					
					if (p.y >= 4)
					{
						p.y--;
					}
					this_thread::sleep_for(chrono::milliseconds(20));
				}
				else
				{
					if(p.y<=6 )
					{
						p.y++;
					}
					this_thread::sleep_for(chrono::milliseconds(20));
				}
			}


		}
		void Update()
		{
			string d = "Gameover \n 다시 시작은 스페이스 바를 눌러주세요";
			if (e.x == p.x && e.y == p.y)
			{
				b = true;
				cRenderer.MoveCursor(10, 3);
				cRenderer.DrawString(d);
				this_thread::sleep_for(chrono::milliseconds(20));
			}

			if (b == false) { e.EnemyMove(); }
		}
		void Render()
		{

			cRenderer.Clear();

			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");

			cRenderer.MoveCursor(e.x, e.y);
			cRenderer.DrawString("e");
			//p.check();

			
			

			cRenderer.MoveCursor(10, 20);

			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));
		}


		//cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));

		
				
		
	};

	


	

}