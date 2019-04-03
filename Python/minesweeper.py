import turtle as gui
import random as r

class Cell:
	def __init__(self, t, xmin, ymin, xmax, ymax):
		self.__t = t
		self.__xmin = int(xmin)
		self.__ymin = int(ymin)
		self.__xmax = int(xmax)
		self.__ymax = int(ymax)
		self.__bomb = False
		self.__cleared = False

	def isIn(self, x, y):
		self.x = x
		self.y = y
		if self.__xmin -5 <= self.x <= self.__xmax and self.__ymin <= self.y <= self.__ymax:
			return True
		else:
			return False

	def setBomb(self):
		self.__bomb = True

	def isBomb(self):
		if self.__bomb == False:
			return False
		else:
			return True

	def clear(self):
		self.__cleared = True
		self.draw()

	def isCleared(self):
		if self.__cleared == True:
			return True
		else:
			return False

	def showCount(self, c):
		self.c = c
		if self.c != 0:
			# Following code block is purely for aesthetics. If this does not adhere to the project's
			# requirements, delete lines 56 - 71. I apologize for any inconvenience.
			self.__t.hideturtle()
			self.__t.penup()
			self.__t.color("gray")
			self.__t.setx(self.__xmin)
			self.__t.sety(self.__ymin)
			self.__t.setheading(90)
			self.__t.begin_fill()
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.end_fill()
			self.__t.penup()

			# Actual showCount function(s):
			self.__t.setx((self.__xmin + self.__xmax) / 2)
			self.__t.sety((self.__ymin + self.__ymax + 55) / 2 - (self.__ymax - self.__ymin))
			self.__t.color("black")
			self.__t.write(int(self.c), False, align = "center", font = ("Times New Roman", 8, "normal"))

	def draw(self):
		self.__t.hideturtle()
		if self.__cleared == False:
			self.__t.color("gray")
			self.__t.penup()
			self.__t.setx(self.__xmin)
			self.__t.sety(self.__ymin)
			self.__t.setheading(90)
			self.__t.begin_fill()
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.end_fill()
			self.__t.penup()
		else:
			if self.isBomb() == True:
				self.__t.color("red")
			else:
				self.__t.color("green")
			self.__t.penup()
			self.__t.setx(self.__xmin)
			self.__t.sety(self.__ymin)
			self.__t.setheading(90)
			self.__t.pendown()
			self.__t.begin_fill()
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.right(90)
			self.__t.forward(self.__xmax - self.__xmin)
			self.__t.end_fill()

