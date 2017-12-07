#ifndef INPUTTABLES_H
#define INPUTTABLES_H

#include<map>

const static struct KeyCodeToIdx {
public:
	const static int A = 0;
	const static int B = 1;
	const static int C = 2;
	const static int D = 3;
	const static int E = 4;
	const static int F = 5;
	const static int G = 6;
	const static int H = 7;
	const static int I = 8;
	const static int J = 9;
	const static int K = 10;
	const static int L = 11;
	const static int M = 12;
	const static int N = 13;
	const static int O = 14;
	const static int P = 15;
	const static int Q = 16;
	const static int R = 17;
	const static int S = 18;
	const static int T = 19;
	const static int U = 20;
	const static int V = 21;
	const static int W = 22;
	const static int X = 23;
	const static int Y = 24;
	const static int Z = 25;

	const static int Up = 26;
	const static int Down = 27;
	const static int Left = 28;
	const static int Right = 29;

	const static int Space = 30;
	const static int LeftControl = 31;
	const static int RightControl = 32;
	const static int LeftShift = 33;
	const static int RightShift = 34;
	const static int LeftAlt = 35;
	const static int RightAlt = 36;

	const static int Esc = 37;
	const static int F1 = 38;
	const static int F2 = 39;
	const static int F3 = 40;
	const static int F4 = 41;
	const static int F5 = 42;
	const static int F6 = 43;
	const static int F7 = 44;
	const static int F8 = 45;
	const static int F9 = 46;
	const static int F10 = 47;
	const static int F11 = 48;
	const static int F12 = 49;

	const static int PauseBreak = 50;
	const static int Insert = 51;
	const static int Delete = 52;
	// 53 Keys Mapped.
}KeyCodeToIdx;

static std::map<int, int> SDLKToKeyCodeIdx = {
		{SDLK_a, KeyCodeToIdx::A},
		{SDLK_b, KeyCodeToIdx::B},
		{SDLK_c, KeyCodeToIdx::C},
		{SDLK_d, KeyCodeToIdx::D},
		{SDLK_e, KeyCodeToIdx::E},
		{SDLK_f, KeyCodeToIdx::F},
		{SDLK_g, KeyCodeToIdx::G},
		{SDLK_h, KeyCodeToIdx::H},
		{SDLK_i, KeyCodeToIdx::I},
		{SDLK_j, KeyCodeToIdx::J},
		{SDLK_k, KeyCodeToIdx::K},
		{SDLK_l, KeyCodeToIdx::L},
		{SDLK_m, KeyCodeToIdx::M},
		{SDLK_n, KeyCodeToIdx::N},
		{SDLK_o, KeyCodeToIdx::O},
		{SDLK_p, KeyCodeToIdx::P},
		{SDLK_q, KeyCodeToIdx::Q},
		{SDLK_r, KeyCodeToIdx::R},
		{SDLK_s, KeyCodeToIdx::S},
		{SDLK_t, KeyCodeToIdx::T},
		{SDLK_u, KeyCodeToIdx::U},
		{SDLK_v, KeyCodeToIdx::V},
		{SDLK_w, KeyCodeToIdx::W},
		{SDLK_x, KeyCodeToIdx::X},
		{SDLK_y, KeyCodeToIdx::Y},
		{SDLK_z, KeyCodeToIdx::Z},

		{SDLK_UP, KeyCodeToIdx::Up},
		{SDLK_DOWN, KeyCodeToIdx::Down},
		{SDLK_LEFT, KeyCodeToIdx::Left},
		{SDLK_RIGHT, KeyCodeToIdx::Right},

		{SDLK_SPACE, KeyCodeToIdx::Space},
		{KMOD_LCTRL,  KeyCodeToIdx::LeftControl},
		{KMOD_RCTRL,  KeyCodeToIdx::RightControl},
		{KMOD_LSHIFT, KeyCodeToIdx::LeftShift},
		{KMOD_RSHIFT, KeyCodeToIdx::RightShift},
		{KMOD_LALT, KeyCodeToIdx::LeftAlt},
		{KMOD_RALT, KeyCodeToIdx::RightAlt},

		{SDLK_ESCAPE, KeyCodeToIdx::Esc},
		{SDLK_F1, KeyCodeToIdx::F1},
		{SDLK_F2, KeyCodeToIdx::F2},
		{SDLK_F3, KeyCodeToIdx::F3},
		{SDLK_F4, KeyCodeToIdx::F4},
		{SDLK_F5, KeyCodeToIdx::F5},
		{SDLK_F6, KeyCodeToIdx::F6},
		{SDLK_F7, KeyCodeToIdx::F7},
		{SDLK_F8, KeyCodeToIdx::F8},
		{SDLK_F9, KeyCodeToIdx::F9},
		{SDLK_F10, KeyCodeToIdx::F10},
		{SDLK_F11, KeyCodeToIdx::F11},
		{SDLK_F12, KeyCodeToIdx::F12},

		{SDLK_PAUSE, KeyCodeToIdx::PauseBreak},
		{SDLK_INSERT, KeyCodeToIdx::Insert},
		{SDLK_DELETE, KeyCodeToIdx::Delete}
};
#endif
