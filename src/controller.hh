#include "executor.cc"

/**************************************************************************************************
*    LoadMaster, a framework for calculating the duration of clustered tasks                      *
*    Copyright (C) 2019  Grant Alexander                                                          *
*                                                                                                 *
*    This program is free software: you can redistribute it and/or modify                         *
*    it under the terms of the GNU Lesser General Public License as published by                  *
*    the Free Software Foundation, either version 3 of the License, or                            *
*    (at your option) any later version.                                                          *
*                                                                                                 *
*    This program is distributed in the hope that it will be useful,                              *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                               *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                *
*    GNU General Public License for more details.                                                 *
*                                                                                                 *
*    You should have received a copy of the GNU General Public License                            *
*    along with this program.  If not, see <https://www.gnu.org/licenses/>.                       *
***************************************************************************************************/

class Controller {
     public:
	     Controller(std::vector<Executor>* executors, std::vector<Item>* items);
		 int GetShortestTime();
		 void LoadStep();
		 void TimeStep(int interval);
		 bool AreExecutorsAllFree();
		 std::vector<Item> GetItems();
		 std::vector<Executor> GetExecutors();
     private:
	     std::vector<Item>* Items;
	     std::vector<Executor>* Executors;
};