class Minesweeper:
	def __init__(self, rows, columns, mines, visability = False):
		self.rows = rows
		self.columns = columns
		self.mines = mines
		self.visability = visability

		self.window = gui.Screen()
		self.window.setworldcoordinates(0, 0, 500, 500)
		self.window.tracer(0, 0)
		self.__t = gui.Turtle()
		self.__t.hideturtle()
		self.__t.speed(0)

		self.__grid = [[Cell(gui.Turtle(), row*25 + 65 + 5, element*25 + 30, row*25 + 65 + 25, element*25 + 50 + 25) for row in range(0, rows)] for element in range(0, columns)]


		drawHeader()

		bombs = 0
		for bomb in range(0, self.mines):
			while bombs < self.mines:
				x = r.randint(0, self.rows - 1)
				y = r.randint(0, self.rows - 1)
				if self.__grid[x][y].isBomb() == False:
					self.__grid[x][y].setBomb()
					# print(self.__grid[x][y].isBomb())
					bombs += 1

		for row in range(0, self.rows):
			for element in range(0, self.columns):
				self.__grid[row][element].draw()

		if self.visability == True:
			for row in range(0, self.rows):
				for column in range(0, self.columns):
					if self.countBombs(row, column) > 0 or self.__grid[row][column].isBomb():
						self.clearCell(row, column)
						self.window.update()

		self.window.listen()
		self.window.onclick(self.getRowCol)
		self.window.update()
		self.window.mainloop()

	def countBombs(self, row, col):
		self.row = row
		self.col = col

		gridLocations = [(-1, 1), (0, 1), (1, 1), (-1, 0), (1, 0), (-1, -1), (0, -1), (1, -1)]
		locations_0_0 = [(1, 0), (0, 1), (1, 1)]
		locations_0_x = [(0, 1), (-1, 0), (-1, 1)]
		locations_0_y = [(1, 0), (0, -1), (1, -1)]
		locations_x_y = [(-1, 0), (0, -1), (-1, -1)]
		locations_left = [(0, 1), (1, -1), (1, 1), (0, -1), (1, 0)]
		locations_right = [(0, 1), (-1, -1), (-1, 1), (0, -1), (-1, 0)]
		locations_top = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0)]
		locations_bottom = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0)]

		bomb_count = 0

		if 0 < self.row < self.rows - 1 and 0 < self.col < self.columns - 1:
			for gridLocation in gridLocations:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif self.row == 0 and self.col == 0:
			for gridLocation in locations_0_0:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif self.row == self.rows - 1 and self.col == self.columns - 1:
			for gridLocation in locations_x_y:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif self.row == self.rows - 1 and self.col == 0:
			for gridLocation in locations_0_x:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif self.row == 0 and self.col == self.columns - 1:
			for gridLocation in locations_0_y:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif self.row == 0 and 0 < self.col < self.columns - 1:
			for gridLocation in locations_left:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif self.row == self.rows - 1 and 0 < self.col < self.columns - 1:
			for gridLocation in locations_right:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif 0 < self.row < self.rows - 1 and self.col == self.columns - 1:
			for gridLocation in locations_top:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		elif 0 < self.row < self.rows - 1 and self.col == 0:
			for gridLocation in locations_bottom:
				if self.__grid[self.row][self.col].isBomb() == False:
					x = self.row + gridLocation[0]
					y = self.col + gridLocation[1]
					if self.__grid[x][y].isBomb() == True:
						bomb_count += 1

		return bomb_count

	def cellsRemaining(self):
		self.remaining_cells = 0
		for row in range(0, self.rows):
			for element in range(0, self.columns):
				if self.__grid[row][element].isCleared() == False and self.__grid[row][element].isBomb() == False:
					self.remaining_cells += 1

		return self.remaining_cells

	def getRowCol(self, x, y):
		self.x = x
		self.y = y

		gameStatus = 0

		if 70 <= self.x <= 415 and 30 <= self.y <= 375:
			found_location = False
			while found_location == False:
				for row in range(0, self.rows):
					for column in range(0, self.columns):
						if self.__grid[row][column].isIn(self.x, self.y) == True:
							location = (row, column)
							found_location = True
							# print("Within Grid: True")

			if self.__grid[location[0]][location[1]].isBomb():
				self.clearCell(location[0], location[1])
				self.visability = True
				gameStatus = True

			elif self.cellsRemaining() == 0:
				self.clearCell(location[0], location[1])
				self.visability = True
				gameStatus = False
			else:
				self.clearCell(location[0], location[1])

		else:
			# print("Within Grid: False")
			location = (-1, -1)

		if gameStatus != 0 or self.cellsRemaining() == 0:
			if gameStatus == False:
				success()
			elif gameStatus == True:
				failure()
			elif self.visability == True and gameStatus == 0:
				success()
			for row in range(0, self.rows):
				for column in range(0, self.columns):
					if self.countBombs(row, column) > 0:
						self.__grid[row][column].showCount(self.countBombs(row, column))
					else:
						self.__grid[row][column].clear()

			self.window.exitonclick()


	def clearCell(self, row , col):
		self.row = row
		self.col = col

		#print(self.cellsRemaining())
		if -1 < self.row < self.rows and -1 < self.col < self.columns and self.__grid[self.row][self.col].isCleared() == False and self.countBombs(self.row, self.col) < 1:
			self.__grid[self.row][self.col].clear()

			self.clearCell(self.row + 1, self.col)
			self.clearCell(self.row - 1, self.col)
			self.clearCell(self.row, self.col + 1)
			self.clearCell(self.row, self.col - 1)
			self.clearCell(self.row, self.col - 1)
			self.clearCell(self.row, self.col + 1)
			self.clearCell(self.row - 1, self.col)
			self.clearCell(self.row + 1, self.col)
		elif -1 < self.row < self.rows and -1 < self.col < self.columns and self.__grid[self.row][self.col].isCleared() == False:
			#self.__grid[self.row][self.col].clear()
			self.__grid[self.row][self.col].clear()
			self.__grid[self.row][self.col].showCount(self.countBombs(self.row, self.col))
		else:
			return 0

def drawHeader():
	gui.hideturtle()
	gui.penup()
	gui.color("gray")
	gui.title("Python-3 Graphical User Interface (GUI)")
	gui.goto(245, 460)
	gui.write("Minesweeper", True, align = "center", font = ("Times New Roman", 24, "bold"))
	gui.goto(245, 445)
	gui.write("Created By:", True, align = "center", font = ("Times New Roman", 12, "bold"))
	gui.goto(245, 430)
	gui.write("Jacob B. Sanders", True, align = "center", font = ("Times New Roman", 12, "normal"))
	gui.goto(245, 415)
	gui.write("sande917@umn.edu", True, align = "center", font = ("Times New Roman", 12, "normal"))

def failure():
	gui.hideturtle()
	gui.penup()
	gui.color("gray")
	gui.goto(245, 390)
	gui.write("Game Over. Please Try Again.", True, align = "center", font = ("Times New Roman", 14, "bold"))

def success():
	gui.hideturtle()
	gui.penup()
	gui.color("gray")
	gui.goto(245, 390)
	gui.write("Congratulations, You Win!", True, align = "center", font = ("Times New Roman", 14, "bold"))

def main():
	game = Minesweeper(14, 14, 15)

if __name__ == '__main__':
	main()
