#include "Game.h"

Game::Game()
{
	player = new Player;
}

Game::~Game()
{
	delete player;
	player = nullptr;
}

void Game::Run()
{
	Intro();
	// Game loop
	running = true;
	while (running == true){ 
		system("cls"); 
		Print_Map();
		room.Description(player->x, player->y); 
		Move(); 
		Check_For_Win();
	}
	Ending();
}

void Game::Intro()
{
	system("cls");
	cout << R"( 
	Good morning! Well, actually maybe not so much today...
	 You seem to have washed ashore on an island you don't
	    recognise. Slowly, you rise to your feet as you 
	          hear an old man rambling up ahead.
	)" << endl;
	Move();
	cout << R"( 
	       The old man comes running right up to you!
	You don't understand a single word of what he says, but
	 he hands you what seems to be a map of the island and
	                  walks off. Score!
	)" << endl;
	system("pause");
}

void Game::Ending()
{
	system("cls");
	cout << R"(
	  You wonder in amazement as to what exists in front
	of you. It's an otherworldly portal! Without a second
	thought, you dive on in and hope for the best. In the
	 blink of an eye you spawn back in a familiar place,
	        it's your home. You finally did it...
	
	)" << endl;
	system("pause");
	cout << R"(
	                  Congratulations
	)" << endl;
	system("pause");
	cout << R"(
	                    You're home.
	)" << endl;
}

void Game::Print_Map()
{
	// Adjusts map printing size for lamp use
	int l = room.map_length;
	if (room.lamp) {
		if (room.lamp->turned_on) l = room.full_length;
	}
	// Prints map
	cout << " ";
	for (int x = 1; x < room.map_height; x++) {
		for (int y = 0; y < l; y++) { 
			if (x == player->x && y == player->y) {
				cout << " O";
			}
			else if (room.room_map[x][y] != '-' && room.room_map[x][y] != ' ') {
				// Adjusts map printing for spell Foresight
				if (room.spell_01) {
					if (room.spell_01->casted) cout << " ?";
					else cout << " -";
				}
				else if (room.room_map[x][y] == 'f') cout << " ?";
				else cout << " -";
			}
			else cout << " " << room.room_map[x][y];
		}
		cout << endl << " ";
	}	
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~";
	if (room.lamp) {
		if (room.lamp->turned_on) cout << "~~~~~~~~";
	} 
	cout << endl;
}

void Game::Move()
{
	// Presents the player with the options they have available
	cout << "\nWhich direction would you like to move? (Up/Down/Left/Right)\n";
	if (room.lamp) cout << "Use lamp (L)\n";
	if (room.book) cout << "Read book (B)\n";
	if (room.key) cout << "Keys: " << room.key->count << endl;
	if (room.spell_01 || room.spell_02) {
		cout << "\nSpells:\n";
		if (room.spell_01) cout << "Foresight (F)\n";
		if (room.spell_02) cout << "Portalise (P)\n";
	}
	// Takes input from the player and converts to lowercase for easier handling
	String* input = new String();
	input->ReadFromConsole();
	input->ToLower();
	// Handles moving up
	if (input->EqualTo("up") || input->EqualTo("north") == true) {
		if (room.room_map[player->x - 1][player->y] && room.room_map[player->x - 1][player->y] != ' ') {
			if (room.room_map[player->x - 1][player->y] == 'f') {
				player->Add_Spell("Foresight");
			}
			player->x--;
		}
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
	}
	// Handles moving down
	else if (input->EqualTo("down") || input->EqualTo("south") == true) {
		if (room.room_map[player->x + 1][player->y] && room.room_map[player->x + 1][player->y] != ' ') {
			if (room.room_map[player->x + 1][player->y] == 'f') {
				player->Add_Spell("Foresight");
			}
			player->x++;
		}
		else if (player->y >= room.map_length && player->x != room.map_height - 1) {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
		else {
			cout << "\nThat way goes right into the ocean! Now is not the time for a swim\n";
			Move();
		}
	}
	// Handles moving left
	else if (input->EqualTo("left") || input->EqualTo("west") == true) {
		if (room.room_map[player->x][player->y - 1] && room.room_map[player->x][player->y - 1] != ' ') {
			if (room.room_map[player->x][player->y - 1] == 'p') {
				player->Add_Spell("Portalise");
			}
			if (room.room_map[player->x][player->y - 1] == 'f') {
				player->Add_Spell("Foresight"); 
			}
			player->y--;
		}
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
	}
	// Handles moving right
	else if (input->EqualTo("right") || input->EqualTo("east") == true) {
		if (room.room_map[player->x][player->y + 1] && room.room_map[player->x][player->y + 1] != ' ' && room.room_map[player->x][player->y + 1] != 's') {
			if (room.room_map[player->x][player->y + 1] == 'f') {
				player->Add_Spell("Foresight");
			}
			player->y++;
		}
		else if (room.room_map[player->x][player->y + 1] == 's' && room.key) {
			cout << "\nYou found a secret panel in the wall! What's going on here???\n";
			room.key->Use();
			player->y++;
		}
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
	}
	// Handles using the lamp
	else if (input->EqualTo("l") && room.lamp != nullptr) {
		if (player->y < room.map_length) {
			cout << "\nYou can't use that here\n";
			Move();
		}
		else room.lamp->Use();
	}
	// Handles reading the book
	else if (input->EqualTo("b") && room.book != nullptr) {
		room.book->Use();
		}
	// Handles using spell Portalise
	else if (input->EqualTo("p") && room.spell_02 != nullptr) {
		room.spell_02->Cast(); 
	}	
	// Handles using spell Foresight
	else if (input->EqualTo("f") && room.spell_01 != nullptr) {
		room.spell_01->Cast();
	}
	// Handles spell search 
	else if (input->EqualTo("search")) {
		cout << "\nWhich spell would you like to search for?\n";
		String* search = new String;
		search->ReadFromConsole();
		search->ToLower();
		player->Find_Spell(search->CStr()); 
		system("pause");
	}
	// Handles invalid input
	else {
		cout << "\nNot a valid input.\n";
		Move();
	}
}

void Game::Check_For_Win()
{
	if (room.spell_02) {
		if (room.spell_02->casted == true) running = false;
	}
}


