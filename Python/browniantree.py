import turtle as gui
import random

def initialize_grid():
	coordinateArray = [[False for i in range(200)] for j in range(200)]
	return coordinateArray

def initialize_world(grid):
	gui.screensize(200, 200)
	
	guiScreen = gui.getscreen()
	guiScreen.setworldcoordinates(0, 0, 199, 199)
	
	gui.penup()
	gui.speed(0)
	gui.hideturtle()

	gui.goto(100, 100)
	gui.dot(5, "blue")
	
	grid[100][100] = True
	
	return grid

def random_angle(r):
	rAngle = random.randint(0, 360)
	gui.setheading(rAngle)
	gui.forward(r + 1)
	
def random_walk(particlePositionX, particlePositionY):
	rDirection = random.choice((1, 2, 3, 4))
	
	if rDirection == 1:
		gui.goto(particlePositionX + 1, particlePositionY)
	elif rDirection == 2:
		gui.goto(particlePositionX - 1, particlePositionY)
	elif rDirection == 3: 
		gui.goto(particlePositionX, particlePositionY + 1)
	else:
		gui.goto(particlePositionX, particlePositionY - 1)
	
def calculate_distance(deltaX, deltaY):
	home = [100, 100]
	x = 0
	y = 1
	
	x_1 = home[x]
	x_2 = deltaX
	y_1 = home[y]
	y_2 = deltaY
	
	deltaDistance = ((((x_2 - x_1)**2 + (y_2 - y_1)**2)**0.5))
	
	return deltaDistance
	
def in_grid_general(x, y):
	binaryCheck = ["x", "y"]

	if x == 199:
		binaryCheck[0] = 1 # Right
	elif x == 0:
		binaryCheck[0] = 2 # Left

	if y == 199:
		binaryCheck[1] = 3 # Top
	elif y == 0:
		binaryCheck[1] = 4 # Bottom
	
	if binaryCheck == ["x", "y"] or binaryCheck == ["x", 3] or binaryCheck == ["x", 4] or binaryCheck == [1, "y"] or binaryCheck == [2, "y"]:
		return True
	else:
		return False
	
def in_grid(x, y):
	binaryCheck = ["x", "y"]

	if x == 199:
		binaryCheck[0] = 1 # Right
	elif x == 0:
		binaryCheck[0] = 2 # Left

	if y == 199:
		binaryCheck[1] = 3 # Top
	elif y == 0:
		binaryCheck[1] = 4 # Bottom
	
	return binaryCheck
	
def hasNeighbor(grid, x, y):
	xCheck = 0
	yCheck = 1
	
	binaryLocation = in_grid(x, y)

	try:
		if binaryLocation[xCheck] == 2: # Left 
			if binaryLocation[yCheck] == 3: # Top 
				if grid[x+1][y] or grid[x][y-1] or grid[x+1][y-1]:
					return True
			elif binaryLocation[yCheck] == 4: # Bottom 
				if grid[x+1][y] or grid[x][y+1] or grid[x+1][y+1]:
					return True

		elif binaryLocation[xCheck] == 1: # Right
			if binaryLocation[yCheck] == 3: # Top
				if grid[x-1][y] or grid[x][y-1] or grid[x-1][y-1]:
					return True
			elif binaryLocation[yCheck] == 4: # Bottom
				if grid[x-1][y] or grid[x][y+1] or grid[x-1][y+1]:
					return True

		else:
			if binaryLocation[xCheck] == "x" and binaryLocation[yCheck] != "y":
				if binaryLocation[y] == 3: # Top
					if grid[x-1][y] or grid[x+1][y] or grid[x][y-1]:
						return True
				elif binaryLocation[yCheck] == 4: # Bottom
					if grid[x-1][y] or grid[x+1][y] or grid[x][y+1]:
						return True
			elif binaryLocation[xCheck] != "x" and binaryLocation[yCheck] == "y":
				if binaryLocation[xCheck] == 1: # Right
					if grid[x-1][y] or grid[x][y+1] or grid[x][y-1]:
						return True
				elif binaryLocation[xCheck] == 2: # Left 
					if grid[x+1][y] or grid[x][y+1] or grid[x][y-1]:
						return True
						
			else:
				if grid[x+1][y+1] or grid[x-1][y+1] or grid[x][y+1] or grid[x+1][y-1] or grid[x+1][y] or grid[x-1][y-1] or grid[x][y-1] or grid[x-1][y]:
					return True
				else:
					return False
	except:
		return False
	
def draw_tree(userInput):
	gui.speed(0)
	particleTotal = int(userInput)
	grid = initialize_grid()
	initialize_world(grid)
	
	radius = 0
	
	homeX = 100
	homeY = 100
	
	particleSum = 1
	
	while particleSum <= particleTotal:
		
		gui.goto(homeX, homeY)
		random_angle(radius)
		particlePosition = gui.position()
		particlePositionX = int(particlePosition[0])
		particlePositionY = int(particlePosition[1])
			
		if hasNeighbor(grid, particlePositionX, particlePositionY) == True and in_grid_general(particlePositionX, particlePositionY) == True:	
			gui.goto(particlePositionX, particlePositionY)
			gui.dot(5, "blue")
			particleSum += 1
			grid[particlePositionX][particlePositionY] = True
			particlePosition = gui.position()
			particlePositionX = int(particlePosition[0])
			particlePositionY = int(particlePosition[1])
			distance = (calculate_distance(particlePositionX, particlePositionY))
			if distance >= radius:
				radius = distance // 1
			check = True
		
		else:
			if in_grid_general(particlePositionX, particlePositionY) == True:	
				attempts = 0
				binaryCheck = False
				while attempts < 200 and binaryCheck == False:
					random_walk(particlePositionX, particlePositionY)
					
					particlePosition = gui.position()
					particlePositionX = int(particlePosition[0])
					particlePositionY = int(particlePosition[1])
					
					if hasNeighbor(grid, particlePositionX, particlePositionY) == True and in_grid_general(particlePositionX, particlePositionY) == True:
						gui.goto(particlePositionX, particlePositionY)
						gui.dot(5, "blue")
						particleSum += 1
						grid[particlePositionX][particlePositionY] = True
						distance = (calculate_distance(particlePositionX, particlePositionY))
						if distance >= radius:
							radius = distance // 1
							
						binaryCheck = True
					else: 
						attempts += 1
	gui.exitonclick()

def main():
	userInput = gui.textinput("Tree", "Total Number of Particles: ")
	draw_tree(userInput)

if __name__ == '__main__':
    main()
