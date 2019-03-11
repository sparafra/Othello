#include "GestioneGioco.h"

GestioneGioco::GestioneGioco(string Directory)
{
	Path = Directory;
	cout<<Path<<endl;
	Path = Path.substr(0, Path.find_last_of("/") + 1);

	FontPath = "";
	FontPath.append(Path);
	FontPath.append(fontfile);
	
	SelectionSxPath = "";
	SelectionDxPath = "";
	
	SelectionDxPath.append(Path);
	SelectionDxPath.append(SelectionDxImageFile);
	SelectionSxPath.append(Path);
	SelectionSxPath.append(SelectionSxImageFile);
	
	cout<<SelectionDxPath<<endl;
	cout<<SelectionSxPath<<endl;
	cout << FontPath << endl;
	
	SkinsFile.push_back("Risorse/Skin/Wood.jpg");
	SkinsFile.push_back("Risorse/Skin/Metal.jpg");
	SkinsFile.push_back("Risorse/Skin/LightWood.jpg");
	SkinsFile.push_back("Risorse/Skin/Blue.jpg");
	
	Multiplayer = true;
	BoardColorSelected = false;
	GameOver = false;
	IndexSkin = 0;

	timerActive=false;
	sec = 30;
	for (int K = 0; K < SkinsFile.size(); K++)
	{
		string PathFile = Path;
		PathFile.append(SkinsFile[K]);
		SkinsPath.push_back(PathFile);
	}

}
void GestioneGioco::Init()
{
	//Initialize
	if (!al_init()) {
		cout << "allegro non inizializzato";
	}
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();

	

	event_queue = al_create_event_queue();

	Disc1Color = al_map_rgb(255, 255, 255);
	Disc2Color = al_map_rgb(0, 0, 0);

	BoardColor = al_map_rgb(167, 22, 3);

	al_register_event_source(event_queue, al_get_mouse_event_source());


	ALLEGRO_BITMAP* Skin = al_load_bitmap(SkinsPath[IndexSkin].c_str());
	F = new Form(Skin);
	
	font = al_load_font(FontPath.c_str(), F->getWidth() * ((float)1/100), 0);

}
void GestioneGioco::MenuLoad(ALLEGRO_EVENT_QUEUE *event_queue, bool SkinBackground)
{
	F->repaint();
	StartMenu* Menu;
	if (SkinBackground)
	{
		Menu = new StartMenu(font, SkinsPath[IndexSkin], F);
		
	}
	else
	{
		Menu = new StartMenu(font, BoardColor, F);
	}
	al_flip_display();

	while (true)
	{
		vector<Button*> Buttons = Menu->getButtons();
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		if (get_event && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 1)
			{
				if (Buttons[0]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Start button
					al_flip_display();
					GameLoad(event_queue);
					break;
				}
				else if (Buttons[1]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Settings button
					al_flip_display();
					SettingsLoad(event_queue);
					break;
				}
				else if (Buttons[2]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Exit button
					this->~GestioneGioco();
					break;
				}
			}

		}
	}
}
void GestioneGioco::SettingsLoad(ALLEGRO_EVENT_QUEUE *event_queue)
{
	bool Save = false;
	F->setColor(al_map_rgb(128, 128, 128));
	F->setImageBackground(false);
	F->repaint();
	Settings* OpenSettings = new Settings(font, SelectionSxPath, SelectionDxPath, SkinsPath, IndexSkin, F);
	al_flip_display();
	while (!Save)
	{
		vector<Button*> Buttons = OpenSettings->getButtons();
		vector<CheckBox*> CheckBoxV = OpenSettings->getCheckBoxVector();
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		if (get_event && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			/*Order Buttons & Index
			
			//Add Board Color Button
			[0] = BoardColorR
			[1] = BoardColorG
			[2] = BoardColorB
			[3] = BoardColorO
			[4] = BoardColorY

			//Add Enemies Button
			[5] = Next
			[6] = Prec

			//Add Disc1 Button
			[7] = Disc1ColorR
			[8] = Disc1ColorG
			[9] = Disc1ColorB
			[10] = Disc1ColorO
			[11] = Disc1ColorBk
			[12] = Disc1ColorW

			//Add Disc2 Button
			[13] = Disc2ColorR
			[14] = Disc2ColorG
			[15] = Disc2ColorB
			[16] = Disc2ColorO
			[17] = Disc2ColorBk
			[18] = Disc2ColorW

			//Add Save Button
			[19] = Save

			CheckBox Order
			[0] = BoardColorCB
			[1] = BoardSkinCB
			[2] = PlayerCB
			[3] = PCCB
			[4] = TimerCB


			*/
			if (ev.mouse.button & 1)
			{
				if (Buttons[0]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardColorR
					BoardColor = al_map_rgb(167, 22, 3);
				}
				else if (Buttons[1]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardColorG
					BoardColor = al_map_rgb(55, 165, 50);
				}
				else if (Buttons[2]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardColorB
					BoardColor = al_map_rgb(11, 65, 202);
				}
				else if (Buttons[3]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardColorO
					BoardColor = al_map_rgb(237, 159, 55);
				}
				else if (Buttons[4]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardColorY
					BoardColor = al_map_rgb(249, 215, 88);
				}
				else if (Buttons[5]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Next
					if (OpenSettings->getIndexSkin() < OpenSettings->getNumberOfSkins()-1)
					{
						OpenSettings->NextPreview(F);
					}
				}
				else if (Buttons[6]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Prec
					if (OpenSettings->getIndexSkin() > 0)
					{
						OpenSettings->PrecPreview(F);
					}
				}
				else if (Buttons[7]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc1ColorR
					Disc1Color = al_map_rgb(167, 22, 3);
				}
				else if (Buttons[8]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc1ColorG
					Disc1Color = al_map_rgb(55, 165, 50);
				}
				else if (Buttons[9]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc1ColorB
					Disc1Color = al_map_rgb(11, 65, 202);
				}
				if (Buttons[10]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc1ColorO
					Disc1Color = al_map_rgb(237, 159, 55);
				}
				else if (Buttons[11]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc1ColorBk
					Disc1Color = al_map_rgb(0, 0, 0);
				}
				else if (Buttons[12]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc1ColorW
					Disc1Color = al_map_rgb(255, 255, 255);
				}
				else if (Buttons[13]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc2ColorR
					Disc2Color = al_map_rgb(167, 22, 3);
				}
				else if (Buttons[14]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc2ColorG
					Disc2Color = al_map_rgb(55, 165, 50);
				}
				else if (Buttons[15]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc2ColorB
					Disc2Color = al_map_rgb(11, 65, 202);
				}
				else if (Buttons[16]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc2ColorO
					Disc2Color = al_map_rgb(237, 159, 55);
				}
				else if (Buttons[17]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc2ColorBk
					Disc2Color = al_map_rgb(0, 0, 0);
				}
				else if (Buttons[18]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Disc2ColorW
					Disc2Color = al_map_rgb(255, 255, 255);
				}
				else if (Buttons[19]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Save
					Save = true;
					IndexSkin = OpenSettings->getIndexSkin();
					
					if(CheckBoxV[2]->getSelected())
					{
						Multiplayer = false;
					}
					else
					{
						Multiplayer = true;
					}
					
					if(CheckBoxV[4]->getSelected())
					{
						timerActive = true;
					}
					else
					{
						timerActive = false;
					}
					if (CheckBoxV[0]->getSelected())
					{
						BoardColorSelected = true;
						F->setImageBackground(false);
						F->setColor(BoardColor);
						MenuLoad(event_queue, false);
					}
					else
					{
						BoardColorSelected = false;
						F->setImageBackground(true);
						F->setSkin(al_load_bitmap(SkinsPath[IndexSkin].c_str()));
						al_flip_display();
						MenuLoad(event_queue, true);
					}
					
				}
				else if (CheckBoxV[0]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardColor CheckBox
					if (!CheckBoxV[0]->getSelected())
					{
						CheckBoxV[0]->changeState();
						CheckBoxV[1]->changeState();
					}
				}
				else if (CheckBoxV[1]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//BoardSkin CheckBox
					if (!CheckBoxV[1]->getSelected())
					{
						CheckBoxV[0]->changeState();
						CheckBoxV[1]->changeState();
					}
				}
				else if (CheckBoxV[2]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Pc CheckBox
					if (!CheckBoxV[2]->getSelected())
					{
						CheckBoxV[2]->changeState();
						CheckBoxV[3]->changeState();
					}
				}
				else if (CheckBoxV[3]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Player CheckBox
					if (!CheckBoxV[3]->getSelected())
					{
						CheckBoxV[2]->changeState();
						CheckBoxV[3]->changeState();
					}
				}
				else if (CheckBoxV[4]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Timer CheckBox
					if (!CheckBoxV[4]->getSelected())
					{
						CheckBoxV[4]->changeState();
					}
					else
					{
						CheckBoxV[4]->changeState();
					}
					
				}
				al_flip_display();
			}
		}
	}
}
void GestioneGioco::GameLoad(ALLEGRO_EVENT_QUEUE* event_queue)
{
	F->repaint();
	GameOver = false;
	StartGame* Game;
	if (BoardColorSelected)
	{
		Game = new StartGame(font, BoardColor, Disc1Color, Disc2Color, F);
	}
	else
	{
		Game = new StartGame(font, SkinsPath[IndexSkin], Disc1Color, Disc2Color, F);
	}
   	if(timerActive)
	{
		timer = al_create_timer(1);
		al_register_event_source(event_queue, al_get_timer_event_source(timer));
		al_start_timer(timer);
	}
	

	CoreOthello* Core = new CoreOthello(Multiplayer);
	int PercentageDimensionDisc = ((Game->getBoardDimension() / 8) - (((float)(Game->getBoardDimension() / 8) / 100) * 60));
	DiscPlayer1 = new Disc(PercentageDimensionDisc, Disc1Color);
	DiscPlayer2 = new Disc(PercentageDimensionDisc, Disc2Color);

	//Init Disc
	Core->Init();
	Game->drawDiscBoard(DiscPlayer1, DiscPlayer2, Core->getMatrix(), Core->getSize());
	
	//Draw Score
	Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);

	//Possible moves
	vector<int>RowPossibileMoves = Core->getRowPossibileMoves();
	vector<int>ColumnsPossibileMoves = Core->getColumnsPossibileMoves();
	for (int K = 0; K < RowPossibileMoves.size(); K++)
	{
		Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
	}
	al_flip_display();

	
	while (!GameOver)
	{
		bool changes = false;
		vector<Button*> Buttons = Game->getButtons();
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		if(get_event && ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(sec > 0)
			{
				sec--;
				Game->drawTimer(sec, F);
				changes = true;
			}
			else
			{
				
				al_stop_timer(timer);
				
				const char* Win;
				if (Core->getScoreCurrentPlayer() > Core->getScoreEnemy())
				{
					if (Core->getCurrentPlayer() == 0)
					{
						Win = "GameOver: Vince Player1";
					}
					else
					{
						Win = "GameOver: Vince Player2";
					}
				}	
				else if (Core->getScoreCurrentPlayer() < Core->getScoreEnemy())
				{
					if (Core->getCurrentPlayer() == 0)
					{
						Win = "GameOver: Vince Player2";
					}
					else
					{
						Win = "GameOver: Vince Player1";
					}
				}
				else
				{
					Win = "GameOver: Parita'";
				}

				//Show Result 
				int Result = al_show_native_message_box(F->getDisplay(), "GameOver", Win, "Vuoi Ricominciare?",
					NULL, ALLEGRO_MESSAGEBOX_YES_NO);

				//Input to Reset and Play again
				if (Result == 1)
				{
					//Reset 
					sec=30;
					al_start_timer(timer);
					Game->clearAllDiscBoard(Core->getMatrix(), Core->getSize());
					for (int K = 0; K < RowPossibileMoves.size(); K++)
					{
						Game->clearDiscBoard(DiscPlayer1->getRadius(), RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
					}
					Core->Init();
					RowPossibileMoves = Core->getRowPossibileMoves();
					ColumnsPossibileMoves = Core->getColumnsPossibileMoves();
					for (int K = 0; K < RowPossibileMoves.size(); K++)
					{
						Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
					}
					Game->drawDiscBoard(DiscPlayer1, DiscPlayer2, Core->getMatrix(), Core->getSize());
					Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);
				}
				GameOver = false;
									
			}
			
		}
		else if (get_event && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 1)
			{
				//Move
				if (Game->getBoard()->Clicked(ev.mouse.x, ev.mouse.y)) //Onboard Click?
				{
					int* RigaColonna = Game->getBoard()->ClickedCell(ev.mouse.x, ev.mouse.y);
					bool MovesCanDoIt = false;

					//Control If it is a possible moves
					for (int K = 0; K < Core->getNumberOfPossibileMoves() && MovesCanDoIt == false; K++)
					{
						if (RowPossibileMoves[K] == RigaColonna[0] && ColumnsPossibileMoves[K] == RigaColonna[1])
						{
							MovesCanDoIt = true;
						}
					}

					//Do it
					if (MovesCanDoIt == true)
					{
						//Clear Previous Possible moves
						for (int K = 0; K < RowPossibileMoves.size(); K++)
						{
							Game->clearDiscBoard(DiscPlayer1->getRadius(), RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
						}
						if (Core->getCurrentPlayer() == 1)
						{
							Game->drawDiscBoard(DiscPlayer2, RigaColonna[0], RigaColonna[1]);
						}
						else
						{
							Game->drawDiscBoard(DiscPlayer1, RigaColonna[0], RigaColonna[1]);
						}

						//SetMove in Core
						Core->setMoves(RigaColonna[0], RigaColonna[1], true);

						//Draw Score
						if (Core->getCurrentPlayer() == 0)
						{
							Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);
							Game->drawCurrentPlayer(0, F);
						}
						else
						{
							Game->drawScore(Core->getScoreEnemy(), Core->getScoreCurrentPlayer(), F);
							Game->drawCurrentPlayer(1, F);
						}
						
						//Change Disc Conquered
						vector<int>RowChanged = Core->getRowChanged();
						vector<int>ColumnsChanged = Core->getColumnsChanged();
						for (int K = 0; K < RowChanged.size(); K++)
						{
							if (Core->getCurrentPlayer() == 1)
							{
								Game->drawDiscBoard(DiscPlayer1, RowChanged[K], ColumnsChanged[K]);
							}
							else
							{
								Game->drawDiscBoard(DiscPlayer2, RowChanged[K], ColumnsChanged[K]);
							}
							
						}

						//Refresh PossibleMoves Or GameOver
						RowPossibileMoves = Core->getRowPossibileMoves();
						ColumnsPossibileMoves = Core->getColumnsPossibileMoves();

						

						if (Core->gameOver() == false)
						{
							for (int K = 0; K < RowPossibileMoves.size(); K++)
							{
								if (Core->getCurrentPlayer() == 0)
								{
									Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
								}
								else
								{
									Game->drawDiscBoard(DiscPlayer2, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
								}
							}

							//Pc Turn
							if (!Multiplayer)
							{
								//Clear Previous Possible moves
								for (int K = 0; K < RowPossibileMoves.size(); K++)
								{
									Game->clearDiscBoard(DiscPlayer1->getRadius(), RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
								}

								//SetMove in Core
								int* RowColumns = Core->IAMove();

								//Draw AI Moves
								if (Core->getCurrentPlayer() == 1)
								{
									Game->drawDiscBoard(DiscPlayer1, RowColumns[0], RowColumns[1]);
								}
								else
								{
									Game->drawDiscBoard(DiscPlayer2, RowColumns[0], RowColumns[1]);
								}

								//Draw Score
								if (Core->getCurrentPlayer() == 0)
								{
									Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);
									Game->drawCurrentPlayer(0, F);
								}
								else
								{
									Game->drawScore(Core->getScoreEnemy(), Core->getScoreCurrentPlayer(), F);
									Game->drawCurrentPlayer(1, F);
								}

								//Change Disc Conquered
								vector<int>RowChanged = Core->getRowChanged();
								vector<int>ColumnsChanged = Core->getColumnsChanged();
								for (int K = 0; K < RowChanged.size(); K++)
								{
									if (Core->getCurrentPlayer() == 1)
									{
										Game->drawDiscBoard(DiscPlayer1, RowChanged[K], ColumnsChanged[K]);
									}
									else
									{
										Game->drawDiscBoard(DiscPlayer2, RowChanged[K], ColumnsChanged[K]);
									}

								}

								//Refresh PossibleMoves Or GameOver
								RowPossibileMoves = Core->getRowPossibileMoves();
								ColumnsPossibileMoves = Core->getColumnsPossibileMoves();
								if (Core->gameOver() == false)
								{
									for (int K = 0; K < RowPossibileMoves.size(); K++)
									{
										if (Core->getCurrentPlayer() == 0)
										{
											Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
										}
										else
										{
											Game->drawDiscBoard(DiscPlayer2, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
										}
									}
								}
								else
								{
									if(timerActive)
									{
										al_stop_timer(timer);
									}
									
									GameOver = Core->gameOver();
									const char* Win;
									if (Core->getScoreCurrentPlayer() > Core->getScoreEnemy())
									{
										if (Core->getCurrentPlayer() == 0)
										{
											Win = "GameOver: Vince Player1";
										}
										else
										{
											Win = "GameOver: Vince Player2";
										}
									}
									else if (Core->getScoreCurrentPlayer() < Core->getScoreEnemy())
									{
										if (Core->getCurrentPlayer() == 0)
										{
											Win = "GameOver: Vince Player2";
										}
										else
										{
											Win = "GameOver: Vince Player1";
										}
									}
									else
									{
										Win = "GameOver: Parita'";
									}

									//Show Result 
									int Result = al_show_native_message_box(F->getDisplay(), "GameOver", Win, "Vuoi Ricominciare?",
										NULL, ALLEGRO_MESSAGEBOX_YES_NO);

									//Input to Reset and Play again
									if (Result == 1)
									{
										//Reset 
										if(timerActive)
										{
											sec=30;
											al_start_timer(timer);
										}
										
										Game->clearAllDiscBoard(Core->getMatrix(), Core->getSize());
										for (int K = 0; K < RowPossibileMoves.size(); K++)
										{
											Game->clearDiscBoard(DiscPlayer1->getRadius(), RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
										}
										Core->Init();
										RowPossibileMoves = Core->getRowPossibileMoves();
										ColumnsPossibileMoves = Core->getColumnsPossibileMoves();
										for (int K = 0; K < RowPossibileMoves.size(); K++)
										{
											Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
										}
										Game->drawDiscBoard(DiscPlayer1, DiscPlayer2, Core->getMatrix(), Core->getSize());
										Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);
									}
									GameOver = false;
								}
							}
						}
						else
						{
							al_flip_display();
							if(timerActive)
							{
								al_stop_timer(timer);
							}
							GameOver = Core->gameOver();
							const char* Win;
							if (Core->getScoreCurrentPlayer() > Core->getScoreEnemy())
							{
								if (Core->getCurrentPlayer() == 0)
								{
									Win = "GameOver: Vince Player1";
								}
								else
								{
									Win = "GameOver: Vince Player2";
								}
							}
							else if (Core->getScoreCurrentPlayer() < Core->getScoreEnemy())
							{
								if (Core->getCurrentPlayer() == 0)
								{
									Win = "GameOver: Vince Player2";
								}
								else
								{
									Win = "GameOver: Vince Player1";
								}
							}
							else
							{
								Win = "GameOver: Parita'";
							}

							//Show Result 
							int Result = al_show_native_message_box(F->getDisplay(), "GameOver", Win, "Vuoi Ricominciare?",
							NULL, ALLEGRO_MESSAGEBOX_YES_NO);

							//Input to Reset and Play again
							if (Result == 1)
							{
								//Reset 
								
								if(timerActive)
								{
									sec=30;
									al_start_timer(timer);
								}
								Game->clearAllDiscBoard(Core->getMatrix(), Core->getSize());
								for (int K = 0; K < RowPossibileMoves.size(); K++)
								{
									Game->clearDiscBoard(DiscPlayer1->getRadius(), RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
								}
								Core->Init();
								RowPossibileMoves = Core->getRowPossibileMoves();
								ColumnsPossibileMoves = Core->getColumnsPossibileMoves();
								for (int K = 0; K < RowPossibileMoves.size(); K++)
								{
									Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
								}
								Game->drawDiscBoard(DiscPlayer1, DiscPlayer2, Core->getMatrix(), Core->getSize());
								Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);
							}
							GameOver = false;
						}	
						changes = true;
					}
					
				}


				//Reset
				if (Buttons[0]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Reset Button Clicked
					if(timerActive)
					{
						sec=30;
						al_start_timer(timer);
					}

					Game->clearAllDiscBoard(Core->getMatrix(), Core->getSize());
					for (int K = 0; K < RowPossibileMoves.size(); K++)
					{
						Game->clearDiscBoard(DiscPlayer1->getRadius(), RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
					}
					Core->Init();
					RowPossibileMoves = Core->getRowPossibileMoves();
					ColumnsPossibileMoves = Core->getColumnsPossibileMoves();
					for (int K = 0; K < RowPossibileMoves.size(); K++)
					{
						Game->drawDiscBoard(DiscPlayer1, RowPossibileMoves[K], ColumnsPossibileMoves[K], true);
					}
					Game->drawDiscBoard(DiscPlayer1, DiscPlayer2, Core->getMatrix(), Core->getSize());
					Game->drawScore(Core->getScoreCurrentPlayer(), Core->getScoreEnemy(), F);
					Game->drawCurrentPlayer(Core->getCurrentPlayer(), F);
					changes=true;
				} //Reset
				
				//Exit
				if (Buttons[1]->Clicked(ev.mouse.x, ev.mouse.y))
				{
					//Exit Button Clicked
					if(timerActive)
					{
						sec=30;
						al_destroy_timer(timer);
					}
					GameOver = true;
					if (BoardColorSelected)
					{
						MenuLoad(event_queue, false);
					}
					else
					{
						MenuLoad(event_queue, true);
					}
					changes = true;	
				} 
			}
		}
		if(changes)
		{
			al_flip_display();
		}
		
	}
}
GestioneGioco::~GestioneGioco()
{
	al_destroy_event_queue(event_queue);
	al_destroy_font(font);
}

void GestioneGioco::Start()
{
	Init();
	MenuLoad(event_queue, true);
}