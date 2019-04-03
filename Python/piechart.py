# Import the Turtle() parent object for subjective assignment of turtle() child object.
from turtle import Turtle
# Import Screen for variable "window" assignment. 
from turtle import Screen
# Import turtle for main call of "turtle.textinput()"
import turtle

# Pure function -- returns a list of the total number of vowels found in the user's input. 
def vowelCount(astring):
	
	# Character Assignment: 
	vA = "a"
	vE = "e"
	vI = "i"
	vO = "o"
	vU = "u"
	
	# Counter initalization: 
	aCounter = 0 
	eCounter = 0
	iCounter = 0
	oCounter = 0
	uCounter = 0
	
	# Each indexed character in the user's input is evaulated and counted if a vowel is found; starts at index value of zero. 
	for i in range(0, len(astring)):
		if astring[i] == vA:
			aCounter = aCounter + 1
		elif astring[i] == vE:
			eCounter = eCounter + 1
		elif astring[i] == vI:
			iCounter = iCounter + 1
		elif astring[i] == vO:
			oCounter = oCounter + 1
		elif astring[i] == vU:
			uCounter = uCounter + 1
		else: 
			# All values of vowels are 0 if vowel is not found in string input. 
			strList = [aCounter, eCounter, iCounter, oCounter, uCounter]
	
	# List is created and assigned counter values from previously evaluated for-loop. 
	strList = [aCounter, eCounter, iCounter, oCounter, uCounter]
	
	# Return/pass strList when vowelCount is called. 
	return strList
	
# Non-Pure Function: pieChart(flist) -- Utilizes the turtle GUI and created a pie chart dependent on string input and vowelCount evaluation. 
def pieChart(flist):
	
	# Reassignment of turtle name:
	pieChart = Turtle()
	# When drawing the pie chart, draw-width is larger than default and equal to a value of 2. 
	pieChart.width(2)
	# Doesn't waste so much time compared to default turtle draw speed. 
	pieChart.speed("fastest")
	
	# Radius of pie chart circle:
	pieRadius = 100
	# Radius of the invisible circle when writing the vowel names to individual slices:
	labelRadius = 75
	
	# Sets center circle coordinates without drawing movements:
	pieChart.penup()
	pieChart.setx(0)
	pieChart.sety(-100)
	pieChart.pendown()
	
	# creates parameters/test conditions later used in pie chart's for-loops 
	listLength = len(flist)
	vowelTotal = sum(flist)
	
	# Pie Chart: 
	
	# Creates an empty circle if no vowels are found in the input string, and draws a message stating such:  
	if vowelTotal == 0:
		pieChart.circle(pieRadius)
		pieChart.penup()
		pieChart.right(90)
		pieChart.forward(100)
		pieChart.right(90)
		pieChart.forward(50)
		pieChart.write("No vowels in user input")
	# Creates a colored pie chart representing the occurance of vowels found in the input string: 
	else:
		# Fraction assignment:
		aFraction = (flist[0]/vowelTotal)
		eFraction = (flist[1]/vowelTotal)
		iFraction = (flist[2]/vowelTotal)
		oFraction = (flist[3]/vowelTotal)
		uFraction = (flist[4]/vowelTotal)
		
		# Angle assignment with respect to pie chart's total angle value and occurance of vowels in input string: 
		aAngle = (360*aFraction)
		eAngle = (360*eFraction)
		iAngle = (360*iFraction)
		oAngle = (360*oFraction)
		uAngle = (360*uFraction)
		
		# List creation of repsective vowel angles later used to determine individual slice sizes in pie chart. 
		angleList = [aAngle, eAngle, iAngle, oAngle, uAngle] 
		
		# Label angle assignment to superimpose labels of each vowel letter onto their respective slices: 
		aLabelAngle = aAngle/2
		eLabelAngle = eAngle/2
		iLabelAngle = iAngle/2
		oLabelAngle = oAngle/2
		uLabelAngle = uAngle/2
		
		# List creation of repsective label angles later used to determine spacial difference between vowel labels. 
		labelAngleList = [aLabelAngle, eLabelAngle, iLabelAngle, oLabelAngle, uLabelAngle] 
		
		# List of colors to be used for each vowel slice.
		colorList = ["Red", "Blue", "Green", "Gray", "Yellow"]
		# List of vowels as a characters that will be written to each vowel slice. 
		vowelList = ["a", "e", "i", "o", "u"]
		
		# Initalize potential position index for each slice and label:
		piePosition = [0, 1, 2, 3, 4] 
		labelPosition = [0, 1, 2, 3, 4] 
		
		# Draw each slice of the pie chart: 
		for i in range(0, listLength):
			if angleList[i] != 0: 
				pieChart.color(colorList[i])
				pieChart.begin_fill()
				pieChart.circle(pieRadius, angleList[i], steps = 100)
				piePosition[i] = pieChart.position()
				pieChart.goto(0, 0)
				pieChart.end_fill()
				pieChart.setposition(piePosition[i])
				
		# Draw a black border of each slice and circumference of pie chart: 
		for i in range(0, listLength):
			if angleList[i] != 0: 
				pieChart.color("Black")
				pieChart.circle(pieRadius, angleList[i], steps = 100)
				piePosition[i] = pieChart.position()
				pieChart.goto(0, 0)
				pieChart.setposition(piePosition[i])
		
		# Bring the center-position of the pie chart back home: 
		pieChart.goto(0, -100)

		# Draw an invisible circle, but write the labels of each value in the area of the label's respective slice: 
		for j in range(0, len(vowelList)):
			if angleList[j] != 0:
				pieChart.color("Black")
				pieChart.penup()
				pieChart.circle(labelRadius, labelAngleList[j], steps = 100)
				pieChart.pendown()
				pieChart.write(vowelList[j], align = "Center", font = ("Times New Roman", 12, "bold"))
				pieChart.penup()
				pieChart.circle(labelRadius, labelAngleList[j], steps = 100)

	# Hide the turtle
	pieChart.hideturtle()
	# Initialize a window with Screen() class properties.
	window = Screen()
	# Exit when the GUI window is clicked.
	window.exitonclick()

# Main function: 
def main():
	# Prompt the User for string input using the turtle GUI.
	userInput = turtle.textinput("pieChart", "Enter a string of any size: ")
	# Create a list that passes the user's input into the pure, vowelCount function.
	frequencyList = (vowelCount(userInput))
	# Pass the frequencyList (return from vowelCount) into the non-pure, pieChart function. 
	vowelCount_pieChart = pieChart(frequencyList)
	# Complete the program. 
	return 0

if __name__ == '__main__':
	main()
